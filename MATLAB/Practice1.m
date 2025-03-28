function c = Practice1(a,b)
    % Computes the sum of two values plus one and the product of the two values.
    % If the sum is positive, the output is the sum plus the product.
    % If either input is zero, the output is 1.
    % If the sum is negative, the output is the negative sum plus the negative product.
    % Works with scalars or arrays of the same length.
    % c = Practice1(a,b)
    % Inputs:
    %   a: first input value (scalar or array)
    %   b: second input value (scalar or array)
    % Outputs:
    %   c: output value (scalar or array)
    % William Carden Practice1 Function
    % EGR 101-02
    % Due Date: 02/20/2025

    % Calculate sum and product
    sum1 = a + b + 1;
    prod = a .* b;
    l = length(a); % Find the length of either array.
    c = zeros(1, l); % Create an empty array for the output.

    for i = 1:l % Loop through each array value.
        if sum1(i) > 0 % If the sum is positive, the output is the sum plus the product.
            c(i) = sum1(i) + prod(i);
        elseif sum1(i) == 0 || prod(i) == 0 % If either input is zero, the output is 1.
            c(i) = 1;
        else % If the sum is negative, the output is the negative sum plus the negative product.
            c(i) = -sum1(i) - prod(i);
        end

    end