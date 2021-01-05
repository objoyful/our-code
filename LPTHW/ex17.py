# pylint: disable=unbalanced-tuple-unpacking
from sys import argv
from os.path import exists

try:
    script, from_file, to_file = argv
except:
    argNum = 3
    script = argv[0]
    print(f"You need to pass {argNum - 1} arguments. You only passed {len(argv) - 1}")
    print("Please type the missing arguments below:")
    
    from_file = input("Argument Number 1: ")
    to_file = input("Argument Number 2: ")
finally:
    print(f"Copying from {from_file} to {to_file}")

    def isError():
        if noError==True:
            print("There is no error yet")
        elif noError==False:
            print("There is an error.")
        elif noError==None:
            print("The program just started.")
        else:
            print("Something else...")

    noError = None
    isError()
    while noError!=True:
        try:
            in_file = open(from_file)
            noError = True
            isError()
        except FileNotFoundError:
            print(f"File '{from_file}' was not found. Please choose a file that exists.")
            from_file = input("New File Name: ")
            noError = False
            isError()
        except:
            print(f"There was a problem opening '{from_file}'. Please choose another.")
            from_file = input("New File Name: ")
            noError = False
            isError()

    indata = in_file.read()

    print(f"The input file is {len(indata)} bytes long")

    print(f"Does the output file exist? {exists(to_file)}")
    print("Ready, hit RETURN to continue, CTRL-C to abort.")
    input()

    out_file = open(to_file, 'w')
    out_file.write(indata)

    print("Alright, all done.")

    out_file.close()
    in_file.close()