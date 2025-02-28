function [mp, tp] = mortgage_a(P, r, y)
% Calculates the monthly payment and total payment for a mortgage given the
% principle, interest rate, and years of the loan.
% [mp, tp] = mortgage_a(P, r, y)
% Inputs:
%   P = the principle amount of the loan (in dollars)
%   r = the interest rate (in %)
%   y = the number of years of the loan
% Outputs:
%   mp = monthly payment (in dollars)
%   tp = total payment (in dollars)
% William Carden Mortgage A Function
% EGR 101-02
% Due Date: 02/13/2025

format bank

if nargin < 3
    y = 30;
end

r = r / 100;

mp = (P * (r / 12)) / (1 - (1 + (r / 12)) ^ (-12 * y));
tp = mp * 12 * y;