%《机器人学 第四版 清华大学出版社》p93，4.1.1 刚体的动能与位能
% 题配图在当前目录的 [图4.2.png]。

syms g;
syms t;
% 对m1有
syms m1 theta1(t) d1;
dtheta1 = diff(theta1, t);
K1 = 1/2 * m1 * (d1 * dtheta1) ^ 2;
P1 = -m1 * g * d1 * cos(theta1);
% 对m2有：
syms d2 m2 theta2(t);
dtheta2 = diff(theta2, t);
x2 = d1*sin(theta1) + d2*sin(theta1+theta2);
y2 = -d1*cos(theta1) - d2 * cos(theta1+theta2);
dx2 = diff(x2, t);
dy2 = diff(y2, t);

K2 = 1/2 * m2 * (dx2 ^ 2 + dy2 ^ 2);
P2 = m2 * g * y2;

% 总能量
K = K1 + K2;
P = P1 + P2;

% 拉格朗日功能平衡法

%% 拉格朗日函数
L = K - P;

%% 求拉格朗日方程
%%% 微分
dL_theta1 = diff(L, theta1);
dL_theta2 = diff(L, theta2);
dL_dtheta1 = diff(L, dtheta1);
dL_dtheta2 = diff(L, dtheta2);
ddL_dtheta1 = diff(dL_dtheta1, t);
ddL_dtheta2 = diff(dL_dtheta2, t);
%%% 得到拉格朗日方程
F1_lagrange = ddL_dtheta1 - dL_theta1;
F2_lagrange = ddL_dtheta2 - dL_theta2;
disp('F1_lagrange = ');
pretty(simplify(F1_lagrange));
disp('F2_lagrange = ');
pretty(simplify(F2_lagrange));
