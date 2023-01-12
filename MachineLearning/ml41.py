# Matplotlib Setup
import matplotlib.pyplot as plt
from matplotlib import style

style.use('ggplot')

# Imports
import numpy as np

# Sample Data
X = np.array([[1, 2],
              [1.5, 1.8],
              [5, 8],
              [8, 8],
              [1, 0.6],
              [9, 11],
              [8, 2],
              [10, 2],
              [9, 3],])

# Plot Sample Data
# plt.scatter(X[:, 0], X[:, 1], s=150)
# plt.show()

# Colors List
colors = 10 * ["g", "r", "c", "b", "k"]

# Mean Shift algorithm
class MeanShift:
    # Initialization
    def __init__(self, radius=1):
        self.radius = radius

    def fit(self, data):
        # Our centroids, at first every point is a centroid
        centroids = {} #{0: [x0, y0], 1:[x1, y1]}

        # Set every point as a centroid
        for i in range(len(data)):
            centroids[i] = data[i]
        
        while True:
            
            plt.scatter(X[:, 0], X[:, 1], s=150)
            for c in centroids:
                plt.scatter(centroids[c][0], centroids[c][1], color='k', s=150, marker='*')

            plt.show()

            
            # Our new centroids will be saved here
            new_centroids = []
            
            for i in centroids:
                # All the points that are within our bandwidth
                in_bandwidth = [] # [[x0, y0], [x1, y1]]
                centroid = centroids[i]

                for featureset in data:
                    # If that point is within our bandwidth
                    if np.linalg.norm(featureset - centroid) < self.radius:
                        # Add point to in_bandwidth list
                        in_bandwidth.append(featureset)
                
                # Move centroid to the middle of the bandwidth
                new_centroid = np.average(in_bandwidth, axis=0)
                new_centroids.append(tuple(new_centroid))
            
            # Get unique centroids
            uniques = sorted(list(set(new_centroids)))
            
            # Save previous centroids and cler centroids variable
            prev_centroids = dict(centroids)
            centroids = {}

            # Add our new centroids to centroids dictionary
            for i in range(len(uniques)):
                centroids[i] = np.array(uniques[i])
            
            optimized = True

            # Check if new centroids are diffeent from old centroids
            for i in centroids:
                # If the new centroids and old centroids are not equal, we aren't optimized
                if not np.array_equal(centroids[i], prev_centroids[i]):
                    optimized = False
                
                # If one centroid isn't optimized, we don't have to check the others
                if not optimized:
                    break
            
            # One we are finnaly optimized, break out of while true loop
            if optimized:
                break
        
        # Save centroids to self
        self.centroids = centroids
    
    def predict(self, data):
        pass

# Fit mean shift
clf = MeanShift()
clf.fit(X)

# Define centroids
centroids = clf.centroids

# Plot points
plt.scatter(X[:, 0], X[:, 1], s=150)

# Plot centroids
for c in centroids:
    plt.scatter(centroids[c][0], centroids[c][1], color='k', s=150, marker='*')

plt.show()