# 矢量P_{a}绕Z_{a}旋转theta然后再绕X_{a}旋转phi,求旋转矩阵

import numpy as np
import math as m

# m.pi就是常量pi
theta = m.pi / 6
phi = m.pi / 45

st = m.sin(theta)    # sin函数只能传入弧度，否则计算错误
ct = m.cos(theta)
sp = m.sin(phi)
cp = m.cos(phi)

R1 = np.array([[ct,-st,0],
               [st,ct,0],
               [0, 0, 1]])

R2 = np.array([
    [1,0,0],
    [0,cp,-sp],
    [0,sp,cp]
])

result = R2 @ R1
print(result)


