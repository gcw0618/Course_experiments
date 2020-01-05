import pandas as pd
import sklearn as sk
import numpy as np
from sklearn.svm import SVC  # .57
from sklearn.metrics import roc_curve, auc
from sklearn.model_selection import learning_curve as lc
import matplotlib.pyplot as plt
from sklearn.neighbors import KNeighborsClassifier  # .42
from sklearn.linear_model import LogisticRegression  # .28
from sklearn.ensemble import RandomForestClassifier  # .57
from sklearn import tree
from sklearn.ensemble import GradientBoostingClassifier  # .57
from sklearn.ensemble import AdaBoostClassifier  # .57
from sklearn.naive_bayes import GaussianNB  # .57
from sklearn.discriminant_analysis import LinearDiscriminantAnalysis  # .28
from sklearn.discriminant_analysis import QuadraticDiscriminantAnalysis  # .28
from sklearn.naive_bayes import MultinomialNB  # .28
from sklearn.metrics import log_loss
from sklearn.metrics import jaccard_similarity_score
from scipy.spatial.distance import dice
import warnings
warnings.filterwarnings("ignore")

df = pd.read_excel('traindata.xlsx')
X = df.drop(labels='y', axis=1)
y = df['y']

print("训练集为")
print(X.head(X.shape[0]))
print("训练集标签为")
print(y.head(X.shape[0]))

df = pd.read_excel('testdata.xlsx')
X_test = df.drop(labels='y', axis=1)
y_test = df['y']
print("测试集为")
print(X_test.head(X_test.shape[0]))
print("测试集标签为")
print(y_test.head(X_test.shape[0]))
acc = []

model = MultinomialNB()
model.fit(X, y)
pred_train = model.predict(X)
print("训练集准确度为 {}".format(np.mean(pred_train == y)))
pred_test = model.predict(X_test)
print("测试集准确度为 {}".format(np.mean(pred_test == y_test)))

y_score = model.predict_proba(X_test)
y_test_roc = np.ones((X_test.shape[0]))
y_score_roc = y_score[range(y_score.shape[0]), y_test]
y_test_roc[0:2] = 0
y_score_roc[0:2] = 1 - y_score_roc[0:2]

print("loss = {}".format(log_loss(y_test_roc, y_score_roc)))
fpr, tpr, thresholds = roc_curve(
    y_test_roc, y_score_roc)

print("DICE value = {}".format(dice(y_test, pred_test)))
print("Jarccard value = {}".format(jaccard_similarity_score(y_test, pred_test)))


# print(fpr)
roc_auc = auc(fpr, tpr)
right_index = (tpr + (1 - fpr) - 1)
yuzhi = max(right_index)
index = np.argmax(right_index)
# .index(max(right_index))
tpr_val = tpr[index]
fpr_val = fpr[index]
# print(fpr, tpr)
# 绘制roc曲线图
plt.subplots(figsize=(7, 5.5))
plt.plot(fpr, tpr, color='darkorange',
         lw=2, label='ROC curve (area = %0.2f)' % roc_auc)
plt.plot([0, 1], [0, 1], color='navy', linestyle='--')
plt.xlim([0.0, 1.0])
plt.ylim([0.0, 1.05])
plt.xlabel('False Positive Rate')
plt.ylabel('True Positive Rate')
plt.title('ROC Curve')
plt.legend(loc="lower right")
plt.show()



# acc.append(np.mean(pred_test == y_test))
# for i in range(8):
# print("i= {} acc = {}".format(i + 1, acc[i]))

# train_size, train_scores, valid_scores = lc(
#     model, X, y, train_sizes=[9, 12, 15, 18])

# print(train_size)
# print(train_scores)
# print(valid_scores)
# plt.figure(figsize=(12, 12))
# # fig.grid()
# plt.subplot(121)
# plt.grid()
# plt.plot(train_size, train_scores)
# plt.subplot(122)
# plt.grid()
# plt.plot(valid_scores)
# plt.show()
