def Richter(r):
    """
    Calculates energy in Joules and the equivalent tons of TNT from a Richter scale measurment.
    Displays a table of the Richter scale value, the energy in Joules, and the equivalent tons of TNT.

    j, tnt = Richter(r)

    Inputs:
        r: Richter scale measurement (from 1-10).
    
    Outputs:
        j: Energy in Joules.
        tnt: Equivalent tons of TNT.

    William Carden Richter function
    EGR 101-02
    Due Date: 04/01/2025
    """
    
    # Create empty lists
    j = []
    tnt = []


    # Print table
    print("Richter Scale\t\tEnergy (Joules)\t\tTNT (tons)")
    for i in range(0, len(r)): 

        j.append(10 ** ((1.5 * r[i]) + 4.8)) # Energy in Joules
        tnt.append(j[i] / (4.184 * (10 ** 9))) # Energy in tons of TNT
        print("%-20g\t%-20g\t%-20g" %(r[i], j[i], tnt[i]))
    
    return j, tnt

def RPSGame():
    """
    Plays a game of Rock, Paper, Scissors against the computer.
    Computer first randomly selects a weapon, then the user selects a weapon.
    
    Weaponds:
        'r': Rock
        'p': Paper
        's': Scissors

    Rock smashes scissors.
    Scissors cut paper.
    Paper covers rock.

    Game continues until someone wins three times.

    Returns wins, losses, and draws.

    wins, losses, draws = RPSGame()

    Outputs:
        wins: Number of wins.
        draws: Number of draws.
        losses: Number of losses.

    William Carden RPSGame function
    EGR 101-02
    Due Date: 04/01/2025
    """   

    import random

    weaponds = ['r', 'p', 's'] # Create list of weaponds
    wins = 0; draws = 0; losses = 0 # Create win/loss/draw counter

    print("Rock, Paper, Scissors, GO!\n")

    while True: # Loop until someone wins three times
        if wins == 3 or losses == 3:
            print("Game over!")
            break

        # Computer randomly selects a weapon
        computer_weapon = random.randint(0, 2)
        computer_weapon = weaponds[computer_weapon]

        # Prompt user for weapon
        user_weapon = input("Select a weapon (r, p, s)> ").lower()
    
        if computer_weapon == user_weapon: # If both user and computer select the same weapon
            print("Draw!\n")
            draws += 1

        elif (computer_weapon == 'r' and user_weapon == 's') or (computer_weapon == 's' and user_weapon == 'p') or (computer_weapon == 'p' and user_weapon == 'r'): # If the computer wins
            print("Computer wins!\n")
            losses += 1

        else: # If the user wins
            print("You win!\n")
            wins += 1
    
    return wins, draws, losses

def Roman_num(numeral):
    """
    Converts a Roman numerals from 1-3999 into an integer.
    Displays the interger value of the Roman numeral or an error message if the numeral is invalid or not a string.

    num = Roman_num(numeral)

    Outputs:
        num: Integer value of the Roman numeral. Outputs 0 if there is an error.

    William Carden Roman_num function
    EGR 101-02
    Due Date: 04/01/2025
    """   

    num = 0 # Create num counter
    letters = [] # Create empty list for each letter in the Roman nuymeral


    # If the input is not a string, raise an error
    if type(numeral) is not str:
        print("Input must be a string.")
        return 0
    
    # Add each letter in the Roman numeral to the list
    for letter in numeral:
        letters.append(letter.upper())

    double = False # Create double letter variable

    for i in range(len(letters)):
        if letters[i] not in ['I', 'V', 'X', 'L', 'C', 'D', 'M']:
            print("Invalid Roman numeral.")
            return 0
        
        if double: # If the previous letter was a double letter, skip this letter
            double = False
        else:
            if letters[i] == 'M': # M
                num += 1000
            
            elif letters[i] == 'D': # D
                num += 500
            
            elif letters[i] == 'C':
                if i + 1 < len(letters):
                    if letters[i + 1] == 'M': # CM
                        num += 900
                        double = True
                    elif letters[i + 1] == 'D': # CD
                        num += 400
                        double = True
                    else: # C
                        num += 100
                else: # C
                    num += 100
            
            elif letters[i] == 'L': # L
                num += 50
            
            elif letters[i] == 'X':
                if i + 1 < len(letters):
                    if letters[i + 1] == 'C': # XC
                        num += 90
                        double = True
                    elif letters[i + 1] == 'L': # XL
                        num += 40
                        double = True
                    else: # X
                        num += 10
                else: # X
                    num += 10
            
            elif letters[i] == 'V': # V
                num += 5
            
            else:
                if i + 1 < len(letters):
                    if letters[i + 1] == 'X': # IX
                        num += 9
                        double = True
                    elif letters[i + 1] == 'V': # IV
                        num += 4
                        double = True
                    else: # I
                        num += 1
                else: # I
                    num += 1
    
    print(numeral, "is equal to", num)
    return num

def PyPiece(x, y):
    """
    Generates three outputs based on the input values of two arrays, x and y.
    
    x and y must be of the same length. 
    The array x can contain any float value.
    The array y must contain only the string 'A', or the string 'B' and determines which function to use for the first output.

    First output:

    y       Output Function
    ========================
    'A'     atan(x) (in degrees)
    'B'     (1 + x^4)^(1/4)
    other   0

    The second output is the average of the first output.
    The third output is the index of the minimum value of x (index is in terms of MATLAB arrrats, so it starts at 1).

    a, b, c = PyPiece(x, y)

    Outputs:
        a: First output determined by the value of x and letter of y.
        b: Second output, average of the first output.
        c: Third output, minimum value of x.

    William Carden PyPiece function
    EGR 101-02
    Due Date: 04/01/2025
    """
    import math

    # If the arrays are not the same length, raise an error
    if len(x) != len(y):
        raise ValueError("x and y must be of the same length.")
    
    # Find first output

    a = [] # Create empty list for first output
    for i in range(len(x)):
        if y[i].upper() == 'A': # if y is A
            a.append(math.degrees(math.atan(x[i]))) # atan(x) (in degrees)
        
        elif y[i].upper() == 'B': # if y is B
            a.append((1 + x[i] ** 4) ** (1/4)) # (1 + x^4)^(1/4)
        
        else: # if y is other
            a.append(0) # 0

    
    b = sum(a) / len(a) # Average of first output
    c = x.index(min(x)) + 1 # Minimum value of x

    return a, b, c