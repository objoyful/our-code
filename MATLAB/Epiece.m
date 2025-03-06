function [a, b, c] = Epiece(x, y)
    % Outputs three values based on the two input arrays which must be of the same length.
    % The first input array is an array of scalars and the second is an array of characters.
    % The first output depends on the character of the second array:
        % A: atan(x) (in degress)
        % B: (1 + x^4)^(1/4)
        % other: 0
    % The second output is the average of the first output.
    % The third output is the index of the minimum value of the first output.
    % [a, b, c] = Epiece(x, y)
    % Inputs:
    %   x = input array of scalars
    %   y = input array of characters
    % Outputs:
    %   a = first output (array)
    %   b = second output (scalar)
    %   c = third output (integer)
    % William Carden Epiece Function - Midterm Question 21
    % EGR 101-02
    % Due Date: 03/04/2025

    if nargin < 2 % Check if there's two inputs.
        error('There must be two input arrays.');
    end

    if length(x) ~= length(y) % Check if the two inputs are the same length.
        error('The two input arrays must be of the same length.');
    end

    % Create empty array for a.
    n = length(x);
    a = zeros(1, n);

    for i = 1:n % Loop through each array element.
        if y(i) == 'A' % Check if the character is A.
            a(i) = atand(x(i));
        elseif y(i) == 'B' % Check if the character is B.
            a(i) = (1 + x(i)^4)^(1/4);
        else % Any other character.
            a(i) = 0;
        end
    end

    % Calculate b and c.
    b = mean(a);
    [~, c] = min(x);