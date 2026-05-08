function [Kt, K, Ka, Ki_list] = robotArmTotalKineticEnergy(T_list, q, qdot, I_list, Ia)
% robotArmTotalKineticEnergy  计算包含传动装置的机械臂系统总动能
%
% [Kt, K, Ka, Ki_list] = robotArmTotalKineticEnergy(T_list, q, qdot, I_list, Ia)
%
% 对应教材式 (4.20)：
%
%   Kt = K + Ka
%
% 其中：
%   K  是所有连杆的总动能；
%   Ka 是所有关节传动装置的总动能。
%
% 输入：
%   T_list  : cell 数组，T_list{i} = 第 i 根连杆的齐次变换矩阵 Ti
%   q       : 广义坐标向量
%   qdot    : 广义速度向量
%   I_list  : cell 数组，I_list{i} = 第 i 根连杆的 4x4 伪惯量矩阵 Ii
%   Ia      : 传动装置等效惯量向量。若没有传动装置，可传入 []。
%
% 输出：
%   Kt      : 机械臂系统总动能
%   K       : 连杆总动能
%   Ka      : 传动装置总动能
%   Ki_list : cell 数组，Ki_list{i} = 第 i 根连杆动能

    [K, Ki_list] = robotArmKineticEnergy(T_list, q, qdot, I_list);

    if nargin < 5 || isempty(Ia)
        Ka = 0;
    else
        Ka = actuatorKineticEnergy(Ia, qdot);
    end

    Kt = K + Ka;
end
