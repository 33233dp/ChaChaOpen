from __future__ import annotations

import html
from http import HTTPStatus
from http.server import SimpleHTTPRequestHandler, ThreadingHTTPServer
from typing import Any
from urllib.parse import parse_qs, quote, unquote, urlparse

from .config import BASE_DIR
from .renderers import (
    asset_url,
    compose_episode_url,
    render_anime_form_page,
    render_card,
    render_chip_list,
    render_episode_section,
    render_playback_section,
    render_source_list,
    render_template,
)
from .repository import (
    anime_exists,
    create_anime,
    get_anime,
    load_catalog,
    record_last_played_episode,
    save_episode_config,
    save_playback_url,
)


class AnimeRequestHandler(SimpleHTTPRequestHandler):
    def __init__(self, *args: Any, **kwargs: Any) -> None:
        super().__init__(*args, directory=str(BASE_DIR), **kwargs)

    def do_GET(self) -> None:
        if self.handle_dynamic_route(include_body=True):
            return
        super().do_GET()

    def do_HEAD(self) -> None:
        if self.handle_dynamic_route(include_body=False):
            return
        super().do_HEAD()

    def do_POST(self) -> None:
        parsed = urlparse(self.path)
        route = unquote(parsed.path)
        if route == "/anime/create":
            self.create_anime_entry()
            return
        if route.startswith("/anime/") and route.endswith("/playback-url"):
            slug = route.removeprefix("/anime/").removesuffix("/playback-url").strip("/")
            if slug:
                self.update_playback_url(slug)
                return
        if route.startswith("/anime/") and route.endswith("/episodes/config"):
            slug = route.removeprefix("/anime/").removesuffix("/episodes/config").strip("/")
            if slug:
                self.update_episode_config(slug)
                return
        self.send_error(HTTPStatus.NOT_FOUND, "Not found")

    def handle_dynamic_route(self, include_body: bool) -> bool:
        parsed = urlparse(self.path)
        route = unquote(parsed.path)
        if route == "/":
            self.render_home(include_body=include_body)
            return True
        if route == "/anime/new":
            self.render_anime_form(include_body=include_body)
            return True
        if route.startswith("/anime/"):
            inner_route = route.removeprefix("/anime/").strip("/")
            if "/episode/" in inner_route and include_body:
                slug, episode_raw = inner_route.split("/episode/", 1)
                if slug and episode_raw.isdigit():
                    self.play_episode(slug, int(episode_raw))
                    return True
            if inner_route:
                self.render_detail(inner_route, include_body=include_body)
                return True
        return False

    def render_home(self, include_body: bool = True) -> None:
        catalog = load_catalog()
        cards = "\n".join(render_card(anime) for anime in catalog)
        page = render_template(
            "index.html",
            {
                "TOTAL_COUNT": str(len(catalog)),
                "POSTER_CARDS": cards,
            },
        )
        self.respond_html(page, include_body=include_body)

    def render_anime_form(
        self,
        include_body: bool = True,
        values: dict[str, str] | None = None,
        error_message: str = "",
    ) -> None:
        page = render_anime_form_page(values or {}, error_message)
        self.respond_html(page, include_body=include_body)

    def render_detail(self, slug: str, include_body: bool = True) -> None:
        anime = get_anime(slug)
        if anime is None:
            self.send_error(HTTPStatus.NOT_FOUND, "Anime not found")
            return

        page = render_template(
            "detail.html",
            {
                "TITLE": html.escape(anime["title"]),
                "SUBTITLE": html.escape(anime["subtitle"]),
                "RELEASE_INFO": html.escape(anime["release_info"]),
                "STUDIO": html.escape(anime["studio"]),
                "SYNOPSIS": html.escape(anime["synopsis"]),
                "PLAYBACK_SECTION": render_playback_section(anime),
                "EPISODE_SECTION": render_episode_section(anime),
                "POSTER_URL": asset_url(anime["poster_path"]),
                "BACKDROP_URL": asset_url(anime["still_path"]),
                "CAST_ITEMS": render_chip_list(anime["cast"], "cast"),
                "KEYWORD_ITEMS": render_chip_list(anime["keywords"], "keyword"),
                "SOURCE_ITEMS": render_source_list(anime["sources"]),
                "BACK_LINK": "/",
            },
        )
        self.respond_html(page, include_body=include_body)

    def update_playback_url(self, slug: str) -> None:
        if get_anime(slug) is None:
            self.send_error(HTTPStatus.NOT_FOUND, "Anime not found")
            return

        form_data = self.read_form_data()
        playback_url = form_data.get("playback_url", [""])[0].strip()
        save_playback_url(slug, playback_url)
        self.redirect(f"/anime/{quote(slug)}", HTTPStatus.SEE_OTHER)

    def create_anime_entry(self) -> None:
        form_data = self.read_form_data()

        def field(name: str, default: str = "") -> str:
            return form_data.get(name, [default])[0].strip()

        values = {
            "slug": field("slug"),
            "title": field("title"),
            "subtitle": field("subtitle"),
            "release_info": field("release_info"),
            "studio": field("studio"),
            "poster_path": field("poster_path"),
            "still_path": field("still_path"),
            "playback_url": field("playback_url"),
            "synopsis": field("synopsis"),
            "cast_text": field("cast_text"),
            "keyword_text": field("keyword_text"),
            "source_text": field("source_text"),
            "episode_count": field("episode_count", "0"),
            "episode_root_domain": field("episode_root_domain"),
            "episode_route": field("episode_route"),
            "episode_query_prefix": field("episode_query_prefix"),
            "episode_start_number": field("episode_start_number", "1"),
            "episode_other": field("episode_other"),
        }

        if not values["slug"] or not values["title"] or not values["poster_path"] or not values["still_path"]:
            self.render_anime_form(
                values=values,
                error_message="slug、番剧名、海报路径和详情页剧照/背景图路径为必填项。",
            )
            return

        if anime_exists(values["slug"]):
            self.render_anime_form(
                values=values,
                error_message="该 slug 已存在，请换一个唯一标识。",
            )
            return

        try:
            episode_count = max(0, int(values["episode_count"] or "0"))
        except ValueError:
            episode_count = 0
        try:
            episode_start_number = int(values["episode_start_number"] or "1")
        except ValueError:
            episode_start_number = 1

        cast = self.parse_lines(values["cast_text"])
        keywords = self.parse_tag_lines(values["keyword_text"])
        sources = self.parse_sources(values["source_text"])

        create_anime(
            {
                "slug": values["slug"],
                "title": values["title"],
                "subtitle": values["subtitle"],
                "release_info": values["release_info"],
                "studio": values["studio"],
                "synopsis": values["synopsis"],
                "cast": cast,
                "keywords": keywords,
                "poster_path": values["poster_path"],
                "still_path": values["still_path"],
                "sources": sources,
                "playback_url": values["playback_url"],
                "episode_count": episode_count,
                "episode_root_domain": values["episode_root_domain"],
                "episode_route": values["episode_route"],
                "episode_query_prefix": values["episode_query_prefix"],
                "episode_start_number": episode_start_number,
                "episode_other": values["episode_other"],
                "last_played_episode": 0,
            }
        )
        self.redirect(f"/anime/{quote(values['slug'])}", HTTPStatus.SEE_OTHER)

    def update_episode_config(self, slug: str) -> None:
        if get_anime(slug) is None:
            self.send_error(HTTPStatus.NOT_FOUND, "Anime not found")
            return

        form_data = self.read_form_data()

        def field(name: str) -> str:
            return form_data.get(name, [""])[0].strip()

        try:
            episode_count = max(0, int(field("episode_count") or "0"))
        except ValueError:
            episode_count = 0
        try:
            episode_start_number = int(field("episode_start_number") or "1")
        except ValueError:
            episode_start_number = 1

        save_episode_config(
            slug=slug,
            episode_count=episode_count,
            episode_root_domain=field("episode_root_domain"),
            episode_route=field("episode_route"),
            episode_query_prefix=field("episode_query_prefix"),
            episode_start_number=episode_start_number,
            episode_other=field("episode_other"),
        )
        self.redirect(f"/anime/{quote(slug)}", HTTPStatus.SEE_OTHER)

    def play_episode(self, slug: str, episode_number: int) -> None:
        anime = get_anime(slug)
        if anime is None:
            self.send_error(HTTPStatus.NOT_FOUND, "Anime not found")
            return

        episode_count = int(anime.get("episode_count") or 0)
        if episode_number <= 0 or episode_number > episode_count:
            self.send_error(HTTPStatus.NOT_FOUND, "Episode not found")
            return

        target_url = compose_episode_url(anime, episode_number)
        if not target_url.strip():
            self.send_error(HTTPStatus.BAD_REQUEST, "Episode URL is not configured")
            return

        record_last_played_episode(slug, episode_number)
        self.redirect(target_url, HTTPStatus.FOUND)

    def read_form_data(self) -> dict[str, list[str]]:
        content_length = int(self.headers.get("Content-Length", "0") or 0)
        payload = self.rfile.read(content_length).decode("utf-8") if content_length else ""
        return parse_qs(payload, keep_blank_values=True)

    def parse_lines(self, raw_text: str) -> list[str]:
        return [line.strip() for line in raw_text.splitlines() if line.strip()]

    def parse_tag_lines(self, raw_text: str) -> list[str]:
        normalized = raw_text.replace("，", ",")
        items: list[str] = []
        for block in normalized.splitlines():
            for item in block.split(","):
                cleaned = item.strip()
                if cleaned:
                    items.append(cleaned)
        return items

    def parse_sources(self, raw_text: str) -> list[dict[str, str]]:
        sources: list[dict[str, str]] = []
        for line in raw_text.splitlines():
            cleaned = line.strip()
            if not cleaned:
                continue
            if "|" in cleaned:
                label, url = cleaned.split("|", 1)
                sources.append({"label": label.strip(), "url": url.strip()})
            else:
                sources.append({"label": cleaned, "url": cleaned})
        return sources

    def redirect(self, location: str, status: HTTPStatus) -> None:
        self.send_response(status)
        self.send_header("Location", location)
        self.send_header("Content-Length", "0")
        self.end_headers()

    def respond_html(self, page: str, include_body: bool = True) -> None:
        payload = page.encode("utf-8")
        self.send_response(HTTPStatus.OK)
        self.send_header("Content-Type", "text/html; charset=utf-8")
        self.send_header("Content-Length", str(len(payload)))
        self.send_header("Cache-Control", "no-store")
        self.end_headers()
        if include_body:
            self.wfile.write(payload)

    def log_message(self, format: str, *args: Any) -> None:
        return


def create_server(host: str, port: int) -> ThreadingHTTPServer:
    return ThreadingHTTPServer((host, port), AnimeRequestHandler)
