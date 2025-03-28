function numeral = num_roman(n)
    % Converts a scalar value from 1 - 3999 into a Roman numeral. 
    % If no value is given, the value 2025 is used.
    % numerals = num_roman(n)
    % Inputs:
    %   n: scalar value to be converted to a Roman numeral (default value of 2025)
    % Outputs:
    %   numeral: the Roman numeral of the given number
    % William Carden num_roman Function
    % EGR 101-02
    % Due Date: 02/27/2025

    % If no value is given, use 2025.
    if nargin == 0
        n = 2025;
    end

    % Error checking
    if n < 1 || n > 3999 % If value is outside 1-3999 range.
        error('Input number must be 1 - 3999');
    end

    if length(n) > 1 % If array was given
        error('Input must be a scalar value');
    end

    numeral = ''; % Create empty string for numeral
    
    while n >= 1000 % Add M's
        n = n - 1000;
        numeral = strcat(numeral, 'M');
    end

    if n >= 900 % Add CM
        n = n - 900;
        numeral = strcat(numeral, 'CM');
    end

    while n >= 500 % Add D's
        n = n - 500;
        numeral = strcat(numeral, 'D');
    end

    if n >= 400 % Add CD
        n = n - 400;
        numeral = strcat(numeral, 'CD');
    end
    
    while n >= 100 % Add C's
        n = n - 100;
        numeral = strcat(numeral, 'C');
    end

    if n >= 90 % Add XC
        n = n - 90;
        numeral = strcat(numeral, 'XC');
    end

    if n >= 50 % Add L
        n = n - 50;
        numeral = strcat(numeral, 'L');
    end

    if n >= 40 % Add XL
        n = n - 40;
        numeral = strcat(numeral, 'XL');
    end

    while n >= 10 % Add X's
        n = n - 10;
        numeral = strcat(numeral, 'X');
    end

    if n >= 9 % Add IX
        n = n - 9;
        numeral = strcat(numeral, 'IX');
    end

    if n >= 5 % Add V
        n = n - 5;
        numeral = strcat(numeral, 'V');
    end

    if n >= 4 % Add IV
        n = n - 4;
        numeral = strcat(numeral, 'IV');
    end

    while n >= 1 % Add I's
        n = n - 1;
        numeral = strcat(numeral, 'I');
    end