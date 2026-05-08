function Ka = actuatorKineticEnergy(Ia, qdot)
% actuatorKineticEnergy  计算所有关节传动装置的总动能
%
% Ka = actuatorKineticEnergy(Ia, qdot)
%
% 对应教材中的传动装置动能：
%
%   Ka = 1/2 * sum(i=1..n) Iai * qdot(i)^2
%
% 输入：
%   Ia    : 传动装置等效惯量向量
%           对转动关节，Ia(i) 表示等效转动惯量；
%           对平动关节，Ia(i) 可表示等效质量。
%   qdot  : 广义速度向量
%
% 输出：
%   Ka    : 所有关节传动装置总动能

    Ia = Ia(:);
    qdot = qdot(:);

    if numel(Ia) ~= numel(qdot)
        error('Ia 和 qdot 的长度必须相同。');
    end

    Ka = 0;

    for i = 1:numel(qdot)
        Ka = Ka + 0.5 * Ia(i) * qdot(i)^2;
    end
end
