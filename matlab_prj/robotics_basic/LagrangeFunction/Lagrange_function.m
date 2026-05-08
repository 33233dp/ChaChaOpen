% 《机器人学 第四版 清华大学出版社》 p117 4.1.1 刚体的动能与位能
syms t;
syms K;
syms x0(t) x1(t);
syms M0 M1;

syms k;
syms g;
syms c;

syms F;


dx0 = diff(x0,t);
dx1 = diff(x1,t);

K = 1/2 * M0 * dx0^2 + 1/2 * M1 * dx1^2;    % 动能
P = 1/2 * k * (x1 - x0)^2 - M1 * g * x1 - M0 * g * x0; % 势能
D = 1/2*c*(dx1 - dx0)^2;    % 损耗
W = F*x1 - F*x0;    % 外部做功

disp('K = ')
pretty(K)

disp('P = ')
pretty(P)

disp('D = ')
pretty(D)

disp('W = ')
pretty(W)

% 利用拉格朗日推运动方程

% 得拉格朗日函数
L = K - P;
disp('L = ')
pretty(L)

% 求运动方程

% 物体0的运动方程
Fi0_Lagrange  = diff(diff(L,dx0), t) - diff(L, x0);
disp('Fi0_Lagrange  = ')
pretty(Fi0_Lagrange )

% 物体1的运动方程
Fi1_Lagrange  = diff(diff(L,dx1), t) - diff(L, x1);
disp('Fi1_Lagrange  = ')
pretty(Fi1_Lagrange )

