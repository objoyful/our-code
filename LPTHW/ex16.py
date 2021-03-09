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

print(f"We're going to erase {filename}.")
print("If you don't want that, hit CTRL-C (^C).")
print("If you do want that, hit RETURN.")

input("?")

print("Opening the file...")
target = open(filename, 'w')

print("Truncating the file.  Goodbye!")
target.truncate()

print("Now I'm going to ask you for three lines.")

line1 = input("line 1: ")
line2 = input("line 2: ")
line3 = input("line 3: ")

print("I'm going to write these to the file.")

target.write(line1)
target.write("\n")
target.write(line2)
target.write("\n")
target.write(line3)
target.write("\n")

print("And finally, we close it.")
target.close()