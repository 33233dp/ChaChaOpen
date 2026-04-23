function [theta1_sol, theta2_sol, theta3_sol] = pieper(a1, a2, a3, alpha1, alpha2, alpha3, d2, d3, d4, x, y, z)
% PIEPER numerical version
% All angles in degrees.
% Input x,y,z are the target position expressed in base frame {0}.
%
% Output:
%   theta1_sol, theta2_sol, theta3_sol
%   column vectors, each row is one solution set

    tol = 1e-6;

    % r from the notes
    r = x^2 + y^2 + z^2;

    % ---- helper functions of theta3 ----
    f1 = @(t3) a3*cosd(t3) + d4*sind(alpha3)*sind(t3) + a2;

    f2 = @(t3) a3*cosd(alpha2)*sind(t3) ...
             - d4*sind(alpha3)*cosd(alpha2)*cosd(t3) ...
             - d4*sind(alpha2)*cosd(alpha3) ...
             - d3*sind(alpha2);

    f3 = @(t3) a3*sind(alpha2)*sind(t3) ...
             - d4*sind(alpha3)*sind(alpha2)*cosd(t3) ...
             + d4*cosd(alpha2)*cosd(alpha3) ...
             + d3*cosd(alpha2);

    k1 = @(t3) f1(t3);
    k2 = @(t3) -f2(t3);
    k3 = @(t3) f1(t3).^2 + f2(t3).^2 + f3(t3).^2 + a1^2 + d2^2 + 2*d2*f3(t3);
    k4 = @(t3) f3(t3)*cosd(alpha1) + d2*cosd(alpha1);

    % ---------------------------------------------------------
    % Step 1: solve theta3 numerically
    % ---------------------------------------------------------
    if abs(a1) < tol
        eq3 = @(t3) r - k3(t3);
    elseif abs(sind(alpha1)) < tol
        eq3 = @(t3) z - k4(t3);
    else
        eq3 = @(t3) (r - k3(t3)).^2/(4*a1^2) + (z - k4(t3)).^2/(sind(alpha1)^2) ...
                  - (k1(t3).^2 + k2(t3).^2);
    end

    % scan over [-180,180] to find sign changes
    scan = -180:1:180;
    vals = zeros(size(scan));
    for i = 1:numel(scan)
        vals(i) = eq3(scan(i));
    end

    theta3_cand = [];

    % roots from sign change intervals
    for i = 1:numel(scan)-1
        v1 = vals(i);
        v2 = vals(i+1);

        if ~isfinite(v1) || ~isfinite(v2)
            continue;
        end

        if abs(v1) < 1e-4
            theta3_cand(end+1,1) = scan(i); %#ok<AGROW>
        elseif v1 * v2 < 0
            try
                rt = fzero(eq3, [scan(i), scan(i+1)]);
                theta3_cand(end+1,1) = rt; %#ok<AGROW>
            catch
            end
        end
    end

    % also try a few seeded solves in case tangent roots are missed
    seeds = -180:20:180;
    for i = 1:numel(seeds)
        try
            rt = fzero(eq3, seeds(i));
            if isfinite(rt)
                theta3_cand(end+1,1) = rt; %#ok<AGROW>
            end
        catch
        end
    end

    theta3_cand = wrapTo180_local(theta3_cand);
    theta3_cand = unique_tol(theta3_cand, 1e-4);

    % ---------------------------------------------------------
    % Step 2: solve theta2 from r-equation or z-equation
    % ---------------------------------------------------------
    theta2_list = [];
    theta3_list = [];

    for i = 1:numel(theta3_cand)
        t3 = theta3_cand(i);

        k1i = k1(t3);
        k2i = k2(t3);
        k3i = k3(t3);
        k4i = k4(t3);

        if abs(a1) < tol
            if abs(sind(alpha1)) < tol
                % degenerate case not handled in this route
                continue;
            end
            % z = (k1*s2 - k2*c2)*salpha1 + k4
            A = k1i * sind(alpha1);
            B = -k2i * sind(alpha1);
            C = z - k4i;
        else
            % r = (k1*c2 + k2*s2)*2*a1 + k3
            A = 2*a1*k1i;
            B = 2*a1*k2i;
            C = r - k3i;
        end

        R = hypot(A, B);
        if R < tol
            continue;
        end

        ratio = C / R;
        if abs(ratio) > 1 + 1e-8
            continue;
        end
        ratio = max(min(ratio, 1), -1);

        phi = atan2d(B, A);
        delta = acosd(ratio);

        t2a = wrapTo180_local(phi + delta);
        t2b = wrapTo180_local(phi - delta);

        theta2_list(end+1,1) = t2a; %#ok<AGROW>
        theta3_list(end+1,1) = t3;  %#ok<AGROW>

        if abs(wrapTo180_local(t2a - t2b)) > 1e-4
            theta2_list(end+1,1) = t2b; %#ok<AGROW>
            theta3_list(end+1,1) = t3;  %#ok<AGROW>
        end
    end

    % ---------------------------------------------------------
    % Step 3: solve theta1 from x,y
    % x = c1*g1 - s1*g2
    % y = s1*g1 + c1*g2
    % => theta1 = atan2(y,x) - atan2(g2,g1)
    % ---------------------------------------------------------
    theta_all = [];

    for i = 1:numel(theta2_list)
        t2 = theta2_list(i);
        t3 = theta3_list(i);

        f1i = f1(t3);
        f2i = f2(t3);
        f3i = f3(t3);

        g1 = cosd(t2)*f1i - sind(t2)*f2i + a1;
        g2 = sind(t2)*cosd(alpha1)*f1i + cosd(t2)*cosd(alpha1)*f2i ...
           - sind(alpha1)*f3i - d2*sind(alpha1);
        g3 = sind(t2)*sind(alpha1)*f1i + cosd(t2)*sind(alpha1)*f2i ...
           + cosd(alpha1)*f3i + d2*cosd(alpha1);

        t1 = wrapTo180_local(atan2d(y, x) - atan2d(g2, g1));

        % numeric consistency check
        xx = cosd(t1)*g1 - sind(t1)*g2;
        yy = sind(t1)*g1 + cosd(t1)*g2;
        zz = g3;

        if abs(xx - x) < 1e-3 && abs(yy - y) < 1e-3 && abs(zz - z) < 1e-3
            theta_all(end+1,:) = [t1, t2, t3]; %#ok<AGROW>
        end
    end

    % final dedup
    if isempty(theta_all)
        theta1_sol = [];
        theta2_sol = [];
        theta3_sol = [];
        return;
    end

    theta_all = unique_tol_rows(theta_all, 1e-3);

    theta1_sol = theta_all(:,1);
    theta2_sol = theta_all(:,2);
    theta3_sol = theta_all(:,3);
end

% =========================
% local helpers
% =========================
function ang = wrapTo180_local(ang)
    ang = mod(ang + 180, 360) - 180;
end

function v = unique_tol(v, tol)
    if isempty(v)
        return;
    end
    v = sort(v(:));
    keep = true(size(v));
    for i = 2:numel(v)
        if abs(v(i) - v(i-1)) < tol
            keep(i) = false;
        end
    end
    v = v(keep);
end

function A = unique_tol_rows(A, tol)
    if isempty(A)
        return;
    end
    A = sortrows(A);
    keep = true(size(A,1),1);
    for i = 2:size(A,1)
        if max(abs(A(i,:) - A(i-1,:))) < tol
            keep(i) = false;
        end
    end
    A = A(keep,:);
end