from fastapi import APIRouter, Depends
from sqlalchemy.orm import Session
from pydantic import BaseModel
from app.database.db import get_db
from app.database.models import Progress
from datetime import datetime

router = APIRouter(prefix='/api/anime/progress', tags=['progress'])


class ProgressInput(BaseModel):
    episode_id: int
    current_time: float
    duration: float


@router.post('')
def save_progress(data: ProgressInput, db: Session = Depends(get_db)):
    existing = db.query(Progress).filter(Progress.episode_id == data.episode_id).first()
    if existing:
        existing.current_time = data.current_time
        existing.duration = data.duration
        existing.updated_at = datetime.now()
    else:
        progress = Progress(
            episode_id=data.episode_id,
            current_time=data.current_time,
            duration=data.duration,
        )
        db.add(progress)
    db.commit()
    return {'status': 'ok'}


@router.get('/{episode_id}')
def get_progress(episode_id: int, db: Session = Depends(get_db)):
    progress = db.query(Progress).filter(Progress.episode_id == episode_id).first()
    if not progress:
        return {'current_time': 0}
    return {'current_time': progress.current_time}
