# Imports
import nltk
from nltk.tokenize import word_tokenize # [i, pulled, the, chair]
from nltk.stem import WordNetLemmatizer # [ran, running, runs, run]
import numpy as np
import random
import pickle
from collections import Counter

lemmatizer = WordNetLemmatizer()
hm_lines = 10000000 # How many lines we want to read