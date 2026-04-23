syms theta1 theta2 theta3 real
syms L1 L2 L3 L4

T01 = DH(0,0, L1+L2,theta1);
T12 = DH(0,sym(pi)/2, 0,theta2);
T23 = DH(L3,0,0,theta3);
T34 = DH(L4,0,0,0);

T04 = T01 * T12 * T23 * T34;
disp("x = ");disp(T04(1,4));
disp("y = ");disp(T04(2,4));
disp("z = ");disp(T04(3,4));