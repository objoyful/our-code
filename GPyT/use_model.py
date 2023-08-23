from curtsies.fmtfuncs import red, bold, green, on_blue, yellow, blue, cyan
from tokenizers import ByteLevelBPETokenizer # type: ignore
from transformers import GPT2Config, GPT2LMHeadModel, GPT2Tokenizer, DataCollatorForLanguageModeling, Trainer, TrainingArguments
from datasets import load_dataset
import os

TRAIN_BASE = False
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

tokenizer = GPT2Tokenizer.from_pretrained(os.path.join("GPyT", "tokenizer"))
tokenizer.add_special_tokens({
    "eos_token": '</s>',
    "bos_token": '<s>',
    "unk_token": '<unk>',
    "pad_token": '<pad>',
    "mask_token": '<mask>'
})

config = GPT2Config(
    vocab_size = tokenizer.vocab_size,
    bos_token = tokenizer.bos_token_id,
    eos_token = tokenizer.eos_token_id
    )

model = GPT2LMHeadModel.from_pretrained(os.path.join("GPyT", "model")).to('cuda') # type: ignore
while True:
    inp = input(">>> ")
    input_ids = tokenizer.encode(inp, return_tensors='pt').to('cuda')
    beam_output = model.generate(
        input_ids,
        max_length = 512,
        num_beams = 10,
        temperature = 0.7,
        no_repeat_ngram_size = 5,
        num_return_sequences = 3
        )
    for beam in beam_output:
        out = tokenizer.decode(beam)
        fout = out.replace('<N>', '\n')

        print(green(str(fout)))