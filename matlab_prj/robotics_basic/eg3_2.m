syms L1 L2 
syms theta1 theta2 theta3 

T01 = DH(0, 0, 0, theta1);% 人为设置参考坐标系
T12 = DH(L1, sym(pi)/2, 0, theta2);
T23 = DH(L2, 0, 0, theta3);
T03 = T01 * T12 * T23;

disp('px ='); disp(T03(1,4));
disp('py ='); disp(T03(2,4));
disp('pz ='); disp(T03(3,4));
