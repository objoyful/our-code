# William Carden factors script
# EGR 101-02
# Due Date: 03/25/2025

while True:
    # Get user input
    i = input("Enter a number to find the factors (quit to exit): ")

    # If user types quit, exit the loop
    if i.lower() == "quit":
        print("Goodbye")
        break
    
    # First convert string to float, then to int (rounds down)
    i = int(float(i))

    isPrime = True # Create isPrime variable to check if number is prime
    # If input is greater than 1, check for factors
    if i > 1:
        # Loop through numbers 2 to i-1
        for j in range(2, i):
            # If the remainder is not 0, there is a factor
            if not i % j:
                print(j, "is a factor of", i)
                isPrime = False # Number can't be prime if it has factors
        
        # If the number is prime, print that it is prime
        if isPrime:
            print(i, "is a prime number.")