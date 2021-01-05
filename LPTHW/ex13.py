# pylint: disable=unbalanced-tuple-unpacking

from sys import argv
# read the WYSS section for how to run this
try:
    script, first, second, third = argv
except:
    argNum = 4
    script = argv[0]
    print(f"You need to pass {argNum - 1} arguments. You only passed {len(argv) - 1}")
    print("Please type the missing arguments below:")

    first = input("Argument Number 1: ")
    second = input("Argument Number 2: ")
    third = input("Argument Number 3: ")
finally:
    print("The script is called:", script)
    print("Your first variable is:", first)
    print("Your second variable is:", second)
    print("Your third variable is:", third)