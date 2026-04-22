% 定义符号变量且声明为实数
syms theta1 theta2 theta4 theta5 theta6 real
syms a2 a3 d3 d4 real

T01 = DH(0,0,0,theta1);
T12 = DH(0, -sym(pi)/2, 0, theta2);

% {1}{2}的x轴重合，因此x1方向的a也是x2方向的a
T23 = DH(a2 + d3,0,0,0); % 第3关节的位移 d3是沿 x_1即x_2方向的移动，因此它作为增量叠加到原有的连杆长度 a2上，使得总位移为 a2+d3。

T34 = DH(a3, -sym(pi)/2, d4, theta4);
T45 = DH(0, sym(pi)/2, 0, theta5);
T56 = DH(0, -sym(pi)/2, 0, theta6);

T06 = T01 * T12 * T23 * T34 * T45 * T56;
disp(T06)

% 打印末端系的位置

disp('px ='); disp(T06(1,4))
disp('py ='); disp(T06(2,4))
disp('pz ='); disp(T06(3,4))
