import tensorflow._api.v2.compat.v1 as tf
import pandas as pd
# import tensorflow as tf
# from tensorflow.examples.tutorials.mnist import input_data
tf.disable_eager_execution()

# minst = input_data.read_data_sets('\\temp\data\\', one_hot = True)
(x_train, y_train), (x_test, y_test) = tf.keras.datasets.mnist.load_data() #(x_train, y_train), (x_test, y_test)

x_train = x_train.flatten().reshape(len(x_train), 784)
x_test = x_test.flatten().reshape(len(x_test), 784)

y_train = pd.get_dummies(y_train).to_numpy()
y_test = pd.get_dummies(y_test).to_numpy()

n_nodes_hl1 = 500
n_nodes_hl2 = 500
n_nodes_hl3 = 500

n_classes = 10
batch_size = 100

# height x width

x = tf.placeholder('float', [None, 784])
y = tf.placeholder('float')

def neural_network_model(data):
    hidden_1_layer = {'weights':tf.Varible(tf.random_normal([784, n_nodes_hl1])),
                      'biases':tf.Varible(tf.random_normal(n_nodes_hl1))}

    hidden_2_layer = {'weights':tf.Varible(tf.random_normal([n_nodes_hl1, n_nodes_hl2])),
                      'biases':tf.Varible(tf.random_normal(n_nodes_hl2))}
    

    hidden_3_layer = {'weights':tf.Varible(tf.random_normal([n_nodes_hl2, n_nodes_hl3])),
                    'biases':tf.Varible(tf.random_normal(n_nodes_hl3))}
    output_layer = {'weights':tf.Varible(tf.random_normal([n_nodes_hl3, n_classes])),
                    'biases':tf.Varible(tf.random_normal(n_classes))}
    
    # (input_data * weights) + biases

    l1 = tf.add(tf.matmul(data, hidden_1_layer['weights']), hidden_1_layer['biases'])
    l1 = tf.nn.relu(l1)

    l2 = tf.add(tf.matmul(l1, hidden_2_layer['weights']), hidden_2_layer['biases'])
    l2 = tf.nn.relu(l2)

    l3 = tf.add(tf.matmul(l2, hidden_3_layer['weights']), hidden_3_layer['biases'])
    l3 = tf.nn.relu(l3)

    output = tf.matmul(l3, output_layer['weights']) + output_layer['biases']

    return output