function plot_quad(A)
    % Plots a quadratic function given the input array A = [A1 A2 A3 A4 A5].
    % Where A1, A2, A3 are required input scalars and A4, A5 are optional input scalars.
    % The quadractic function is of the form y = A1 + A2 * x + A3 * x^2.
    % The x range for the plot is A4 to A5.
    % The defualt value for A4 is -10 and the defualt for A5 is A4 + 20.
    % plot_quad(A)
    % Inputs:
    %   A = input array of scalars (at least 3 scalars required)
    % William Carden plot_quad Function - Midterm Question 22
    % EGR 101-02
    % Due Date: 03/04/2025

    n = length(A);

    if n < 3 % Check if there are at least 3 inputs.
        error('At least 3 input scalars are required.');
    end

    if n == 3 % If neither A4 nor A5 are provided.
        A(4) = -10; % Default value for A4.
    end

    if n < 5 % If A5 is not provided.
        A(5) = A(4) + 20; % Default value for A5.
    end

    x = linspace(A(4), A(5), 1000); % X values
    y = A(1) + A(2) * x + A(3) * x.^2; % Y values

    % Create plot title.
    plot_title = {'Plot of y = '};

    for i = 1:3 % Loop through each A value.
        plot_title = strcat(plot_title, num2str(A(i))); % Add each number to plot title, even if it's zero.

        if i == 2 % If it's the second term add x.
            plot_title = strcat(plot_title, '\cdotx');
        elseif i > 2 % If it's the third term add x^2.
            plot_title = strcat(plot_title, '\cdotx^', num2str(i - 1));
        end

        if i < 3 % If it's not the last term add a plus sign.
            plot_title = strcat(plot_title, {' + '});
        end
    end

    % Plot the function.
    plot(x, y, 'r-');
    xlabel('X');
    ylabel('Y');
    title(plot_title);