function I_i = pseudoInertiaMatrix(Jxx, Jxy, Jxz, Jyy, Jyz, Jzz, mx, my, mz, m)
% pseudoInertiaMatrix  构造连杆的 4x4 伪惯量矩阵
%
% 输入：
%   Jxx = ∫ x^2 dm
%   Jxy = ∫ x*y dm
%   Jxz = ∫ x*z dm
%   Jyy = ∫ y^2 dm
%   Jyz = ∫ y*z dm
%   Jzz = ∫ z^2 dm
%
%   mx  = ∫ x dm
%   my  = ∫ y dm
%   mz  = ∫ z dm
%   m   = ∫ dm
%
% 输出：
%   I_i : 4x4 伪惯量矩阵

    I_i = [
        Jxx, Jxy, Jxz, mx;
        Jxy, Jyy, Jyz, my;
        Jxz, Jyz, Jzz, mz;
        mx,  my,  mz,  m
    ];
end
