function [delta, Tdelta] = differential_motion(D)
% 输入的D是行向量！注意！
delta = [
            0, -D(6), D(5), D(1);
            D(6), 0, -D(4), D(2);
            -D(5), D(4), 0, D(3);
            0, 0, 0, 0
        ];

Tdelta = [
             0, (-D(6))', (D(5))', D(1)';
            (D(6))', 0, (D(4))', D(2)';
            (-D(5))', (D(4))', 0, D(3)';
            0, 0, 0, 0
         ];

end