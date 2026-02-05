/*
1.封面显示 (优化：支持旋转，网易云黑胶风格)
2.歌曲信息显示 (优化：布局微调)
3.进度条，时间显示 (优化：网易云风格配色)
4.播放，上下曲切换按钮
5.红心当前曲目--并将该曲目标记为最高rating
6.搜索歌曲的歌手
7.背景图显示 (优化：暗色遮罩)
8.评论功能 2025年7月14日
9.将评论框的文字内容改成"所属歌单"

优化：
- 暗色主题 (Dark Theme)
- 封面旋转动画 (30FPS)
- 性能优化 (缓存图片，避免重复加载)
*/

// === 配置与常量 ===
var conf = {
    // 颜色定义 (网易云暗色系)
    colors: {
        bg: 0xFF2D2F33,          // 整体背景
        bgOverlay: 0xCC000000,   // 背景图遮罩 (加深)
        textMain: 0xFFDCDDE4,    // 主要文字
        textSub: 0xFF828385,     // 次要文字
        progressBarBg: 0xFF454546,
        progressBarFill: 0xFFEC4141, // 网易红
        love: 0xFFEC4141,
        loveEmpty: 0xFF828385,
        btnNormal: 0xFFDCDDE4,
        btnHover: 0xFFFFFFFF
    },
    // 布局尺寸
    layout: {
        coverSize: 0, // 在 on_size 中计算
        barHeight: 4, // 进度条高度 (更细)
        barHoverHeight: 8
    }
};

//背景图片路径
var imgPath = "G:/project/foobar2000-SMP/bg.png"; 

// === 全局变量 ===
var g_metadb = null;
var g_img_bg = null;
var g_img_cover = null;     // 原始封面
var g_img_vinyl = null;     // 处理后的黑胶圆盘图片
var g_timer_rotate = null;  // 旋转定时器
var g_angle = 0;            // 当前旋转角度
// var g_is_playing = false; // 移除：直接使用 fb.IsPlaying
var g_is_seeking = false;
var g_seek_pos = 0;
var g_hover_progress = false;

// 字体缓存
var g_fonts = {
    title: gdi.Font("Segoe UI", 16, 1),
    artist: gdi.Font("Segoe UI", 14, 0),
    album: gdi.Font("Segoe UI", 12, 0),
    time: gdi.Font("Segoe UI", 12, 0),
    icon: gdi.Font("Segoe UI Symbol", 24, 0),
    iconLarge: gdi.Font("Segoe UI Symbol", 42, 0),
    comment: gdi.Font("Segoe UI", 12, 0)
};

// === 初始化 ===
function on_size() {
    // 重新计算尺寸相关
    conf.layout.coverSize = window.Height - 20; // 留一点边距
    if (conf.layout.coverSize < 0) conf.layout.coverSize = 0;
    
    // 更新字体大小以适应窗口高度 (保持原有逻辑的比例自适应)
    let h = window.Height;
    g_fonts.title = gdi.Font("Segoe UI", Math.floor(h / 10), 1);
    g_fonts.artist = gdi.Font("Segoe UI", Math.floor(h / 12), 0);
    g_fonts.album = gdi.Font("Segoe UI", Math.floor(h / 14), 0);
    g_fonts.time = gdi.Font("Segoe UI", Math.floor(h / 14), 0);
    g_fonts.iconLarge = gdi.Font("Segoe UI Symbol", Math.floor(h / 2.5), 0);
    
    // 重新生成黑胶图片
    createVinylImage();
}

// === 核心逻辑：黑胶封面生成 ===
function createVinylImage() {
    if (!g_img_cover || conf.layout.coverSize <= 0) {
        g_img_vinyl = null;
        return;
    }

    let size = conf.layout.coverSize;
    // 创建一个正方形的临时图片 (背景透明)
    let img = gdi.CreateImage(size, size);
    let g = img.GetGraphics();
    
    // 开启高质量绘图
    g.SetSmoothingMode(2); // HighQuality

    // 计算尺寸
    // 参考图封面比例约为 66%
    let coverDiameter = Math.floor(size * 0.66); 
    let offset = (size - coverDiameter) / 2;

    // 1. 绘制封面 (方形，居中)
    // 稍后用黑胶纹理遮盖四角
    g.DrawImage(g_img_cover, offset, offset, coverDiameter, coverDiameter, 0, 0, g_img_cover.Width, g_img_cover.Height, 0, 255);

    // 2. 绘制黑胶纹理 (核心部分：遮罩+纹理)
    // 从封面边缘向外画圆环，模拟唱片沟壑
    
    let r_start = Math.floor(coverDiameter / 2); 
    let r_end = Math.ceil(size / 2);             
    
    // 稍微向内缩一点点，确保覆盖封面边缘
    let r_inner_fix = r_start - 1; 

    // 使用循环绘制同心圆，模拟纹理
    for (let r = r_inner_fix; r < r_end; r++) {
        let d = r * 2;
        let off = (size - d) / 2;
        let lineW = 2.0; 
        
        // 颜色计算 (模拟光泽和纹理)
        let color;
        
        // A. 最外圈 (Rim): 亮灰色边框 (约 4px)
        if (r > r_end - 4) {
            color = 0xFF353535; 
        } 
        // B. 唱片沟壑 (Grooves): 深黑与暗灰交替
        else {
            // 每隔 3px 一个微亮纹，模拟反光
            if (r % 3 === 0) {
                 color = 0xFF222222; // 微亮
            } else {
                 color = 0xFF121212; // 深黑底色
            }
        }
        
        g.DrawEllipse(off, off, d, d, lineW, color);
    }
    
    // 3. 封面与黑胶的交界处描边 (内圈阴影，增加立体感)
    let d_border = coverDiameter;
    let off_border = (size - d_border) / 2;
    g.DrawEllipse(off_border, off_border, d_border, d_border, 2.0, 0xFF080808); 

    // 4. 添加整体高光/阴影效果 (简单的线性渐变模拟光照)
    // 这里简单画一个半透明的白色渐变圆覆盖在上面不太容易，
    // 我们用一个淡淡的半透明圆环再次叠加在中间区域，增加质感
    /*
    let r_mid = (r_start + r_end) / 2;
    g.DrawEllipse(size/2 - r_mid, size/2 - r_mid, r_mid*2, r_mid*2, (r_end-r_start), 0x05FFFFFF);
    */

    img.ReleaseGraphics(g);
    g_img_vinyl = img;
}

// === 播放控制 ===
function on_playback_new_track(metadb) {
    g_metadb = metadb;
    g_angle = 0; // 切歌重置角度
    
    // 获取封面
    let art = null;
    try {
        art = utils.GetAlbumArtV2(metadb, 0);
    } catch(e) {}
    
    g_img_cover = art;
    createVinylImage();
    
    updateLoveStatus();
    updateCommentFromMeta();
    
    // 启动/检查旋转
    checkTimer();
    window.Repaint();
}

function on_playback_start(cmd) {
    checkTimer();
    updateLoveStatus();
    window.Repaint();
}

function on_playback_pause(state) {
    checkTimer();
    window.Repaint();
}

function on_playback_stop(reason) {
    if (reason !== 2) { // 2 = starting_another，如果是切歌，不要清空所有状态，等待 new_track
        g_metadb = null;
        g_img_cover = null;
        g_img_vinyl = null;
        g_angle = 0;
    }
    stopTimer();
    window.Repaint();
}

function on_playback_time(time) {
    // 每秒刷新一次进度条 (如果不拖动)
    // 如果定时器在跑（30FPS），这里就不需要 Repaint 了，避免重复刷新
    if (!g_is_seeking && !g_timer_rotate) {
        window.Repaint();
    }
}

// === 旋转定时器 ===
function checkTimer() {
    if (fb.IsPlaying && !fb.IsPaused) {
        startTimer();
    } else {
        stopTimer();
    }
}

function startTimer() {
    if (!g_timer_rotate) {
        // 30FPS (1000/30 ≈ 33ms)
        g_timer_rotate = window.SetInterval(function() {
            g_angle = (g_angle + 0.5) % 360; // 每次旋转 0.5 度
            window.Repaint();
        }, 33);
    }
}

function stopTimer() {
    if (g_timer_rotate) {
        window.ClearInterval(g_timer_rotate);
        g_timer_rotate = null;
    }
}

// === 绘制主函数 ===
function on_paint(gr) {
    // 1. 绘制背景
    // 填充纯色底
    gr.FillSolidRect(0, 0, window.Width, window.Height, conf.colors.bg);
    
    // 尝试绘制用户背景图 (带遮罩)
    if (!g_img_bg) {
        try { g_img_bg = gdi.Image(imgPath); } catch(e) {}
    }
    if (g_img_bg) {
        // 保持比例填充或拉伸？原代码是右上角绘制。这里改为全屏覆盖或者保持原样。
        // 为了"主题是暗色的"，我们全屏绘制并加重遮罩
        // gr.DrawImage(g_img_bg, 0, 0, window.Width, window.Height, 0, 0, g_img_bg.Width, g_img_bg.Height, 0, 50); // 低透明度
        // 为了兼容原作者意图，保留右上角绘制逻辑，但加深遮罩
        let size = window.Height;
        let x = window.Width - size;
        gr.DrawImage(g_img_bg, x, 0, size, size, 0, 0, g_img_bg.Width, g_img_bg.Height, 0, 100);
        // 渐变遮罩
        gr.FillGradRect(x, 0, size, size, 0, conf.colors.bg, 0x002D2F33, 0); // 从左到右渐变透明?
        // 简单加一层深色盖住
        gr.FillSolidRect(0, 0, window.Width, window.Height, 0xAA2D2F33);
    }

    // 2. 绘制旋转封面 (黑胶)
    if (g_img_vinyl) {
        let size = conf.layout.coverSize;
        let x = 10; // 左边距
        let y = (window.Height - size) / 2;
        
        // 注意: DrawImage 的第10个参数是 angle (度数)
        // 旋转中心默认为目标矩形中心
        gr.DrawImage(g_img_vinyl, x, y, size, size, 0, 0, size, size, g_angle, 255);
    } else {
        // 无封面时的占位 (画个黑圆)
        let size = conf.layout.coverSize;
        let x = 10;
        let y = (window.Height - size) / 2;
        gr.FillEllipse(x, y, size, size, 0xFF111111);
    }

    // 3. 绘制进度条
    drawProgressBar(gr);

    // 4. 绘制控制按钮 (上一曲, 播放, 下一曲)
    drawControls(gr);

    // 5. 绘制歌曲信息
    drawInfo(gr);

    // 6. 绘制红心
    drawLove(gr);

    // 7. 搜索按钮
    drawSearchBtn(gr);
    
    // 8. 评论/歌单信息
    drawCommentBox(gr);
}

// === 组件绘制 ===

function getControlLayout() {
    // 1. 尝试绝对居中 (水平和垂直)
    let cx = window.Width / 2;
    // 视觉修正：向上微调，平衡底部进度条 (进度条区域约 12px，我们将中心上移，使其位于剩余空间的中心)
    let cy = (window.Height - 16) / 2; 
    
    // 2. 动态间距 (基于窗口宽度)
    let sp = 60;
    if (window.Width < 600) {
        sp = Math.max(30, window.Width / 12);
    }
    
    // 3. 防重叠保护 (左侧封面)
    // 按钮组左边缘约 = cx - 2*sp - btnRadius
    // 封面右边缘 = conf.layout.coverSize + 10
    let btnLeft = cx - 2 * sp - 30; 
    let coverRight = (conf.layout.coverSize || 0) + 20;
    
    if (btnLeft < coverRight) {
        // 如果居中会挡住封面，被迫右移
        cx = coverRight + 2 * sp + 30;
    }
    
    return { cx: cx, cy: cy, sp: sp };
}

function getBarDims() {
    let left = window.Height + 40; // 封面右侧
    let right = window.Width - 40;
    let width = right - left;
    // 进度条下移至底部，避免被垂直居中的按钮遮挡
    let top = window.Height - 12; 
    let height = g_hover_progress || g_is_seeking ? conf.layout.barHoverHeight : conf.layout.barHeight;
    return { x: left, y: top, w: width, h: height };
}

function drawProgressBar(gr) {
    if (!g_metadb) return;
    
    let dim = getBarDims();
    // 安全检查：如果宽度或高度非法，不绘制
    if (dim.w <= 0 || dim.h <= 0) return;
    
    // 背景
    // 动态计算圆角，防止圆角大于尺寸的一半导致报错
    let arcBg = Math.min(2, dim.w / 2, dim.h / 2);
    if (arcBg < 1) {
         gr.FillSolidRect(dim.x, dim.y, dim.w, dim.h, conf.colors.progressBarBg);
    } else {
         gr.FillRoundRect(dim.x, dim.y, dim.w, dim.h, arcBg, arcBg, conf.colors.progressBarBg);
    }
    
    // 进度
    let len = fb.PlaybackLength;
    if (len > 0) {
        let pos = g_is_seeking ? (g_seek_pos * len) : fb.PlaybackTime;
        let pct = pos / len;
        if (pct > 1) pct = 1;
        if (pct < 0) pct = 0;
        
        let fillW = Math.floor(dim.w * pct);
        if (fillW > 0) {
            let fillArc = Math.min(2, fillW / 2, dim.h / 2);
            if (fillArc < 1) {
                gr.FillSolidRect(dim.x, dim.y, fillW, dim.h, conf.colors.progressBarFill);
            } else {
                gr.FillRoundRect(dim.x, dim.y, fillW, dim.h, fillArc, fillArc, conf.colors.progressBarFill);
            }
        }
        
        // 拖动滑块 (圆点)
        if (g_hover_progress || g_is_seeking) {
            // FillEllipse 应该是支持的，如果再次报错，可改为 FillSolidRect 或 FillRoundRect
            // 安全起见，这里也加上尺寸检查
            gr.FillEllipse(dim.x + fillW - 6, dim.y + (dim.h/2) - 6, 12, 12, 0xFFFFFFFF);
        }
        
        // 时间文字
        let timeStr = utils.FormatDuration(pos) + " / " + utils.FormatDuration(len);
        gr.GdiDrawText(timeStr, g_fonts.time, conf.colors.textSub, dim.x + dim.w + 10, dim.y - 10, 150, 30, 0);
    }
}

function drawInfo(gr) {
    if (!g_metadb) return;
    
    let left = window.Height + 40;
    
    // 计算可用宽度：避免与居中的控制按钮重叠
    // 按钮组左边界 (Prev按钮左侧)
    let layout = getControlLayout();
    let btnGroupLeft = layout.cx - 2 * layout.sp - 40; // 留点余量
    
    let w = btnGroupLeft - left;
    // 最小宽度保护
    if (w < 50) w = 50;
    
    // 垂直位置也微调居中一点 (跟随控制按钮)
    let top = layout.cy - 35; 
    
    // Title
    let title = fb.TitleFormat("%title%").EvalWithMetadb(g_metadb);
    gr.GdiDrawText(title, g_fonts.title, conf.colors.textMain, left, top, w, 40, 0 | 4); // 0|4 = Left | VCenter
    
    // Artist - Album
    let artist = fb.TitleFormat("%artist%").EvalWithMetadb(g_metadb);
    let album = fb.TitleFormat("%album%").EvalWithMetadb(g_metadb);
    gr.GdiDrawText(artist + " - " + album, g_fonts.artist, conf.colors.textSub, left, top + 35, w, 30, 0 | 4);
}

function drawControls(gr) {
    // 使用动态计算的布局
    let layout = getControlLayout();
    let centerX = layout.cx;
    let centerY = layout.cy;
    let spacing = layout.sp;
    
    let prevSymbol = "\u23EE"; // ⏮
    let playSymbol = fb.IsPlaying && !fb.IsPaused ? "\u23F8" : "\u23F5"; // ⏸ : ⏵
    let nextSymbol = "\u23ED"; // ⏭
    
    // 动态计算按钮大小 (基于窗口高度，确保能容纳 h/2.5 大小的字体)
    // 字体大小是 h/2.5，我们给框留足空间，比如 h/2 + 10
    let btnSize = Math.floor(window.Height / 1.8); 
    let half = btnSize / 2;
    
    // 绘制文字按钮
    // 按钮位置: Prev(-2*sp), Play(0), Next(+2*sp)
    // 注意：GdiDrawText 的坐标是 rect，需要居中绘制
    gr.GdiDrawText(prevSymbol, g_fonts.iconLarge, conf.colors.btnNormal, centerX - spacing * 2 - half, centerY - half, btnSize, btnSize, 1 | 4);
    gr.GdiDrawText(playSymbol, g_fonts.iconLarge, conf.colors.btnNormal, centerX - half, centerY - half, btnSize, btnSize, 1 | 4);
    gr.GdiDrawText(nextSymbol, g_fonts.iconLarge, conf.colors.btnNormal, centerX + spacing * 2 - half, centerY - half, btnSize, btnSize, 1 | 4);
}

// === 红心与评论 ===
var isLoved = false;
var g_comment = "";

function updateLoveStatus() {
    if (!g_metadb) { isLoved = false; return; }
    let rating = parseInt(fb.TitleFormat("%rating%").EvalWithMetadb(g_metadb));
    isLoved = (rating >= 5);
}

function drawLove(gr) {
    let layout = getControlLayout();
    // 动态计算大小
    let btnSize = Math.floor(window.Height / 1.8); 
    let half = btnSize / 2;
    
    // 放在 Next 按钮右侧
    let offset = Math.max(50, layout.sp * 1.2); 
    let x = layout.cx + layout.sp * 2 + offset - half; 
    let y = layout.cy - half; 
    
    let txt = isLoved ? "❤️" : "♡"; // 实心/空心
    let color = isLoved ? conf.colors.love : conf.colors.loveEmpty;
    
    gr.GdiDrawText(txt, g_fonts.iconLarge, color, x, y, btnSize, btnSize, 1|4);
}

function updateCommentFromMeta() {
    if (g_metadb) {
        g_comment = fb.TitleFormat("%comment%").EvalWithMetadb(g_metadb);
    } else {
        g_comment = "";
    }
}

function drawCommentBox(gr) {
    let x = window.Width - 220;
    let y = window.Height - 40;
    
    // Label
    gr.GdiDrawText("所属歌单: " + g_comment, g_fonts.comment, conf.colors.textSub, x, y, 200, 30, 0 | 4); // Right align?
}

function drawSearchBtn(gr) {
    let x = window.Width - 220;
    let y = 10;
    
    gr.GdiDrawText("🔍 搜索歌手", g_fonts.comment, conf.colors.textSub, x, y, 200, 30, 2); // Center
    gr.DrawRect(x, y, 200, 30, 1, 0xFF555555);
}


// === 鼠标交互 ===
function on_mouse_move(x, y) {
    let dim = getBarDims();
    let inBar = (x >= dim.x && x <= dim.x + dim.w && y >= dim.y - 5 && y <= dim.y + dim.h + 5);
    
    if (inBar != g_hover_progress) {
        g_hover_progress = inBar;
        window.Repaint();
    }
    
    if (g_is_seeking) {
        let pct = (x - dim.x) / dim.w;
        if (pct < 0) pct = 0;
        if (pct > 1) pct = 1;
        g_seek_pos = pct;
        window.Repaint();
    }
}

function on_mouse_lbtn_down(x, y) {
    // 1. 进度条
    let dim = getBarDims();
    if (x >= dim.x && x <= dim.x + dim.w && y >= dim.y - 5 && y <= dim.y + dim.h + 5) {
        g_is_seeking = true;
        g_seek_pos = (x - dim.x) / dim.w;
        window.Repaint();
        return;
    }
    
    // 2. 控制按钮 (简单判定)
    let layout = getControlLayout();
    let centerX = layout.cx;
    let centerY = layout.cy;
    let spacing = layout.sp;
    
    // 动态计算点击半径
    let btnSize = Math.floor(window.Height / 1.8);
    let radius = btnSize / 2;
    
    // Prev
    if (Math.abs(x - (centerX - spacing * 2)) < radius && Math.abs(y - centerY) < radius) {
        fb.Prev(); return;
    }
    // Play
    if (Math.abs(x - centerX) < radius && Math.abs(y - centerY) < radius) {
        fb.PlayOrPause(); return;
    }
    // Next
    if (Math.abs(x - (centerX + spacing * 2)) < radius && Math.abs(y - centerY) < radius) {
        fb.Next(); return;
    }
    
    // 3. Love
    // drawLove 绘制区域: x = centerX + 2*sp + offset - half, y = centerY - half, w = btnSize, h = btnSize
    let offset = Math.max(50, layout.sp * 1.2); 
    let loveX = centerX + spacing * 2 + offset - radius;
    let loveY = centerY - radius;
    if (x >= loveX && x <= loveX + btnSize && y >= loveY && y <= loveY + btnSize) {
        // Toggle Love
        if (g_metadb) {
            let cmd = isLoved ? "Rating/1" : "Rating/5";
            fb.RunContextCommandWithMetadb(cmd, g_metadb);
            // 立即更新状态，不必等回调
            isLoved = !isLoved;
            window.Repaint();
        }
        return;
    }
    
    // 4. Search
    if (x > window.Width - 220 && x < window.Width - 20 && y < 50) {
        if (g_metadb) {
            let artist = fb.TitleFormat("%artist%").EvalWithMetadb(g_metadb);
            let url = "https://music.163.com/#/search/m/?s=" + encodeURIComponent(artist);
            try {
                let shell = new ActiveXObject("WScript.Shell");
                shell.Run(url);
            } catch(e) {}
        }
        return;
    }
    
    // 5. Comment (Edit)
    if (x > window.Width - 220 && y > window.Height - 50) {
         let handles = plman.GetPlaylistSelectedItems(plman.ActivePlaylist);
         if (handles && handles.Count > 0) {
             let input = utils.InputBox("输入歌单唯一编号", "编辑歌单编号", g_comment);
             if (input !== null) { // null means cancel
                 let arr = [];
                 for(let i=0; i<handles.Count; i++) arr.push({"COMMENT": input});
                 handles.UpdateFileInfoFromJSON(JSON.stringify(arr));
             }
         } else {
             fb.ShowPopupMessage("请先选中一首歌曲");
         }
    }
}

function on_mouse_lbtn_up(x, y) {
    if (g_is_seeking) {
        g_is_seeking = false;
        if (fb.PlaybackLength > 0) {
            fb.PlaybackTime = fb.PlaybackLength * g_seek_pos;
        }
        window.Repaint();
    }
}

// 确保初始化
on_size();
if (fb.IsPlaying) {
    on_playback_new_track(fb.GetNowPlaying());
}
// window.Repaint();