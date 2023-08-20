from curtsies.fmtfuncs import red, bold, green, on_blue, yellow, blue, cyan
from tokenizers import ByteLevelBPETokenizer # type: ignore
from transformers import GPT2Config, GPT2LMHeadModel, GPT2Tokenizer
import os

TRAIN_BASE = True
paths = [os.path.join("GPyT", "python_code.txt")]
tokenizer = ByteLevelBPETokenizer()

if TRAIN_BASE:
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

inp = "print('Hello World!')"
t = tokenizer.encode(inp)
print(t.ids)
print(t.tokens)
