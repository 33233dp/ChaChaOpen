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
     cosd(theta),-sind(theta),0,a;
     sind(theta) * cosd(alpha),cosd(theta) * cosd(alpha),-sind(alpha),-d * sind(alpha);
     sind(theta) * sind(alpha),cosd(theta) * sind(alpha),cosd(alpha),d * cosd(alpha);
     0,0,0,1
    ];
end
