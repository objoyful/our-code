# Import Libraries
import numpy as np
from sklearn import preprocessing, svm
import sklearn.model_selection as cross_validation
import pandas as pd

# Read in Data
df = pd.read_csv('MachineLearning\\ml14-data\\breast-cancer-wisconsin.data', index_col='id')
df.replace('?', -99999, inplace=True)
# df.drop(['id'], 1, inplace=True)

# Defining X and Y
X = np.array(df.drop(['class'], axis=1))
y = np.array(df['class'])

# Splitting training and testing data
X_train, X_test, y_train, y_test = cross_validation.train_test_split(X, y, test_size=0.2)

# Fitting Model
clf = svm.SVC(kernel='linear')
clf.fit(X_train, y_train)

# Finding accuracy
accuracy = clf.score(X_test, y_test)
print(accuracy)

# Making Predictions
# example_measures = np.array([[4, 2, 1, 1, 1, 2, 3, 2, 1], [7, 2, 1, 1, 1, 2, 3, 10, 1]])
# prediction = clf.predict(example_measures)

# print(prediction)