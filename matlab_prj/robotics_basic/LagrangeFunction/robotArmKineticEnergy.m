function [K, Ki_list] = robotArmKineticEnergy(T_list, q, qdot, I_list)
% robotArmKineticEnergy  计算 n 连杆机械臂所有连杆的总动能
%
% [K, Ki_list] = robotArmKineticEnergy(T_list, q, qdot, I_list)
%
% 对应教材式 (4.19)：
%
%   K = sum(i=1..n) Ki
%     = 1/2 * sum(i=1..n) sum(j=1..i) sum(k=1..i)
%       Trace( ∂Ti/∂qj * Ii * (∂Ti/∂qk).' ) * qdot(j) * qdot(k)
%
% 输入：
%   T_list  : cell 数组，T_list{i} = 第 i 根连杆的齐次变换矩阵 Ti
%   q       : 广义坐标向量，例如 [q1; q2; ...; qn]
%   qdot    : 广义速度向量，例如 [q1_dot; q2_dot; ...; qn_dot]
%   I_list  : cell 数组，I_list{i} = 第 i 根连杆的 4x4 伪惯量矩阵 Ii
%
% 输出：
%   K       : n 根连杆总动能
%   Ki_list : cell 数组，Ki_list{i} = 第 i 根连杆动能

    n = numel(T_list);

    if numel(I_list) ~= n
        error('I_list 的元素个数必须与 T_list 相同。');
    end

    if numel(q) < n || numel(qdot) < n
        error('q 和 qdot 的长度至少应为连杆数量 n。');
    end

    q = q(:);
    qdot = qdot(:);

    K = 0;
    Ki_list = cell(n, 1);

    for i = 1:n
        dT_dq = cell(i, 1);

        for j = 1:i
            dT_dq{j} = diff(T_list{i}, q(j));
        end

        Ki_list{i} = rodKineticEnergy(dT_dq, qdot, I_list{i}, i);
        K = K + Ki_list{i};
    end
end
