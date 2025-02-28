function solution = riddle()
    % Finds the correct number of marbles according to the riddle below. 
    % The solution is reached when every marble count is a positive integer. Outputs the first soultion. 
    % Also creates three pie charts of the first three solutions.
    % Riddle:
    % The number of red marbles (R) is unknown
    % The number of yellow marbles (Y) is (4R – 4) / 5
    % The number of green marbles (G) is (2R + Y + 9) / 3
    % The number of blue marbles (B) is (3G + 2Y + 7) / 5
    % The number of purple marbles (P) is (R + Y + G + B - 79) / 4
    % solution = riddle()
    % Outputs:
    %   solution = output array of the solution (red, yellow, green, blue, purple marbles)
    % William Carden riddle Function
    % EGR 101-02
    % Due Date: 02/27/2025

    % Creat an empty matrix for the soloutions.
    solution = zeros(3, 5);
    
    % Name each color
    color_names = ["Red Marbles", "Yellow Marbles", "Green Marbles", "Blue Marbles", "Purple Marbles"];
    
    % RGB matrix for each color
    colors = [
        [1, 0, 0];   % Red
        [1, 1, 0];   % Yellow
        [0, 1, 0];   % Green
        [0, 0, 1];   % Blue
        [0.5, 0, 0.5] % Purple
    ];

    R = 0; % Start with 0 red marbles

    for i = 1:3 % Loop through 3 solutions.
        while true
            % Calculate the number of marbles
            R = R + 1;
            Y = (4 * R - 4) / 5;
            G = (2 * R + Y + 9) / 3;
            B = (3 * G + 2 * Y + 7) / 5;
            P = (R + Y + G + B - 79) / 4;

            % Check if each marble count is a positive integer
            R_whole = mod(R, 1) == 0 && R > 0;
            Y_whole = mod(Y, 1) == 0 && Y > 0;
            G_whole = mod(G, 1) == 0 && G > 0;
            B_whole = mod(B, 1) == 0 && B > 0;
            P_whole = mod(P, 1) == 0 && P > 0;

            % If all marble counts are positive integers, break the loop
            if (R_whole && Y_whole && G_whole && B_whole && P_whole)
                break;
            end
        end
        
        % Store the marble counts in the solution matrix
        solution(i, :) = [R, Y, G, B, P];

        % Plot the pie chart.
        figure;
        p = piechart(solution(i, :), color_names);
        p.LabelStyle = "namedata";
        p.ColorOrder = colors;
  
    end

    % Set the output as the first solution
    solution = solution(1, :);