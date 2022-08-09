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

TRAIN_DIR = "MachineLearning/ml60-data/train"
TEST_DIR = "MachineLearning/ml60-data/test"

IMG_SIZE = 50
LR = 1e-3

MODEL_NAME = 'MachineLearning\\ml60-data\\dogsvscats-{}-{}.model'.format(LR, '2conv-basic')

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
    np.save('MachineLearning\\ml60-data\\train_data.npy', training_data)
    
    return training_data

def proccess_test_data():
    testing_data = []

    for img in tqdm(os.listdir(TEST_DIR)):
        path = os.path.join(TEST_DIR, img)
        
        img_num = img.split('.')[0]
        img = cv2.resize(cv2.imread(path, cv2.IMREAD_GRAYSCALE), (IMG_SIZE, IMG_SIZE))

        testing_data.append([np.array(img), img_num])
        np.save('MachineLearning\\ml60-data\\test-data.npy', testing_data)
        
        return testing_data

train_data = create_train_data()

convnet = input_data(shape = [None, IMG_SIZE, IMG_SIZE, 1], name = 'input')

convnet = conv_2d(convnet, 32, 2, activation = 'relu')
convnet = max_pool_2d(convnet, 2)

convnet = conv_2d(convnet, 64, 2, activation = 'relu')
convnet = max_pool_2d(convnet, 2)

convnet = fully_connected(convnet, 1024, activation = 'relu')
convnet = dropout(convnet, 0.8)

convnet = fully_connected(convnet, 2, activation = 'softmax')
convnet = regression(convnet, optimizer = 'adam', learning_rate = LR, loss = 'categorical_crossentropy', name = 'targets')

model = tflearn.DNN(convnet, tensorboard_dir='MachineLearning\\ml60-data\\log')