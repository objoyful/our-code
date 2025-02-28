function Graphs()
    % Graphs three different functions:
    % y1 = sin(5pi * x) / (1 + x^4)
    % y2 = 1 / (1 + x^4)
    % y3 = -1 / (1 + x^4)
    % Graphs()
    % William Carden Graphs Function
    % EGR 101-02
    % Due Date: 02/21/2025

    % Defines how many data points created and creates an array from -2 to 2 with that many points.
    l = 10000;
    x = linspace(-2, 2, l);

    % Calculates the y values for each function.
    y1 = sin(5 * pi * x) ./ (1 + x.^4);
    y2 = 1 ./ (1 + x.^4);
    y3 = -1 ./ (1 + x.^4);

    % Plots each function.
    hold on;
    plot(x, y1, 'k-');
    plot(x, y2, 'b-.');
    plot(x, y3, 'r--');
    hold off;

    % Title, labels, and legend.
    title('Three Graphs');
    
    xlabel('X');
    ylabel('Y');

    legend('y_{1} = sin(5\pi\cdotx) / (1+x^{4})', 'y_{2} = 1 / (1+x^{4})', 'y_{3} = -1 / (1+x^{4})', 'Location', 'SouthOutside');