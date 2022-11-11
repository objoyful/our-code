# Imports
import quandl, math, datetime
import pandas as pd
import numpy as np
from sklearn import preprocessing, svm
from sklearn.linear_model import LinearRegression
import sklearn.model_selection as cross_validation
import matplotlib.pyplot as plt
from matplotlib import style

style.use('ggplot')

# Data Setup
df = quandl.get('WIKI/GOOGL')
df = df[['Adj. Open', 'Adj. High', 'Adj. Low', 'Adj. Close', 'Adj. Volume']]

# Creating Features
df['HL_PCT'] = (df['Adj. High'] - df['Adj. Close']) / df['Adj. Close'] * 100.0
df['PCT_change'] = (df['Adj. Close'] - df['Adj. Open']) / df['Adj. Open'] * 100.0

# X
df = df[['Adj. Close', 'HL_PCT', 'PCT_change', 'Adj. Volume']]

# Y
forcast_col = 'Adj. Close'
df.fillna(-999999, inplace=True)


forcast_out = int(math.ceil(0.01 * len(df)))
print(forcast_out)

df['label'] = df[forcast_col].shift(-forcast_out)

X = np.array(df.drop(['label'], 1))
X = preprocessing.scale(X)
X_lately = X[-forcast_out:]
X = X[:-forcast_out]

df.dropna(inplace=True)
y = np.array(df['label'])

X_train, X_test, y_train, y_test = cross_validation.train_test_split(X, y, test_size=0.1)

clf = LinearRegression()
clf.fit(X_train, y_train)
accuracy = clf.score(X_test, y_test)

forcast_set = clf.predict(X_lately)
print(forcast_set, accuracy, forcast_out)

df['Forcast'] = np.nan

last_date = df.iloc[-1].name
last_unix = last_date.timestamp()
one_day = 86400
next_unix = last_unix + one_day

for i in forcast_set:
    next_date = datetime.datetime.fromtimestamp(next_unix)
    next_unix += one_day

    df.loc[next_date] = [np.nan for _ in range(len(df.columns) - 1)] + [i]

df['Adj. Close'].plot()
df['Forcast'].plot()

plt.legend(loc=4)
plt.xlabel('Date')
plt.ylabel('Price')
plt.show()