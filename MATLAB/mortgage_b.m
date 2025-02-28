function mortgage_b(P, r)
% Compares the monthly payment of two mortgages, one 15 years and one 30 
% years.
% mortgage_b(P, r)
% Inputs:
%   P = the principle amount of the loan (in dollars)
%   r = the interest rate (in %)
% William Carden Mortgage B Function
% EGR 101-02
% Due Date: 02/13/2025

if nargin < 2
    r = 6.5;
end
if nargin < 1
    P = 200000;
end

r = r / 100;

P = P : -5000: P - 50000;

mp_15 = (P * (r / 12)) / (1 - (1 + (r / 12)) ^ (-12 * 15));
mp_30 = (P * (r / 12)) / (1 - (1 + (r / 12)) ^ (-12 * 30));

fprintf("Principal\t15 Year Payback\t30 Year Payback\n");
fprintf('$%9.f\t$%9.2f\t$%9.2f\n', [P; mp_15; mp_30]);