# Imports
import matplotlib.pyplot as plt
import numpy as np
from matplotlib import style

# Setup Plots
style.use('ggplot')

# Sample Data
data_dict = {-1: np.array([[1, 7],
                           [2, 8],
                           [3, 8]]),
             
             1: np.array([[5, 1],
                          [6, -1],
                          [7, 3]])}

# Support Vector Machine
class Support_Vector_Machine:
    def __init__(self, visualization=True):
        self.visualization = visualization
        self.colors = {1: 'r', -1: 'b'}
        
        if self.visualization:
            self.fig = plt.figure()
            self.ax = self.fig.add_subplot(1, 1, 1)
    
    # train
    def fit(self, data):
        self.data = data

        # {||w||: [w, b]}
        opt_dict = {}

        # Mulitplying w by these
        transforms = [[1, 1],
                      [-1, 1],
                      [-1, -1],
                      [1, -1]]
        
        # break data out into all data list
        all_data = []
        for yi in self.data:
            for featureset in self.data[yi]:
                for feature in featureset:
                    all_data.append(feature)
        
        # Find max and min values, then delete all_data
        self.max_feature_value = max(all_data)
        self.min_feature_value = min(all_data)
        all_data = None
        
        # Define our step sizes
        step_sizes = [self.max_feature_value * 0.1,
                      self.max_feature_value * 0.01,
                      # Point of Expense:
                      self.max_feature_value * 0.001]
        
        # We can take larger steps with b
        b_range_multiple = 5
        b_multiple = 5

        # Our best value for w, start with max value * 10
        latest_optimum = self.max_feature_value * 10

        for step in step_sizes:
            # Set w to our best values
            w = np.array([latest_optimum, latest_optimum])
            
            # Loop until we're optimized
            optimized = False
            while not optimized:
                # Step through b's
                for b in np.arange(-1 * (self.max_feature_value * b_range_multiple), 
                                   self.max_feature_value * b_range_multiple,
                                   step * b_multiple):
                    for transformation in transforms:
                        # Multiply w by our transforms
                        w_t = w * transformation
                        found_option = True

                        # Check our condition for all data
                        # yi(xi.w + b) >= 1
                        for yi in self.data:
                            for xi in self.data[yi]:
                                if not yi * (np.dot(w_t, xi) + b) >= 1:
                                    found_option = False
                        
                        # If our condition is met, save w, b to opt_dict
                        if found_option:
                            opt_dict[np.linalg.norm(w_t)] = [w_t, b]
                
                # No need to go less than 0 because we already checked for negatives
                if w[0] < 0:
                    optimized = True
                    print("Optimized a step")
                else:
                    # Decrease w by step amount
                    w = w - step
            
            # Find the lowest mag of w
            norms = sorted([n for n in opt_dict])
            opt_choice = norms[0]

            self.w = opt_choice[0]
            self.b = opt_choice[1]

            # Set w to the one with the lowest mag, plus a little extra, and start next step
            latest_optimum = opt_choice[0][0] + step * 2
            
    def predict(self, features):
        # sign(x.w + b)
        classification = np.sign(np.dot(np.array(features), self.w) + self.b)

        return classification