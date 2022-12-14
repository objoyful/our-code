# Matplotlib Setup
import matplotlib.pyplot as plt
from matplotlib import style
style.use('ggplot')

# Imports
import numpy as np
from sklearn.cluster import KMeans
from sklearn import preprocessing
import pandas as pd

# Feature Explaination
'''
Pclass Passenger Class (1 = 1st; 2 = 2nd; 3 = 3rd)
survival Survival (0 = No; 1 = Yes)
name Name
sex Sex
age Age
sibsp Number of Siblings/Spouses Aboard
parch Number of Parents/Children Aboard
ticket Ticket Number
fare Passenger Fare (British pound)
cabin Cabin
embarked Port of Embarkation (C = Cherbourg; Q = Queenstown; S = Southampton)
boat Lifeboat
body Body Identification Number
home.dest Home/Destination
'''

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

# Fit KMeans with 2 clusters
clf = KMeans(n_clusters=2, n_init='auto')
clf.fit(X)

# Find accuracy
correct = 0
for i in range(len(X)):
    predict_me = np.array(X[i].astype(float))
    predict_me = predict_me.reshape(-1, len(predict_me))
    prediction = clf.predict(predict_me)

    if prediction[0] == y[i]:
        correct += 1

print(correct / len(X))