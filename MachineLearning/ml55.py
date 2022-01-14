import tensorflow._api.v2.compat.v1 as tf
from tensorflow.python.ops import rnn_cell, rnn
import tensorflow.keras.datasets.mnist as mn
# from tensorflow.examples.tutorials.mnist import input_data

# minst = input_data.read_data_sets('\\temp\data\\', one_hot = True)
mnist = mn.load_data()

hm_epochs = 10

n_classes = 10
batch_size = 100
chunk_size = 28
n_chunks = 28
rnn_size = 128

# height x width
tf.disable_eager_execution()
x = tf.placeholder('float', [None, n_chunks, chunk_size])
y = tf.placeholder('float')

def recurent_neural_network_model(x):
    layer = {'weights':tf.Variable(tf.random_normal([rnn_size, n_classes])), 
             'biases':tf.Variable(tf.random_normal([n_classes]))}

    x = tf.transpose(x, [1, 0, 2])
    x = tf.reshape(x, [-1, chunk_size])
    x = tf.split(x, n_chunks, 0)

    lstm_cell = rnn_cell.BasicLSTMCell(rnn_size)
    outputs, states = rnn.rnn(lstm_cell, x, dtype = tf.float32)

    output = tf.matmul(outputs[-1], layer['weights']) + layer['biases']

    return output

def train_neural_network(x):
    prediction = recurent_neural_network_model(x)
    cost = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits(logits = prediction, labels = y))
    optimizer = tf.train.AdamOptimizer().minimize(cost)
    
    with tf.Session() as sess:
        sess.run(tf.initialize_all_variables())
        
        for epoch in range(hm_epochs):
            epoch_loss = 0
            
            for _ in range(int(mnist.train.num_examples / batch_size)):
                epoch_x, epoch_y = mnist.train.next_batch(batch_size)
                epoch_x = epoch_x.reshape((batch_size, n_chunks, chunk_size))
                
                _, c = sess.run([optimizer, cost], feed_dict = {x: epoch_x, y: epoch_y})
                epoch_loss += c
            
            print('Epoch', epoch, 'completed out of', hm_epochs, 'loss:', epoch_loss)

        correct = tf.equal(tf.argmax(prediction, 1), tf.argmax(y, 1))

        accuracy = tf.reduce_mean(tf.cast(correct, 'float'))
        print('Accuracy:', accuracy.eval({x: mnist.test.images.reshape((-1, n_chunks, chunk_size)), y: mnist.test.labels}))

train_neural_network(x)