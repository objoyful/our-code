# Matplotlib Imports
import matplotlib.pyplot as plt
from matplotlib import style
style.use('ggplot')

# Imports
import numpy as np
from sklearn.cluster import KMeans

# Sample Data
X = np.array([[1, 2],
              [1.5, 1.8],
              [5, 8],
              [8, 8],
              [1, 0.6],
              [9, 11]])

# Plot Data
# plt.scatter(X[:,0], X[:,1], s=150)
# plt.show()

# KMeans Algorithim
clf = KMeans(n_clusters=3)
clf.fit(X)

# Define centroids and labels
centroids = clf.cluster_centers_ # [[x1, y1], [x2, y2]]
labels = clf.labels_ # [0, 0, 1, 1, 0, 1]

# Define colors
colors = 10 * ["g.", "r.", "c.", "b.", "k."]

# Plot
for i in range(len(X)):
    plt.plot(X[i][0], X[i][1], colors[labels[i]], markersize=20)

#                    [x1, x2]         [y1, y2]
plt.scatter(centroids[:, 0], centroids[:, 1], marker='x', s=150, linewidths=5)
plt.show()