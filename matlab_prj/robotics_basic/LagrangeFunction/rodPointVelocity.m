function v = rodPointVelocity(dT_dq, qdot, r_i, i)
% rodPointVelocity  计算连杆 i 上一点的速度
%
% v = rodPointVelocity(dT_dq, qdot, r_i, i)
%
% 输入：
%   dT_dq : cell 数组，dT_dq{j} = ∂T_i / ∂q_j
%           每个元素通常是 4x4 矩阵
%
%   qdot  : 广义速度列向量，例如 [q1_dot; q2_dot; q3_dot]
%
%   r_i   : 点在连杆 i 坐标系下的位置，齐次坐标形式
%           例如 [x; y; z; 1]
%
%   i     : 当前连杆编号
%
% 输出：
%   v     : 该点在固定坐标系下的速度向量，取前三项

    Vmat = zeros(4,4);

    for j = 1:i
        Vmat = Vmat + dT_dq{j} * qdot(j);
    end

    v_hom = Vmat * r_i;

    v = v_hom(1:3);
end
