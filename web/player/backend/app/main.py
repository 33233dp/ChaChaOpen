import os
from fastapi import FastAPI
from fastapi.middleware.cors import CORSMiddleware
from fastapi.staticfiles import StaticFiles
from fastapi.responses import FileResponse
from app.database.db import init_db
from app.api import anime, stream, progress, config

app = FastAPI(title='My Anime Site', version='1.0.0')

app.add_middleware(
    CORSMiddleware,
    allow_origins=['*'],
    allow_credentials=True,
    allow_methods=['*'],
    allow_headers=['*'],
)

app.include_router(anime.router)
app.include_router(stream.router)
app.include_router(progress.router)
app.include_router(config.router)

COVERS_DIR = os.path.abspath(os.path.join(os.path.dirname(__file__), '..', '..', 'data', 'covers'))
os.makedirs(COVERS_DIR, exist_ok=True)
app.mount('/api/covers', StaticFiles(directory=COVERS_DIR), name='covers')


@app.get('/api/subtitle')
def get_subtitle(folder_path: str, filename: str):
    subtitle_path = os.path.join(folder_path, filename)
    if os.path.isfile(subtitle_path):
        return FileResponse(subtitle_path)
    return {'error': 'Subtitle not found'}, 404


@app.on_event('startup')
def on_startup():
    init_db()