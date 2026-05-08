function Ki = rodKineticEnergy(dT_dq, qdot, I_i, i)
% rodKineticEnergy  计算第 i 根连杆的动能
%
% Ki = rodKineticEnergy(dT_dq, qdot, I_i, i)
%
% 对应教材中的单根连杆动能公式：
%
%   Ki = 1/2 * sum(j=1..i) sum(k=1..i)
%        Trace( ∂Ti/∂qj * Ii * (∂Ti/∂qk).' ) * qdot(j) * qdot(k)
%
% 其中：
%   Ti   是从连杆 i 坐标系到基坐标系的齐次变换矩阵；
%   Ii   是连杆 i 的 4x4 伪惯量矩阵；
%   qj   是第 j 个广义坐标；
%   qdot 是广义速度。
%
% 输入：
%   dT_dq : cell 数组
%           dT_dq{j} = ∂T_i / ∂q_j
%           每个元素是 4x4 矩阵
%
%   qdot  : 广义速度列向量
%           qdot = [q1_dot; q2_dot; ...; qi_dot]
%
%   I_i   : 第 i 根连杆的伪惯量矩阵，4x4
%
%   i     : 当前连杆编号
%
% 输出：
%   Ki    : 第 i 根连杆的动能

    Ki = 0;

    for j = 1:i
        for k = 1:i
            term = dT_dq{j} * I_i * dT_dq{k}.' * qdot(j) * qdot(k);
            Ki = Ki + trace(term);
        end
    end

    Ki = 0.5 * Ki;
end
