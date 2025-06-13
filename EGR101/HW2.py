def password(new_or_current_user):
    """
    If the user is a new user, create a new username and password and store it in userpass.csv.
    If the user is a current user, check if the username and password match the record in userpass.csv.

    If the input is true, the user is a new user. If it is false, the user is a current user.
    If the username and password are valid for a new user, the output is true, otherwise false.
    If the username and password match for a current user, the output is true, otherwise false.

    Username must be between 6 and 16 characters long.
    Password must:
        - be between 6 and 16 characters long
        - have at least one uppercase letter
        - have at least one lowercase letter
        - have at least one number
        - have at least one special character (~, !, @, #, $, %, ^ , &, *, <, >, /, or ?)
        - not have repeated characters
        - not have any other characters

    valid_or_match = password(new_or_current_user)

    Inputs:
        new_or_current_user: True if the user is a new user, False if the user is a current user.

    Outputs:
        valid_or_match: True if the username and password are valid for a new user, or if the username and password match for a current user. False otherwise.

    William Carden password function
    EGR 101-02
    Due Date: 04/22/2025
    """

    import csv

    # Get unsername and password from user
    username = input("Enter username: ")
    passwrd = input("Enter password: ")

    userpass = {}

    # Read userpass.csv file
    with open('userpass.csv', newline='') as file:
        file_data = csv.reader(file, delimiter=',')

        # Append each row to the userpass dictionary
        for row in file_data:
            userpass[row[0]] = row[1]

    if new_or_current_user:  # If the user is a new user
        valid_username = False

        # Check if valid username
        if username in userpass:
            print("User already exists.")
        elif len(username) < 6:
            print("Username is too short.")
        elif len(username) > 16:
            print("Username is too long.")
        else:
            valid_username = True
    
        # Flags for valid password
        last_char = ''
        repeated_char = False
        invalid_char = False
        upper_case = False
        lower_case = False
        number = False
        special_char = False
        special_chars = ['~', '!', '@', '#', '$', '%', '^', '&', '*', '<', '>', '/', '?']

        for char in passwrd:
            # Check if password has repeated characters
            if char == last_char:
                repeated_char = True

            # Check if password has valid or invalid characters using ASCII values
            if ord(char) > 64 and ord(char) < 91:
                upper_case = True
            elif ord(char) > 96 and ord(char) < 123:
                lower_case = True
            elif ord(char) > 47 and ord(char) < 58:
                number = True
            elif char in special_chars:
                special_char = True
            else:
                invalid_char = True
            
            last_char = char
        
        # Password is valid only if all conditions are met
        valid_password = upper_case and lower_case and number and special_char and len(passwrd) >= 6 and len(passwrd) <= 16 and not repeated_char and not invalid_char
        # Output is true if username and password are both valid
        valid_or_match = valid_username and valid_password

        # Password length error messages
        if len(passwrd) < 6:
            print("Password is too short.")
        if len(passwrd) > 16:
            print("Password is too long.")
        
        # Repeated or invalid character error messages
        if repeated_char:
            print("Password cannot have repeated characters.")
        if invalid_char:
            print("Password has invalid characters.")

        # Password character type error messages
        if not upper_case:
            print("Password must have at least one uppercase letter.")
        if not lower_case:
            print("Password must have at least one lowercase letter.")
        if not number:
            print("Password must have at least one number.")
        if not special_char:
            print("Password must have at least one special character. (~, !, @, #, $, %, ^ , &, *, <, >, /, or ?)")
        
        # If the username and password are valid, write them to userpass.csv
        if valid_or_match:
            with open('userpass.csv', 'a', newline='') as file:
                writer = csv.writer(file)
                
                writer.writerow([username, passwrd])

        return valid_or_match
    
    else:  # If the user is a current user
        # Check if user exists
        if username in userpass:
            # Check if password matches
            if userpass[username] == passwrd:
                return True
            else:
                print("Username and password do not match.")
                return False
        else:
            print("Username and password do not match.")
            return False

def grocery_cost(grocery_list):
    """
    Calculates the cost of a grocery list based on the prices and available stock in grocery.py.
    Returns the total cost and final grocery list after stock is considered.

    If there is not enough stock for an item, the user will be asked if they want the available quantity.
    Displays subtotal, tax of 6.5%, and total cost.

    total_cost, final_grocery_list = grocery_cost(grocery_list)

    Inputs:
        grocery_list: A dicitionary of grocery items and their quantities.
    
    Outputs:
        total_cost: The total cost of the grocery list.
        final_grocery_list: A dictionary of grocery items and their quantities after stock is considered.

    William Carden grocery_cost function
    EGR 101-02
    Due Date: 04/22/2025
    """
    try:
        from grocery import stock, prices
    except:
        stock = {
            "tomato soup": 20,
            "cheese": 10,
            "bread": 3,
            "milk": 1,
            "butter": 7,
            "coffee": 8,
            "ice cream": 5,
            "orange juice":  12,
            "bacon": 2,
            "tortilla chips":  4,
            "ramen":  25
        }

        prices = {
            "tomato soup": 2.38,
            "cheese": 4.22,
            "bread": 2.38,
            "milk": 3.07,
            "butter": 3.97,
            "coffee": 6.56,
            "ice cream": 3.87,
            "orange juice":  3.96,
            "bacon": 6.47,
            "tortilla chips":  5.94,
            "ramen":  0.30
        }

    # Initialize variables
    final_grocery_list = {}
    subtotal_cost = 0

    # Loop through each item in grocery list
    for item in grocery_list:
        # If the item is not in stock
        if item not in stock:
            print("The item", item, "is currently not in stock.")
        else:
            quantity = grocery_list[item]
            
            # If the quantity is greater than stock
            if quantity > stock[item]:
                stock_wanted = input("Only " + str(stock[item]) + " of item " + item + " is availble. Do you want that amount? (y/n)")

                if stock_wanted.lower() == 'y':
                    # Update final grocery list and subtotal cost
                    final_grocery_list[item] = stock[item]
                    subtotal_cost += prices[item] * stock[item]
                    
                    # Remove item from stock
                    del stock[item]
                    del prices[item]
            else:
                # Update final grocery list and subtotal cost
                final_grocery_list[item] = quantity
                subtotal_cost += prices[item] * quantity
                
                # Subtract quantity from stock
                stock[item] = stock[item] - quantity
        
    
    # Calculate tax and total cost
    tax = subtotal_cost * 0.065
    total_cost = subtotal_cost + tax

    # Print subtotal, tax, and total cost
    print("%10s$%05.2f" % ("Subtotal: ", subtotal_cost))
    print("%10s$%05.2f" % ("Tax: ", tax))
    print("%10s$%05.2f" % ("Total: ", total_cost))

    return round(total_cost, 2), final_grocery_list

def primes(n):
    """
    Find's the nth prime number and the floating point approximation of the nth prime number, given the input n.
    The prime number approximation is p(n) = n * ln(n) + n * (ln(ln(n)) - 0.9385). Only valid for n > 1.

    If n is 0, both outputs are 0.
    If n is 1, the first prime number is 2 and the approximation is 0.

    prime_num, p = primes(n)

    Inputs:
        n: The nth prime number to find.
    
    Outputs:
        prime_num: The nth prime number.
        p: The floating point approximation of the nth prime number.

    William Carden primes function
    EGR 101-02
    Due Date: 04/22/2025
    """

    import math

    n = int(n)  # Convert n to integer

    if n < 1: # If n is less than 1.
        return 0, 0
    elif n == 1: # If n is 1.
        return 2, 0

    # Find the nth prime number
    prime_count = 0
    prime_num = 0
    primes_list = [1] * n * 100
    primes_list[0] = 0
    num = 1

    for i in primes_list:
        if i == 1:
            prime_count += 1
            for j in range(num * 2, n * 100, num):
                primes_list[j - 1] = 0
        
        if prime_count == n:
            prime_num = num
            break

        num = num + 1

    # Find the floating point approximation of the nth prime number
    p = n * math.log(n) + n * (math.log(math.log(n)) - 0.9385)

    return prime_num, p

def PrimeBonus(filename):
    """
    Calculates the nth prime number and the difference between the nth prime number and its floating point approximation.

    Calculation done for all n values from 1 to 1000.

    Outputs to the CSV file given.

    Inputs:
        filename: The name of the CSV file to output the results to.

    William Carden PrimeBonus function
    EGR 101-02
    Due Date: 04/22/2025
    """

    import csv

    outputs = []

    # Loop through n values from 1 to 1000
    for N in range(1, 1001):
        n, p = primes(N)

        error = n - p
        outputs.append([n, error])

    # Write results to CSV file
    with open(filename, 'w', newline='') as output_file:
        writer = csv.writer(output_file, delimiter=',')

        # Write header
        writer.writerow(['n', 'Error'])

        # Write data
        for n, error in outputs:
            writer.writerow([n, error])