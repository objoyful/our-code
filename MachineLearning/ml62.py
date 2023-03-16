import gymnasium as gym
import random
import numpy as np
import tflearn
from tflearn.layers.core import input_data, dropout, fully_connected
from tflearn.layers.estimator import regression
from statistics import mean, median
from collections import Counter
import os

LR = 1e-3
env = gym.make('CartPole-v0')
env.reset()
goal_steps = 500
score_requirement = 50
inital_games = 50000
n_epochs = 10

def some_random_games():
    env = gym.make('CartPole-v0', render='human')
    for episode in range(5):
        env.reset()
        for t in range(goal_steps):
            env.render()
            action = env.action_space.sample()
            observation, reward, terminated, truncated, info = env.step(action)
            if terminated or truncated:
                break

# some_random_games()
def initial_population():
    training_data = [] # [[prev_observation, [1, 0]], [prev_observation, [0, 1]]]] [[prev_observation, move], [prev_observation, move]]
    scores = [] # 23....
    accepted_scores = [] # 51..

    for _ in range(inital_games):
        score = 0
        game_memory = [] # [[prev_observation, 0], [prev_observation, 1]] 
        prev_observation = []

        for _ in range(goal_steps):
            action = random.randrange(0, 2)
            observation, reward, terminated, truncated, info = env.step(action)
            done = terminated or truncated

            if len(prev_observation) > 0:
                game_memory.append([prev_observation, action])
            
            prev_observation = observation
            score += reward

            if done:
                break
        
        if score >= score_requirement:
            accepted_scores.append(score)
            for data in game_memory:
                if data[1] ==  1:
                    output = [0, 1]
                elif data[1] ==  0:
                    output = [1, 0]
                
                training_data.append([data[0], output])
        
        env.reset()
        scores.append(score)
    
    training_data_save = np.array(training_data, dtype=object)
    try:
        os.makedirs('MachineLearning/ml62-data')
    except:
        pass
    np.save('MachineLearning/ml62-data/saved.npy', training_data_save)

    print('Average accepted score:', mean(accepted_scores))
    print('Median accepted score:', median(accepted_scores))
    print('Average score:', mean(scores))
    print('Median score:', median(scores))
    print(Counter(accepted_scores))

    return training_data

def neural_network_model(input_size):
    network = input_data([None, input_size, 1], name='input')

    network = fully_connected(network, 128, activation='relu')
    network = dropout(network, 0.8)

    network = fully_connected(network, 256, activation='relu')
    network = dropout(network, 0.8)

    network = fully_connected(network, 512, activation='relu')
    network = dropout(network, 0.8)

    network = fully_connected(network, 256, activation='relu')
    network = dropout(network, 0.8)

    network = fully_connected(network, 128, activation='relu')
    network = dropout(network, 0.8)

    network = fully_connected(network, 2, activation='softmax')
    network = regression(network, optimizer='adam', learning_rate=LR, loss='categorical_crossentropy', name='targets')

    model = tflearn.DNN(network, tensorboard_dir='MachineLearning/ml62-data/log')

    return model

def train_model(training_data, model=False):
    X = np.array([i[0] for i in training_data]).reshape(-1, len(training_data[0][0]), 1)
    y = [i[1] for i in training_data]

    if not model:
        model = neural_network_model(input_size=len(X[0]))
    
    model.fit({'input': X}, {'targets': y}, n_epoch=n_epochs, snapshot_step=500, show_metric=True, run_id='openai')

    return model

training_data = initial_population()
model = train_model(training_data)

env = gym.make('CartPole-v0', render_mode='human')

scores = []
choices = [] # 0 1 1 0 1 

for each_game in range(10):
    score = 0
    game_memory = []
    prev_obs = []
    env.reset()

    for _ in range(goal_steps):
        env.render()
        if len(prev_obs) == 0:
            action = random.randrange(0, 2)
        else:
            action = np.argmax(model.predict(prev_obs.reshape(-1, len(prev_obs), 1))[0]) # [0, 1] = 1 [1, 0] = 0
        choices.append(action)

        new_observation, reward, terminated, truncated, info = env.step(action)
        done = terminated or truncated
        prev_obs = new_observation
        game_memory.append([new_observation, action])
        score += reward
        if done:
            break
    scores.append(score)

print("Average Score", sum(scores) / len(scores))
print("Best Score:", max(scores))
print("Choice 1: {}, Choice 0: {}".format(choices.count(1) / len(choices),
                                          choices.count(0) / len(choices)))