import tensorflow._api.v2.compat.v1 as tf
from tensorflow.python.ops import rnn_cell, rnn
import pandas as pd
import numpy as np
# from tensorflow.examples.tutorials.mnist import input_data
tf.disable_eager_execution()

# minst = input_data.read_data_sets('\\temp\data\\', one_hot = True)
(x_train, y_train), (x_test, y_test) = tf.keras.datasets.mnist.load_data() #(x_train, y_train), (x_test, y_test)

x_train = x_train.flatten().reshape(len(x_train), 784) 
x_test = x_test.flatten().reshape(len(x_test), 784)

y_train = pd.get_dummies(y_train).to_numpy()
y_test = pd.get_dummies(y_test).to_numpy()

hm_epochs = 10
n_classes = 10
batch_size = 128

chunk_size = 28
n_chunks = 28
rnn_size = 128

# height x width
x = tf.placeholder('float', [None, n_chunks, chunk_size])
y = tf.placeholder('float')

def recurent_neural_network_model(x):
    layer = {'weights':tf.Variable(tf.random_normal([rnn_size, n_classes])), 
             'biases':tf.Variable(tf.random_normal([n_classes]))}

    x = tf.transpose(x, [1, 0, 2])
    x = tf.reshape(x, [-1, chunk_size])
    x = tf.split(x, n_chunks, 0)

    lstm_cell = rnn_cell.BasicLSTMCell(rnn_size)
    outputs, states = rnn.static_rnn(lstm_cell, x, dtype=tf.float32)

    output = tf.matmul(outputs[-1], layer['weights']) + layer['biases']

    return output

def train_neural_network(x):
    prediction = recurent_neural_network_model(x)
    cost = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits(logits=prediction, labels=y))
    optimizer = tf.train.AdamOptimizer().minimize(cost)
    
    with tf.Session() as sess:
        sess.run(tf.global_variables_initializer())
        
        for epoch in range(hm_epochs):
            epoch_loss = 0
            
            i = 0
            while i < len(x_train):
                start = i
                end = i + batch_size

                batch_x = np.array(x_train[start:end])
                batch_x = batch_x.reshape((batch_size, n_chunks, chunk_size))

                batch_y = np.array(y_train[start:end])

                _, c = sess.run([optimizer, cost], feed_dict={x: batch_x, y: batch_y})
                epoch_loss += c

                i += batch_size
            
            print('Epoch', epoch + 1, 'completed out of', hm_epochs, 'loss:', epoch_loss)

        correct = tf.equal(tf.argmax(prediction, 1), tf.argmax(y, 1))

        accuracy = tf.reduce_mean(tf.cast(correct, 'float'))
        print('Accuracy:', accuracy.eval({x: x_test.reshape((-1, n_chunks, chunk_size)), y: y_test}))

train_neural_network(x)