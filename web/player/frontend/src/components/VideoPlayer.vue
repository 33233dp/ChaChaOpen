<template>
  <div class="relative w-full bg-black rounded-lg overflow-hidden">
    <video
      ref="videoRef"
      class="w-full"
      style="max-height: 80vh;"
      controls
      :src="streamUrl"
      @timeupdate="onTimeUpdate"
      @pause="onPause"
      @loadedmetadata="onLoaded"
    >
      <track
        v-if="subtitleUrl"
        kind="subtitles"
        :src="subtitleUrl"
        srclang="zh-CN"
        default
      />
    </video>
  </div>
</template>

<script setup lang="ts">
import { ref, watch, onMounted, onBeforeUnmount } from 'vue'
import { getStreamUrl, getSubtitleUrl, saveProgress } from '@/utils/api'

const props = defineProps<{
  episodeId: number
  initialTime?: number
  subtitle: string | null
  folderPath: string
}>()

const videoRef = ref<HTMLVideoElement | null>(null)
const streamUrl = ref('')
const subtitleUrl = ref('')
const lastSaveTime = ref(0)

watch(() => props.episodeId, (newId) => {
  streamUrl.value = getStreamUrl(newId)
  updateSubtitle()
}, { immediate: true })

watch(() => props.subtitle, () => {
  updateSubtitle()
})

function updateSubtitle() {
  if (props.subtitle && props.folderPath) {
    subtitleUrl.value = getSubtitleUrl(props.folderPath, props.subtitle)
  } else {
    subtitleUrl.value = ''
  }
}

onMounted(() => {
  if (props.initialTime && props.initialTime > 0) {
    const trySeek = () => {
      if (videoRef.value && videoRef.value.readyState >= 1) {
        videoRef.value.currentTime = props.initialTime!
      }
    }
    videoRef.value?.addEventListener('loadedmetadata', trySeek, { once: true })
  }
})

let saveTimer: ReturnType<typeof setInterval> | null = null
onMounted(() => {
  saveTimer = setInterval(() => {
    tryAutoSave()
  }, 10000)
})

onBeforeUnmount(() => {
  tryAutoSave()
  if (saveTimer) clearInterval(saveTimer)
})

function onLoaded() {
  if (props.initialTime && props.initialTime > 0 && videoRef.value) {
    videoRef.value.currentTime = props.initialTime
  }
}

function onTimeUpdate() {
}

function onPause() {
  tryAutoSave()
}

function tryAutoSave() {
  if (!videoRef.value || !videoRef.value.duration) return
  const now = Date.now()
  if (now - lastSaveTime.value < 5000) return
  lastSaveTime.value = now
  saveProgress(
    props.episodeId,
    videoRef.value.currentTime,
    videoRef.value.duration
  )
}
</script>