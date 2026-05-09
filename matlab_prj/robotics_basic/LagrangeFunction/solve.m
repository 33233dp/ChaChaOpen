% 定义符号变量
syms theta1 theta2 dtheta1 dtheta2 ddtheta1 ddtheta2 d1 d2;
syms m1 m2;
% 广义坐标及其微分
q = [theta1 theta2];
qdot = [dtheta1 dtheta2];
qddot = [ddtheta1 ddtheta2];

% 计算A矩阵和T矩阵(DH法)
A1 = dhTransform(theta1, 0, d1, 0);
A2 = dhTransform(theta2,0,d2,0);
T1 = A1;
T2 = A1 * A2; % T02
T_list = {T1, T2};

%% 计算总动能
% 构造伪惯量矩
% 1的惯量
I1 = pseudoInertiaMatrix(0,0,0,0,0,0,0,0,0,m1);
% 2的惯量
I2 = pseudoInertiaMatrix(0,0,0,0,0,0,0,0,0,m2);
I_list = {I1, I2};
% 计算总动能
%   Kt      : 机械臂系统总动能
%   K       : 连杆总动能
%   Ka      : 传动装置总动能
%   Ki_list : cell 数组，Ki_list{i} = 第 i 根连杆动能
syms Ia1 Ia2 real;
Ia = [
        Ia1;
        Ia2;
     ];
[Kt, K, Ka, Ki_list] = robotArmTotalKineticEnergy(T_list,q,qdot,I_list,Ia);
disp('Kt');pretty(simplify(Kt));
disp('K');pretty(simplify(K));
disp('Ka');pretty(simplify(Ka));
disp('Ki_list{1}');pretty(simplify(Ki_list{1}));
disp('Ki_list{2}');pretty(simplify(Ki_list{2}));

%% 动力学方程
% 重力:图中 x0 轴向下，重力沿 x0 正方向。
syms g real;
gravity = [
            g;
            0;
            0;
          ]
%   tau  : n x 1 广义力/关节力矩向量
%   Dij  : n x n 惯性系数矩阵
%   Dijk : n x n x n 速度二次项系数
%   Di   : n x 1 重力项
[tau, Dij, Dijl, Di] = robotArmGeneralizedTorque(T_list, q, qdot, qddot, I_list, Ia, gravity);

disp('tau = ');pretty(simplify(tau));

%% dh函数
function A = dhTransform(theta, alpha, a, d)

  A = [

    cos(theta), -sin(theta)*cos(alpha),  sin(theta)*sin(alpha), a*cos(theta);

    sin(theta),  cos(theta)*cos(alpha), -cos(theta)*sin(alpha), a*sin(theta);

    0,   sin(alpha),   cos(alpha), d;

    0,  0, 0,  1

];

end