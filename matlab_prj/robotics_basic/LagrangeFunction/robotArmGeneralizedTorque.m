function [tau, Dij, Dijk, Di] = robotArmGeneralizedTorque(T_list, q, qdot, qddot, I_list, Ia, gravity)
% robotArmGeneralizedTorque  按教材式 (4.24)-(4.27) 计算机械臂广义力/力矩
%
% [tau, Dij, Dijk, Di] = robotArmGeneralizedTorque(T_list, q, qdot, qddot, I_list, Ia, gravity)
%
% 复现的公式为：
%
%   tau_i = sum(j=1..n) Dij(i,j)*qddot(j)
%           + Iai*qddot(i)
%           + sum(j=1..n) sum(k=1..n) Dijk(i,j,k)*qdot(j)*qdot(k)
%           + Di(i)
%
%   Dij(i,j) =
%       sum(p=max(i,j)..n) Trace( ∂Tp/∂qj * Ip * (∂Tp/∂qi).' )
%
%   Dijk(i,j,k) =
%       sum(p=max(i,j,k)..n) Trace( ∂²Tp/(∂qj∂qk) * Ip * (∂Tp/∂qi).' )
%
%   Di(i) =
%       sum(p=i..n) -gravity.' * ∂Tp/∂qi * mp*rp
%
% 输入：
%   T_list  : cell 数组，T_list{p} 是第 p 根连杆坐标系到基坐标系的 4x4 齐次变换矩阵 Tp
%   q       : n x 1 广义坐标向量，例如 [q1; q2; ...; qn]
%   qdot    : n x 1 广义速度向量，例如 [dq1; dq2; ...; dqn]
%   qddot   : n x 1 广义加速度向量，例如 [ddq1; ddq2; ...; ddqn]
%   I_list  : cell 数组，I_list{p} 是第 p 根连杆的 4x4 伪惯量矩阵 Ip
%   Ia      : n x 1 传动装置等效惯量。没有传动装置时可传入 []。
%   gravity : 3 x 1 或 4 x 1 重力加速度向量，必须在基坐标系中表达。
%             例如 y 轴向上时可取 [0; -g; 0]，函数会自动补成 [0; -g; 0; 0]。
%
% 输出：
%   tau  : n x 1 广义力/关节力矩向量
%   Dij  : n x n 惯性系数矩阵
%   Dijk : n x n x n 速度二次项系数
%   Di   : n x 1 重力项
%
% 使用限制：
%   1. 本函数假定机械臂是串联开链机构，且第 p 根连杆的 Tp 只依赖 q1 到 qp。
%      公式中的求和下限 max(i,j) 和 max(i,j,k) 正是基于这个串联结构得到的。
%   2. T_list{p} 必须是从连杆 p 坐标系到基坐标系的齐次变换矩阵，不能混用相邻连杆变换。
%      如果只有相邻变换，应先相乘得到从连杆坐标系到基坐标系的 Tp。
%   3. I_list{p} 必须和 T_list{p} 使用同一个连杆 p 坐标系。
%      伪惯量矩阵应由 pseudoInertiaMatrix 构造，第四列需满足 [mx; my; mz; m] = mp*rp。
%      重力项 Di 使用的就是这一列；如果第四列不是质量一阶矩，重力项会错误。
%   4. q、qdot、qddot 的排列顺序必须完全一致。本函数不会自动从 q 推导 qdot 或 qddot。
%   5. Ia 只实现图中对角形式 Iai*qddot_i，不包含电机转子之间的耦合惯量。
%      对转动关节，Ia 是等效转动惯量；对平动关节，Ia 可按等效质量理解。
%   6. 本函数只包含刚体惯性项、速度二次项、重力项和简单传动惯量项；
%      不包含摩擦、阻尼、弹性、外力、约束力，也不处理闭链机构。
%   7. 符号求导和三重求和在多自由度机械臂上会很慢，结果也可能很长。
%      建议先用较少自由度验证，再按需要对输出使用 simplify。

    n = numel(T_list);

    if numel(I_list) ~= n
        error('I_list 的元素个数必须与 T_list 相同。');
    end

    if numel(q) ~= n || numel(qdot) ~= n || numel(qddot) ~= n
        error('q、qdot、qddot 的长度必须与 T_list 的元素个数相同。');
    end

    q = q(:);
    qdot = qdot(:);
    qddot = qddot(:);

    if nargin < 6 || isempty(Ia)
        Ia = sym(zeros(n, 1));
    else
        Ia = Ia(:);
        if numel(Ia) ~= n
            error('Ia 的长度必须与 T_list 的元素个数相同。');
        end
    end

    gravity = gravity(:);
    if numel(gravity) == 3
        gravity = [gravity; sym(0)];
    elseif numel(gravity) ~= 4
        error('gravity 必须是 3x1 或 4x1 向量。');
    end

    dT_dq = cell(n, n);
    d2T_dq = cell(n, n, n);

    for p = 1:n
        for i = 1:p
            dT_dq{p, i} = diff(T_list{p}, q(i));
        end

        for j = 1:p
            for k = 1:p
                d2T_dq{p, j, k} = diff(dT_dq{p, j}, q(k));
            end
        end
    end

    Dij = sym(zeros(n, n));
    Dijk = sym(zeros(n, n, n));
    Di = sym(zeros(n, 1));
    tau = sym(zeros(n, 1));

    for i = 1:n
        for j = 1:n
            for p = max(i, j):n
                Dij(i, j) = Dij(i, j) + trace(dT_dq{p, j} * I_list{p} * dT_dq{p, i}.');
            end
        end

        for j = 1:n
            for k = 1:n
                for p = max([i, j, k]):n
                    Dijk(i, j, k) = Dijk(i, j, k) ...
                        + trace(d2T_dq{p, j, k} * I_list{p} * dT_dq{p, i}.');
                end
            end
        end

        for p = i:n
            massMoment = I_list{p}(:, 4);
            Di(i) = Di(i) - gravity.' * dT_dq{p, i} * massMoment;
        end
    end

    for i = 1:n
        tau(i) = Ia(i) * qddot(i) + Di(i);

        for j = 1:n
            tau(i) = tau(i) + Dij(i, j) * qddot(j);

            for k = 1:n
                tau(i) = tau(i) + Dijk(i, j, k) * qdot(j) * qdot(k);
            end
        end
    end
end
