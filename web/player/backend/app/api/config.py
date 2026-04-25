from fastapi import APIRouter
from app.core.scanner import load_settings, save_settings
from pydantic import BaseModel
from typing import Optional

router = APIRouter(prefix='/api/config', tags=['config'])


class ConfigInput(BaseModel):
    video_paths: Optional[list[str]] = None
    exclude_keywords: Optional[list[str]] = None


@router.get('')
def get_config():
    return load_settings()


@router.put('')
def update_config(data: ConfigInput):
    current = load_settings()
    if data.video_paths is not None:
        current['video_paths'] = data.video_paths
    if data.exclude_keywords is not None:
        current['exclude_keywords'] = data.exclude_keywords
    save_settings(current)
    return current
