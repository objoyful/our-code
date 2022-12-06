from math import sqrt
from ml15 import find_distance
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import style
from collections import Counter
import warnings

style.use('fivethirtyeight')

# Sample dataset
dataset = {
    'g': [[1, 2], [2, 3], [3, 1]],
    'r': [[6, 5], [7, 7], [8, 6]]
}

# Prediction point
new_features = [8, 0]


# [[plt.scatter(ii[0], ii[1], s=100, color=i) for ii in dataset[i]] for i in dataset]
# plt.scatter(new_features[0], new_features[1], s=100)
# plt.show()


def k_nearest_neighbors(data, predict, k=3):
    if len(data) >= k:
        warnings.warn('K is set to a value less than total voting groups!')
    
    distances = []

    for group in data:
        for feature in data[group]:
            euclidean_distance = find_distance(feature, predict)
            distances.append([euclidean_distance, group])

    votes = [i[1] for i in sorted(distances)[:k]]

    print(Counter(votes).most_common(2))
    print(Counter(votes).most_common(1)[0])
    vote_result = Counter(votes).most_common(1)[0][0]
    
    return vote_result

result = k_nearest_neighbors(dataset, new_features, k=3)
print(result)

[[plt.scatter(ii[0], ii[1], s=100, color=i) for ii in dataset[i]] for i in dataset]
plt.scatter(new_features[0], new_features[1], s=100, color=result)
plt.show()