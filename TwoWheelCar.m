% 差速小车数学模型(匀速运动)
%% 车身参数
Wheel_distance = 5;
Wheel_radius = 1;
V_x = zeros(200,1);
V_y = zeros(200,1);
X = zeros(200,1);
Y = zeros(200,1);
theta = zeros(200,1);
%%% 输入速度
V_left = 2;
V_right = 3;

% 小车运动
%% 速度解算-速度-角速度
V = (V_left + V_right) / 2;
omega = (V_right - V_left) / Wheel_distance;

fprintf('小车的线速度 V = %.2f m/s\n', V);
fprintf('小车的角速度 omega = %.2f rad/s\n', omega);

% 时间参数
total_time = 10; 
step_size = 0.05; 
num_steps = total_time / step_size;

% 运动解算
for i = 1:num_steps
    if i == 1
        theta(i) = omega * step_size;
    else 
        theta(i) = theta(i-1) + omega * step_size;
    end
        V_x(i) = V * cos(theta(i));
        V_y(i) = V * sin(theta(i));
    % 位置更新
    if i == 1
        X(i) = V_x(i) * step_size;
        Y(i) = V_y(i) * step_size;
    else
        X(i) = X(i-1) + V_x(i) * step_size;
        Y(i) = Y(i-1) + V_y(i) * step_size;
    end
end

% 绘制位置轨迹
figure;
plot(X, Y);
xlabel('x 位置 (m)');
ylabel('y 位置 (m)');
title('差速小车位置轨迹');
grid on;
