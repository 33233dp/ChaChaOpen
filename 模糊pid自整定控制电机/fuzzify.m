function mu = fuzzify(input)
% 改进版模糊化函数，处理边界语言变量
% input: 输入数值
% mu   : 1x7 各语言变量隶属度 [NB NM NS ZO PS PM PB]

% 定义每个语言变量的三角形 [a, b, c]
% 最左 NB a = -Inf，最右 PB c = Inf
mf = [
   -2.0 -1.5 -1.0;   % NB
   -1.0 -0.5  0.0;   % NM
   -0.5  0.0  0.5;   % NS
   -0.25 0.0 0.25;   % ZO
    0.0  0.5  1.0;   % PS
    0.5  1.0  1.5;   % PM
    1.0  1.5  2.0   % PB
];

mu = zeros(1,7);

for i = 1:7
    a = mf(i,1);
    b = mf(i,2);
    c = mf(i,3);
    
    if isinf(a) && ~isinf(c)
        % NB 半无限三角形
        if input <= b
            mu(i) = 1;
        elseif input > b && input < c
            mu(i) = (c - input) / (c - b);
        else
            mu(i) = 0;
        end
    elseif ~isinf(a) && isinf(c)
        % PB 半无限三角形
        if input >= b
            mu(i) = 1;
        elseif input > a && input < b
            mu(i) = (input - a) / (b - a);
        else
            mu(i) = 0;
        end
    else
        % 普通三角形
        if input <= a || input >= c
            mu(i) = 0;
        elseif input > a && input <= b
            mu(i) = (input - a) / (b - a);
        elseif input > b && input < c
            mu(i) = (c - input) / (c - b);
        end
    end
end

end
