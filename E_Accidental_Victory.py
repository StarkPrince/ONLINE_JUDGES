# for _ in range(int(input())):
#     n = int(input())
#     a = list(map(int, input().split()))
#     mx = max(a)
#     d = {}
#     sm = j = 0
#     for i in a:
#         if i not in d:
#             d[i] = 0
#         d[i] += 1
#     for i in sorted(d.keys()):
#         print(i, end=' ')
#         sm += i*d[i]
#         if sm >= mx:
#             j = i
#             break
#     print(j)


# from sklearn.model_selection import train_test_split
import matplotlib.pyplot as plt

import matplotlib as mpl

import pandas as pd

import seaborn as sns

# import sklearn

import numpy as np

url = "https://raw.githubusercontent.com/ludobouan/linear-regressionsklearn/master/challenge_dataset.txt"
df = pd.read_csv(url, names=['X","Y'])

df.head()

sns.regplot(x="X", y="Y", data=df, fit_reg=False)

plt.show()

# X_train, X test. y_train, y test = np.asarray(train_test_split(dfl 'X'], di[Y], test_size=0.1))
# from sklearn.linear model import LinearRegression

# reg LinearRegression()

# reg.fit(X_train.values.reshape(-1.1), y_train.values.reshape(-1, 1))
# x_line= np.arange(5, 25).reshape(-1.1) sns.regplot(x=df[X], y-dfl'Y'], 'data-df. fit_reg=False)

# plt.plotix line, reg.predict(x line))

# plt.show()
# print("Score: , reg.score(X_test.values.reshape(-1, 1). y_test.values.reshape(-1, 1)))
