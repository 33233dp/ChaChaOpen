#!/usr/bin/env python3
"""Lightweight todo application backend.

Start with:
    python app.py
"""

from __future__ import annotations

import json
import os
import calendar
import sqlite3
from datetime import datetime, timezone, date
from http import HTTPStatus
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path
from urllib.parse import parse_qs, urlparse


BASE_DIR = Path(__file__).resolve().parent
DB_PATH = BASE_DIR / "task_manager.db"
TASKS_PAGE_PATH = BASE_DIR / "index.html"
HEATMAP_PAGE_PATH = BASE_DIR / "heatmap.html"
HOST = "127.0.0.1"
PORT = int(os.environ.get("PORT", "8000"))


def now_iso() -> str:
    return datetime.now(timezone.utc).isoformat(timespec="milliseconds")


def open_db() -> sqlite3.Connection:
    conn = sqlite3.connect(DB_PATH)
    conn.row_factory = sqlite3.Row
    conn.execute("PRAGMA foreign_keys = ON")
    conn.execute("PRAGMA journal_mode = WAL")
    return conn


def init_db() -> None:
    with open_db() as conn:
        conn.execute(
            """
            CREATE TABLE IF NOT EXISTS tasks (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                title TEXT NOT NULL,
                note TEXT NOT NULL DEFAULT '',
                due_date TEXT NOT NULL DEFAULT '',
                priority INTEGER NOT NULL DEFAULT 2,
                completed INTEGER NOT NULL DEFAULT 0,
                created_at TEXT NOT NULL,
                updated_at TEXT NOT NULL
            )
            """
        )
        conn.execute(
            """
            CREATE INDEX IF NOT EXISTS idx_tasks_completed_due
            ON tasks (completed, due_date, created_at DESC)
            """
        )
        conn.execute(
            """
            CREATE TABLE IF NOT EXISTS task_events (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                task_id INTEGER,
                event_type TEXT NOT NULL,
                event_date TEXT NOT NULL,
                occurred_at TEXT NOT NULL
            )
            """
        )
        conn.execute(
            """
            CREATE INDEX IF NOT EXISTS idx_task_events_date
            ON task_events (event_date, event_type)
            """
        )

        existing_events = conn.execute("SELECT COUNT(*) AS count FROM task_events").fetchone()["count"]
        if int(existing_events or 0) == 0:
            rows = conn.execute("SELECT id, created_at FROM tasks ORDER BY id ASC").fetchall()
            if rows:
                timestamp = now_iso()
                conn.executemany(
                    """
                    INSERT INTO task_events (task_id, event_type, event_date, occurred_at)
                    VALUES (?, 'created', ?, ?)
                    """,
                    [
                        (
                            row["id"],
                            str(row["created_at"])[:10],
                            timestamp,
                        )
                        for row in rows
                    ],
                )

        columns = {row["name"] for row in conn.execute("PRAGMA table_info(tasks)").fetchall()}
        if "completed_at" not in columns:
            conn.execute("ALTER TABLE tasks ADD COLUMN completed_at TEXT NOT NULL DEFAULT ''")
        conn.execute(
            """
            UPDATE tasks
            SET completed_at = COALESCE(
                (
                    SELECT event_date
                    FROM task_events
                    WHERE task_events.task_id = tasks.id
                      AND task_events.event_type = 'completed'
                    ORDER BY occurred_at DESC, id DESC
                    LIMIT 1
                ),
                ''
            )
            WHERE completed = 1 AND completed_at = ''
            """
        )


def local_date_iso() -> str:
    return datetime.now().astimezone().date().isoformat()


def parse_month_key(value: str | None) -> tuple[int, int]:
    if not value:
        today = datetime.now().astimezone().date()
        return today.year, today.month
    parts = value.split("-")
    if len(parts) != 2:
        raise ValueError("month 必须是 YYYY-MM 格式")
    year = int(parts[0])
    month = int(parts[1])
    if month < 1 or month > 12:
        raise ValueError("month 必须是 YYYY-MM 格式")
    return year, month


def parse_year_key(value: str | None) -> int:
    if not value:
        return datetime.now().astimezone().year
    if len(value) != 4 or not value.isdigit():
        raise ValueError("year 必须是 YYYY 格式")
    return int(value)


def month_bounds(year: int, month: int) -> tuple[date, date]:
    last_day = calendar.monthrange(year, month)[1]
    return date(year, month, 1), date(year, month, last_day)


def year_bounds(year: int) -> tuple[date, date]:
    return date(year, 1, 1), date(year, 12, 31)


def log_event(conn: sqlite3.Connection, task_id: int | None, event_type: str, event_date: str | None = None) -> None:
    conn.execute(
        """
        INSERT INTO task_events (task_id, event_type, event_date, occurred_at)
        VALUES (?, ?, ?, ?)
        """,
        (
            task_id,
            event_type,
            event_date or local_date_iso(),
            now_iso(),
        ),
    )


def row_to_task(row: sqlite3.Row) -> dict:
    return {
        "id": row["id"],
        "title": row["title"],
        "note": row["note"],
        "due_date": row["due_date"],
        "priority": row["priority"],
        "completed": bool(row["completed"]),
        "completed_at": row["completed_at"] if "completed_at" in row.keys() else "",
        "created_at": row["created_at"],
        "updated_at": row["updated_at"],
    }


def validate_task_payload(data: dict, partial: bool = False) -> tuple[dict, list[str]]:
    errors: list[str] = []
    payload: dict = {}

    if not partial or "title" in data:
        title = str(data.get("title", "")).strip()
        if not title:
            errors.append("title 不能为空")
        elif len(title) > 120:
            errors.append("title 不能超过 120 个字符")
        else:
            payload["title"] = title

    if "note" in data or not partial:
        note = str(data.get("note", "")).strip()
        if len(note) > 500:
            errors.append("note 不能超过 500 个字符")
        else:
            payload["note"] = note

    if "due_date" in data or not partial:
        due_date = str(data.get("due_date", "")).strip()
        if due_date:
            try:
                datetime.strptime(due_date, "%Y-%m-%d")
            except ValueError:
                errors.append("due_date 必须是 YYYY-MM-DD 格式")
            else:
                payload["due_date"] = due_date
        else:
            payload["due_date"] = ""

    if "priority" in data or not partial:
        try:
            priority = int(data.get("priority", 2))
        except (TypeError, ValueError):
            errors.append("priority 必须是 1、2 或 3")
        else:
            if priority not in {1, 2, 3}:
                errors.append("priority 必须是 1、2 或 3")
            else:
                payload["priority"] = priority

    if "completed" in data and partial:
        payload["completed"] = 1 if bool(data.get("completed")) else 0

    return payload, errors


def serve_page(path: Path, handler: BaseHTTPRequestHandler) -> bool:
    if not path.exists():
        handler._send_json({"error": f"{path.name} 不存在"}, HTTPStatus.NOT_FOUND)  # type: ignore[attr-defined]
        return False
    handler._send_bytes(path.read_bytes(), "text/html; charset=utf-8")  # type: ignore[attr-defined]
    return True


class TodoHandler(BaseHTTPRequestHandler):
    server_version = "TaskFlow/1.0"

    def log_message(self, format: str, *args) -> None:  # noqa: A003
        return

    def _send_bytes(
        self,
        content: bytes,
        content_type: str,
        status: int = 200,
        write_body: bool = True,
    ) -> None:
        self.send_response(status)
        self.send_header("Content-Type", content_type)
        self.send_header("Content-Length", str(len(content)))
        self.send_header("Cache-Control", "no-store")
        self.end_headers()
        if write_body:
            self.wfile.write(content)

    def _send_json(self, payload: dict, status: int = 200) -> None:
        content = json.dumps(payload, ensure_ascii=False).encode("utf-8")
        self._send_bytes(content, "application/json; charset=utf-8", status)

    def _read_json(self) -> dict:
        length = int(self.headers.get("Content-Length", "0") or "0")
        if not length:
            return {}
        raw = self.rfile.read(length)
        if not raw:
            return {}
        try:
            return json.loads(raw.decode("utf-8"))
        except json.JSONDecodeError:
            raise ValueError("请求体必须是合法 JSON")

    def _task_id_from_path(self) -> tuple[int | None, str]:
        path = urlparse(self.path).path.rstrip("/")
        parts = path.split("/")
        if len(parts) >= 4 and parts[1] == "api" and parts[2] == "tasks":
            try:
                task_id = int(parts[3])
            except ValueError:
                return None, ""
            action = parts[4] if len(parts) >= 5 else ""
            return task_id, action
        return None, ""

    def do_GET(self) -> None:
        parsed = urlparse(self.path)
        if parsed.path == "/" or parsed.path == "/index.html":
            if not serve_page(TASKS_PAGE_PATH, self):
                return
            return

        if parsed.path == "/heatmap" or parsed.path == "/heatmap.html":
            if not serve_page(HEATMAP_PAGE_PATH, self):
                return
            return

        if parsed.path == "/api/health":
            self._send_json({"ok": True, "service": "TaskFlow"})
            return

        if parsed.path == "/api/tasks":
            params = parse_qs(parsed.query)
            status = (params.get("status", ["all"])[0] or "all").lower()
            query = (params.get("q", [""])[0] or "").strip().lower()
            with open_db() as conn:
                sql = "SELECT * FROM tasks"
                clauses = []
                values: list[object] = []

                if status == "active":
                    clauses.append("completed = 0")
                elif status == "completed":
                    clauses.append("completed = 1")

                if query:
                    clauses.append("(LOWER(title) LIKE ? OR LOWER(note) LIKE ?)")
                    like = f"%{query}%"
                    values.extend([like, like])

                if clauses:
                    sql += " WHERE " + " AND ".join(clauses)

                sql += " ORDER BY completed ASC, CASE WHEN due_date = '' THEN 1 ELSE 0 END, due_date ASC, priority DESC, created_at DESC"
                rows = conn.execute(sql, values).fetchall()
                tasks = [row_to_task(row) for row in rows]

            self._send_json({"tasks": tasks})
            return

        if parsed.path == "/api/stats":
            with open_db() as conn:
                row = conn.execute(
                    """
                    SELECT
                        COUNT(*) AS total,
                        SUM(CASE WHEN completed = 0 THEN 1 ELSE 0 END) AS active,
                        SUM(CASE WHEN completed = 1 THEN 1 ELSE 0 END) AS completed
                    FROM tasks
                    """
                ).fetchone()
            self._send_json(
                {
                    "total": int(row["total"] or 0),
                    "active": int(row["active"] or 0),
                    "completed": int(row["completed"] or 0),
                }
            )
            return

        if parsed.path == "/api/activity":
            params = parse_qs(parsed.query)
            try:
                if "month" in params and "year" not in params:
                    year, month = parse_month_key(params.get("month", [None])[0])
                    start, end = month_bounds(year, month)
                    granularity = "month"
                else:
                    year = parse_year_key(params.get("year", [None])[0])
                    start, end = year_bounds(year)
                    granularity = "year"
            except (TypeError, ValueError):
                self._send_json({"error": "year 必须是 YYYY 格式，month 必须是 YYYY-MM 格式"}, HTTPStatus.BAD_REQUEST)
                return

            with open_db() as conn:
                if granularity == "month":
                    rows = conn.execute(
                        """
                        SELECT event_date, COUNT(*) AS count
                        FROM task_events
                        WHERE event_date BETWEEN ? AND ? AND event_type = 'completed'
                        GROUP BY event_date
                        ORDER BY event_date ASC
                        """,
                        (start.isoformat(), end.isoformat()),
                    ).fetchall()
                    counts = {row["event_date"]: int(row["count"] or 0) for row in rows}
                    daily_counts = []
                    current = start
                    while current <= end:
                        key = current.isoformat()
                        daily_counts.append({"date": key, "count": counts.get(key, 0)})
                        current = date.fromordinal(current.toordinal() + 1)

                    self._send_json(
                        {
                            "month": f"{year:04d}-{month:02d}",
                            "start": start.isoformat(),
                            "end": end.isoformat(),
                            "total": sum(item["count"] for item in daily_counts),
                            "daily_counts": daily_counts,
                        }
                    )
                    return

                rows = conn.execute(
                    """
                    SELECT event_date, COUNT(*) AS count
                    FROM task_events
                    WHERE event_date BETWEEN ? AND ? AND event_type = 'completed'
                    GROUP BY event_date
                    ORDER BY event_date ASC
                    """,
                    (start.isoformat(), end.isoformat()),
                ).fetchall()

            counts = {row["event_date"]: int(row["count"] or 0) for row in rows}
            daily_counts = []
            monthly_totals: dict[str, int] = {}
            current = start
            while current <= end:
                key = current.isoformat()
                count = counts.get(key, 0)
                daily_counts.append({"date": key, "count": count})
                month_key = key[:7]
                monthly_totals[month_key] = monthly_totals.get(month_key, 0) + count
                current = date.fromordinal(current.toordinal() + 1)

            monthly_counts = []
            for month in range(1, 13):
                month_key = f"{year:04d}-{month:02d}"
                monthly_counts.append({"month": month_key, "count": monthly_totals.get(month_key, 0)})

            self._send_json(
                {
                    "year": f"{year:04d}",
                    "start": start.isoformat(),
                    "end": end.isoformat(),
                    "total": sum(item["count"] for item in daily_counts),
                    "daily_counts": daily_counts,
                    "monthly_counts": monthly_counts,
                }
            )
            return

        self._send_json({"error": "未找到资源"}, HTTPStatus.NOT_FOUND)

    def do_HEAD(self) -> None:
        parsed = urlparse(self.path)
        if parsed.path == "/" or parsed.path == "/index.html":
            if not TASKS_PAGE_PATH.exists():
                self.send_response(HTTPStatus.NOT_FOUND)
                self.send_header("Content-Type", "application/json; charset=utf-8")
                self.send_header("Content-Length", str(len('{"error":"index.html 不存在"}'.encode("utf-8"))))
                self.end_headers()
                return
            self._send_bytes(
                TASKS_PAGE_PATH.read_bytes(),
                "text/html; charset=utf-8",
                write_body=False,
            )
            return

        if parsed.path == "/heatmap" or parsed.path == "/heatmap.html":
            if not HEATMAP_PAGE_PATH.exists():
                self.send_response(HTTPStatus.NOT_FOUND)
                self.send_header("Content-Type", "application/json; charset=utf-8")
                self.send_header("Content-Length", str(len('{"error":"heatmap.html 不存在"}'.encode("utf-8"))))
                self.end_headers()
                return
            self._send_bytes(
                HEATMAP_PAGE_PATH.read_bytes(),
                "text/html; charset=utf-8",
                write_body=False,
            )
            return

        if parsed.path == "/api/health":
            payload = json.dumps({"ok": True, "service": "TaskFlow"}, ensure_ascii=False).encode("utf-8")
            self._send_bytes(payload, "application/json; charset=utf-8", write_body=False)
            return

        if parsed.path in {"/api/tasks", "/api/stats", "/api/activity"}:
            if parsed.path == "/api/tasks":
                payload = json.dumps({"tasks": []}, ensure_ascii=False).encode("utf-8")
            elif parsed.path == "/api/stats":
                payload = json.dumps({"total": 0, "active": 0, "completed": 0}, ensure_ascii=False).encode("utf-8")
            else:
                payload = json.dumps(
                    {"year": "", "month": "", "start": "", "end": "", "total": 0, "daily_counts": [], "monthly_counts": []},
                    ensure_ascii=False,
                ).encode("utf-8")
            self._send_bytes(payload, "application/json; charset=utf-8", write_body=False)
            return

        self.send_response(HTTPStatus.NOT_FOUND)
        payload = json.dumps({"error": "未找到资源"}, ensure_ascii=False).encode("utf-8")
        self.send_header("Content-Type", "application/json; charset=utf-8")
        self.send_header("Content-Length", str(len(payload)))
        self.end_headers()

    def do_POST(self) -> None:
        parsed = urlparse(self.path)
        if parsed.path != "/api/tasks":
            self._send_json({"error": "未找到资源"}, HTTPStatus.NOT_FOUND)
            return

        try:
            data = self._read_json()
        except ValueError as exc:
            self._send_json({"error": str(exc)}, HTTPStatus.BAD_REQUEST)
            return

        payload, errors = validate_task_payload(data)
        if errors:
            self._send_json({"error": "；".join(errors)}, HTTPStatus.BAD_REQUEST)
            return

        timestamp = now_iso()
        with open_db() as conn:
            cursor = conn.execute(
                """
                INSERT INTO tasks (title, note, due_date, priority, completed, completed_at, created_at, updated_at)
                VALUES (?, ?, ?, ?, 0, '', ?, ?)
                """,
                (
                    payload["title"],
                    payload.get("note", ""),
                    payload.get("due_date", ""),
                    payload.get("priority", 2),
                    timestamp,
                    timestamp,
                ),
            )
            task_id = cursor.lastrowid
            log_event(conn, task_id, "created")
            row = conn.execute("SELECT * FROM tasks WHERE id = ?", (task_id,)).fetchone()

        self._send_json({"task": row_to_task(row)}, HTTPStatus.CREATED)

    def do_PATCH(self) -> None:
        task_id, action = self._task_id_from_path()
        if task_id is None:
            self._send_json({"error": "未找到资源"}, HTTPStatus.NOT_FOUND)
            return

        try:
            data = self._read_json() if self.headers.get("Content-Length") else {}
        except ValueError as exc:
            self._send_json({"error": str(exc)}, HTTPStatus.BAD_REQUEST)
            return

        with open_db() as conn:
            existing = conn.execute("SELECT * FROM tasks WHERE id = ?", (task_id,)).fetchone()
            if not existing:
                self._send_json({"error": "任务不存在"}, HTTPStatus.NOT_FOUND)
                return

            if action == "toggle":
                new_completed = 0 if existing["completed"] else 1
                completed_at = local_date_iso() if new_completed else ""
                now = now_iso()
                conn.execute(
                    "UPDATE tasks SET completed = ?, completed_at = ?, updated_at = ? WHERE id = ?",
                    (new_completed, completed_at, now, task_id),
                )
                if new_completed:
                    log_event(conn, task_id, "completed")
                else:
                    latest_completed = conn.execute(
                        """
                        SELECT id
                        FROM task_events
                        WHERE task_id = ? AND event_type = 'completed'
                        ORDER BY occurred_at DESC, id DESC
                        LIMIT 1
                        """,
                        (task_id,),
                    ).fetchone()
                    if latest_completed:
                        conn.execute(
                            """
                            UPDATE task_events
                            SET event_type = 'reopened', event_date = ?, occurred_at = ?
                            WHERE id = ?
                            """,
                            (local_date_iso(), now, latest_completed["id"]),
                        )
                    else:
                        log_event(conn, task_id, "reopened")
                row = conn.execute("SELECT * FROM tasks WHERE id = ?", (task_id,)).fetchone()
                self._send_json({"task": row_to_task(row)})
                return

            payload, errors = validate_task_payload(data, partial=True)
            if errors:
                self._send_json({"error": "；".join(errors)}, HTTPStatus.BAD_REQUEST)
                return

            if not payload:
                self._send_json({"error": "没有可更新的字段"}, HTTPStatus.BAD_REQUEST)
                return

            assignments = []
            values: list[object] = []
            for key, value in payload.items():
                assignments.append(f"{key} = ?")
                values.append(value)
            assignments.append("updated_at = ?")
            values.append(now_iso())
            values.append(task_id)

            conn.execute(
                f"UPDATE tasks SET {', '.join(assignments)} WHERE id = ?",
                values,
            )
            log_event(conn, task_id, "updated")
            row = conn.execute("SELECT * FROM tasks WHERE id = ?", (task_id,)).fetchone()

        self._send_json({"task": row_to_task(row)})

    def do_DELETE(self) -> None:
        task_id, _ = self._task_id_from_path()
        if task_id is None:
            self._send_json({"error": "未找到资源"}, HTTPStatus.NOT_FOUND)
            return

        with open_db() as conn:
            cursor = conn.execute("DELETE FROM tasks WHERE id = ?", (task_id,))
            if cursor.rowcount == 0:
                self._send_json({"error": "任务不存在"}, HTTPStatus.NOT_FOUND)
                return
            log_event(conn, task_id, "deleted")

        self._send_json({"deleted": True})

    def do_OPTIONS(self) -> None:
        self.send_response(HTTPStatus.NO_CONTENT)
        self.send_header("Allow", "GET, POST, PATCH, DELETE, OPTIONS")
        self.send_header("Access-Control-Allow-Origin", "*")
        self.send_header("Access-Control-Allow-Methods", "GET, POST, PATCH, DELETE, OPTIONS")
        self.send_header("Access-Control-Allow-Headers", "Content-Type")
        self.end_headers()


def main() -> None:
    init_db()
    server = ThreadingHTTPServer((HOST, PORT), TodoHandler)
    print(f"TaskFlow 已启动: http://{HOST}:{PORT}")
    try:
        server.serve_forever()
    except KeyboardInterrupt:
        print("\n正在关闭服务...")
    finally:
        server.server_close()


if __name__ == "__main__":
    main()
