<template>
  <div
    class="grid transition-all duration-300"
    :style="gridStyle"
  >
    <AnimeCard
      v-for="anime in animeList"
      :key="anime.id"
      :name="anime.name"
      :cover-url="anime.cover_url"
      :episode-count="anime.episode_count"
      @click="$emit('select', anime)"
    />
  </div>
</template>

<script setup lang="ts">
import { computed } from 'vue'
import AnimeCard from './AnimeCard.vue'
import type { AnimeItem } from '@/utils/api'

const props = defineProps<{
  animeList: AnimeItem[]
  columns: number
}>()

defineEmits<{
  select: [anime: AnimeItem]
}>()

const gridStyle = computed(() => {
  const gap = Math.max(8, 24 - (props.columns - 2) * 3)
  return {
    gridTemplateColumns: `repeat(${props.columns}, 1fr)`,
    gap: `${gap}px`,
  }
})
</script>
