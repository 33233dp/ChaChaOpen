% 题配图为图 4.5，连杆参数为表 4.2。

%

% 本脚本根据已有函数复现二连杆机械手的动力学求解过程：

%   1. 根据表 4.2 建立标准 DH 变换矩阵 A1、A2；

%   2. 计算从各连杆坐标系到基坐标系的 T1、T2；

%   3. 使用 pseudoInertiaMatrix 构造 m1、m2 的伪惯量矩阵；

%   4. 使用 robotArmTotalKineticEnergy 计算总动能；

%   5. 使用 robotArmGeneralizedTorque 计算惯性项、速度耦合项和重力项。

%

% 使用限制：

%   1. 文件名 solve.m 会遮蔽 MATLAB Symbolic Math Toolbox 自带的 solve 函数。

%      因此在当前目录运行本脚本时，不要在脚本中直接调用内置 solve。

%      如果需要使用内置 solve，建议把本文件改名，例如 solve_two_link_robot.m。

%   2. 本脚本只针对图 4.5 的二连杆串联开链机械臂，不适用于闭链机构。

%   3. 这里把 m1、m2 视为集中在各自连杆坐标系原点的质点。

%      若质量分布不是质点模型，应重新填写每根连杆的伪惯量矩阵 I1、I2。

%   4. A1、A2 按标准 DH 矩阵构造：

%      Rot(z,theta) * Trans(z,d) * Trans(x,a) * Rot(x,alpha)。

%      如果教材或其他资料采用改进 DH 法，本脚本的 T 矩阵需要相应修改。

%   5. 重力方向按图中基坐标系取在 x0 正方向，所以 gravity = [g; 0; 0]。

%      如果坐标系方向不同，应修改 gravity。

%   6. 传动装置等效惯量 Ia1、Ia2 只按对角项加入，即 Ia_i*qddot_i。

%      不包含摩擦、阻尼、柔性、外力、约束力或电机转子耦合惯量。

  

clear;

clc;

  

%% 定义符号变量

  

syms theta1 theta2 real;

syms dtheta1 dtheta2 real;

syms ddtheta1 ddtheta2 real;

syms d1 d2 real;

syms m1 m2 real;

syms Ia1 Ia2 real;

syms g real;

  

q = [theta1; theta2];

qdot = [dtheta1; dtheta2];

qddot = [ddtheta1; ddtheta2];

  

%% 根据表 4.2 建立 A 矩阵

  

% 表 4.2：

%   连杆 1：变量 theta1，alpha = 0，a = d1，d = 0

%   连杆 2：变量 theta2，alpha = 0，a = d2，d = 0

A1 = dhTransform(theta1, 0, d1, 0);

A2 = dhTransform(theta2, 0, d2, 0);

  

% T_list{i} 必须是第 i 根连杆坐标系到基坐标系的总变换。

T1 = A1;

T2 = A1 * A2;

T_list = {T1, T2};

  

%% 构造伪惯量矩阵

  

% 质点位于各自连杆坐标系原点时：

%   ∫x dm = ∫y dm = ∫z dm = 0

%   ∫x^2 dm、∫xy dm 等二阶积分也为 0

%

% 因此伪惯量矩阵只有右下角质量项非零。

I1 = pseudoInertiaMatrix(0, 0, 0, 0, 0, 0, 0, 0, 0, m1);

I2 = pseudoInertiaMatrix(0, 0, 0, 0, 0, 0, 0, 0, 0, m2);

I_list = {I1, I2};

  

%% 计算总动能

  

Ia = [Ia1; Ia2];

[Kt, K, Ka, Ki_list] = robotArmTotalKineticEnergy(T_list, q, qdot, I_list, Ia);

  

Kt = simplify(Kt);

K = simplify(K);

Ka = simplify(Ka);

Ki_list{1} = simplify(Ki_list{1});

Ki_list{2} = simplify(Ki_list{2});

  

%% 计算动力学方程

  

% 图中 x0 轴向下，重力沿 x0 正方向。

gravity = [g; 0; 0];

  

[tau, Dij, Dijk, Di] = robotArmGeneralizedTorque(T_list, q, qdot, qddot, I_list, Ia, gravity);

  

tau = simplify(tau);

Dij = simplify(Dij);

Dijk = simplify(Dijk);

Di = simplify(Di);

  

%% 显示结果

  

disp('A1 = ');

pretty(A1);

  

disp('A2 = ');

pretty(A2);

  

disp('T1 = ');

pretty(T1);

  

disp('T2 = ');

pretty(T2);

  

disp('K1 = ');

pretty(Ki_list{1});

  

disp('K2 = ');

pretty(Ki_list{2});

  

disp('K = ');

pretty(K);

  

disp('Ka = ');

pretty(Ka);

  

disp('Kt = ');

pretty(Kt);

  

disp('Dij = ');

pretty(Dij);

  

disp('Dijk(:,:,1) = ');

pretty(Dijk(:,:,1));

  

disp('Dijk(:,:,2) = ');

pretty(Dijk(:,:,2));

  

disp('Di = ');

pretty(Di);

  

disp('tau = ');

pretty(tau);

  

%% 本脚本使用的标准 DH 变换矩阵

  

function A = dhTransform(theta, alpha, a, d)

% dhTransform  标准 DH 齐次变换矩阵

%

% A = dhTransform(theta, alpha, a, d)

%

% 标准 DH 形式：

%   A = Rot(z,theta) * Trans(z,d) * Trans(x,a) * Rot(x,alpha)

%

% 输入限制：

%   theta、alpha、a、d 可以是数值或符号量；

%   本函数只返回单节相邻坐标系变换，不负责连乘得到总 T 矩阵。

  

  A = [

  cos(theta), -sin(theta)*cos(alpha), sin(theta)*sin(alpha), a*cos(theta);

  sin(theta),  cos(theta)*cos(alpha), -cos(theta)*sin(alpha), a*sin(theta);

  0,  sin(alpha),   cos(alpha),  d;

  0,   0,  0,   1

  ];

end