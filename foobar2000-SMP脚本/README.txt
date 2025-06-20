//变量


//封面显示
function cover_print(gr){
    let metadb = fb.GetNowPlaying();
    if(!metadb) return;
    
    let cover = null;
    
    try {//获取封面
        cover = utils.GetAlbumArtV2(metadb,0);
        }
    catch(e){//如果有错误
        cover = null;
        }
    
    if(cover){//如果获得封面;
    // DrawImage 函数参数说明：
    // cover：图片对象
    // 10, 10：绘制起点坐标（左上角位置）
    // 100, 100：绘制宽度和高度
    // 0, 0, img.Width, img.Height：图片源图的起始坐标和尺寸，表示完整图片
    // 0：绘制时的额外标志，0 表示正常绘制
    gr.DrawImage(cover,0,0,window.Height,window.Height,0,0,cover.Width,cover.Height,0);
    }
}
function getPlaybackPercent()//获取播放进度百分比
{
    let position = fb.PlaybackTime;
    let PlayBack_length = fb.PlaybackLength;
    return position / PlayBack_length;    // 返回百分比
}

let isSeeking = false;     // 鼠标是否正在拖动进度条
let seekX = 0;             // 当前鼠标X坐标
//鼠标监听
function on_mouse_lbtn_down(x, y) {
    let barX = window.Height * 2;
    let barY = window.Height * (3 / 4) - 4;
    let barWidth = window.Width - 2 * barX;
    let barHeight = 8;

    // 如果点击在进度条区域内
    if (x >= barX && x <= barX + barWidth && y >= barY && y <= barY + barHeight) {
        isSeeking = true;
        seekX = x;
        window.Repaint();
    }
}

function on_mouse_move(x, y) {
    if (isSeeking) {
        seekX = x;
        window.Repaint();
    }
}

function on_mouse_lbtn_up(x, y) {
    if (isSeeking) {
        let barX = window.Height * 2;
        let barWidth = window.Width - 2 * barX;
        let percent = (x - barX) / barWidth;
        percent = Math.max(0, Math.min(1, percent)); // 限制0-1

        // 设置播放位置
        fb.PlaybackTime = fb.PlaybackLength * percent;

        isSeeking = false;
        window.Repaint();
    }
}
//进度条绘制
function Progress_Bar(gr){
    let barX = window.Height * 2;
    let barY = window.Height * (3 / 4) - 4;
    let barWidth = window.Width - 2 * barX;
    let barHeight = 8;
    
    let percent = isSeeking ? (seekX - barX) / barWidth : getPlaybackPercent();
    percent = Math.max(0, Math.min(1, percent)); // 限制范围0-1
    
    gr.FillSolidRect(barX,barY,barWidth, 8, 0xFFCCCCCC);
    gr.FillSolidRect(barX,barY,barWidth * percent, barHeight, 0xffff0000);
}
//绘制歌曲信息
function playBack_Info(gr){
    let metadb = fb.GetNowPlaying();
    if(metadb){
        let title = fb.TitleFormat("%title%").EvalWithMetadb(metadb);
        let artist = fb.TitleFormat("%artist%").EvalWithMetadb(metadb);
        let album = fb.TitleFormat("%album%").EvalWithMetadb(metadb);
        let genre = fb.TitleFormat("%genre%").EvalWithMetadb(metadb);
        let year = fb.TitleFormat("%date%").EvalWithMetadb(metadb);
        let duration = fb.TitleFormat("%length%").EvalWithMetadb(metadb); // 例如 "03:42"
        
        let font = gdi.Font("Segoe UI", window.Height / 10, 0);
        let color = 0xff000000;
        gr.GdiDrawText("标题: " + title, font, color, window.Height*1.1,  window.Height / 12, window.Width, window.Height / 2);
        gr.GdiDrawText("歌手: " + artist, font, color, window.Height*1.1,  window.Height / 4, window.Width, window.Height / 2);
    }
}


//事件监听
function on_playback_new_track(metadb){//监听到新曲目
    window.Repaint();//刷新面板    
}

function on_playback_time(position){
    window.Repaint();
}

//绘制图像
function on_paint(gr) {//gr = graphics
    gr.FillSolidRect(0, 0, window.Height, window.Height, 0xffffffff); //绘制区域
    cover_print(gr); // 调用封面绘制函数
    Progress_Bar(gr);
    playBack_Info(gr);
}


