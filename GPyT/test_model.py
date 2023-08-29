from curtsies.fmtfuncs import red, bold, green, on_blue, yellow, blue, cyan
from transformers import GPT2Config, GPT2LMHeadModel, GPT2Tokenizer
import os

NEWLINECHAR = '<N>'

def encode_newlines(inp):
    return inp.replace('\n', NEWLINECHAR)
def decode_newlines(inp):
    return inp.replace(NEWLINECHAR, '\n')

tokenizer = GPT2Tokenizer.from_pretrained(os.path.join("GPyT", "tokenizer"))
tokenizer.add_special_tokens({
    "eos_token": '</s>',
    "bos_token": '<s>',
    "unk_token": '<unk>',
    "pad_token": '<pad>',
    "mask_token": '<mask>'
})


model = GPT2LMHeadModel.from_pretrained(os.path.join("GPyT", "model")).to('cuda') # type: ignore

inp = "def __init__"
input_ids = tokenizer.encode(inp, return_tensors='pt').to('cuda')

model_out = model.generate(
    input_ids,
    max_length = 512,
    num_beams = 10,
    temperature = 0.7,
    no_repeat_ngram_size = 5,
    num_return_sequences = 3,
    return_dict_in_generate = True,
    output_scores = True
    )

for k in model_out:
    print(k)
for out in model_out['sequences']: # type: ignore
    print(out)

print(len(model_out['scores'])) # type: ignore

for mask_token in model_out['scores']: # type: ignore
    print(len(mask_token))
    for beam in mask_token:
        print(len(beam))
    break
