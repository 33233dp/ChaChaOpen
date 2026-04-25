<template>
  <div class="min-h-screen relative flex flex-col" style="background: #0a0a0f;">
    <header class="flex items-center gap-4 px-6 py-3" style="backdrop-filter: blur(16px); background: rgba(10,10,15,0.8); border-bottom: 1px solid rgba(255,255,255,0.06);">
      <button
        @click="goBack"
        class="flex items-center gap-1.5 px-3 py-2 rounded-full text-sm text-cyan-400 transition-all hover:bg-cyan-400/10"
        style="border: 1px solid rgba(0,240,255,0.2);"
      >
        <ArrowLeft class="w-4 h-4" />
        返回
      </button>
      <h1 class="text-lg font-bold text-white truncate">{{ animeName }}</h1>
    </header>

    <div class="flex flex-1 overflow-hidden">
      <div class="flex-1 flex items-center justify-center p-4">
        <VideoPlayer
          v-if="currentEpisodeId"
          :key="currentEpisodeId"
          :episode-id="currentEpisodeId"
          :initial-time="initialTime"
          :subtitle="currentSubtitle"
          :folder-path="folderPath"
        />
      </div>

      <aside class="w-64 flex-shrink-0 overflow-y-auto p-4" style="backdrop-filter: blur(12px); background: rgba(255,255,255,0.03); border-left: 1px solid rgba(255,255,255,0.06);">
        <h2 class="text-sm font-bold text-gray-400 mb-3">剧集列表</h2>
        <ul class="space-y-1">
          <li
            v-for="ep in episodes"
            :key="ep.id"
            @click="selectEpisode(ep)"
            class="flex items-center gap-2 px-3 py-2 rounded-lg cursor-pointer text-sm transition-all"
            :class="ep.id === currentEpisodeId
              ? 'text-cyan-400'
              : 'text-gray-400 hover:text-white hover:bg-white/5'"
            :style="ep.id === currentEpisodeId ? 'background: rgba(0,240,255,0.08); border-left: 2px solid #00f0ff;' : 'border-left: 2px solid transparent;'"
          >
            <Play class="w-3.5 h-3.5 flex-shrink-0" v-if="ep.id === currentEpisodeId" />
            <span class="w-3.5 flex-shrink-0" v-else />
            <span class="truncate">{{ ep.display_name }}</span>
            <span v-if="ep.subtitle" class="text-xs text-cyan-400/60 ml-auto">字幕</span>
          </li>
        </ul>
      </aside>
    </div>
  </div>
</template>

<script setup lang="ts">
import { ref, onMounted } from 'vue'
import { useRoute, useRouter } from 'vue-router'
import { ArrowLeft, Play } from 'lucide-vue-next'
import VideoPlayer from '@/components/VideoPlayer.vue'
import { fetchAnimeDetail, fetchProgress, type EpisodeItem } from '@/utils/api'

const route = useRoute()
const router = useRouter()

const animeId = Number(route.params.animeId)
const animeName = ref('')
const folderPath = ref('')
const episodes = ref<EpisodeItem[]>([])
const currentEpisodeId = ref<number>(0)
const currentSubtitle = ref<string | null>(null)
const initialTime = ref(0)

function goBack() {
  router.push({ name: 'home' })
}

async function selectEpisode(ep: EpisodeItem) {
  currentEpisodeId.value = ep.id
  currentSubtitle.value = ep.subtitle
  try {
    const progress = await fetchProgress(ep.id)
    initialTime.value = progress.current_time || 0
  } catch {
    initialTime.value = 0
  }
}

onMounted(async () => {
  try {
    const detail = await fetchAnimeDetail(animeId)
    animeName.value = detail.name
    folderPath.value = detail.folder_path
    episodes.value = detail.episodes

    if (detail.episodes.length > 0) {
      const firstEp = detail.episodes[0]
      currentEpisodeId.value = firstEp.id
      currentSubtitle.value = firstEp.subtitle
      try {
        const progress = await fetchProgress(firstEp.id)
        initialTime.value = progress.current_time || 0
      } catch {
        initialTime.value = 0
      }
    }
  } catch (e) {
    console.error('Failed to load anime detail', e)
  }
})
</script>