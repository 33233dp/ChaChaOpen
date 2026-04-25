from sqlalchemy import Column, Integer, String, Float, DateTime, func
from app.database.db import Base


class Anime(Base):
    __tablename__ = 'anime'

    id = Column(Integer, primary_key=True, autoincrement=True)
    name = Column(String(255), nullable=False, index=True)
    folder_path = Column(String(512), nullable=False, unique=True)
    cover_filename = Column(String(255), nullable=True)
    episode_count = Column(Integer, default=0)
    last_played_at = Column(DateTime, nullable=True)
    created_at = Column(DateTime, server_default=func.now())
    updated_at = Column(DateTime, server_default=func.now(), onupdate=func.now())


class Episode(Base):
    __tablename__ = 'episodes'

    id = Column(Integer, primary_key=True, autoincrement=True)
    anime_id = Column(Integer, nullable=False, index=True)
    filename = Column(String(255), nullable=False)
    display_name = Column(String(255), nullable=False)
    file_path = Column(String(512), nullable=False, unique=True)
    subtitle = Column(String(255), nullable=True)
    duration = Column(Float, nullable=True)
    sort_order = Column(Integer, default=0)
    created_at = Column(DateTime, server_default=func.now())


class Progress(Base):
    __tablename__ = 'progress'

    id = Column(Integer, primary_key=True, autoincrement=True)
    episode_id = Column(Integer, nullable=False, unique=True, index=True)
    current_time = Column(Float, default=0)
    duration = Column(Float, default=0)
    updated_at = Column(DateTime, server_default=func.now(), onupdate=func.now())