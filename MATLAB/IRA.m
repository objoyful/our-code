function [m, a] = IRA(monthly_savings, interest_rate) %#ok<FNDEF>
    % Calculates the number of months it takes for an IRA to reach $1,000,000, with a maximum of 600 months, and the total savings after that time.
    % [months, total_savings] = ira(monthly_savings, interest_rate)
    % Inputs:
    %   monthly_savings = the amount of savings deposited each month (in dollars) (default value of $250)
    %   interest_rate = the interest rate (in %) (default value of 5%)
    % Outputs:
    %   m = the number of months it takes for the IRA reach $1,000,000 (in months) (max 600 months)
    %   a = the total savings after such time (in dollars)
    % William Carden IRA Function
    % EGR 101-02
    % Due Date: 02/18/2025

    format bank

    % If there's one input, assume it's monthly_savings and set interest_rate to 5%
    if nargin < 2
        interest_rate = 5;
    end

    % If there's no inputs, set monthly_savings to $250 and interest_rate to 5%
    if nargin == 0
        monthly_savings = 250;
    end 

    % set N to the length of monthly_savings and create empty arrays for m and a
    N = length(monthly_savings);
    m = zeros(1, N); a = zeros(1, N);

    for j = 1:N % Loop through each monthly_savings value
        for k = 0:600 % Loop through each month up to 600 months
            % Set the savings amount.
            a(j) = monthly_savings(j) + a(j) * (1 + interest_rate / 1200);

            % If the total savings reaches $1,000,000, break.
            if a(j) >= 1000000
                break
            end
        end
        
        % Set the number of months it took to reach $1,000,000
        m(j) = k;
    end