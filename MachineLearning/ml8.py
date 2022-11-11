# Import Libraries
from statistics import mean
import numpy as np
import matplotlib.pyplot as plt

# Setup Data
xs = np.array([1, 2, 3, 4, 5, 6], dtype=np.float64)
ys = np.array([5, 4, 6, 5, 6, 7], dtype=np.float64)

# Plot Data
plt.scatter(xs, ys)
plt.show()

# Find the best fit slope
def best_fit_slope(xs, ys):
    numerator = mean(xs) * mean(ys) - mean(xs * ys)
    denominator = mean(xs) ** 2 - mean(xs ** 2)
    m = numerator / denominator
    
    return m

# Print Slope
m = best_fit_slope(xs, ys)
print(m)