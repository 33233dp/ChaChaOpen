% 1. 定义矩阵
H = [ 0,  1,  0,  0;
      0,  0, -1,  0;
     -1,  0,  0,  0;
      0,  0,  0,  1];

% 2. 提取 3x3 旋转矩阵
R = H(1:3, 1:3);

% 3. 计算旋转角度 theta (基于迹的公式)
% tr(R) = 1 + 2*cos(theta)
theta = acos((trace(R) - 1) / 2);

% 4. 计算旋转轴 f (利用反对称部分)
% f = [r32-r23; r13-r31; r21-r12] / (2*sin(theta))
if sin(theta) > 1e-6
    f = (1 / (2 * sin(theta))) * [R(3,2) - R(2,3); 
                                  R(1,3) - R(3,1); 
                                  R(2,1) - R(1,2)];
else
    % 特殊情况处理（如 theta 为 0 或 pi）
    if trace(R) > 0
        f = [0; 0; 0]; % 无旋转
    else
        % theta = pi 的情况需要通过特征向量或特殊分解
        [V, D] = eig(R);
        [~, idx] = min(abs(diag(D) - 1));
        f = V(:, idx);
    end
end

% 5. 输出结果
fprintf('旋转角度 theta (弧度): %.4f\n', theta);
fprintf('旋转角度 theta (角度): %.2f 度\n', rad2deg(theta));
fprintf('旋转轴 f:\n');
disp(f);