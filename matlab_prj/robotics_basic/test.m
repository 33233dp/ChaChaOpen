% 定义矩阵 A
A = [0 0 1 10; 
     1 0 0 5; 
     0 1 0 0;
     0 0 0 1];

d = [1,0,0.5];
der = [0,0.1,0;];

D = [d,der];

deta = differential_motion(D);

dA = deta * A;
disp(dA);
