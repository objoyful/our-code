def Guess(x=False):
    """
    Plays a guessing game where the users inputs a number from 1-100 and the function tries to guess the number.
    The function continues to guess until it finds the correct number or the user quits the program.
    If no number is provided, a random number will be selected.

    guesses = Guess(x)

    Inputs:
        x: A number from 1-100 to be guessed. If no number is provided, a random number is chosen.
    
    Outputs:
        guesses: The number of guesses it took to find the correct number or quit. If the user quits at any time the value is 0.

    William Carden Guess function
    EGR 101-02
    Due Date: 03/27/2025
    """

    import random

    guesses = 0 # Create guess counter
    
    # If no number is provided, create a random one.
    if type(x) is not int:
        x = random.randint(1, 100)
        print("No number provided, attempting to guess", x)
    else:
        print("Attempting to guess", x)
    
    while True:
        # Create random number
        guess_num = random.randint(1, 100)
        print("Guessing the number", guess_num)
        guesses += 1

        if guess_num > x: # If the number is too high
            responce = input("Guess was too high! Press enter to continue or type 'quit' to exit >>> ")
        elif guess_num < x: # If the number is too low
            responce = input("Guess was too low! Press enter to continue or type 'quit' to exit >>> ")
        else: # If the number is correct
            print("Guess was correct! It took", guesses, "guesses.")
            return guesses

        if responce.lower() == "quit": # If the user quits
            print("Quitting game.")
            
            guesses = 0
            return guesses