#!/usr/bin/env python3
from __future__ import annotations

import argparse
import html
import json
import sqlite3
from functools import lru_cache
from http import HTTPStatus
from http.server import SimpleHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path
from typing import Any
from urllib.parse import parse_qs, quote, unquote, urlparse


BASE_DIR = Path(__file__).resolve().parent
DB_PATH = BASE_DIR / "data" / "anime.db"
TEMPLATE_DIR = BASE_DIR / "templates"

CATALOG_SEED: list[dict[str, Any]] = [
    {
        "slug": "fate-zero",
        "title": "Fate/Zero",
        "subtitle": "第四次圣杯战争的群像剧",
        "release_info": "2011-2012 · ufotable",
        "studio": "ufotable",
        "synopsis": (
            "以《Fate/stay night》前传为背景，七名魔术师与七位英灵在冬木市围绕圣杯"
            "展开第四次圣杯战争。卫宫切嗣、言峰绮礼与远坂时臣等人各怀信念，在理"
            "想、救赎与牺牲之间不断碰撞。"
        ),
        "cast": [
            "卫宫切嗣 / 小山力也",
            "爱丽丝菲尔 / 大原沙耶香",
            "Saber / 川澄绫子",
            "言峰绮礼 / 中田让治",
            "远坂时臣 / 速水奖",
            "Lancer / 绿川光",
        ],
        "keywords": [
            "圣杯战争",
            "英灵召唤",
            "群像叙事",
            "理想冲突",
            "黑暗奇幻",
            "宿命悲剧",
        ],
        "poster_path": "poster/fate zero.webp",
        "still_path": "Stills/fate zero.webp",
        "sources": [
            {"label": "Fate/Zero 官方故事", "url": "https://www.fate-zero.jp/story/"},
            {"label": "Fate/Zero 官方角色", "url": "https://www.fate-zero.jp/character/"},
            {"label": "Wikipedia", "url": "https://en.wikipedia.org/wiki/Fate/Zero"},
        ],
    },
    {
        "slug": "attack-on-titan",
        "title": "进击的巨人",
        "subtitle": "墙外世界与自由代价的史诗",
        "release_info": "2013-2023 · WIT STUDIO / MAPPA",
        "studio": "WIT STUDIO / MAPPA",
        "synopsis": (
            "人类被高墙包围，在巨人威胁下苟活。艾伦目睹家园被毁后加入调查兵团，"
            "与三笠、阿尔敏一起追索巨人的真相，也逐步卷入关于自由、战争与历史的"
            "残酷选择。"
        ),
        "cast": [
            "艾伦·耶格尔 / 梶裕贵",
            "三笠·阿克曼 / 石川由依",
            "阿尔敏·阿诺德 / 井上麻里奈",
            "利威尔 / 神谷浩史",
            "艾尔文·史密斯 / 小野大辅",
            "韩吉·佐耶 / 朴璐美",
        ],
        "keywords": [
            "巨人",
            "调查兵团",
            "高墙世界",
            "自由",
            "复仇",
            "战争真相",
        ],
        "poster_path": "poster/进击的巨人.webp",
        "still_path": "Stills/进击的巨人.webp",
        "sources": [
            {"label": "进击的巨人 官方站点", "url": "https://shingeki.tv/final/"},
            {"label": "进击的巨人 官方角色", "url": "https://shingeki.tv/final/character/"},
            {"label": "Wikipedia", "url": "https://en.wikipedia.org/wiki/Attack_on_Titan_(TV_series)"},
        ],
    },
    {
        "slug": "guilty-crown",
        "title": "罪恶王冠",
        "subtitle": "失序东京下的少年与王之能力",
        "release_info": "2011-2012 · Production I.G",
        "studio": "Production I.G",
        "synopsis": (
            "在“天启病毒”重创后的近未来东京，樱满集因结识歌手楪祈而被卷入反抗组"
            "织“葬仪社”。当他获得从他人内心抽出“Void”的能力后，个人选择与集体命"
            "运开始交织。"
        ),
        "cast": [
            "樱满集 / 梶裕贵",
            "楪祈 / 茅野爱衣",
            "恙神涯 / 中村悠一",
            "篠宫绫濑 / 花泽香菜",
            "校条祭 / 嶋村侑",
            "四分仪 / 子安武人",
        ],
        "keywords": [
            "天启病毒",
            "Void",
            "反抗组织",
            "超能力",
            "青春成长",
            "近未来东京",
        ],
        "poster_path": "poster/罪恶王冠.webp",
        "still_path": "Stills/罪恶王冠.webp",
        "sources": [
            {"label": "罪恶王冠 官方介绍", "url": "https://www.guilty-crown.jp/introduction/"},
            {"label": "罪恶王冠 官方角色", "url": "https://www.guilty-crown.jp/character/"},
            {"label": "Wikipedia", "url": "https://en.wikipedia.org/wiki/Guilty_Crown"},
        ],
    },
    {
        "slug": "steins-gate",
        "title": "命运石之门",
        "subtitle": "世界线交错中的时间旅行悬疑",
        "release_info": "2011 · WHITE FOX",
        "studio": "WHITE FOX",
        "synopsis": (
            "自称“疯狂科学家”的冈部伦太郎与未来道具研究所伙伴在秋叶原误打误撞造出"
            "能够改变过去的 D-mail。随着世界线不断偏移，他们必须在友情、爱情与因果"
            "代价之间做出抉择。"
        ),
        "cast": [
            "冈部伦太郎 / 宫野真守",
            "牧濑红莉栖 / 今井麻美",
            "椎名真由理 / 花泽香菜",
            "桥田至 / 关智一",
            "阿万音铃羽 / 田村由香里",
            "菲利斯·喵喵 / 桃井晴子",
        ],
        "keywords": [
            "时间旅行",
            "世界线",
            "D-mail",
            "SERN",
            "秋叶原",
            "科幻悬疑",
        ],
        "poster_path": "poster/命运石之门.webp",
        "still_path": "Stills/命运石之门.webp",
        "sources": [
            {"label": "STEINS;GATE 官方故事", "url": "https://steinsgate.tv/story/"},
            {"label": "STEINS;GATE 官方声优访谈", "url": "https://steinsgate.tv/special/castcomment/"},
            {"label": "Wikipedia", "url": "https://en.wikipedia.org/wiki/Steins;Gate_(TV_series)"},
        ],
    },
]


def ensure_database() -> None:
    DB_PATH.parent.mkdir(parents=True, exist_ok=True)
    with sqlite3.connect(DB_PATH) as connection:
        connection.execute(
            """
            CREATE TABLE IF NOT EXISTS anime (
                slug TEXT PRIMARY KEY,
                title TEXT NOT NULL,
                subtitle TEXT NOT NULL,
                release_info TEXT NOT NULL,
                studio TEXT NOT NULL,
                synopsis TEXT NOT NULL,
                cast_json TEXT NOT NULL,
                keywords_json TEXT NOT NULL,
                poster_path TEXT NOT NULL,
                still_path TEXT NOT NULL,
                sources_json TEXT NOT NULL,
                playback_url TEXT NOT NULL DEFAULT '',
                episode_count INTEGER NOT NULL DEFAULT 0,
                episode_root_domain TEXT NOT NULL DEFAULT '',
                episode_route TEXT NOT NULL DEFAULT '',
                episode_query_prefix TEXT NOT NULL DEFAULT '',
                episode_start_number INTEGER NOT NULL DEFAULT 1,
                episode_other TEXT NOT NULL DEFAULT '',
                last_played_episode INTEGER NOT NULL DEFAULT 0
            )
            """
        )
        ensure_column(connection, "anime", "playback_url", "TEXT NOT NULL DEFAULT ''")
        ensure_column(connection, "anime", "episode_count", "INTEGER NOT NULL DEFAULT 0")
        ensure_column(
            connection, "anime", "episode_root_domain", "TEXT NOT NULL DEFAULT ''"
        )
        ensure_column(connection, "anime", "episode_route", "TEXT NOT NULL DEFAULT ''")
        ensure_column(
            connection, "anime", "episode_query_prefix", "TEXT NOT NULL DEFAULT ''"
        )
        ensure_column(
            connection, "anime", "episode_start_number", "INTEGER NOT NULL DEFAULT 1"
        )
        ensure_column(connection, "anime", "episode_other", "TEXT NOT NULL DEFAULT ''")
        ensure_column(
            connection, "anime", "last_played_episode", "INTEGER NOT NULL DEFAULT 0"
        )
        connection.executemany(
            """
            INSERT INTO anime (
                slug,
                title,
                subtitle,
                release_info,
                studio,
                synopsis,
                cast_json,
                keywords_json,
                poster_path,
                still_path,
                sources_json,
                playback_url
            ) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
            ON CONFLICT(slug) DO UPDATE SET
                title = excluded.title,
                subtitle = excluded.subtitle,
                release_info = excluded.release_info,
                studio = excluded.studio,
                synopsis = excluded.synopsis,
                cast_json = excluded.cast_json,
                keywords_json = excluded.keywords_json,
                poster_path = excluded.poster_path,
                still_path = excluded.still_path,
                sources_json = excluded.sources_json
            """,
            [
                (
                    anime["slug"],
                    anime["title"],
                    anime["subtitle"],
                    anime["release_info"],
                    anime["studio"],
                    anime["synopsis"],
                    json.dumps(anime["cast"], ensure_ascii=False),
                    json.dumps(anime["keywords"], ensure_ascii=False),
                    anime["poster_path"],
                    anime["still_path"],
                    json.dumps(anime["sources"], ensure_ascii=False),
                    "",
                )
                for anime in CATALOG_SEED
            ],
        )
        connection.commit()
    load_catalog.cache_clear()


def ensure_column(
    connection: sqlite3.Connection, table: str, column: str, definition: str
) -> None:
    columns = {row[1] for row in connection.execute(f"PRAGMA table_info({table})")}
    if column not in columns:
        connection.execute(f"ALTER TABLE {table} ADD COLUMN {column} {definition}")


@lru_cache(maxsize=1)
def load_catalog() -> list[dict[str, Any]]:
    with sqlite3.connect(DB_PATH) as connection:
        connection.row_factory = sqlite3.Row
        rows = connection.execute(
            "SELECT * FROM anime ORDER BY title COLLATE NOCASE"
        ).fetchall()

    catalog: list[dict[str, Any]] = []
    for row in rows:
        catalog.append(
            {
                **dict(row),
                "cast": json.loads(row["cast_json"]),
                "keywords": json.loads(row["keywords_json"]),
                "sources": json.loads(row["sources_json"]),
            }
        )
    return catalog


def get_anime(slug: str) -> dict[str, Any] | None:
    for anime in load_catalog():
        if anime["slug"] == slug:
            return anime
    return None


@lru_cache(maxsize=None)
def load_template(name: str) -> str:
    return (TEMPLATE_DIR / name).read_text(encoding="utf-8")


def render_template(name: str, context: dict[str, str]) -> str:
    output = load_template(name)
    for key, value in context.items():
        output = output.replace(f"{{{{{key}}}}}", value)
    return output


def asset_url(path: str) -> str:
    return "/" + quote(path.replace("\\", "/"), safe="/")


def render_card(anime: dict[str, Any]) -> str:
    title = html.escape(anime["title"])
    subtitle = html.escape(anime["subtitle"])
    release_info = html.escape(anime["release_info"])
    poster_url = asset_url(anime["poster_path"])
    still_url = asset_url(anime["still_path"])
    detail_url = f"/anime/{quote(anime['slug'])}"
    search_text = " ".join([anime["title"], anime["subtitle"], *anime["keywords"]]).lower()
    return f"""
    <article class="poster-card" data-search="{html.escape(search_text)}">
      <a class="poster-card__link" href="{detail_url}" aria-label="查看 {title} 详情">
        <div class="poster-card__glow" style="background-image: url('{still_url}');"></div>
        <img class="poster-card__image" src="{poster_url}" alt="{title} 海报" loading="lazy">
        <div class="poster-card__meta">
          <p class="poster-card__release">{release_info}</p>
          <h2>{title}</h2>
          <p class="poster-card__subtitle">{subtitle}</p>
        </div>
      </a>
    </article>
    """.strip()


def render_chip_list(items: list[str], variant: str) -> str:
    return "\n".join(
        f'<li class="{variant}-chip">{html.escape(item)}</li>' for item in items
    )


def render_source_list(items: list[dict[str, str]]) -> str:
    return "\n".join(
        (
            '<li><a href="{url}" target="_blank" rel="noreferrer">'
            "{label}</a></li>"
        ).format(url=html.escape(item["url"]), label=html.escape(item["label"]))
        for item in items
    )


def render_playback_section(anime: dict[str, Any]) -> str:
    playback_url = str(anime.get("playback_url", "") or "")
    return f"""
    <section class="playback-card">
      <form class="playback-form" method="post" action="/anime/{quote(anime['slug'])}/playback-url" data-playback-form>
        <input
          class="playback-form__input"
          data-playback-input
          name="playback_url"
          type="url"
          inputmode="url"
          aria-label="番剧播放地址"
          placeholder="请输入播放地址"
          value="{html.escape(playback_url, quote=True)}"
          readonly
        >
        <div class="playback-form__dock" data-playback-dock>
          <div class="playback-form__actions">
            <button class="playback-form__button playback-form__button--toggle" type="button" data-edit-toggle aria-pressed="false">编辑地址</button>
            <button class="playback-form__button playback-form__button--save" type="submit" data-save-button disabled>保存地址</button>
          </div>
        </div>
      </form>
    </section>
    """.strip()


def episode_url_components(anime: dict[str, Any]) -> dict[str, str]:
    return {
        "root_domain": str(anime.get("episode_root_domain", "") or "").strip(),
        "route": str(anime.get("episode_route", "") or "").strip(),
        "query_prefix": str(anime.get("episode_query_prefix", "") or "").strip(),
        "other": str(anime.get("episode_other", "") or "").strip(),
    }


def episode_start_number(anime: dict[str, Any]) -> int:
    raw_value = anime.get("episode_start_number", 1)
    if raw_value in (None, ""):
        return 1
    return int(raw_value)


def compose_episode_url(anime: dict[str, Any], episode_number: int) -> str:
    components = episode_url_components(anime)
    root_domain = components["root_domain"].rstrip("/")
    route = components["route"]
    start_number = episode_start_number(anime)
    mapped_episode_number = start_number + episode_number - 1
    if route and not route.startswith("/"):
        route = "/" + route
    return f"{root_domain}{route}{components['query_prefix']}{mapped_episode_number}{components['other']}"


def render_episode_section(anime: dict[str, Any]) -> str:
    count = int(anime.get("episode_count") or 0)
    last_played = int(anime.get("last_played_episode") or 0)
    if count <= 0:
        episodes = '<p class="episodes-empty">尚未配置剧集</p>'
    else:
        episode_items = []
        for episode_number in range(1, count + 1):
            episode_items.append(
                """
                <a class="episode-card{active}" href="/anime/{slug}/episode/{episode}" target="_blank" rel="noreferrer">
                  <span class="episode-card__roman">{episode}</span>
                  <span class="episode-card__label">第 {episode} 集</span>
                </a>
                """.strip().format(
                    active=" episode-card--active" if episode_number == last_played else "",
                    slug=quote(anime["slug"]),
                    episode=episode_number,
                )
            )
        episodes = "\n".join(episode_items)

    last_label = str(last_played) if last_played > 0 else "未播放"
    episode_count_value = str(count) if count > 0 else "0"
    start_number_value = str(episode_start_number(anime))
    components = episode_url_components(anime)
    return f"""
    <section class="episodes-panel" data-episodes-panel>
      <div class="episodes-panel__head">
        <div class="episodes-panel__title">
          <p class="episodes-panel__eyebrow">Episodes</p>
          <h2>剧集</h2>
        </div>
        <div class="episodes-panel__status">
          <span class="episodes-panel__status-label">上一次播放</span>
          <span class="episodes-panel__status-value">{last_label}</span>
        </div>
        <button class="episodes-panel__config-toggle" type="button" data-episodes-config-toggle aria-expanded="false">配置</button>
      </div>
      <form class="episodes-config" method="post" action="/anime/{quote(anime['slug'])}/episodes/config" data-episodes-config-form hidden>
        <div class="episodes-config__grid">
          <label class="episodes-config__field">
            <span>总集数</span>
            <input name="episode_count" type="number" min="0" step="1" value="{html.escape(episode_count_value, quote=True)}">
          </label>
          <label class="episodes-config__field">
            <span>根域名</span>
            <input name="episode_root_domain" type="text" value="{html.escape(components['root_domain'], quote=True)}">
          </label>
          <label class="episodes-config__field">
            <span>路由</span>
            <input name="episode_route" type="text" value="{html.escape(components['route'], quote=True)}">
          </label>
          <label class="episodes-config__field">
            <span>查询参数前缀</span>
            <input name="episode_query_prefix" type="text" value="{html.escape(components['query_prefix'], quote=True)}">
          </label>
          <label class="episodes-config__field">
            <span>起始集数</span>
            <input name="episode_start_number" type="number" step="1" value="{html.escape(start_number_value, quote=True)}">
          </label>
          <label class="episodes-config__field">
            <span>集数</span>
            <input type="text" value="自动生成" readonly>
          </label>
          <label class="episodes-config__field">
            <span>其他</span>
            <input name="episode_other" type="text" value="{html.escape(components['other'], quote=True)}">
          </label>
        </div>
        <div class="episodes-config__actions">
          <button class="episodes-config__save" type="submit">保存配置</button>
        </div>
      </form>
      <div class="episodes-grid">
        {episodes}
      </div>
    </section>
    """.strip()


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
        if route.startswith("/anime/"):
            inner_route = route.removeprefix("/anime/").strip("/")
            if "/episode/" in inner_route and include_body:
                slug, episode_raw = inner_route.split("/episode/", 1)
                if slug and episode_raw.isdigit():
                    self.play_episode(slug, int(episode_raw))
                    return True
            slug = inner_route
            if slug:
                self.render_detail(slug, include_body=include_body)
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

        content_length = int(self.headers.get("Content-Length", "0") or 0)
        payload = self.rfile.read(content_length).decode("utf-8") if content_length else ""
        form_data = parse_qs(payload, keep_blank_values=True)
        playback_url = form_data.get("playback_url", [""])[0].strip()

        with sqlite3.connect(DB_PATH) as connection:
            connection.execute(
                "UPDATE anime SET playback_url = ? WHERE slug = ?",
                (playback_url, slug),
            )
            connection.commit()

        load_catalog.cache_clear()
        self.send_response(HTTPStatus.SEE_OTHER)
        self.send_header("Location", f"/anime/{quote(slug)}")
        self.send_header("Content-Length", "0")
        self.end_headers()

    def update_episode_config(self, slug: str) -> None:
        if get_anime(slug) is None:
            self.send_error(HTTPStatus.NOT_FOUND, "Anime not found")
            return

        content_length = int(self.headers.get("Content-Length", "0") or 0)
        payload = self.rfile.read(content_length).decode("utf-8") if content_length else ""
        form_data = parse_qs(payload, keep_blank_values=True)

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

        with sqlite3.connect(DB_PATH) as connection:
            current_last_played = connection.execute(
                "SELECT last_played_episode FROM anime WHERE slug = ?",
                (slug,),
            ).fetchone()
            last_played = int(current_last_played[0]) if current_last_played else 0
            if episode_count == 0 or last_played > episode_count:
                last_played = 0

            connection.execute(
                """
                UPDATE anime
                SET episode_count = ?,
                    episode_root_domain = ?,
                    episode_route = ?,
                    episode_query_prefix = ?,
                    episode_start_number = ?,
                    episode_other = ?,
                    last_played_episode = ?
                WHERE slug = ?
                """,
                (
                    episode_count,
                    field("episode_root_domain"),
                    field("episode_route"),
                    field("episode_query_prefix"),
                    episode_start_number,
                    field("episode_other"),
                    last_played,
                    slug,
                ),
            )
            connection.commit()

        load_catalog.cache_clear()
        self.send_response(HTTPStatus.SEE_OTHER)
        self.send_header("Location", f"/anime/{quote(slug)}")
        self.send_header("Content-Length", "0")
        self.end_headers()

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

        with sqlite3.connect(DB_PATH) as connection:
            connection.execute(
                "UPDATE anime SET last_played_episode = ? WHERE slug = ?",
                (episode_number, slug),
            )
            connection.commit()

        load_catalog.cache_clear()
        self.send_response(HTTPStatus.FOUND)
        self.send_header("Location", target_url)
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


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="番剧观看管理网页")
    parser.add_argument("--host", default="127.0.0.1", help="监听地址")
    parser.add_argument("--port", type=int, default=8000, help="监听端口")
    parser.add_argument(
        "--init-db",
        action="store_true",
        help="只初始化数据库，不启动 Web 服务",
    )
    return parser.parse_args()


def main() -> None:
    args = parse_args()
    ensure_database()
    if args.init_db:
        print(f"Database ready: {DB_PATH}")
        return

    server = ThreadingHTTPServer((args.host, args.port), AnimeRequestHandler)
    print(f"Serving on http://{args.host}:{args.port}")
    try:
        server.serve_forever()
    except KeyboardInterrupt:
        pass
    finally:
        server.server_close()


if __name__ == "__main__":
    main()
