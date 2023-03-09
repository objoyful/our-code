import gymnasium as gym
import random
import numpy as np
import tflearn
from tflearn.layers.core import input_data, dropout, fully_connected
from tflearn.layers.estimator import regression
from statistics import mean, median
from collections import Counter

LR = 1e-3
env = gym.make('CartPole-v0', render_mode="human")
env.reset()
goal_steps = 500
score_requirement = 50
inital_games = 10000

def some_random_games():
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
    training_data = []
    scores = []
    accept_scores = []

    for _ in range(inital_games):
        score = 0
        game_memory = []
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
            accept_scores.append(score)
            for data in game_memory:
                if data[1] ==  1:
                    output = [0, 1]
                elif data[1] ==  0:
                    output = [1, 0]
                
                training_data.appened([data[0], output])
        
        env.reset()
        scores.append(score)
    
    training_data_save = np.array(training_data)
    np.save('MachineLearning/ml60-data/saved.npy', training_data_save)

    print('Average accepted score:', mean(accept_scores))
    print('Median accepted score:', median(accept_scores))
    print(Counter(accept_scores))

    return training_data

initial_population()