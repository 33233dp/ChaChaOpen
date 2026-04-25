import numpy as np
import math as m

# f系中的坐标
# uf_T = np.array([3,2,2]) 这是行向量
# uf_T_ext = np.append(uf_T, 1)

# 列向量
uf = np.array([
    [3],
    [2],
    [2],
    [1],
])

F = np.array([
    [0, -1, 0, 10],
    [1, 0, 0, 20],
    [0, 0, 1, 1],
    [0, 0, 0, 1]
])
# 错误做法-----
# uf_T_ext = uf_T_ext.reshape(4,1)
# F_inv = np.linalg.inv(F)
# 基坐标系的坐标
# ub = F_inv @ uf_T_ext

# 正确做法-----
ub = F @ uf

# （1）
print(ub[:3])

# #【注】F即代表坐标系也代表由F坐标系相对基坐标系的选装矩阵。F中左上角的3*3矩阵是旋转矩阵，
# F右上角的3*1向量是F系坐标原点在基坐标系中的坐标。

# （2）首先让 $\boldsymbol{F}$ 绕基坐标系的 $y$ 轴旋转 $90^\circ$，然后沿基系 $x$ 轴方向平移 20 个单位。求变换所得新坐标系 $\boldsymbol{F}'$。
T = np.array([
    [0,0,1,20],
    [0,1,0,0],
    [-1,0,0,0],
    [0,0,0,1]
])

F1 = T @ F
print(F1)

# (3) 确定表示同一点但由坐标系 $\boldsymbol{F}'$ 所描述的矢量 $\boldsymbol{v}'$。
# 设”同一点“为 ub

v1 = np.linalg.inv(F1) @ ub
print(v1)

# 绕y轴旋转的旋转矩阵函数
def rot_y(theta):
    c = np.cos(theta)
    s = np.sin(theta)
    return np.array([
        [c,  0, s, 0],
        [0,  1, 0, 0],
        [-s, 0, c, 0],
        [0,  0, 0, 1]
    ])
T = rot_y(m.pi / 2)
T[0 , 3] = 20 #平移：x轴方向平移 [0,3]即第一行第四列元素
F1 = T @ F
print(F1)

# (4) 让 $\boldsymbol{F}$ 绕自己的 $y$ 轴旋转 $90^\circ$，求变换所得新坐标系 $\boldsymbol{F}''$
F11 = F @ rot_y(m.pi / 2)
print(F11)

# **“左乘固定轴，右乘运动轴”**


