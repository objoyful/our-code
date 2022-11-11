# Imports
import random
from statistics import mean
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import style

# Setting up plot
style.use('fivethirtyeight')

# Example Data
xs = np.array([random.random, random.random, random.random], dtype=np.float64)
ys = np.array([random.random, random.random, random.random], dtype=np.float64)

# Plotting Data w/o Line
# plt.scatter(xs, ys)
# plt.show()

# Find the best fit line
def best_fit_slope_and_intercept(xs, ys):
    m = (((mean(xs) * mean(ys)) - mean(xs * ys)) / 
    ((mean(xs) ** 2) - mean(xs ** 2)))

    b = mean(ys) - m * mean(xs)
    
    return m, b

# Find squared error
def squared_error(ys_orig, ys_line):
    return sum((ys_line - ys_orig) ** 2)

# R Squared
def coeficent_of_determination(ys_orig, ys_line):
    y_mean_line = [mean(ys_orig) for y in ys_orig]
    
    squared_error_regr = squared_error(ys_orig, ys_line)
    squared_error_mean = squared_error(ys_orig, y_mean_line)

    return 1 - (squared_error_regr / squared_error_mean)


m, b = best_fit_slope_and_intercept(xs, ys)

regression_line = [(m * x) + b for x in xs]

predit_x = 8
predit_y = (m * predit_x) + b

r_squared = coeficent_of_determination(ys, regression_line)
print(r_squared)

plt.scatter(xs, ys)
plt.scatter(predit_x, predit_y, color = 'g')
plt.plot(xs, regression_line)

plt.show()