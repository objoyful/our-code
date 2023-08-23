from curtsies.fmtfuncs import red, bold, green, on_blue, yellow, blue, cyan
from tokenizers import ByteLevelBPETokenizer # type: ignore
from transformers import GPT2Config, GPT2LMHeadModel, GPT2Tokenizer
import os

TRAIN_BASE = True
root_dir = os.path.abspath(os.sep)
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

inp = "print('Hello World')"
# t = tokenizer.encode(inp)
# print(t.ids)
# print(t.tokens)

tokenizer = GPT2Tokenizer.from_pretrained(os.path.join("GPyT", "tokenizer"))
tokenizer.add_special_tokens({
    "eos_token": '</s>',
    "bos_token": '<s>',
    "unk_token": '<unk>',
    "pad_token": '<pad>',
    "mask_token": '<mask>'
})

t = tokenizer.encode(inp)
print(t)
print(tokenizer.decode(t))