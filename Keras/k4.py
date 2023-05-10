import tensorflow as tf
from tensorflow._api.v2.compat import v1
from tensorflow import keras
from keras.datasets import cifar10
from keras.preprocessing.image import ImageDataGenerator
from keras.models import Sequential
from keras.layers import Dense, Dropout, Activation, Flatten
from keras.layers import Conv2D, MaxPooling2D
from keras.callbacks import TensorBoard
import pickle
import os
import time

NAME = "Cats-vs-dog-cnn-64x2-{}".format(int(time.time()))

tensorboard = TensorBoard(log_dir=os.path.join("Keras", "k4-data", "logs", NAME))
# gpu_amt = 0.33
# gpu_options = v1.GPUOptions(per_process_gpu_memory_fraction=gpu_amt)
# sess = v1.Session(config=v1.ConfigProto(gpu_options=gpu_options))

with open(os.path.join("Keras", "k2-data", "X.pickle"), 'rb') as f:
    X = pickle.load(f)

with open(os.path.join("Keras", "k2-data", "y.pickle"), 'rb') as f:
    y = pickle.load(f)

X = X / 255.0
model = Sequential()

model.add(Conv2D(64, (3, 3), input_shape=X.shape[1:]))
model.add(Activation('relu'))
model.add(MaxPooling2D(pool_size=(2, 2)))

model.add(Conv2D(64, (3, 3)))
model.add(Activation('relu'))
model.add(MaxPooling2D(pool_size=(2, 2)))

model.add(Flatten())
# model.add(Dense(64))
# model.add(Activation('relu'))

model.add(Dense(1))
model.add(Activation('sigmoid'))

model.compile(loss='binary_crossentropy',
              optimizer='adam',
              metrics=['accuracy'])

model.fit(X, y, batch_size=32, validation_split=0.1, epochs=20, callbacks=[tensorboard])