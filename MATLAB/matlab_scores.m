%% MATLAB Scores Assignment
% William Carden
% EGR 101-02
% Due Date: 02/06/2025

% Data for Exam 1 and Exam 2.
Ex1 = [98 75 0 55 83 75 92 80 76 72 69 89 87 71 90 80 75 72 69 90 88];
Ex2 = [88 95 59 0 84 82 74 100 95 68 91 84 95 78 68 85 87 76 89 95 94];

% Calculate the amount of students who recieved a F, D, C, B, and A for each exam.
f_exam1 = sum(Ex1 < 60); f_exam2 = sum(Ex2 < 60);
d_exam1 = sum(Ex1 < 70 & Ex1 >= 60); d_exam2 = sum(Ex2 < 70 & Ex2 >= 60);
c_exam1 = sum(Ex1 < 80 & Ex1 >= 70); c_exam2 = sum(Ex2 < 80 & Ex2 >= 70);
b_exam1 = sum(Ex1 < 90 & Ex1 >= 80); b_exam2 = sum(Ex2 < 90 & Ex2 >= 80);
a_exam1 = sum(Ex1 >= 90); a_exam2 = sum(Ex2 >= 90);

% Calculate the mean and STD of exam 1 
mean_exam1 = mean(Ex1); mean_exam2 = mean(Ex2);
std_exam1 = std(Ex1); std_exam2 = std(Ex2);

% Calculate the average score of each student and how many got above a 70%.
avg_scores = (Ex1 + Ex2) / 2;
passing_students = sum(avg_scores >= 70);

% Print amount of students who recieved each grade on exam 1.
fprintf("Student Scores On Exam 1\n");
fprintf("%d scored between 90-100%%\n", a_exam1);
fprintf("%d scored between 80-89%%\n", b_exam1);
fprintf("%d scored between 70-79%%\n", c_exam1);
fprintf("%d scored between 60-69%%\n", d_exam1);
fprintf("%d scored between 0-59%%\n\n", f_exam1);

% Print amount of students who recieved each grade on exam 2.
fprintf("Student Scores On Exam 2\n");
fprintf("%d scored between 90-100%%\n", a_exam2);
fprintf("%d scored between 80-89%%\n", b_exam2);
fprintf("%d scored between 70-79%%\n", c_exam2);
fprintf("%d scored between 60-69%%\n", d_exam2);
fprintf("%d scored between 0-59%%\n\n", f_exam2);

% Display the average and standard deviation on each exam.
fprintf("Exam 1 Average: %f\n", mean_exam1);
fprintf("Exam 1 Standard Deviation: %f\n\n", std_exam1);

fprintf("Exam 2 Average: %f\n", mean_exam2);
fprintf("Exam 2 Standard Deviation: %f\n\n", std_exam2);

% Display table of students
student_numbers = 1:21;

fprintf("Student Number:")
fprintf("%5d", student_numbers);

fprintf("\n%15s", "Exam 1 Score:");
fprintf("%5d", Ex1);

fprintf("\n%15s", "Exam 2 Score:");
fprintf("%5d", Ex2);

fprintf("\n%15s", "Average Scores:");
fprintf("%5.1f", avg_scores);

fprintf("\n");