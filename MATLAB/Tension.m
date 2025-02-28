function [t_min, d_t_min] = Tension(l_b, l_c, w, d_min, d_max)
    % Calculates the maximum tension and the corresponding connection distance of a string holding a weight connected to a rod at the end of a hinge
    % given the length of the rod, length of the string, the weight of the object, and the
    % maximum and minimum connection distances from the hinge to the attachment point of the string.
    % Outputs a plot of the tension of the string vs. the connection length at twenty different values.
    % [t_min, d_t_min] = Tension(l_b, l_c, w, d_min, d_max)
    % Inputs:
    %   l_b = the length of the rod (in meters)
    %   l_c = the length of the string (in meters)
    %   w = the weight of the object (in Newtons)
    %   d_min = the minimum distance from the hinge to the attachment point of the string (in meters)
    %   d_max = the maximum distance from the hinge to the attachment point of the string (in meters)
    % Outputs:
    %   t_min = the minimum tension of the string (in Newtons)
    %   d_t_min = the distance from the hinge to the cable attachment point at the minimum tension (in meters)
    % William Carden Tension Function
    % EGR 101-02
    % Due Date: 02/21/2025

    % Create an array of twenty connection distances.
    d = linspace(d_min, d_max, 20);
    
    % Tension formula
    t = (l_b * l_c * w) ./ (d .* sqrt(l_c^2 - d.^2));
    
    % Calculate the minimum tension and the corresponding connection distance.
    [t_min, pos] = min(t);
    d_t_min = d(pos);

    % Graphs tension vs. connection distance.
    hold on;
    plot(d, t, 'b-', 'MarkerSize', 5);
    plot(d, t, 'm^', 'MarkerSize', 5);
    hold off;
    
    % Label and title.
    xlabel('Rod Connection Length (meters)');
    ylabel('Cable Tension (Newtons)');
    title('Cable Tension vs. Rod Connection Length');