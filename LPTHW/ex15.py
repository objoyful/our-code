# pylint: disable=unbalanced-tuple-unpacking
from sys import argv

try:
    script, filename = argv
except:
    argNum = 2
    script = argv[0]
    print(f"You need to pass {argNum - 1} arguments. You only passed {len(argv) - 1}")
    print("Please type the missing arguments below:")
    
    filename = input("Argument Number 1: ")

txt = open(filename)

print(f"Here's your file {filename}:")
print(txt.read())

print("Type the filename again:")
file_again = input("> ")

txt_again = open(file_again)

print(txt_again.read())