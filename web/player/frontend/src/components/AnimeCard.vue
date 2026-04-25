<template>
  <div
    class="group relative cursor-pointer"
    :style="{ aspectRatio: '3/4' }"
    @click="$emit('click')"
  >
    <div class="glow-border absolute -inset-[1px] rounded-xl opacity-0 group-hover:opacity-100 transition-opacity duration-500 overflow-hidden">
      <div class="glow-spinner absolute inset-0" />
    </div>

    <div
      class="relative w-full h-full rounded-xl overflow-hidden"
      style="backdrop-filter: blur(12px); background: rgba(255,255,255,0.05); border: 1px solid rgba(255,255,255,0.08); box-shadow: 0 8px 32px rgba(0,0,0,0.4);"
    >
      <div v-if="!imageLoaded && !imageError" class="w-full h-full pulse-placeholder" />

      <div v-if="imageError && !coverUrl" class="w-full h-full flex flex-col items-center justify-center gap-2" style="background: #1a1a2e;">
        <ImageOff class="w-8 h-8 text-gray-500" />
        <span class="text-xs text-gray-500">缺失封面</span>
      </div>

      <img
        v-if="coverUrl"
        :src="coverUrl"
        :alt="name"
        class="w-full h-full object-cover transition-transform duration-500 group-hover:scale-105"
        :class="{ 'opacity-0': !imageLoaded }"
        @load="onLoad"
        @error="onError"
      />

      <div class="absolute inset-0 bg-gradient-to-t from-black/80 via-transparent to-transparent" />

      <div class="absolute bottom-0 left-0 right-0 p-3">
        <h3 class="text-sm font-bold text-white truncate">{{ name }}</h3>
        <p class="text-xs text-gray-400 mt-0.5">{{ episodeCount }} 集</p>
      </div>
    </div>
  </div>
</template>

<script setup lang="ts">
import { ref } from 'vue'
import { ImageOff } from 'lucide-vue-next'

defineProps<{
  name: string
  coverUrl: string | null
  episodeCount: number
}>()

defineEmits<{
  click: []
}>()

const imageLoaded = ref(false)
const imageError = ref(false)

function onLoad() {
  imageLoaded.value = true
}

function onError() {
  imageError.value = true
  imageLoaded.value = false
}
</script>

<style scoped>
.pulse-placeholder {
  background: #1a1a2e;
  animation: pulse-breathe 2s ease-in-out infinite;
}

.glow-spinner {
  background: conic-gradient(
    from 0deg,
    transparent 0%,
    #00f0ff 10%,
    transparent 20%
  );
  animation: conic-spin 2s linear infinite;
}

.glow-border {
  border-radius: 0.75rem;
}
</style>
