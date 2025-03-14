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
V_right = 2;

% 小车运动
%% 速度解算-速度-角速度
V = (V_left + V_right) / 2;
omega = (V_right - V_left) / Wheel_distance;

fprintf('小车的线速度 V = %.2f m/s\n', V);
fprintf('小车的角速度 omega = %.2f rad/s\n', omega);

% 时间参数
total_time = 100; 
step_size = 0.05; 
num_steps = total_time / step_size;

% 期望值
X_target = 10; % 目标x位置
Y_target = 5;  % 目标y位置

% 位置误差阈值
error_threshold = 0.3;

% PID 参数（位置控制）
Kp_position = 0.1; % 比例系数
Ki_position = 0.01; % 积分系数
Kd_position = 0.05; % 微分系数

% PID 参数（角度控制）
Kp_angle = 0.2;
Ki_angle = 8.4;
Kd_angle = 0.2;

% PID 参数（停车控制）
Kp_stop = 0.5;
Ki_stop = 0.1;
Kd_stop = 0.05;

% 初始化误差积分和上一次误差
integral_error_y = 0;
previous_error_y = 0;
integral_error_theta = 0;
previous_error_theta = 0;
integral_error_stop_left = 0;
previous_error_stop_left = 0;
integral_error_stop_right = 0;
previous_error_stop_right = 0;

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
    % 计算当前 Y 坐标偏差
    error_y = Y_target - Y(i);
    
    % 计算误差积分
    integral_error_y = integral_error_y + error_y * step_size;
    % 计算误差微分
    derivative_error_y = (error_y - previous_error_y) / step_size;
    % 计算 PID 控制量（位置控制）
    control_y = Kp_position * error_y + Ki_position * integral_error_y + Kd_position * derivative_error_y;
    
    % 计算目标角度
    target_theta = atan2(Y_target - Y(i), X_target - X(i));
    
    % 计算角度误差
    error_theta = target_theta - theta(i);
    % 处理角度误差在 -pi 到 pi 之间
    error_theta = atan2(sin(error_theta), cos(error_theta));
    
    % 计算误差积分（角度控制）
    integral_error_theta = integral_error_theta + error_theta * step_size;
    % 计算误差微分（角度控制）
    derivative_error_theta = (error_theta - previous_error_theta) / step_size;
    % 计算 PID 控制量（角度控制）
    control_theta = Kp_angle * error_theta + Ki_angle * integral_error_theta + Kd_angle * derivative_error_theta;
    
    % 判断是否到达目标位置
    if abs(X(i) - X_target) < error_threshold && abs(Y(i) - Y_target) < error_threshold
       % 到达目标位置，使用 PID 控制停车
        % 左车轮速度误差
        error_stop_left = 0 - V_left;
        integral_error_stop_left = integral_error_stop_left + error_stop_left * step_size;
        derivative_error_stop_left = (error_stop_left - previous_error_stop_left) / step_size;
        control_stop_left = Kp_stop * error_stop_left + Ki_stop * integral_error_stop_left + Kd_stop * derivative_error_stop_left;
        V_left = V_left + control_stop_left;
        
        % 右车轮速度误差
        error_stop_right = 0 - V_right;
        integral_error_stop_right = integral_error_stop_right + error_stop_right * step_size;
        derivative_error_stop_right = (error_stop_right - previous_error_stop_right) / step_size;
        control_stop_right = Kp_stop * error_stop_right + Ki_stop * integral_error_stop_right + Kd_stop * derivative_error_stop_right;
        V_right = V_right + control_stop_right;
    else
        % 根据角度偏差调整轮速
        V_left = V - control_theta;
        V_right = V + control_theta;
        % 根据 Y 坐标偏差调整线速度
        V = control_y;
    end
    
    % 速度限制，避免速度过大
    V_left = max(min(V_left, 10), -10);
    V_right = max(min(V_right, 10), -10);
    
    % 更新速度和角速度
    V = (V_left + V_right) / 2;
    omega = (V_right - V_left) / Wheel_distance;
    
    % 更新上一次误差
    previous_error_y = error_y;
    previous_error_theta = error_theta;
end

% 绘制位置轨迹
figure;
plot(X, Y);
hold on;
plot(X_target, Y_target, 'ro', 'MarkerFaceColor', 'r'); % 标记目标位置
xlabel('x 位置 (m)');
ylabel('y 位置 (m)');
title('差速小车位置轨迹');
grid on;
    