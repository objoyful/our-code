import numpy as np
from sklearn import preprocessing, neighbors, svm
import sklearn.model_selection as cross_validation
import pandas as pd


df = pd.read_csv('MachineLearning/breast-cancer-wisconsin.data')
df.replace('?', -99999, inplace=True)
df.drop(['id'], 1, inplace=True)

X = np.array(df.drop(['class'], 1))
y = np.array(df['class'])

X_train, X_test, y_train, y_test = cross_validation.train_test_split(X, y, test_size = 0.2)

clf = svm.SVC(kernel = 'linear')
clf.fit(X_train, y_train)

accuracy = clf.score(X_test, y_test)