# Matplotlib Setup
import matplotlib.pyplot as plt
from matplotlib import style
from numpy.lib.arraysetops import unique
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
    def __init__(self, radius=None, radius_norm_step=100):
        self.radius = radius
        self.radius_norm_step = radius_norm_step

    def fit(self, data):
        if self.radius == None:
            # Find the average position of all of our data
            all_data_centroid = np.average(data, axis=0)
            all_data_norm = np.linalg.norm(all_data_centroid)
            
            # Set the radius as avg position / step
            self.radius = all_data_norm / self.radius_norm_step
        
        # Our centroids, at first every point is a centroid
        centroids = {}

        # Set every point as a centroid
        for i in range(len(data)):
            centroids[i] = data[i]
        
        # 99, 98, 97 etc. This will be weights we apply to each point
        weights = [i for i in range(self.radius_norm_step)][::-1]

        while True:
            # Our new centroids will be saved here
            new_centroids = []
            for i in centroids:
                # All the points that are within our bandwidth
                in_bandwidth = []
                centroid = centroids[i]

                for featureset in data:
                    # Find distance
                    distance = np.linalg.norm(featureset - centroid)
                    
                    if distance == 0:
                        distance = 0.000000000001
                    
                    # How far away the point is will determine the index of the "weights" list, and thus how how are weight. The further away, the higher the index, the lower the weight. If the index is out of range, set it the the highest amount
                    weight_index = int(distance / self.radius)
                    if weight_index > self.radius_norm_step - 1:
                        weight_index = self.radius_norm_step - 1
                    
                    # Getting the weight and squaring it. Repeating feature that many times, then adding it to in_bandwidth
                    to_add = (weights[weight_index] ** 2) * [featureset]
                    in_bandwidth += to_add
                    

                # Move centroid to the middle of the bandwidth
                new_centroid = np.average(in_bandwidth, axis=0)
                new_centroids.append(tuple(new_centroid))
            
            # Get unique centroids
            uniques = sorted(list(set(new_centroids)))
            
            # Centroids we are going to remove
            to_pop = []

            # Loop through every centroid
            for i in uniques:
                # Loop through every other centroid
                for ii in uniques:
                    # If the two centroids are within a radius from each other, add them to to_pop list
                    if i == ii:
                        pass
                    elif np.linalg.norm(np.array(i) - np.array(ii)) <= self.radius:
                        to_pop.append(ii)
                        break
  
            # Remove centroids from uniques
            for i in to_pop:
                try:
                    uniques.remove(i)
                except:
                    pass

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
        
        # Classify each point
        self.classifications = {} #{0: [...], 1: [...]}
        
        # Make each key
        for i in range(len(self.centroids)):
            self.classifications[i] = []
        
        # Add each point to what centroid it's closest to
        for featureset in data:
            # Find the distances to all the centroids
            distances = [np.linalg.norm(featureset - self.centroids[centroid]) for centroid in self.centroids]
            
            # Find the smallest distance
            classification = distances.index(min(distances))
            self.classifications[classification].append(featureset)
    
    def predict(self, data):
        distances = [np.linalg.norm(data - self.centroids[centroid]) for centroid in self.centroids]
        classification = distances.index(min(distances))

        return classification
    

# Fit mean shift
clf = MeanShift()
clf.fit(X)

# Define centroids
centroids = clf.centroids



# Plot centroids
for c in centroids:
    plt.scatter(centroids[c][0], centroids[c][1], color='k', s=150, marker='*')

plt.show()