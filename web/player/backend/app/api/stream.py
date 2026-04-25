import os
from fastapi import APIRouter, Request, Response, Depends
from fastapi.responses import StreamingResponse
from sqlalchemy.orm import Session
from app.database.db import get_db
from app.database.models import Episode

router = APIRouter(prefix='/api/stream', tags=['stream'])

CHUNK_SIZE = 1024 * 1024 * 2


@router.get('/{episode_id}')
def stream_video(episode_id: int, request: Request, db: Session = Depends(get_db)):
    episode = db.query(Episode).filter(Episode.id == episode_id).first()
    if not episode:
        return Response(status_code=404)

    file_path = episode.file_path
    if not os.path.isfile(file_path):
        return Response(status_code=404)

    file_size = os.path.getsize(file_path)
    range_header = request.headers.get('range')

    if range_header:
        range_match = range_header.replace('bytes=', '').split('-')
        start = int(range_match[0])
        end = int(range_match[1]) if range_match[1] else min(start + CHUNK_SIZE, file_size - 1)
    else:
        start = 0
        end = file_size - 1

    content_length = end - start + 1

    ext = os.path.splitext(file_path)[1].lower()
    content_type_map = {
        '.mp4': 'video/mp4',
        '.mkv': 'video/x-matroska',
        '.avi': 'video/x-msvideo',
        '.wmv': 'video/x-ms-wmv',
        '.flv': 'video/x-flv',
        '.mov': 'video/quicktime',
        '.webm': 'video/webm',
        '.ts': 'video/mp2t',
    }
    content_type = content_type_map.get(ext, 'video/mp4')

    def iter_file():
        with open(file_path, 'rb') as f:
            f.seek(start)
            remaining = content_length
            while remaining > 0:
                chunk = f.read(min(CHUNK_SIZE, remaining))
                if not chunk:
                    break
                remaining -= len(chunk)
                yield chunk

    headers = {
        'Content-Range': f'bytes {start}-{end}/{file_size}',
        'Accept-Ranges': 'bytes',
        'Content-Length': str(content_length),
        'Content-Type': content_type,
    }

    return StreamingResponse(
        iter_file(),
        status_code=206,
        headers=headers,
        media_type=content_type,
    )
