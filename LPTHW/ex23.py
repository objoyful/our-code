# This exercise is all about strings, bytes , and character encodings.
# The languages.txt file is a list of human languages that UTF-8 understands.
# Now as you probably know, all data that is stored is a 0 (off) or a 1 (on). These are calles bits.
# Now, if it was like that, that would be extremely inefficient so they string 8 of these up to create a byte.
# This can encode 256 number (0-255) in binary. Each of these numbers represent a character. For an example, Z is 90 or 1011010.
# This is the American Standard Code for Information Interchange or ASCII
# The problem is though, 256 characters isn't enough. Sure it can display English, but it can't display most other languages and emojis.
# This is where Unicode comes in. Unicode has 32 bits instead of 8 bits. This means it can hold 2^32 number or 4,294,967,295.
# That's enough for all the languages and tons of emojis.
# One problem: there is a lot of wasted space. Instead of each character being 1 byte it's 4. Imagine taking up 4 times as much space on your hard drive.
# So what they did was still use 8 bit for the most common characters, but then escape into 32 bit when rare ones come up.

# pylint: disable=unbalanced-tuple-unpacking
import sys
try:
    script, input_encoding, error = sys.argv
except:
    argv = sys.argv
    
    argNum = 3
    script = argv[0]
    print(f"You need to pass {argNum - 1} argument(s). You only passed {len(argv) - 1}")
    print("Please type the missing arguments below:")
    
    input_encoding = input("Argument Number 1: ")
    error = input("Argument Number 2: ")

def main(language_file, encoding, errors):
    line = language_file.readline()

    if line:
        print_line(line, encoding, errors)
        return main(language_file, encoding, errors)


def print_line(line, encoding, errors):
    next_lang = line.strip()
    raw_bytes = next_lang.encode(encoding, errors=errors)
    cooked_string = raw_bytes.decode(encoding, errors=errors)

    print(raw_bytes, "<===>", cooked_string)


languages = open("languages.txt", encoding="utf-8")

main(languages, input_encoding, error)