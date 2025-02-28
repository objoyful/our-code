%% MATLAB Assignment 1
% William Carden
% EGR 101-02
% Due Date: 1/23/2025
%
%% Assignment 1, Part I
side_b = 81;
side_c = 45;
angle_alpha = 47;

side_a = sqrt(side_b^2 + side_c^2 - 2 * side_b * side_c * cosd(angle_alpha))
angle_beta = acosd((side_a^2 + side_c^2 - side_b^2) / (2 * side_a * side_c))
angle_gamma = acosd((side_a^2 + side_b^2 - side_c^2) / (2 * side_a * side_b))

%% Assignment 1, Part II
n = 52;
r = 8;

combos = factorial(n) / (factorial(r) * factorial(n - r))