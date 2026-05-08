% 《机器人学 第四版 清华大学出版社》p93
% 题配图在当前目录的 [图4.2.png]。
%
% 本脚本推导平面二连杆机械臂的动力学方程。
% 建模思路：
%   1. 选取 theta1(t)、theta2(t) 作为两个广义坐标；
%   2. 分别写出连杆 1、连杆 2 的动能和势能；
%   3. 得到系统总动能 K 和总势能 P；
%   4. 构造拉格朗日函数 L = K - P；
%   5. 对 theta1、theta2 分别计算拉格朗日方程。

%% 定义重力、时间和连杆 1 参数

syms g;
syms t;

% m1 表示连杆 1 的等效质量；
% theta1(t) 表示连杆 1 相对惯性坐标系的转角；
% d1 表示关节 1 到连杆 1 质心的距离，或教材图中对应的等效长度。
syms m1 theta1(t) d1;

% dtheta1 是 theta1 对时间的一阶导数，也就是连杆 1 的角速度。
dtheta1 = diff(theta1, t);

% 连杆 1 的动能。
% 若质心到转轴距离为 d1，则质心线速度大小为 d1*dtheta1，
% 因此平动动能写成 1/2*m1*(d1*dtheta1)^2。
K1 = 1/2 * m1 * (d1 * dtheta1) ^ 2;

% 连杆 1 的势能。
% 这里使用 y = -d1*cos(theta1) 作为质心高度坐标，
% 因此 P1 = m1*g*y = -m1*g*d1*cos(theta1)。
P1 = -m1 * g * d1 * cos(theta1);

%% 定义连杆 2 参数，并计算质心位置

% d2 表示关节 2 到连杆 2 质心的距离；
% m2 表示连杆 2 的等效质量；
% theta2(t) 表示连杆 2 相对连杆 1 的转角。
syms d2 m2 theta2(t);

% dtheta2 是 theta2 对时间的一阶导数，也就是第二个广义角速度。
dtheta2 = diff(theta2, t);

% 连杆 2 质心在平面惯性坐标系中的位置。
% 第一段 d1*sin(theta1)、-d1*cos(theta1) 来自关节 2 的位置；
% 第二段 d2*sin(theta1+theta2)、-d2*cos(theta1+theta2)
% 来自连杆 2 质心相对关节 2 的位置。
x2 = d1*sin(theta1) + d2*sin(theta1+theta2);
y2 = -d1*cos(theta1) - d2 * cos(theta1+theta2);

% 对 x2、y2 关于时间求导，得到连杆 2 质心速度的两个分量。
% 因为 theta1、theta2 都是 t 的函数，所以 MATLAB 会自动使用链式法则。
dx2 = diff(x2, t);
dy2 = diff(y2, t);

%% 计算连杆 2 的动能和势能

% 连杆 2 的速度平方为 vx^2 + vy^2，即 dx2^2 + dy2^2。
K2 = 1/2 * m2 * (dx2 ^ 2 + dy2 ^ 2);

% 连杆 2 的势能为 m2*g*y2。
% y2 已经包含两个连杆角度对质心高度的影响。
P2 = m2 * g * y2;

%% 计算系统总能量

% 系统总动能等于两个连杆动能之和。
K = K1 + K2;

% 系统总势能等于两个连杆势能之和。
P = P1 + P2;

%% 拉格朗日函数

% 拉格朗日函数 L = K - P。
% 它把系统的动力学信息集中到一个标量函数中，
% 后续对每个广义坐标分别套用拉格朗日方程即可。
L = K - P;

%% 求拉格朗日方程

% 对二连杆机械臂，两个广义坐标为：
%   q1 = theta1
%   q2 = theta2
%
% 对每个广义坐标 qi，拉格朗日方程左侧为：
%   d/dt(∂L/∂dqi) - ∂L/∂qi
%
% 若右侧没有额外列出非保守力或关节力矩，
% 这里计算出的 F1_lagrange、F2_lagrange 可以理解为
% 对应广义坐标所需的广义力/广义力矩表达式。

%% 计算 L 对广义坐标的偏导

% dL_theta1、dL_theta2 分别对应 ∂L/∂theta1 和 ∂L/∂theta2。
dL_theta1 = diff(L, theta1);
dL_theta2 = diff(L, theta2);

%% 计算 L 对广义速度的偏导

% dL_dtheta1、dL_dtheta2 分别对应 ∂L/∂dtheta1 和 ∂L/∂dtheta2。
dL_dtheta1 = diff(L, dtheta1);
dL_dtheta2 = diff(L, dtheta2);

%% 对 ∂L/∂dtheta 再关于时间求导

% ddL_dtheta1 对应 d/dt(∂L/∂dtheta1)；
% ddL_dtheta2 对应 d/dt(∂L/∂dtheta2)。
% 这一步会产生角加速度项，也会通过链式法则产生速度耦合项。
ddL_dtheta1 = diff(dL_dtheta1, t);
ddL_dtheta2 = diff(dL_dtheta2, t);

%% 得到两个关节的拉格朗日方程

% 第一个广义坐标 theta1 对应的动力学方程左侧。
F1_lagrange = ddL_dtheta1 - dL_theta1;

% 第二个广义坐标 theta2 对应的动力学方程左侧。
F2_lagrange = ddL_dtheta2 - dL_theta2;

% 显示化简后的两个方程，便于和教材或手推结果对照。
disp('F1_lagrange = ');
pretty(simplify(F1_lagrange));

disp('F2_lagrange = ');
pretty(simplify(F2_lagrange));
