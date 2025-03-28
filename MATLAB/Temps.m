function Temps(vals, unit)
    % Prints a table of the given temperatures in the given unit converted to four different units:
    % Celsius, Fahrenheit, Rankine, and Kelvin
    % Temps(vals, unit)
    % Inputs:
    %   vals: an array of temperatures to be converted
    %   unit: a string representing the unit of the given temperatures where
    %       F is Fahrenheit, C is Celsius, R is Rankine, and K is Kelvin.
    % William Carden Temps Function
    % EGR 101-02
    % Due Date: 02/27/2025

    % Create empty temps matrix
    num_vals = length(vals);
    temps = zeros(length(vals), 4);

    for i = 1:num_vals % Loop through each temperature
        if unit == 'F'
            temps(i, 1) = vals(i); % Fahrenheit
            temps(i, 2) = (vals(i) - 32) * (5 /9); % Celsius
            temps(i, 4) = temps(i, 2) + 273.15; % Kelvin
            temps(i, 3) = temps(i, 4) * (9 / 5); % Rankine
        elseif unit == 'C'
            temps(i, 2) = vals(i); % Celsius
            temps(i, 1) = (vals(i) * (9 / 5)) + 32; % Fahrenheit
            temps(i, 4) = vals(i) + 273.15; % Kelvin
            temps(i, 3) = temps(i, 4) * (9 / 5); % Rankine
        elseif unit == 'R'
            temps(i, 3) = vals(i); % Rankine
            temps(i, 4) = vals(i) * (5 / 9); % Kelvin
            temps(i, 2) = temps(i, 4) - 273.15; % Celsius
            temps(i, 1) = (temps(i, 2) * (9 / 5)) + 32; % Fahrenheit
        else
            temps(i, 4) = vals(i); % Kelvin
            temps(i, 2) = vals(i) - 273.15; % Celsius
            temps(i, 1) = (temps(i, 2) * (9 / 5)) + 32; % Fahrenheit
            temps(i, 3) = vals(i) * (9 / 5); % Rankine
        end
    end

    % Print Table
    fprintf('%35s\n', 'Temperature Conversion Chart');
    fprintf("%8.1f°F%8.1f°C%8.1f°R%8.1f°K\n", transpose(temps));