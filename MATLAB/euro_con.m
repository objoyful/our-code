function euro_con
% Function to convert between the 
% Euros and US dollars
% No inputs and no outputs.
% Displays a conversion table
% Final Exam 5/1/25
% Question 21
% by Daniel Armentrout
rate=0;
while rate==0      % Keep asking for input until valid rate
  srate=input('Enter the Euro to Dollar conversion rate? ','s');
  rate=str2num(srate);
  if isempty(rate) % Input is not a number
    disp('Please enter the rate as a value.');
    rate=0;
  end  
end
v=20:20:200;       % Value vector
e=v/rate*1.025;    % Euro exchange with 2.5% fee
d=v*rate*1.025;    % dollar exchange with 2.5% fee
% Display Table
fprintf('Dollars to Euros    Euros   to Dollars\n');
A=[v;e;v;d];       % Assemble matrix for table values
Sym=char(8364);    % Get euro character symbol
fp=['$%-7.2f= ',Sym,'%-7.2f  ',Sym,'%-7.2f= $%-7.2f\n'];
fprintf(fp,A);