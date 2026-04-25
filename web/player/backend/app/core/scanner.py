import os
import json
import re
from typing import Optional

SETTINGS_PATH = os.path.abspath(os.path.join(os.path.dirname(__file__), '..', '..', 'config', 'settings.json'))
COVERS_DIR = os.path.abspath(os.path.join(os.path.dirname(__file__), '..', '..', 'data', 'covers'))

VIDEO_EXTENSIONS = {'.mp4', '.mkv', '.avi', '.wmv', '.flv', '.mov', '.webm', '.ts'}
SUBTITLE_EXTENSIONS = {'.ass', '.srt', '.ssa', '.vtt', '.sub', '.idx'}


def load_settings() -> dict:
    with open(SETTINGS_PATH, 'r', encoding='utf-8') as f:
        return json.load(f)


def save_settings(data: dict):
    with open(SETTINGS_PATH, 'w', encoding='utf-8') as f:
        json.dump(data, f, ensure_ascii=False, indent=2)


def normalize_name(name: str) -> str:
    return name.strip().lower()


def find_cover(folder_name: str) -> Optional[str]:
    if not os.path.isdir(COVERS_DIR):
        return None
    normalized = normalize_name(folder_name)
    for fname in os.listdir(COVERS_DIR):
        name_without_ext = os.path.splitext(fname)[0]
        if normalize_name(name_without_ext) == normalized:
            return fname
    return None


def parse_episode_number(filename: str) -> Optional[int]:
    patterns = [
        r'[Ee](?:pisode)?[._\s-]*(\d+)',
        r'[第卷](?:\d+|多|几)?[集话卷部][\s._-]*(\d+)',
        r'[第卷](\d+)[集话卷部]',
        r'[(\[](\d{1,3})[)\]]',
        r'[._-](\d{2,3})[._-]',
    ]
    for pattern in patterns:
        match = re.search(pattern, filename)
        if match:
            try:
                return int(match.group(1))
            except (ValueError, IndexError):
                continue
    return None


def find_subtitle(folder_path: str, video_filename: str) -> Optional[str]:
    video_base = os.path.splitext(video_filename)[0]
    video_ep_num = parse_episode_number(video_filename)

    try:
        entries = os.listdir(folder_path)
    except PermissionError:
        return None

    for entry in entries:
        if not os.path.isfile(os.path.join(folder_path, entry)):
            continue
        ext = os.path.splitext(entry)[1].lower()
        if ext not in SUBTITLE_EXTENSIONS:
            continue

        entry_base = os.path.splitext(entry)[0]
        entry_ep_num = parse_episode_number(entry)

        if video_ep_num is not None:
            if entry_ep_num == video_ep_num:
                return entry
        else:
            if entry_base == video_base or entry_base.startswith(video_base) or video_base.startswith(entry_base):
                return entry

    return None


def scan_video_folders() -> list[dict]:
    settings = load_settings()
    video_paths = settings.get('video_paths', [])
    exclude_keywords = settings.get('exclude_keywords', [])

    results = []

    for base_path in video_paths:
        if not os.path.isdir(base_path):
            continue
        _scan_recursive(base_path, base_path, exclude_keywords, results)

    return results


def _scan_recursive(current_path: str, base_path: str, exclude_keywords: list[str], results: list[dict]):
    name = os.path.basename(current_path)

    for kw in exclude_keywords:
        if kw.lower() in name.lower():
            return

    has_video = False
    has_subfolder = False

    try:
        entries = os.listdir(current_path)
    except PermissionError:
        return

    for entry in entries:
        full_path = os.path.join(current_path, entry)
        if os.path.isdir(full_path):
            skip = False
            for kw in exclude_keywords:
                if kw.lower() in entry.lower():
                    skip = True
                    break
            if not skip:
                has_subfolder = True
        elif os.path.isfile(full_path):
            ext = os.path.splitext(entry)[1].lower()
            if ext in VIDEO_EXTENSIONS:
                has_video = True

    if has_video and not has_subfolder:
        episodes = []
        for entry in sorted(entries):
            full_path = os.path.join(current_path, entry)
            if os.path.isfile(full_path):
                ext = os.path.splitext(entry)[1].lower()
                if ext in VIDEO_EXTENSIONS:
                    display_name = os.path.splitext(entry)[0]
                    subtitle = find_subtitle(current_path, entry)
                    episodes.append({
                        'filename': entry,
                        'display_name': display_name,
                        'file_path': full_path,
                        'subtitle': subtitle,
                    })

        cover_filename = find_cover(name)
        results.append({
            'name': name,
            'folder_path': current_path,
            'cover_filename': cover_filename,
            'episodes': episodes,
        })
    elif has_subfolder:
        for entry in entries:
            full_path = os.path.join(current_path, entry)
            if os.path.isdir(full_path):
                _scan_recursive(full_path, base_path, exclude_keywords, results)