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
                # Move centroid to the middle of the cluster by finding the average of every point in that cluster
                self.centroids[classification] = np.average(self.classifications[classification], axis=0)
            
            optimized = True

            for c in self.centroids:
                # Location of the previous centroid
                original_cetroid = prev_centroids[c]

                # Location of the current centroid
                current_centroid = self.centroids[c]

                # If the difference between the previous centroid and current centroid is not within tol, set optimized to False
                if np.sum((current_centroid - original_cetroid) / original_cetroid * 100.0) > self.tol:
                    optimized = False
            
            # If we are done optimizing, break out of for loop
            if optimized:
                break

    def predict(self, data):
        # Find the distances from that point to centroids
        distances = [np.linalg.norm(data - self.centroids[centroid]) for centroid in self.centroids]
        
        # Classify that point (0 or 1 in our case)
        classification = distances.index(min(distances))

        return classification

# Fit model
clf = K_Means()
clf.fit(X)

# Plot centroid
for centroid in clf.centroids:
    # Make a point on graph for each centroid
    plt.scatter(clf.centroids[centroid][0], clf.centroids[centroid][1], marker='o', color='k', s=150, linewidths=5)

# Plot every point
# Loop through every class
for classification in clf.classifications:
    # Set color for that class
    color = colors[classification]
    
    # Loop through evey point in that class
    for featureset in clf.classifications[classification]:
        # Plot that point
        plt.scatter(featureset[0], featureset[1], marker='x', color=color, s=150, linewidths=5)

# Test predictions with unkown sample data
unkowns = np.array([[1, 3],
                   [8, 9],
                   [0, 3],
                   [5, 4],
                   [6, 4]])

# Loop thorugh every unkown point
for unknown in unkowns:
    # Classify each point
    classification = clf.predict(unknown)
    
    # Plot points
    plt.scatter(unknown[0], unknown[1], marker='*', color=colors[classification], s=150, linewidths=5)

plt.show()