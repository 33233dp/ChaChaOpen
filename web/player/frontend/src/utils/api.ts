const API_BASE = '/api'

export interface AnimeItem {
  id: number
  name: string
  cover_url: string | null
  episode_count: number
  last_played_at: string | null
}

export interface EpisodeItem {
  id: number
  filename: string
  display_name: string
  subtitle: string | null
  duration: number | null
}

export interface AnimeDetail {
  anime_id: number
  name: string
  folder_path: string
  episodes: EpisodeItem[]
}

export async function fetchAnimeList(): Promise<AnimeItem[]> {
  const res = await fetch(`${API_BASE}/anime/list`)
  return res.json()
}

export async function fetchAnimeDetail(animeId: number): Promise<AnimeDetail> {
  const res = await fetch(`${API_BASE}/anime/${animeId}/episodes`)
  return res.json()
}

export async function triggerScan(): Promise<{ scanned_count: number }> {
  const res = await fetch(`${API_BASE}/anime/scan`, { method: 'POST' })
  return res.json()
}

export async function fetchProgress(episodeId: number): Promise<{ current_time: number }> {
  const res = await fetch(`${API_BASE}/anime/progress/${episodeId}`)
  return res.json()
}

export async function saveProgress(episodeId: number, currentTime: number, duration: number): Promise<void> {
  await fetch(`${API_BASE}/anime/progress`, {
    method: 'POST',
    headers: { 'Content-Type': 'application/json' },
    body: JSON.stringify({ episode_id: episodeId, current_time: currentTime, duration }),
  })
}

export function getStreamUrl(episodeId: number): string {
  return `${API_BASE}/stream/${episodeId}`
}

export function getSubtitleUrl(folderPath: string, filename: string): string {
  const encodedPath = encodeURIComponent(folderPath)
  const encodedFile = encodeURIComponent(filename)
  return `${API_BASE}/subtitle?folder_path=${encodedPath}&filename=${encodedFile}`
}