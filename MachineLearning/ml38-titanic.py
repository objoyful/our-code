# Matplotlib Setup
import matplotlib.pyplot as plt
from matplotlib import style
style.use('ggplot')

# Imports
import numpy as np
import pandas as pd
from sklearn import preprocessing

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

# Read Data
df = pd.read_excel('MachineLearning\\ml35-data\\titanic.xls')

# Drop unnecessary columns, convert to numeric values, and fill missing values
df.drop(['body', 'name'], axis=1, inplace=True)
df = df.apply(pd.to_numeric, errors='ignore', axis=1) # df.convert_objects(convert_numeric = True)
df.fillna(0, inplace = True)

# Convert objects to ints
def handle_non_numerical_data(df):
    # List of columns
    columns = df.columns.values

    for column in columns:
        text_digit_vals = {} # {"Female": 0, "Male": 1}
        
        # From Female get 0, from Male get 1, will apply this to data
        def convert_to_int(val):
            return text_digit_vals[val]
        
        # Only run on columns that aren't int or float
        if df[column].dtype != np.int64 and df[column].dtype !=  np.float64:
            column_contents = df[column].values.tolist()
            
            # Get unique elements from column
            unique_elements = set(column_contents)
            
            # Start x counter
            x = 0
            for unique in unique_elements:
                # If we haven't added that value to text_digit_vals, then add it
                if unique not in text_digit_vals:
                    # Assign that key to x, and then increase x
                    text_digit_vals[unique] = x
                    x += 1
            
            # Apply our dictionary to our data
            df[column] = list(map(convert_to_int, df[column]))
    return df

df = handle_non_numerical_data(df)
# print(df.head())

# Define features and labels
X = np.array(df.drop(['survived'], axis=1).astype(float))
X = preprocessing.scale(X)
y = np.array(df['survived'])

# Fit model
clf = K_Means()
clf.fit(X)

# Find accuracy
correct = 0
for i in range(len(X)):
    predict_me = np.array(X[i].astype(float))
    predict_me = predict_me.reshape(-1, len(predict_me))
    prediction = clf.predict(predict_me)

    if prediction == y[i]:
        correct += 1

print(correct / len(X))