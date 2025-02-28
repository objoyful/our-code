function T = feels_like(T_ambient, wind_or_humidity)
% Calculates the wind chill if the temperature is below 50 degress or the
% heat index if the temperature is above 80 degrees and the humidity is
% above 40%
% T = feels_like(T_ambient, wind_or_humidity)
% Inputs:
%   T_ambient = the ambient temperature in degrees Fahrenheit
%   wind_or_humidity = the wind speed in MPH if T_ambient <= 50 or the relative humidity if T_ambient >= 80
% Outputs:
%   T = the apparent temperature
% William Carden Feels Like Function
% EGR 101-02
% Due Date: 02/13/2025

format bank

if T_ambient <= 50 % Calculate the wind chill if the temperature is below 50 degrees.
    T = 35.74 + 0.6215 * T_ambient - 35.74 * (wind_or_humidity ^ 0.16) + 0.4275 * T_ambient * (wind_or_humidity ^ 0.16);

elseif T_ambient >= 80 && wind_or_humidity >= 40 % Calculate the heat index if the temperature is above 80 degrees and the humidity is above 40%.
    c1 = -42.379; c2 = 2.04901523; c3 = 10.14333127; c4 = -0.22475541; c5 = -0.00683783; c6 = -0.05481717; c7 = 0.00122874; c8 = 0.00085282; c9 = -0.00000199;

    T = c1 + c2 * T_ambient + c3 * wind_or_humidity + c4 * T_ambient * wind_or_humidity + c5 * (T_ambient ^ 2) + c6 * (wind_or_humidity ^ 2) + c7 * (T_ambient ^ 2) * wind_or_humidity + c8 * T_ambient * (wind_or_humidity ^ 2) + c9 * (T_ambient ^ 2) * (wind_or_humidity ^ 2);

else % If the temperature is between 50 and 80 degrees or the humidity is less than 40%, the apparent temperature is the same as the ambient temperature.
    T = T_ambient;

end

% Round to the tenth place.
T = round(T, 1);