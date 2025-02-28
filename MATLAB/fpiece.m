function [a, b, c] = fpiece(x)
    % Calculates a function's output given an input array, as well as the average value and the index of the minimum value.
    % The function applied depends on the input value.
    % Input Value:  Function:
    % x < 0         tan^-1(x) / 13 (in degrees)
    % 0 <= x <= 1   15 * x^(1/3)
    % 1 < x <= 10   3 / z! (where z is x rounded up to the nearest whole number)
    % x > 10        16 * log10(x)
    % [a, b, c] = fpiece(x)
    % Inputs:
    %   x = input array
    % Outputs:
    %   a = output array
    %   b = average of the output array
    %   c = index of the minimum value in output array
    % William Carden fpiece Function
    % EGR 101-02
    % Due Date: 02/21/2025

    % Creates an empty array the same length as the input array.
    l = length(x);
    a = zeros(1, l);

    % Loops through each value in the input array and calculates the output value.
    for i = 1:l
        if x(i) < 0 % x < 0
            a(i) = atand(x(i)) / 13; % tan^-1(x) / 13 (in degrees)
        elseif x(i) <= 1 % 0 <= x <= 1
            a(i) = 15 * (x(i) ^ (1/3)); % 15 * x^(1/3)
        elseif x(i) <= 10 % 1 < x <= 10
            a(i) = 3 / factorial(ceil(x(i))); % 3 / z! (where z is x rounded up to the nearest whole number)
        else % x > 10
            a(i) = 16 * log10(x(i)); % 16 * log10(x)
        end
    end

    % Calculates the average of the output array and the index of the minimum value.
    b = mean(a);
    [~, c] = min(a);