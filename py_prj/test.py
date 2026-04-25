import numpy as np
import math as m

uf = np.array([
    [3],
    [2],
    [2],
    [1]
])

F = np.array([
    [0,-1,0,10],
    [1,0,0,20],
    [0,0,1,1],
    [0,0,0,1]
])

# (1)$\boldsymbol{u}$ 为由 $\boldsymbol{F}$ 所描述的一点。 确定表示同一点但由基坐标系描述的矢量 $\boldsymbol{u}$。
u = F @ uf
print(u)

# (2) 首先让 $\boldsymbol{F}$ 绕基坐标系的 $y$ 轴旋转 $90^\circ$，然后沿基系 $x$ 轴方向平移 20 个单位。求变换所得新坐标系 $\boldsymbol{F}'$。

T = np.array([
    [0,0,1,20],
    [0,1,0,0],
    [-1,0,0,0],
    [0,0,0,1]
])

F1 = T @ F
print(F1)

# (3) 确定表示同一点但由坐标系 $\boldsymbol{F}'$ 所描述的矢量 $\boldsymbol{v}'$。
v = np.linalg.inv(F1) @ u 
print(v)
# (4) 让 $\boldsymbol{F}$ 绕自己的 $y$ 轴旋转 $90^\circ$，求变换所得新坐标系 $\boldsymbol{F}''$
T1 = np.array([
    [0,0,1,0],
    [0,1,0,0],
    [-1,0,0,0],
    [0,0,0,1]
])
F11 = F @ T1
print(F11)