function []=disp_prime(n)
    % This function is the starting point for the disp_prime bonus
    % assignment. Your task is to modify this code so it will run
    % faster. Your bonus will be determined by how much faster your
    % code runs in comparison to this code.
    % The input value n is the number of prime numbers to display.
    % There is no function output but the code displays prime
    % numbers in the command window.
    tic; c=0; v=2; % Initialize values
    if n<1 disp('No primes'); % Check for valid input
    else
    if n>=1 fprintf('2, '); c=1; end
    if n>=2 fprintf('3, '); c=2; end
    if n>=3 v=5;
    while c<n
    if isprime(v) fprintf('%6d, ',v);
    c=c+1;
    if 0==mod(c,5) fprintf('\n'); end
    end
    v=v+2; % Skip all the even values
    end
    end
    if 0~=mod(c,5) fprintf('\n'); end
    fprintf('Run time is %.3f\n',toc) % Display program run time
    end
    