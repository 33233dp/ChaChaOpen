% DH函数
function T = DH(a, alpha, d, theta)
% DH 标准DH法的齐次变换矩阵
% 输入：
%   a 连杆长度
%   alpha 连杆扭角
%   d 连杆偏距
%   theta 关节角
% 返回值：
% T 4*4变换矩阵
T = [
     cos(theta),-sin(theta),0,a;
     sin(theta) * cos(alpha),cos(theta) * cos(alpha),-sin(alpha),-d * sin(alpha);
     sin(theta) * sin(alpha),cos(theta) * sin(alpha),cos(alpha),d * cos(alpha);
     0,0,0,1
    ];
end
