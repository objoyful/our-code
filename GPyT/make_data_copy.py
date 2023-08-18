import os
from curtsies.fmtfuncs import red, bold, green, on_blue, yellow, blue, cyan
import time

MAX_CHAR_LENGTH = 512
MIN_CHAR_LENGTH = 256
NEWLINECHAR = "<N>"

d = os.path.join("GPyT", "repos_test")
file_paths = []

for dirpath, dirnames, filenames in os.walk(d):
    for f in filenames:
        full_path = os.path.join(dirpath, f)
        file_paths.append(full_path)

print(len(file_paths))

with open(os.path.join("GPyT", 'python_code.txt'), 'a') as m:
    for file in file_paths:
        f = open(file, 'r').read()
        f = f.replace('\n', NEWLINECHAR)
        
        if 100 < len(f) < MAX_CHAR_LENGTH:
            print(f)
            m.write(f + '\n')
        else:
            splits = f.split(NEWLINECHAR * 2)
            segments = ''
            for split in splits:
                if MIN_CHAR_LENGTH <= len(segments) <= MAX_CHAR_LENGTH:
                    m.write(segments + '\n')
                    segments = split
                else:
                    segments += split
                print(len(segments))