import quandl, math
import pandas as pd
import numpy as np
from sklearn import preprocessing, svm
from sklearn.linear_model import LinearRegression
import sklearn.model_selection as cross_validation

df = quandl.get('WIKI/GOOGL')
df = df[['Adj. Open', 'Adj. High', 'Adj. Low', 'Adj. Close', 'Adj. Volume', ]]
df['HL_PCT'] = (df['Adj. High'] - df['Adj. Close']) / df['Adj. Close'] * 100.0
df['PCT_change'] = (df['Adj. Close'] - df['Adj. Open']) / df['Adj. Open'] * 100.0

df = df[['Adj. Close', 'HL_PCT', 'PCT_change', 'Adj. Volume']]

forcast_col = 'Adj. Close'
df.fillna(-999999, inplace=True)

forcast_out = int(math.ceil(0.01 * len(df)))
print(forcast_out)

df['label'] = df[forcast_col].shift(-forcast_out)
df.dropna(inplace=True)

X = np.array(df.drop(['label'], 1))
y = np.array(df['label'])

X = preprocessing.scale(X)
y = np.array(df['label'])

X_train, X_test, y_train, y_test = cross_validation.train_test_split(X, y, test_size=0.1)

clf = svm.SVR()
clf.fit(X_train, y_train)
accuracy = clf.score(X_test, y_test)

print(accuracy)