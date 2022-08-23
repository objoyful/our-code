import tensorflow._api.v2.compat.v1 as tf
import tensorflow_datasets
# from tensorflow.examples.tutorials.mnist import input_data

# minst = input_data.read_data_sets('\\temp\data\\', one_hot = True)
mnist = tensorflow_datasets.load('mnist')

n_nodes_hl1 = 500
n_nodes_hl2 = 500
n_nodes_hl3 = 500

n_classes = 10
batch_size = 100

# height x width
tf.disable_eager_execution()
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