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

some_random_games()