%% MATLAB Assignment 2
% William Carden
% EGR 101-02
% Due Date: 1/28/2025

format compact

% Slopes and interceps
m1 = -5.93;
b1 = 103.6;
m2 = 8.2;
b2 = -8.3;
m3 = 1.21;
b3 = 0;

% x1, x2, x3 row vectors
x1 = -2:1.1:17;
x2 = linspace(-3.2, 19, 17);
x3 = -3.7:2.6:20;

% Calculate y1, y2, and y3 using the slope-intercept formula.
y1 = m1 * x1 + b1;
y2 = m2 * x2 + b2;
y3 = m3 * x3 + b3;

% Calculate the mean values of y1, y2, y3.
mean_y1 = mean(y1);
mean_y2 = mean(y2);
mean_y3 = mean(y3);

% Calculate the smallest values of y1, y2, y3.
min_y1 = min(y1);
min_y2 = min(y2);
min_y3 = min(y3);

% Calculate the largest values of x1, x2, x3.
max_x1 = max(x1);
max_x2 = max(x2);
max_x3 = max(x3);

% Plot values
plot(x1, y1, 'bo', x2, y2, 'gx', x3, y3, 'm*')

% Mean of all y values
mean_all_ys = mean([y1 y2 y3])

% Sum of y minimums
sum_y_mins = sum([min_y1 min_y2 min_y3])

% Sum of x maxiums
sum_x_maxs = sum([max_x1 max_x2 max_x3])