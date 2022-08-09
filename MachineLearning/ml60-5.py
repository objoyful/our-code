import cv2
import numpy as np
import os
from random import shuffle
from tqdm import tqdm
import tflearn
from tflearn.layers.conv import conv_2d, max_pool_2d
from tflearn.layers.core import input_data, dropout, fully_connected
from tflearn.layers.estimator import regression
import tflearn.datasets.mnist as mnist
import tensorflow._api.v2.compat.v1 as tf
import matplotlib.pyplot as plt

tf.reset_default_graph()

data_dir = "MachineLearning\\ml60-data\\"

TRAIN_DIR = data_dir + "train"
TEST_DIR = data_dir + "test"

IMG_SIZE = 50
LR = 1e-3

MODEL_NAME = 'dogsvscats-{}-{}.model'.format(LR, '6conv-basic')

def label_img(img):
    # dog.93.png
    word_label = img.split('.')[-3]

    if word_label == 'cat': return [1, 0]
    elif word_label == 'dog': return [0, 1]

def create_train_data():
    training_data = []

    for img in tqdm(os.listdir(TRAIN_DIR)):
        label = label_img(img)
        
        path = os.path.join(TRAIN_DIR, img)
        img = cv2.resize(cv2.imread(path, cv2.IMREAD_GRAYSCALE), (IMG_SIZE, IMG_SIZE))

        training_data.append([np.array(img), np.array(label)])
    
    shuffle(training_data)
    np.save(data_dir + 'train_data.npy', training_data)
    
    return training_data

def proccess_test_data():
    testing_data = []

    for img in tqdm(os.listdir(TEST_DIR)):
        path = os.path.join(TEST_DIR, img)
        
        img_num = img.split('.')[0]
        img = cv2.resize(cv2.imread(path, cv2.IMREAD_GRAYSCALE), (IMG_SIZE, IMG_SIZE))

        testing_data.append([np.array(img), img_num])
    
    np.save(data_dir + 'test_data.npy', testing_data)
    return testing_data

# train_data = create_train_data()
train_data = np.load(data_dir + "train_data.npy", allow_pickle = True)

convnet = input_data(shape = [None, IMG_SIZE, IMG_SIZE, 1], name = 'input')

convnet = conv_2d(convnet, 32, 2, activation = 'relu')
convnet = max_pool_2d(convnet, 2)

convnet = conv_2d(convnet, 64, 2, activation = 'relu')
convnet = max_pool_2d(convnet, 2)

convnet = conv_2d(convnet, 32, 2, activation = 'relu')
convnet = max_pool_2d(convnet, 2)

convnet = conv_2d(convnet, 64, 2, activation = 'relu')
convnet = max_pool_2d(convnet, 2)

convnet = conv_2d(convnet, 32, 2, activation = 'relu')
convnet = max_pool_2d(convnet, 2)

convnet = conv_2d(convnet, 64, 2, activation = 'relu')
convnet = max_pool_2d(convnet, 2)

convnet = fully_connected(convnet, 2, activation = 'softmax')
convnet = regression(convnet, optimizer = 'adam', learning_rate = LR, loss = 'categorical_crossentropy', name = 'targets')

model = tflearn.DNN(convnet, tensorboard_dir = data_dir + 'log')

if os.path.exists(data_dir + '{}.meta'.format(MODEL_NAME)):
    model.load(data_dir + MODEL_NAME)
    print("Model loaded")
else:
    train = train_data[:-500]
    test = train_data[-500:]

    X = np.array([i[0] for i in train]).reshape(-1, IMG_SIZE, IMG_SIZE, 1)
    Y = [i[1] for i in train]

    test_x = np.array([i[0] for i in test]).reshape(-1, IMG_SIZE, IMG_SIZE, 1)
    test_y = [i[1] for i in test]

    model.fit({'input': X}, {'targets': Y}, n_epoch = 5, 
        validation_set = ({'input': test_x}, {'targets': test_y}),
        snapshot_step = 500, show_metric = True, run_id = MODEL_NAME)

    model.save(data_dir + MODEL_NAME)

# test_data = proccess_test_data()
test_data = np.load(data_dir + 'test_data.npy', allow_pickle = True)

fig = plt.figure()

# for num, data in enumerate(test_data[:12]):
#     # cat: [1, 0]
#     # dog: [0, 1]
    
#     img_num = data[1]
#     img_data = data[0]

#     y = fig.add_subplot(3, 4, num + 1)
#     orig = img_data
#     data = img_data.reshape(IMG_SIZE, IMG_SIZE, 1)

#     model_out = model.predict([data])[0]

#     if np.argmax(model_out) == 1: str_label = 'Dog'
#     else: str_label = 'Cat'

#     y.imshow(orig, cmap = 'gray')
#     plt.title(str_label)
#     y.axes.get_xaxis().set_visible(False)
#     y.axes.get_yaxis().set_visible(False)
# plt.show()

with open(data_dir + 'submission-file.csv', 'w') as f:
    f.write('id,label\n')

with open(data_dir + 'submission-file.csv', 'a') as f:
    for data in tqdm(test_data):
        img_num = data[1]
        img_data = data[0]

        orig = img_data
        data = img_data.reshape(IMG_SIZE, IMG_SIZE, 1)

        model_out = model.predict([data])[0]
        f.write('{},{}\n'.format(img_num, model_out[1]))