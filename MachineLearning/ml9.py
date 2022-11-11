# Import Libraries
from statistics import mean
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import style

# Setting up plot
style.use('fivethirtyeight')

# Setting up data
xs = np.array([1, 2, 3, 4, 5, 6], dtype=np.float64)
ys = np.array([5, 4, 6, 5, 6, 11], dtype=np.float64)

# Plot data
# plt.scatter(xs, ys)
# plt.show()

# Find best fit slope and intercept
def best_fit_slope_and_intercept(xs, ys):
    numerator = mean(xs) * mean(ys) - mean(xs * ys)
    denominator = mean(xs) ** 2 - mean(xs ** 2)
    m = numerator / denominator

    b = mean(ys) - m * mean(xs)
    
    return m, b

m, b = best_fit_slope_and_intercept(xs, ys)

regression_line = [(m * x) + b for x in xs]

predit_x = 8
predit_y = (m * predit_x) + b

plt.scatter(xs, ys)
plt.scatter(predit_x, predit_y, color = 'g')
plt.plot(xs, regression_line)

plt.show()