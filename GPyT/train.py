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
    vocab_size=tokenizer.vocab_size,
    bos_token=tokenizer.bos_token_id,
    eos_token=tokenizer.eos_token_id
    )

model = GPT2LMHeadModel(config)
data = load_dataset("text", data_files=paths)

def encode(lines):
    return tokenizer(lines['text'], add_special_tokens=True, truncation=True, max_length=512)

<<<<<<< HEAD
data.set_transform(encode) # type: ignore
=======
data.set_transform(encode) #type: ignore
>>>>>>> 6e0e14d8ebe7f48076861a2be3432d903b4a7176
data = data['train'] # type: ignore

data_collator = DataCollatorForLanguageModeling(tokenizer=tokenizer, mlm=True, mlm_probability=0.15)

training_args = TrainingArguments(
    output_dir=os.path.join("GPyT", "model"),
    overwrite_output_dir=True,
    num_train_epochs=10,
    per_device_train_batch_size=10,
    save_steps=100,
    save_total_limit=2,
    prediction_loss_only=True,
    remove_unused_columns=False
)

trainer = Trainer(
    model=model,
    args=training_args,
    data_collator=data_collator,
    train_dataset=data # type: ignore
)

trainer.train()
trainer.save_model(os.path.join("GPyT", "model"))