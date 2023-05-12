import tensorflow as tf
from tensorflow._api.v2.compat import v1
from tensorflow import keras
from keras.datasets import cifar10
from keras.preprocessing.image import ImageDataGenerator
from keras.models import Sequential
from keras.layers import Dense, Dropout, Activation, Flatten
from keras.layers import Conv2D, MaxPooling2D
from keras.callbacks import TensorBoard
from keras.utils import Sequence
import numpy as np
import pickle
import os
import time

dense_layer_sizes = [256, 512, 1024]
dense_layers = [1, 2]
layer_sizes = [128]
conv_layers = [3]

val_size = 0.1

# gpu_amt = 0.33
# gpu_options = v1.GPUOptions(per_process_gpu_memory_fraction=gpu_amt)
# sess = v1.Session(config=v1.ConfigProto(gpu_options=gpu_options))

with open(os.path.join("Keras", "k2-data", "X.pickle"), 'rb') as f:
    X = pickle.load(f)

with open(os.path.join("Keras", "k2-data", "y.pickle"), 'rb') as f:
    y = pickle.load(f)

X = X / 255.0
val_count = int(val_size * len(X))

X_train = X[:-val_count]
X_test = X[-val_count:]
y_train = y[:-val_count]
y_test = y[-val_count:]

class DataGenerator(Sequence):
    def __init__(self, x_set, y_set, batch_size):
        self.x, self.y = x_set, y_set
        self.batch_size = batch_size

    def __len__(self):
        return int(np.ceil(len(self.x) / float(self.batch_size)))

    def __getitem__(self, idx):
        batch_x = self.x[idx * self.batch_size:(idx + 1) * self.batch_size]
        batch_y = self.y[idx * self.batch_size:(idx + 1) * self.batch_size]
        return batch_x, batch_y

train_gen = DataGenerator(X_train, y_train, 32)
test_gen = DataGenerator(X_test, y_test, 32)
for dense_layer_size in dense_layer_sizes:
    for dense_layer in dense_layers:
        for layer_size in layer_sizes:
            for conv_layer in conv_layers:
                NAME = "{}-conv-{}-nodes-{}-dense-{}-dense_size-{}".format(conv_layer, layer_size, dense_layer, dense_layer_size, int(time.time()))
                print(NAME)

                tensorboard = TensorBoard(log_dir=os.path.join("Keras", "k5-data", "logs", NAME))
                
                model = Sequential()

                model.add(Conv2D(layer_size, (3, 3), input_shape=X.shape[1:]))
                model.add(Activation('relu'))
                model.add(MaxPooling2D(pool_size=(2, 2)))
                
                for l in range(conv_layer - 1):
                    model.add(Conv2D(layer_size, (3, 3)))
                    model.add(Activation('relu'))
                    model.add(MaxPooling2D(pool_size=(2, 2)))

                model.add(Flatten())
                
                for l in range(dense_layer):
                    model.add(Dense(dense_layer_size))
                    model.add(Activation('relu'))

                model.add(Dense(1))
                model.add(Activation('sigmoid'))

                model.compile(loss='binary_crossentropy',
                            optimizer='adam',
                            metrics=['accuracy'])

                model.fit(train_gen, validation_data=test_gen, epochs=10, callbacks=[tensorboard])