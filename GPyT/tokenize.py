from curtsies.fmtfuncs import red, bold, green, on_blue, yellow, blue, cyan
from tokenizers import models
import tokenizers
import os

paths = [os.path.join("GPyT", "python_code.txt")]
tokenizer = tokenizers.ByteLevelBPETokenizer()

tokenizer.train(files=paths, vocab_size=52000, min_frequency=2, special_tokens=[
    '<s>',
    '<pad>',
    '</s>',
    '<unk>',
    '<mask>'
])

try:
    os.makedirs(os.path.join("GPyT", "tokenizer"))
except:
    pass
tokenizer.save_model(os.path.join("GPyT", "tokenizer"))