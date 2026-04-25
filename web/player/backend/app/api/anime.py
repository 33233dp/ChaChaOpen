from fastapi import APIRouter, Depends
from sqlalchemy.orm import Session
from app.database.db import get_db
from app.database.models import Anime, Episode
from app.core.scanner import scan_video_folders
from datetime import datetime

router = APIRouter(prefix='/api/anime', tags=['anime'])


@router.get('/list')
def get_anime_list(db: Session = Depends(get_db)):
    animes = db.query(Anime).order_by(Anime.name).all()
    result = []
    for a in animes:
        result.append({
            'id': a.id,
            'name': a.name,
            'cover_url': f'/api/covers/{a.cover_filename}' if a.cover_filename else None,
            'episode_count': a.episode_count,
            'last_played_at': a.last_played_at.isoformat() if a.last_played_at else None,
        })
    return result


@router.get('/{anime_id}/episodes')
def get_anime_episodes(anime_id: int, db: Session = Depends(get_db)):
    anime = db.query(Anime).filter(Anime.id == anime_id).first()
    if not anime:
        return {'error': 'Anime not found'}, 404

    episodes = db.query(Episode).filter(
        Episode.anime_id == anime_id
    ).order_by(Episode.sort_order).all()

    return {
        'anime_id': anime.id,
        'name': anime.name,
        'folder_path': anime.folder_path,
        'episodes': [
            {
                'id': ep.id,
                'filename': ep.filename,
                'display_name': ep.display_name,
                'subtitle': ep.subtitle,
                'duration': ep.duration,
            }
            for ep in episodes
        ],
    }


@router.post('/scan')
def trigger_scan(db: Session = Depends(get_db)):
    scanned = scan_video_folders()

    for item in scanned:
        existing = db.query(Anime).filter(Anime.folder_path == item['folder_path']).first()
        if existing:
            existing.name = item['name']
            existing.cover_filename = item['cover_filename']
            existing.episode_count = len(item['episodes'])
            existing.updated_at = datetime.now()

            for idx, ep_data in enumerate(item['episodes']):
                existing_ep = db.query(Episode).filter(Episode.file_path == ep_data['file_path']).first()
                if existing_ep:
                    existing_ep.filename = ep_data['filename']
                    existing_ep.display_name = ep_data['display_name']
                    existing_ep.subtitle = ep_data.get('subtitle')
                    existing_ep.sort_order = idx
                else:
                    new_ep = Episode(
                        anime_id=existing.id,
                        filename=ep_data['filename'],
                        display_name=ep_data['display_name'],
                        file_path=ep_data['file_path'],
                        subtitle=ep_data.get('subtitle'),
                        sort_order=idx,
                    )
                    db.add(new_ep)
        else:
            new_anime = Anime(
                name=item['name'],
                folder_path=item['folder_path'],
                cover_filename=item['cover_filename'],
                episode_count=len(item['episodes']),
            )
            db.add(new_anime)
            db.flush()

            for idx, ep_data in enumerate(item['episodes']):
                new_ep = Episode(
                    anime_id=new_anime.id,
                    filename=ep_data['filename'],
                    display_name=ep_data['display_name'],
                    file_path=ep_data['file_path'],
                    subtitle=ep_data.get('subtitle'),
                    sort_order=idx,
                )
                db.add(new_ep)

    stale_animes = db.query(Anime).all()
    scanned_paths = {item['folder_path'] for item in scanned}
    for anime in stale_animes:
        if anime.folder_path not in scanned_paths:
            db.query(Episode).filter(Episode.anime_id == anime.id).delete()
            db.delete(anime)

    db.commit()
    return {'scanned_count': len(scanned)}