from  transformers import AutoTokenizer, AutoModelWithLMHead

tokenizer = AutoTokenizer.from_pretrained("Sentdex/GPyT")
model = AutoModelWithLMHead.from_pretrained("Sentdex/GPyT").to('cuda')

def generate(code, max_length=100):
    '''Takes input code, replaces newline chars with <N>,
    tokenizes, feeds thru model, decoes,
    then reformats the newlines back in'''

    newlinechar = '<N>'
    converted = code.replace('\n', newlinechar)

    tokenized = tokenizer.encode(converted, return_tensors='pt').to('cuda') # type: ignore
    resp = model.generate(tokenized, max_length=max_length).to('cuda')

    decoded = tokenizer.decode(resp[0])
    reformatted = decoded.replace('<N>', '\n')

    return reformatted

print(generate("import"))