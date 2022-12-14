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
              [9, 11]])

# Plot Sample Data
plt.scatter(X[:,0], X[:,1], s = 150)
plt.show()

# List of different colors
colors = 10 * ["g", "r", "c", "b", "k"]

# KMeans algorithm
class K_Means:
    # Initialization
    def __init__(self, k=2, tol=0.001, max_iter=300):
        self.k = k # Amount of clusters
        self.tol = tol # Tolerance
        self.max_iter = max_iter # Max iterations

    def fit(self, data):
        # Centroids
        self.centroids = {}

        # Set the centroids to the first k points
        for i in range(self.k):
            self.centroids[i] = data[i]
        
        for i in range(self.max_iter):
            # Dictionary that holds the classes as keys, and the features as values
            self.classifications = {}

            for i in range(self.k):
                self.classifications[i] = [] # {0: [], 1: []}
            
            # Loop through each point in dataset
            for featureset in data:
                # Find the distances from that point to centroids
                distances = [np.linalg.norm(featureset - self.centroids[centroid]) for centroid in self.centroids]
                
                # Classify that point (0 or 1 in our case)
                classification = distances.index(min(distances))
                
                # Append that to classifiation dictionary
                self.classifications[classification].append(featureset)
        
            prev_centroids = dict(self.centroids)

            for classification in self.classifications:
                pass
                
                # Move centroid to the middle of the cluster by finding the average of every point in that cluster
                # self.centroids[classification] = np.average(self.classifications[classification], axis=0)

    def predict(self, data):
        pass