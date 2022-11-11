# Import Libraries
import numpy as np
from sklearn import preprocessing, neighbors
import sklearn.model_selection as cross_validation
import pandas as pd

df = pd.read_csv('MachineLearning\\ml14-data\\breast-cancer-wisconsin.data', index_col='id')
df.replace('?', -99999, inplace=True)
# df.dropna(inplace=True)
# df.drop(['id'], axis=1, inplace=True)

X = np.array(df.drop(['class'], axis=1))
y = np.array(df['class'])

X_train, X_test, y_train, y_test = cross_validation.train_test_split(X, y, test_size=0.2)

clf = neighbors.KNeighborsClassifier(n_jobs=-1)
clf.fit(X_train, y_train)

accuracy = clf.score(X_test, y_test)
print(accuracy)

example_measures = np.array([[4, 2, 1, 1, 1, 2, 3, 2, 1], [7, 2, 1, 1, 1, 2, 3, 10, 1]])
# example_measures = example_measures.reshape(1, -1)
prediction = clf.predict(example_measures)

print(prediction)