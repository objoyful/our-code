function [] = disp_prime(n)
% Calculates the the first n prime numbers. About 96-97% faster than original code. 
% Takes about 2.5 seconds to calculate the first million prime numbers (compared to 78 seconds from original code).
% [] = disp_prime(n)
% Inputs:
%   n = the number of prime numbers to calculate
% William Carden Prime Numbers Function
% EGR 101-02
% Due Date: 02/20/2025
    
    tic; l = ceil(n*100); b=ones(1, l); p=zeros(1, n); % Initialize values
    
    if n<1; disp('No primes'); % Check for valid input
    else
        b(1) = 0;
        p_i = 0;
        for i = 1:l
            if b(i) == 1
                p_i = p_i + 1;
                p(p_i) = i;
        
                for j = (2 * i):i:l
                    b(j) = 0;
                end
            end

            if p_i == n
                p = p(1:n);
                break
            end
                
        end
        
        if n > 1
            fprintf('%6.0f, %6.0f, %6.0f, %6.0f, %6.0f, \n ', p(1:(n-1)));
        end
        
        fprintf('%6.0f\n', p(n));

    fprintf('Run time is %.3f\n',toc) % Display program run time
    end
