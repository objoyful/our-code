# Import Libraries
from math import sqrt
import numpy as np
from collections import Counter
import warnings
import pandas as pd
import random
from ml15 import find_distance

confidence = []
# K Nearest Neighbors Algorithm
def k_nearest_neighbors(data, predict, k=3):
    if len(data) >= k:
        warnings.warn('K is set to a value less than total voting groups!')
    
    distances = []

    for group in data:
        for features in data[group]:
            euclidean_distance = find_distance(features, predict)
            # np.linalg.norm(np.array(features) - np.array(predict))
            distances.append([euclidean_distance, group])

    votes = [i[1] for i in sorted(distances)[:k]]
    vote_result = Counter(votes).most_common(1)[0][0]

    confidence = Counter(votes).most_common(1)[0][1] / k
    
    return vote_result, confidence

# Read in file
df = pd.read_csv('MachineLearning\\ml14-data\\breast-cancer-wisconsin.data')
df.replace('?', -99999, inplace=True)
df.drop(['id'], axis=1, inplace=True)

# Convert to list and shuffle
full_data = df.astype(float).values.tolist()
random.shuffle(full_data)

# Create empty dictionaries
test_size = 0.2
train_set = {
    2:[],
    4:[]
    }
test_set = {
    2:[],
    4:[]
    }

# Split train and test data
train_data = full_data[:-int(test_size * len(full_data))]
test_data = full_data[-int(test_size * len(full_data)):]

# Populate dictionaries
for i in train_data:
    train_set[i[-1]].append(i[:-1])

for i in test_data:
    test_set[i[-1]].append(i[:-1])

# Find accuracy
correct = 0
total = 0

confidences = []
for group in test_set: #2, 4
    for data in test_set[group]:
        vote, confidence = k_nearest_neighbors(train_set, data, k=5)
        confidences.append(confidence)
        
        if group == vote:
            correct += 1
        else:
            print(confidence)
        
        total += 1

print('Accuracy =', correct / total)
print('Confidence:', sum(confidences) / len(confidences))