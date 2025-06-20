/*
1.封面显示
2.歌曲信息显示
3.进度条，时间显示
4.播放，上下曲切换按钮
5.红心当前曲目--并将该曲目标记为最高rating
新增：
6.搜索歌曲的歌手
7.背景图显示
*/

//背景图片路径
var imgPath = "G:/7.project/foobar2000-SMP/bg.png"; // 绝对路径，注意格式

// === 封面绘制函数 ===
function cover_print(gr) {
    let metadb = fb.GetNowPlaying(); // 获取当前播放曲目的元数据（metadb）
    if (!metadb) return; // 如果没有播放内容，直接返回

    let cover = null; // 初始化封面变量

    try {
        cover = utils.GetAlbumArtV2(metadb, 0); // 获取封面（0 表示 front cover）
    } catch (e) {
        cover = null; // 如果获取失败，设为 null
    }

    if (cover) {
        // 将封面图片绘制在左上角，尺寸为 window.Height * window.Height（正方形）
        gr.DrawImage(cover, 0, 0, window.Height, window.Height, 0, 0, cover.Width, cover.Height, 0);
    }
}

// === 计算当前播放百分比 ===
function getPlaybackPercent() {
    let pos = fb.PlaybackTime;       // 当前播放时间（单位：秒）
    let len = fb.PlaybackLength;     // 曲目总时长（单位：秒）

    // 如果播放时长非法，则返回 0，避免计算错误
    if (!len || isNaN(pos) || pos < 0 || len <= 0) return 0;

    return pos / len; // 返回百分比（范围 0~1）
}

// === 播放条控制状态变量 ===
let isSeeking = false; // 表示是否正在拖动进度条
let seekX = 0;          // 拖动时鼠标的 x 坐标
let hoverX = 0;         // 鼠标悬浮时的 x 坐标
let isHovering = false; // 鼠标是否悬停在进度条上

// === 鼠标按下时的回调 ===
// 不要定义 isPlaying，全用 fb.IsPlaying 判断状态

function on_mouse_lbtn_down(x, y) {
    let centerY = window.Height / 3;
    let centerX = window.Width / 2;
    let spacing = 60;
    let radius = 24;

    function isInside(cx, cy) {
        let dx = x - cx;
        let dy = y - cy;
        return dx * dx + dy * dy <= radius * radius;
    }

    if (isInside(centerX - spacing * 2 + 24, centerY)) {
        fb.Prev();
        window.Repaint();
        updateLoveStatus(); // 更新红心状态
        return;
    } else if (isInside(centerX, centerY)) {
        fb.PlayOrPause();
        window.Repaint();
        setTimeout(() => window.Repaint(), 150);
        updateLoveStatus();
        return;
    } else if (isInside(centerX + spacing + 24, centerY)) {
        fb.Next();
        window.Repaint();
        updateLoveStatus();
        return;
    }

    if (isInLoveButton(x, y)) {
        toggleLove(); // 点击红心打分
        return;
    }

    if (isInProgressBar(x, y)) {
        isSeeking = true;
        seekX = x;
        window.Repaint();
    }
}

// === 鼠标移动时的回调 ===
function on_mouse_move(x, y) {
    if (isSeeking) {
        seekX = x; // 拖动中，实时记录位置
        window.Repaint();
    } else {
        // 非拖动状态，只处理悬浮提示
        isHovering = isInProgressBar(x, y);
        hoverX = x;
        window.Repaint();
    }
}

// === 鼠标抬起时的回调 ===
function on_mouse_lbtn_up(x, y) {
    if (isSeeking) {
        // 计算拖动后的百分比位置
        let percent = (seekX - getBarX()) / getBarWidth();
        percent = Math.max(0, Math.min(1, percent)); // 限制 0~1 范围

        // 设置新的播放时间
        fb.PlaybackTime = fb.PlaybackLength * percent;

        isSeeking = false;
        window.Repaint();
    }
}

// === 判断是否在进度条区域内 ===
function isInProgressBar(x, y) {
    return x >= getBarX() && x <= getBarX() + getBarWidth() &&
           y >= getBarY() && y <= getBarY() + getBarHeight();
}

// === 获取进度条位置和尺寸 ===
function getBarX() { return window.Height * 2; }               // 左边距
function getBarY() { return window.Height * 0.75 - 4; }        // 上边距
function getBarWidth() { return window.Width - 2 * getBarX(); }// 宽度
function getBarHeight() { return 8; }                          // 高度

// === 绘制进度条背景 ===
function ProgressBackGround_Bar(gr) {
    gr.FillRoundRect(getBarX(), getBarY(), getBarWidth(), getBarHeight(), 2, 2, 0xFFE0E0E0); // 灰色圆角矩形
}

// === 绘制已播放进度条 ===
function Progress_Bar(gr) {
    if (fb.PlaybackLength <= 0) return; // 仅判断时长合法性即可

    let percent = isSeeking ? (seekX - getBarX()) / getBarWidth() : getPlaybackPercent();
    percent = Math.max(0, Math.min(1, percent)); // 限制 0~1 范围

    let w = Math.floor(getBarWidth() * percent);
    let h = getBarHeight();

    // 只有当宽高都大于 0 时才绘制
    if (!isNaN(w) && w > 0 && h > 0) {
        // 圆角不能超过宽或高的一半
        let arc = Math.min(2, w / 2, h / 2);
        gr.FillRoundRect(getBarX(), getBarY(), w, h, arc, arc, 0xFF1E90FF);
    }
}

// === 绘制时间文本（当前 / 总时长） ===
function drawTimeText(gr) {
    if (!fb.IsPlaying || fb.PlaybackLength <= 0) return;

    let font = gdi.Font("Segoe UI", Math.floor(window.Height / 14), 0);
    let color = 0xff000000; // 黑色

    let pos = isSeeking ? (seekX - getBarX()) / getBarWidth() : getPlaybackPercent();
    pos = Math.max(0, Math.min(1, pos));

    let sec = Math.floor(fb.PlaybackLength * pos);
    let curTime = formatTime(sec);
    let totalTime = formatTime(Math.floor(fb.PlaybackLength));

    let text = `${curTime} / ${totalTime}`;

    gr.GdiDrawText(text, font, color, getBarX()+getBarWidth(), getBarY() - 12, 140, window.Height / 2, 0);
}

// === 秒转为 mm:ss 字符串 ===
function formatTime(sec) {
    let m = Math.floor(sec / 60);
    let s = sec % 60;
    return `${m}:${s < 10 ? '0' + s : s}`;
}

// === 绘制播放信息 ===
function playBack_Info(gr){
    let metadb = fb.GetNowPlaying();
    if (!metadb) return;

    // 读取标签字段
    let title = fb.TitleFormat("%title%").EvalWithMetadb(metadb);
    let artist = fb.TitleFormat("%artist%").EvalWithMetadb(metadb);
    let album = fb.TitleFormat("%album%").EvalWithMetadb(metadb);

    let font = gdi.Font("Segoe UI", window.Height / 10, 0);
    let color = 0xff000000;
    gr.GdiDrawText("标题: " + title, font, color, window.Height*1.1,  window.Height / 12, window.Width, window.Height / 2);
    gr.GdiDrawText("歌手: " + artist, font, color, window.Height*1.1, (window.Height / 12)+(window.Height / 5), window.Width, window.Height / 2);
    gr.GdiDrawText("专辑: " + album, font, color, window.Height*1.1, (window.Height / 12) + 2*(window.Height / 5), window.Width, window.Height / 2);   
}

// === 播放器事件监听 ===
function on_playback_time(pos) { window.Repaint(); }           // 播放时间变化时刷新
function on_playback_new_track(metadb) {
    updateLoveStatus(); // 每次切歌时更新红心状态
    window.Repaint();
}
function on_playback_start() {
    updateLoveStatus(); // 播放时也更新红心状态
    window.Repaint();
}

// === 红心按钮逻辑 ===
let isLoved = false;

// 计算爱心按钮位置和大小
function getLoveButtonX() {
    return getBarX() + getBarWidth() + 20;
}
function getLoveButtonY() {
    return window.Height / 3 - 14;
}
const loveButtonSize = 40; // 按钮大小（宽高）

// 判断坐标是否在爱心按钮范围内
function isInLoveButton(x, y) {
    let bx = getLoveButtonX();
    let by = getLoveButtonY();
    return x >= bx && x <= bx + loveButtonSize &&
           y >= by && y <= by + loveButtonSize;
}

// 绘制爱心按钮（字符）
function drawLoveButton(gr) {
    let font = gdi.Font("Segoe UI Symbol", loveButtonSize, 1);
    // 红色或者灰色
    let color = isLoved ? 0xFFFF0000 : 0xFF888888;
    let x = getLoveButtonX();
    let y = getLoveButtonY();

    let heart = "❤️";  // Unicode 红心符号
    gr.GdiDrawText(heart, font, color, x, y, loveButtonSize, loveButtonSize +20, 0x00000001 | 0x00000004);
}

// === 节流更新红心状态 ===
let lastUpdateLoveTime = 0;
function updateLoveStatus() {
    let now = Date.now();
    if (now - lastUpdateLoveTime < 1000) return; // 1秒内只更新一次，节流保护
    lastUpdateLoveTime = now;

    let metadb = fb.GetNowPlaying();
    if (!metadb) {
        isLoved = false;
        return;
    }
    let rating = parseInt(fb.TitleFormat("%rating%").EvalWithMetadb(metadb));
    isLoved = rating >= 5;
}

// 切换喜欢状态，点击爱心即可切换打分/取消评分
function toggleLove() {
    let metadb = fb.GetNowPlaying();
    if (!metadb) return;

    try {
        if (isLoved) {
            fb.RunContextCommandWithMetadb("Rating/1", metadb);
            isLoved = false;
        } else {
            fb.RunContextCommandWithMetadb("Rating/5", metadb);
            isLoved = true;
        }
        window.Repaint();
    } catch (e) {
        fb.ShowPopupMessage("无法修改评分，请确认插件和写标签设置正常。\n错误：" + e);
    }
}


// === 播放器事件监听 ===
function on_playback_time(pos) {
    updateLoveStatus();
    window.Repaint();
}
function on_playback_new_track(metadb) {
    updateLoveStatus();
    window.Repaint();
}
function on_playback_start() {
    updateLoveStatus();
    window.Repaint();
}

// === 初始化时读取当前曲目红心状态 ===
updateLoveStatus();

//百度当前歌曲的歌手
// 与绘图一致的按钮坐标
var btn_x = window.Width - window.Width / 10;
var btn_y = window.Height / 12;
var btn_w = 200;
var btn_h = 30;
function on_mouse_lbtn_up(x, y) {
    if (x >= btn_x && x <= btn_x + btn_w && y >= btn_y && y <= btn_y + btn_h) {
        var metadb = fb.GetFocusItem();
        if (metadb) {
            var title = metadb.Title || "";
            var artist = "";

            var info = metadb.GetFileInfo();
            if (info) {
                var index = info.MetaFind("artist");
                if (index >= 0) {
                    artist = info.MetaValue(index, 0);
                }
            }

            var query = encodeURIComponent(title + " " + artist);
            var url = "https://search.bilibili.com/all?keyword=" + query;

            // 打开浏览器
            var shell = new ActiveXObject("WScript.Shell");
            shell.Run(url);
        } else {
            fb.ShowPopupMessage("请先选中一首歌曲");
        }
    }
}

var bg_img = null;
function PathJoin() {
    let parts = Array.from(arguments);
    return parts.map((p, i) => {
        if (i === 0) return p.replace(/[\/\\]+$/, '');
        else return p.replace(/^[\/\\]+|[\/\\]+$/g, '');
    }).join('\\');
}
// 加载背景图片，路径是 SMP 默认文件夹下的 bg.png
var bg_img = null;
var bg_img_load_failed = false;


function loadBackgroundImage() {
    if (bg_img || bg_img_load_failed) return; // 已加载或失败过，不再重复尝试

    try {
        bg_img = gdi.Image(imgPath);
    } catch (e) {
        bg_img_load_failed = true;
        fb.ShowPopupMessage("加载背景图片失败，请确认文件路径和格式正确。\n错误：" + e);
    }
}


// 绘制背景图片，绘制在左上角，尺寸为 window.Height * window.Height
// 绘制背景图片，绘制在右上角，尺寸为 window.Height * window.Height
function drawBackgroundImage(gr) {
    if (!bg_img) return;

    let size = window.Height;
    let x = window.Width - size; // 右上角
    let y = 0;

    // 绘制背景图
    gr.DrawImage(bg_img, x, y, size, size, 0, 0, bg_img.Width, bg_img.Height, 0);

    // 叠加渐变遮罩（从左侧全白不透明 → 右侧透明）
    let gradientWidth = Math.floor(size * 2.5); // 渐变宽度为背景图宽度的60%
    for (let i = 0; i < gradientWidth; i++) {
        let alpha = 255 - Math.floor((i / gradientWidth) * 255);
        let color = (alpha << 24) | 0xFFFFFF;
        gr.FillSolidRect(x + i, y, 1, size, color);
    }
}



// === 主绘制函数 ===
function on_paint(gr) {
    gr.FillSolidRect(0, 0, window.Width, window.Height, 0xffffffff); // 白底背景

    loadBackgroundImage();
    drawBackgroundImage(gr);

    cover_print(gr);               // 封面
    ProgressBackGround_Bar(gr);   // 进度条背景
    Progress_Bar(gr);             // 播放进度
    drawTimeText(gr);             // 时间显示
    playBack_Info(gr);            // 曲目信息
    drawLoveButton(gr);           // 爱心按钮

    // 使用内置符号绘制上一曲、播放/暂停、下一曲按钮
    let symbolFont = gdi.Font("Segoe UI Symbol", 42, 0);
    let color = 0xFF000000;
    let centerY = window.Height / 3;
    let spacing = 60;
    let centerX = window.Width / 2;

    let prevSymbol = "⏮";
    let playSymbol = fb.IsPlaying ? "⏸" : "⏵";
    let nextSymbol = "⏭";

    gr.GdiDrawText(prevSymbol, symbolFont, color,
        centerX - spacing * 2, centerY - 24, 48, 48,
        0x00000001 | 0x00000004);

    gr.GdiDrawText(playSymbol, symbolFont, color,
        centerX - 24, centerY - 24, 48, 48,
        0x00000001 | 0x00000004);

    gr.GdiDrawText(nextSymbol, symbolFont, color,
        centerX + spacing, centerY - 24, 48, 48,
        0x00000001 | 0x00000004);

    //百度搜索当前歌曲      
    var bg_color = 0xFF1E90FF; // 颜色和字体定义
    var text_color = 0xFF1E90F0;
    var font = gdi.Font("Segoe UI", window.Height / 10, 1);
   gr.GdiDrawText("搜索该歌手", font, text_color, btn_x, btn_y, 200, 30);// 绘制按钮文字
}

// === 初始化时读取当前曲目红心状态 ===
updateLoveStatus();
