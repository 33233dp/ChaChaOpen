<template>
  <div class="fixed inset-0 overflow-hidden pointer-events-none" style="z-index: 0;">
    <div
      class="absolute rounded-full"
      style="width: 600px; height: 600px; top: -10%; left: -5%; background: radial-gradient(circle, rgba(26,26,46,0.8) 0%, transparent 70%); animation: float-blob-1 20s ease-in-out infinite;"
    />
    <div
      class="absolute rounded-full"
      style="width: 500px; height: 500px; top: 40%; right: -10%; background: radial-gradient(circle, rgba(22,33,62,0.7) 0%, transparent 70%); animation: float-blob-2 25s ease-in-out infinite;"
    />
    <div
      class="absolute rounded-full"
      style="width: 450px; height: 450px; bottom: -5%; left: 30%; background: radial-gradient(circle, rgba(26,26,46,0.6) 0%, transparent 70%); animation: float-blob-3 22s ease-in-out infinite;"
    />
  </div>
</template>
