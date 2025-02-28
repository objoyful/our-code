%% MATLAB Line Equation Assignment
% William Carden
% EGR 101-02
% Due Date: 02/04/2025

time = linspace(0, 2, 16);
L = input("Enter the inductance to plot for an RL circuit? ");

R1 = 1; R2 = 1.5; R3 = 2; R4 = 3;

I1 = 24 * exp((-R1 / L) * time);
I2 = 24 * exp((-R2 / L) * time);
I3 = 24 * exp((-R3 / L) * time);
I4 = 24 * exp((-R4 / L) * time);

if max([I1(8) I2(8) I3(8) I4(8)]) < 1
    disp("Inductance too small to plot anything.");
else
    hold on
    
    if I1(8) > 1
        plot(time, I1, 'b--s');
        legend("1.0 \Omega");
    end

    if I2(8) > 1
        plot(time, I2, 'r--o');
        legend("1.0 \Omega", "1.5 \Omega");
    end
    
    if I3(8) > 1
        plot(time, I3, 'c--*');
        legend("1.0 \Omega", "1.5 \Omega", "2.0 \Omega");
    end
    
    if I4(8) > 1
        plot(time, I4, 'm--^');
        legend("1.0 \Omega", "1.5 \Omega", "2.0 \Omega", "3.0 \Omega");
    end

    title("Current Plot");
    xlabel("Time (s)");
    ylabel("Current (Amps)");
    
    hold off
end