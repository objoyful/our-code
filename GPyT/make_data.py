import os
from curtsies.fmtfuncs import red, bold, green, on_blue, yellow, blue, cyan
import time

MAX_CHAR_LENGTH = 512
MIN_CHAR_LENGTH = 400
NEWLINECHAR = "<N>"

d = os.path.join("GPyT", "repos_test")
full_paths = []

for dirpath, dirnames, filenames in os.walk(d):
    for f in filenames:
        full_path = os.path.join(dirpath, f)
        full_paths.append(full_path)

with open(os.path.join("GPyT", "python_code.txt"), 'a') as f:
    for fpath in full_paths:
        d = open(fpath, 'r').read()
        fd = d.replace('\n', NEWLINECHAR)

        if 100 < len(d) <= MAX_CHAR_LENGTH:
            f.write(fd + '\n')

        else:
            sd = fd.split(NEWLINECHAR * 2)
            substring = ''

            for split in sd:
                substring += split + (NEWLINECHAR * 2)

                if MIN_CHAR_LENGTH <= len(substring) <= MAX_CHAR_LENGTH:
                    f.write(substring + '\n')
                    substring = ''
