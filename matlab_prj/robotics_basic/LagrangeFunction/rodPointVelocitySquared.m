function v2 = rodPointVelocitySquared(dT_dq, qdot, r_i, i)
% rodPointVelocitySquared  计算连杆 i 上一点速度的平方
%
% 输入：
%   dT_dq : cell 数组，dT_dq{j} = ∂T_i / ∂q_j
%   qdot  : 广义速度列向量
%   r_i   : 点在连杆 i 坐标系下的位置，齐次坐标 [x; y; z; 1]
%   i     : 当前连杆编号
%
% 输出：
%   v2    : 速度平方 v^2

    Vmat = zeros(4,4);

    for j = 1:i
        Vmat = Vmat + dT_dq{j} * qdot(j);
    end

    v_hom = Vmat * r_i;

    v = v_hom(1:3);

    v2 = v.' * v;
end