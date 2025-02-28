% Indexing Example
% Enter girl scouts names

clear       % Erase all variables USE CAREFULLY
clc         % Clear the Command Window
close all   % Close any plots

gs1='Ann';
gs2='Sue';
gs3='Zoe';
gs4='May';

as1=254.25;	%average sales in dollars
as2=148.95;	%average sales in dollars
as3=78.59;	%average sales in dollars
as4=197.23;	%average sales in dollars

girl_scouts = [gs1; gs2; gs3; gs4]
aver_sales = [as1; as2; as3; as4]
[sales_max, scout_max] = max(aver_sales)
[sales_min, scout_min] = min(aver_sales)

max_gs = girl_scouts(scout_max)
min_gs = girl_scouts(scout_min)
disp(max_gs)