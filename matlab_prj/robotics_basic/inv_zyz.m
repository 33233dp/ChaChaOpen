function [phi, theta, psi] = inv_zyz(R)
% R = Rot(z,phi) * Rot(y,theta) * Rot(z,psi)
% angles in degrees

    eps_val = 1e-8;

    theta = atan2d(sqrt(R(1,3)^2 + R(2,3)^2), R(3,3));

    if abs(sind(theta)) > eps_val
        phi = atan2d(R(2,3), R(1,3));
        psi = atan2d(R(3,2), -R(3,1));
    else
        % singular case
        phi = 0;
        if abs(theta) < 1e-6
            psi = atan2d(R(2,1), R(1,1));
        else
            psi = atan2d(R(2,1), -R(1,1));
        end
    end

    phi = wrapTo180_local(phi);
    theta = wrapTo180_local(theta);
    psi = wrapTo180_local(psi);
end

function ang = wrapTo180_local(ang)
    ang = mod(ang + 180, 360) - 180;
end