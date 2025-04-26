from flask import Flask, render_template, send_file, request, Response
from flask_cors import CORS
import os
import re
import logging
from natsort import natsorted

# 视频文件存放路径
VIDEO_DIR = '/media/cha_cha/MediaDisk1/2.番剧/1.进击的巨人/进击的巨人-第一季'
VIDEO_DIR2 = '/media/cha_cha/MediaDisk1/2.番剧/7.《死神 第一季》'
VIDEO_DIR3 = '/media/cha_cha/MediaDisk1/2.番剧/4.斩！赤红之瞳/[Lilith-Raws] Akame ga Kill!'
VIDEO_DIR4 = '/media/cha_cha/MediaDisk1/2.番剧/6.钢之炼金术师/【高清剧集网发布 www.PTHDTV.com】钢之炼金术师[全51集][中文字幕].Hagane.no.renkinjutsushi.2003.S01E01.1080p.HAMI.WEB-DL.H264.AAC-ZerTV'
VIDEO_DIR5 = '/media/cha_cha/MediaDisk1/2.番剧/5.寄生兽/寄生兽'
VIDEO_DIR6 = '/media/cha_cha/MediaDisk1/2.番剧/15.bloodC'
VIDEO_DIR7 = '/media/cha_cha/MediaDisk1/2.番剧/14.无职转生'

app = Flask(__name__)
CORS(app)

# 配置日志
logging.basicConfig(level=logging.DEBUG)

def get_cpu_temperature():
    # 读取文件获取温度
    with open("/sys/class/thermal/thermal_zone0/temp", "r") as f:
        temp = f.read()
    return float(temp) / 1000  # 转换为摄氏度

# 自定义排序函数，处理多种文件名格式
def custom_sort_key(filename):
    # 尝试匹配 [xxx]name xx_x264.mp4 格式
    match = re.search(r'\[\w+\]\w+\s+(\d+) _x264\.mp4', filename)
    if match:
        return int(match.group(1))
    # 尝试匹配 SxxExx 格式
    match = re.search(r'S\d+E(\d+)', filename)
    if match:
        return int(match.group(1))
    # 尝试匹配纯数字编号
    match = re.search(r'(\d+)\.mp4', filename)
    if match:
        return int(match.group(1))
    # 尝试匹配 Episode_xx 格式
    match = re.search(r'Episode_(\d+)', filename)
    if match:
        return int(match.group(1))
    # 尝试匹配可能的其他集数编号格式，如 第x集
    match = re.search(r'第(\d+)集', filename)
    if match:
        return int(match.group(1))
    return filename

@app.route('/')
def index():
    # 获取 CPU 温度
    temperature = get_cpu_temperature()
    # 将温度传递到前端模板
    return render_template('index.html', temperature=temperature)

@app.route('/image')
def get_image():
    image_path = '/home/cha_cha/Pictures/image.png'
    return send_file(image_path, mimetype='image/png')

# 视频页面
@app.route('/video_1')
def video_1():
    video_type = request.args.get('video_type', '1')
    if video_type == '1':
        video_dir = VIDEO_DIR
        title = '进击的巨人'
        background_image = '/static/进击的巨人.png'
    elif video_type == '2':
        video_dir = VIDEO_DIR2
        title = '死神 第一季'
        background_image = '/static/死神第一季壁纸.jpg'
    elif video_type == '3':
        video_dir = VIDEO_DIR3
        title = '斩！赤红之瞳'
        background_image = '/static/斩.jpg'
    elif video_type == '4':
        video_dir = VIDEO_DIR4
        title = '钢之炼金术师'
        background_image = '/static/钢之炼金术师.png'
    elif video_type == '5':
        video_dir = VIDEO_DIR5
        title = '寄生兽'
        background_image = '/static/寄生兽.jpg'
    elif video_type == '6':
        video_dir = VIDEO_DIR6
        title = 'bloodC'
        background_image = '/static/bloodc.jpg'
    elif video_type == '7':
        video_dir = VIDEO_DIR7
        title = '无职转生'
        background_image = '/static/无职转生.jpg'
    else:
        video_dir = VIDEO_DIR
        title = '进击的巨人'
        background_image = '/static/进击的巨人.png'

    logging.debug(f"当前视频类型: {video_type}，视频目录: {video_dir}")
    try:
        videos = [f for f in os.listdir(video_dir) if f.endswith('.mp4')]
        if video_type in ['1', '2', '3', '4', '5', '6', '7']:
            # 使用 natsorted 结合自定义排序函数
            videos = natsorted(videos, key=custom_sort_key)
        logging.debug(f"找到的视频文件: {videos}")
        return render_template('video_1.html', videos=videos, title=title, background_image=background_image, video_type=video_type)
    except FileNotFoundError:
        logging.error(f"视频目录 {video_dir} 未找到")
        return Response("视频目录未找到", status=404)

# 播放视频
@app.route('/play_video')
def play_video():
    video_type = request.args.get('video_type', '1')
    filename = request.args.get('filename')
    if video_type == '1':
        video_dir = VIDEO_DIR
    elif video_type == '2':
        video_dir = VIDEO_DIR2
    elif video_type == '3':
        video_dir = VIDEO_DIR3
    elif video_type == '4':
        video_dir = VIDEO_DIR4
    elif video_type == '5':
        video_dir = VIDEO_DIR5
    elif video_type == '6':
        video_dir = VIDEO_DIR6
    elif video_type == '7':
        video_dir = VIDEO_DIR7
    else:
        video_dir = VIDEO_DIR

    logging.debug(f"请求播放的视频类型: {video_type}，文件名: {filename}，视频目录: {video_dir}")
    file_path = os.path.join(video_dir, filename)
    if os.path.exists(file_path):
        return send_file(file_path, mimetype='video/mp4')
    else:
        logging.error(f"视频文件 {file_path} 未找到")
        return Response("视频文件未找到", status=404)

# 播放字幕
@app.route('/play_subtitle')
def play_subtitle():
    video_type = request.args.get('video_type', '1')
    filename = request.args.get('filename')

    # 确保字幕文件扩展名是 .srt
    if not filename.endswith('.srt'):
        filename = filename.rsplit('.', 1)[0] + '.srt'

    if video_type == '1':
        video_dir = VIDEO_DIR
    elif video_type == '2':
        video_dir = VIDEO_DIR2
    elif video_type == '3':
        video_dir = VIDEO_DIR3
    elif video_type == '4':
        video_dir = VIDEO_DIR4
    elif video_type == '5':
        video_dir = VIDEO_DIR5
    elif video_type == '6':
        video_dir = VIDEO_DIR6
    elif video_type == '7':
        video_dir = VIDEO_DIR7
    else:
        video_dir = VIDEO_DIR

    subtitle_path = os.path.join(video_dir, filename)

    if os.path.exists(subtitle_path):
        logging.debug(f"找到字幕文件: {subtitle_path}")

        # 读取 .srt 文件并转换为 .vtt 格式
        with open(subtitle_path, 'r', encoding='utf-8') as srt_file:
            srt_content = srt_file.read()

        # 转换 .srt 到 .vtt 格式
        vtt_content = "WEBVTT\n\n"  # WebVTT 的头部

        # 替换 .srt 中的时间
        lines = srt_content.splitlines()
        for line in lines:
            if '-->' in line:
                line = line.replace(',', '.')
            vtt_content += line + '\n'

        return Response(vtt_content, mimetype='text/vtt')
    else:
        logging.debug(f"未找到字幕文件: {subtitle_path}")
        return Response("未找到字幕文件", status=404)


if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port=5004)
    