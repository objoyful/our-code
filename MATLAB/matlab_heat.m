%% MATLAB Assignment 3
% William Carden
% EGR 101-02
% Due Date: 1/30/2025

format default

% Inputs
T_i = input("Current temperaure of the Coke (deg F)? ");
T_r = input("Temperature of your friend's fridge (deg F)? ");
T_c = input("Ideal Coke drinking temperature (deg F)? ");

% Inverse time constant
k = 0.042;

% Calculate time
t = -(1/k) * log((T_c - T_r) / (T_i - T_r));

minutes = floor(t);
seconds = mod(t * 60, 60);

fprintf("\nIt should take %g minutes and %.0f seconds to cool the Coke to %g degrees F" + ...
    "\nfrom %g degrees F if my fridge has a temperature of %g degrees F.\n", minutes, seconds, T_c, T_i, T_r);

% Calculate time if the fridge temperature is - 4.2 °F
T_r_minus = T_r - 4.22;

t_minus = -(1/k) * log((T_c - T_r_minus) / (T_i - T_r_minus));

minutes_minus = floor(t_minus);
seconds_minus = mod(t_minus * 60, 60);

fprintf("At %.1f degrees F, it will take %g minutes and %.0f seconds to cool.\n", T_r_minus, minutes_minus, seconds_minus)

% Calculate time if the fridge temperature is + 4.2 °F
T_r_plus = T_r + 4.2;

t_plus = -(1/k) * log((T_c - T_r_plus) / (T_i - T_r_plus));

minutes_plus = floor(t_plus);
seconds_plus = mod(t_plus * 60, 60);

fprintf("At %g degrees F, it will take %g minutes and %.0f seconds to cool.\n", T_r_plus, minutes_plus, seconds_plus)