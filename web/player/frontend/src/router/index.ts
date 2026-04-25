import { createRouter, createWebHistory } from 'vue-router'
import HomePage from '@/pages/HomePage.vue'
import PlayerPage from '@/pages/PlayerPage.vue'

const routes = [
  {
    path: '/',
    name: 'home',
    component: HomePage,
  },
  {
    path: '/player/:animeId',
    name: 'player',
    component: PlayerPage,
  },
]

const router = createRouter({
  history: createWebHistory(),
  routes,
})

export default router
