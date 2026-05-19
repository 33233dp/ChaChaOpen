from __future__ import annotations

import html
from functools import lru_cache
from typing import Any
from urllib.parse import quote

from .config import TEMPLATE_DIR


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


def render_anime_form_page(values: dict[str, str], error_message: str = "") -> str:
    context = {
        "ERROR_BANNER": (
            f'<p class="editor-error">{html.escape(error_message)}</p>'
            if error_message
            else ""
        ),
        "SLUG": html.escape(values.get("slug", ""), quote=True),
        "TITLE": html.escape(values.get("title", ""), quote=True),
        "SUBTITLE": html.escape(values.get("subtitle", ""), quote=True),
        "RELEASE_INFO": html.escape(values.get("release_info", ""), quote=True),
        "STUDIO": html.escape(values.get("studio", ""), quote=True),
        "POSTER_PATH": html.escape(values.get("poster_path", ""), quote=True),
        "STILL_PATH": html.escape(values.get("still_path", ""), quote=True),
        "PLAYBACK_URL": html.escape(values.get("playback_url", ""), quote=True),
        "SYNOPSIS": html.escape(values.get("synopsis", "")),
        "CAST_TEXT": html.escape(values.get("cast_text", "")),
        "KEYWORD_TEXT": html.escape(values.get("keyword_text", "")),
        "SOURCE_TEXT": html.escape(values.get("source_text", "")),
        "EPISODE_COUNT": html.escape(values.get("episode_count", "0"), quote=True),
        "EPISODE_ROOT_DOMAIN": html.escape(
            values.get("episode_root_domain", ""), quote=True
        ),
        "EPISODE_ROUTE": html.escape(values.get("episode_route", ""), quote=True),
        "EPISODE_QUERY_PREFIX": html.escape(
            values.get("episode_query_prefix", ""), quote=True
        ),
        "EPISODE_START_NUMBER": html.escape(
            values.get("episode_start_number", "1"), quote=True
        ),
        "EPISODE_OTHER": html.escape(values.get("episode_other", ""), quote=True),
    }
    return render_template("anime_form.html", context)


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
            <span>集数查询偏移</span>
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
