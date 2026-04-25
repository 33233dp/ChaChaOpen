<template>
  <div class="min-h-screen relative">
    <DiffuseBackground />

    <div class="relative z-10">
      <header class="sticky top-0 z-50 flex items-center justify-between px-6 py-3" style="backdrop-filter: blur(16px); background: rgba(10,10,15,0.7); border-bottom: 1px solid rgba(255,255,255,0.06);">
        <div class="flex items-center gap-4 flex-1">
          <h1 class="text-lg font-bold text-white whitespace-nowrap">🎌 My Anime Site</h1>
          <div class="relative max-w-md flex-1">
            <Search class="absolute left-3 top-1/2 -translate-y-1/2 w-4 h-4 text-gray-500" />
            <input
              v-model="searchQuery"
              type="text"
              placeholder="搜索番剧..."
              class="w-full pl-9 pr-4 py-2 rounded-lg text-sm text-white placeholder-gray-500 outline-none focus:ring-1 focus:ring-cyan-400/50"
              style="background: rgba(255,255,255,0.06); border: 1px solid rgba(255,255,255,0.08);"
            />
          </div>
        </div>

        <div class="flex items-center gap-4 ml-4">
          <div class="flex items-center gap-2">
            <span class="text-xs text-gray-400 whitespace-nowrap">列数</span>
            <input
              v-model.number="columns"
              type="range"
              min="2"
              max="8"
              step="1"
              class="w-20 accent-cyan-400"
            />
            <span class="text-xs text-cyan-400 font-mono w-4 text-center">{{ columns }}</span>
          </div>

          <button
            @click="handleScan"
            class="flex items-center gap-1.5 px-3 py-1.5 rounded-lg text-xs text-cyan-400 transition-all hover:bg-cyan-400/10"
            style="border: 1px solid rgba(0,240,255,0.2);"
            :disabled="scanning"
          >
            <RefreshCw class="w-3.5 h-3.5" :class="{ 'animate-spin': scanning }" />
            {{ scanning ? '扫描中...' : '刷新' }}
          </button>
        </div>
      </header>

      <main class="px-6 py-6">
        <div v-if="loading" class="flex items-center justify-center py-20">
          <div class="pulse-placeholder w-16 h-16 rounded-xl" />
        </div>

        <div v-else-if="filteredAnime.length === 0" class="flex flex-col items-center justify-center py-20 text-gray-500">
          <Film class="w-12 h-12 mb-3" />
          <p>{{ searchQuery ? '没有找到匹配的番剧' : '暂无番剧，请先扫描视频路径' }}</p>
        </div>

        <AnimeGrid
          v-else
          :anime-list="filteredAnime"
          :columns="columns"
          @select="goToPlayer"
        />
      </main>
    </div>
  </div>
</template>

<script setup lang="ts">
import { ref, computed, onMounted } from 'vue'
import { useRouter } from 'vue-router'
import { Search, RefreshCw, Film } from 'lucide-vue-next'
import DiffuseBackground from '@/components/DiffuseBackground.vue'
import AnimeGrid from '@/components/AnimeGrid.vue'
import { fetchAnimeList, triggerScan, type AnimeItem } from '@/utils/api'

const router = useRouter()
const animeList = ref<AnimeItem[]>([])
const searchQuery = ref('')
const columns = ref(Number(localStorage.getItem('anime-columns') || 5))
const loading = ref(true)
const scanning = ref(false)

const filteredAnime = computed(() => {
  if (!searchQuery.value) return animeList.value
  const q = searchQuery.value.toLowerCase()
  return animeList.value.filter(a => a.name.toLowerCase().includes(q))
})

function goToPlayer(anime: AnimeItem) {
  router.push({ name: 'player', params: { animeId: anime.id } })
}

async function loadAnimeList() {
  loading.value = true
  try {
    animeList.value = await fetchAnimeList()
  } catch (e) {
    console.error('Failed to load anime list', e)
  } finally {
    loading.value = false
  }
}

async function handleScan() {
  scanning.value = true
  try {
    await triggerScan()
    await loadAnimeList()
  } catch (e) {
    console.error('Scan failed', e)
  } finally {
    scanning.value = false
  }
}

onMounted(() => {
  loadAnimeList()
})

import { watch } from 'vue'
watch(columns, (val) => {
  localStorage.setItem('anime-columns', String(val))
})
</script>
