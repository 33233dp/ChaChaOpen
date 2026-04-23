syms theta1 theta2 theta3 real
syms L1 L2 L3 L4

% 错误：T01 = DH(0, 0, 0,theta1); 

T01 = DH(0,0,L1+L2,theta1);% 注意d是0_i-1 与O_i之间z_i方向的位移，而不是x_i-1与x_i的偏移距离！
                            % 每个坐标系的坐标原点并不固定在关节上，而是取决于z_i-1与z_i的共垂线即x_i-1与z_i-1交点
T12 = DH(0, sym(pi)/2, 0,theta2); 
T23 = DH(L3, 0, 0, theta3);

T03 = T01 * T12 * T23;
disp("T03 x = ");disp(T03(1,4));
disp("T03 y = ");disp(T03(2,4));
disp("T03 z = ");disp(T03(3,4));

% 若要求求末端T04则有
T34 = DH(L4,0,0,0);
T04 =T01 * T12 * T23 * T34;
disp("T04 x = ");disp(T04(1,4));
disp("T04 y = ");disp(T04(2,4));
disp("T04 z = ");disp(T04(3,4));