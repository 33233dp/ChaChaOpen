function D = differentialMotionVector(dx, dy, dz, fx, fy, fz, dtheta)
    % 平移分量
    translation = [  dx, dy,  dz];
    
    % 旋转分量（假设是力矩/扭矩）
    rotation = [fx * dtheta, fy * dtheta, fz * dtheta  ];
    
    % 将平移和旋转分量合并
    D = [translation, rotation];
end
