from __future__ import annotations

import json
import sqlite3
from functools import lru_cache
from typing import Any

from .config import DB_PATH
from .seed import CATALOG_SEED


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


def anime_exists(slug: str) -> bool:
    return get_anime(slug) is not None


def create_anime(record: dict[str, Any]) -> None:
    with sqlite3.connect(DB_PATH) as connection:
        connection.execute(
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
                playback_url,
                episode_count,
                episode_root_domain,
                episode_route,
                episode_query_prefix,
                episode_start_number,
                episode_other,
                last_played_episode
            ) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
            """,
            (
                record["slug"],
                record["title"],
                record["subtitle"],
                record["release_info"],
                record["studio"],
                record["synopsis"],
                json.dumps(record["cast"], ensure_ascii=False),
                json.dumps(record["keywords"], ensure_ascii=False),
                record["poster_path"],
                record["still_path"],
                json.dumps(record["sources"], ensure_ascii=False),
                record["playback_url"],
                record["episode_count"],
                record["episode_root_domain"],
                record["episode_route"],
                record["episode_query_prefix"],
                record["episode_start_number"],
                record["episode_other"],
                record["last_played_episode"],
            ),
        )
        connection.commit()
    load_catalog.cache_clear()


def save_playback_url(slug: str, playback_url: str) -> None:
    with sqlite3.connect(DB_PATH) as connection:
        connection.execute(
            "UPDATE anime SET playback_url = ? WHERE slug = ?",
            (playback_url, slug),
        )
        connection.commit()
    load_catalog.cache_clear()


def save_episode_config(
    slug: str,
    episode_count: int,
    episode_root_domain: str,
    episode_route: str,
    episode_query_prefix: str,
    episode_start_number: int,
    episode_other: str,
) -> None:
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
                episode_root_domain,
                episode_route,
                episode_query_prefix,
                episode_start_number,
                episode_other,
                last_played,
                slug,
            ),
        )
        connection.commit()
    load_catalog.cache_clear()


def record_last_played_episode(slug: str, episode_number: int) -> None:
    with sqlite3.connect(DB_PATH) as connection:
        connection.execute(
            "UPDATE anime SET last_played_episode = ? WHERE slug = ?",
            (episode_number, slug),
        )
        connection.commit()
    load_catalog.cache_clear()
