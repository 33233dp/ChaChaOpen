# 🎌 My Anime Site

基于 FastAPI + Vue 3 的个人本地番剧管理系统。

## ⚙️ 核心配置 (必看)

本项目不提供自动刮削，需手动管理路径与封面。

请编辑 `backend/config/settings.json` 文件：

```json
{
  "video_paths": [
    "/media/chacha/GameDriver/MediaLib/Anime/"
  ],
  "exclude_keywords": ["@Recycle", "temp", ".DS_Store"]
}
```

> **注意**：程序会递归扫描这些路径。如果文件夹内存在视频文件，该文件夹名将作为番剧标题。若文件夹内还有子文件夹，则继续递归到子文件夹匹配。

### 2. 封面自动关联说明

将封面图片放入 `data/covers/` 目录下。

- **匹配规则**：`图片名 (无后缀)` === `视频所在的文件夹名`（忽略大小写和首尾空格）
- **示例**：
  - 文件夹路径：`../Animes/咒术回战/`
  - 封面文件：`data/covers/咒术回战.jpg`

### 3. 环境启动

```bash
# 安装后端依赖
cd backend
pip install -r requirements.txt

# 启动后端 (建议在 tmux 窗口运行)
uvicorn app.main:app --reload --host 0.0.0.0 --port 8000

# 安装前端依赖
cd frontend
npm install

# 启动前端
npm run dev
```

前端默认运行在 `http://localhost:5173`，会自动代理 `/api` 请求到后端 `http://localhost:8000`。

## 📂 工程文件夹组织结构

```text
player/
├── backend/                # FastAPI 后端
│   ├── app/
│   │   ├── api/            # 路由层
│   │   │   ├── anime.py    # 番剧列表、详情、扫描
│   │   │   ├── stream.py   # 视频流分发与 Range Header
│   │   │   ├── progress.py # 播放进度读写
│   │   │   └── config.py   # 用户配置接口
│   │   ├── core/
│   │   │   └── scanner.py  # 递归扫描逻辑（叶子文件夹匹配）
│   │   ├── database/
│   │   │   ├── db.py       # 数据库连接与初始化
│   │   │   └── models.py   # ORM 模型定义
│   │   └── main.py         # FastAPI 入口
│   ├── config/
│   │   └── settings.json   # 【用户修改】视频路径配置
│   └── requirements.txt
├── frontend/               # Vue 3 + Vite + Tailwind CSS
│   ├── src/
│   │   ├── components/
│   │   │   ├── AnimeCard.vue      # 悬浮玻璃封面卡片
│   │   │   ├── AnimeGrid.vue      # 封面墙网格
│   │   │   ├── DiffuseBackground.vue  # 弥散动态背景
│   │   │   └── VideoPlayer.vue    # 视频播放器
│   │   ├── pages/
│   │   │   ├── HomePage.vue       # 封面墙主页
│   │   │   └── PlayerPage.vue     # 播放页
│   │   ├── utils/
│   │   │   └── api.ts             # API 请求封装
│   │   └── router/
│   │       └── index.ts           # 路由配置
│   └── vite.config.ts
├── data/
│   ├── covers/             # 【手动投放区】存放封面图片
│   └── library.db          # SQLite 数据库（自动生成）
└── README.md
```

## 🛠️ 关键逻辑说明

### 叶子文件夹匹配策略

- 递归遍历用户自定义路径
- 如果一个文件夹内**直接包含视频文件**且**没有子文件夹**，则认为该文件夹是一个"番剧单元"
- 取该文件夹的 `basename` 作为番剧名称
- 示例：
  - `/Anime/进击的巨人/Season 1/01.mp4` → 匹配名为 `Season 1`
  - `/Anime/孤独摇滚/01.mp4` → 匹配名为 `孤独摇滚`

### 封面匹配算法

- 将文件夹名和 `data/covers/` 中的文件名均转为小写并去除首尾空格后进行匹配
- 如果没找到匹配，前端显示"缺失封面"占位图
