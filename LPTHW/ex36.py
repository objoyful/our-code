# In exercise 26, rules were given for if statements, for loops, while loops and tips were given for debugging.
# Also, you had to design a game similar to the one in ex25.


# Rules for if-statements:

# 1. Every if must have an else.
# 2. If an else doesn't make sence, then use a die function in the else.
#    This function prints out an error and dies.
# 3. Never nest if-statements more than 2 deep.
# 4. Treat if-statements like paragraphs, where each if-elif-else grouping is like a set of sentences.
#    Put blank lines before and after,
# 5. Your Boolean test should be simple. If not, move it to a varible and give it a good name.

# NOTE: These rules are just for the begining stages and not meant for real programs.

# Rules for loops:

# 1. Only use a while-loop when looping forever. This is only for Python.
# 2. Use a for-loop for anything else. Especially when there is a fixed amount of things to loop over.

# Tips for Debugging:

# 1. Don't use a dubugger. You don't get any specific useful information that's confusing.
# 2. The best way to debug is to use print to see what the varibles are in different points in the program.
# 3. Make sure parts of your program work as you wirte them. You don't want to write a massive progarm and then have a million errors.


# Now we write our own game similar to the one in ex35:
from sys import exit

def first_door():
    redo = False
    while True:
        if redo:
            print("Bobby is still blocking the other door. What do you do?")
        else:
            print("You go into a dark room. You see Bobby blocking another door. What do you do?")
        bobby = input("> ")
        if "punch" in bobby:
            print("Bobby is knocked out. What do you do?")
            knocked = input("> ")

            if "open door" in knocked:
                dead("You open the door and see a room full of gold!")
            elif "punch" in knocked or "taunt" in knocked:
                dead("Bobby gets really mad and kicks your butt.")
            else:
                dead(f"While you do {knocked}, Bobby gets up and kicks your butt.")
        elif "open door" in bobby:
            dead("He  gets really mad and kicks your butt.")
        elif "distract" in bobby:
            print("He gets confused, he's still blocking the door.")
        else:
            redo = True
        redo = True

def second_door():
    attack = "The bear attacks and kills you."
    bear_redo = False
    bear = None
    while True:
        if bear_redo:
            print("The bear is still eating the pumpkin pie. What do you do?")
        else:
            print("You walk into a room were a bear is eating pumkin pie.")
            print("You are starving. What do you do?")
        bear = input("> ")
        if "scream" in bear or "punch" in bear or "attack" in bear or "taunt" in bear or "grab pie" in bear or "move" in bear:
            dead(attack)
        elif "pepper spray" in bear:
            dead("The bear colapses and you eat the pie.")
        else:
            bear_redo = True
        bear_redo = True

def dead(reason):
    print(f"{reason}  Good job!")
    print("Would you like to try again")
    again = input("> ")
    if "y" in again or "Y" in again or "yes" in again or "Yes" in again or "YES" in again:
        spaces = '\n' * 100
        print(spaces)
        start()
    else:
        exit(0)


def start():
    pick_door = False
    while True:
        if pick_door:
            print("Dude, pick a door.")
        else:
            print("You are in a dark room. There are 2 doors. Which one do you open?")
        door = input("> ")
        if "one" in door or "first" in door or "1" in door:
            first_door()
        elif "two" in door or "second" in door or "2" in door:
            second_door()
        else:
            pick_door = True


start()