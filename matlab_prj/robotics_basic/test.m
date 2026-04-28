% TWC = TW0 * TW06 * T6C
% TWC = TWD * TDC
TWD = [
          1,0,0,830;
          0,1,0,20; 
          0,0,1,330;
          0,0,0,1
      ];
TDC = [
          cosd(35), -sind(35),0,-280;
          sind(35), cosd(35), 0,250;
          0,        0,        1,62.5;
          0,        0,        0,1
      ];
TWC = TWD * TDC;

TW0 = [
          1,0,0,0;
          0,1,0,0;
          0,0,1,373;
          0,0,0,1
      ];
T6C = [
          0,0,1,0;
          0,-1,0,0;
          1,0,0,206;
          0,0,0,1
      ];

T06 = TW0 \ TWC / T6C;
P6o_ORG = T06(1:3,4);
disp('P6o_ORG ='); disp(P6o_ORG);

[theta1, theta2, theta3] = pieper(-30,340,-40,-90,0,-90,0,0,338,P6o_ORG(1), P6o_ORG(2), P6o_ORG(3));
disp('theta1 ='); disp(theta1);
disp('theta2 ='); disp(theta2);
disp('theta3 ='); disp(theta3);

theta1 = 21.7166;
theta2 =  -52.1867;
theta3 =  2.4824;

T01 = DH(0,0,0,theta1);
T12 = DH(-30,-90,0,theta2);
T23 = DH(340,0,0,theta3);
T03 = T01 * T12 * T23;

R03 = T03(1:3, 1:3);
R06 = T06(1:3,1:3);
R36 = R03' * R06;
[phi, beta, psi] = inv_zyz(R36);
disp('phi ='); disp(phi);
disp('beta ='); disp(beta);   
disp('psi ='); disp(psi);