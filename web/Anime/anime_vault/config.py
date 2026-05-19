from __future__ import annotations

from pathlib import Path


PACKAGE_DIR = Path(__file__).resolve().parent
BASE_DIR = PACKAGE_DIR.parent
DB_PATH = BASE_DIR / "data" / "anime.db"
TEMPLATE_DIR = BASE_DIR / "templates"
