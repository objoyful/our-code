function plot_poly(c, xmin, xmax)
    % Plots a polynomial fuction with the given coefficients and given xmin and xmax values.
    % The polynomial has the form y = c(1) + c(2)x + c(3)x^2 + c(4)x^3 + c(5)x^4 + c(6)x^5
    % If less than 6 coefficients are given the remaining coefficients are set to 0.
    % If more than 6 coefficients are given, the rest are ignored.
    % plot_poly(c, xmin, xmax)
    % Inputs:
    %   c: coefficients of the polynomial (array)
    %   xmin: minimum x value (defualt value of -10)
    %   xmax: maximum x value (default value of 10, or xmin + 20 if xmax is given)
    % William Carden plot_poly Function
    % EGR 101-02
    % Due Date: 02/27/2025

    if nargin == 2 % If only two inputs are given
        xmax = xmin + 20;
    elseif nargin == 1 % If only one input is given
        xmin = -10;
        xmax = 10;
    end

    n = length(c); % Get the number of coefficients
    if n > 6 % There can only be a max of 6 coefficients
        n = 6;
    end

    coeff = zeros(1, 6); % Create an array of coefficients
    coeff(1:n) = c(1:n); % Populate the array with coefficients, if there are less than 6, the rest are 0


    x = linspace(xmin, xmax, 1000); % Create x values
    y = coeff(1) + coeff(2) * x + coeff(3) * x.^2 + coeff(4) * x.^3 + coeff(5) * x.^4 + coeff(6) * x.^5; % Create y values

    graph_title = {'y = '}; % Create graph title
    
    first_coeff = 1;
    
    for i = 1:n % Create graph title
        if coeff(i) % If the coefficient is not 0
            if ~first_coeff % If it is not the first coefficient, add a plus sign
                graph_title = strcat(graph_title, {' + '});
            end

            if i == 1 % If its the constant coefficient don't add an x
                graph_title = strcat(graph_title, num2str(coeff(i)));
            elseif i == 2 % If it's the first coefficient, add an x
                graph_title = strcat(graph_title, num2str(coeff(i)), 'x');
            else % If it's any other coefficient, add an x to the power of
                graph_title = strcat(graph_title, num2str(coeff(i)), 'x^', num2str(i - 1));
            end

            first_coeff = 0;
        end
    end

    if coeff == zeros(1, 6) % If all the coefficients are 0, set graph title to y = 0
        graph_title = strcat(graph_title, '0');
    end

    plot(x, y, 'r'); % Plot the polynomial
    
    xlabel('x'); % Label x axis
    ylabel('y'); % Label y axis

    title(strcat({'Plot of '}, graph_title)); % Set graph title