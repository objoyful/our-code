def euro_con():
    """
    Converts between Euros and US Dollars for values from $20 - $200 and €20 - €200 using the given exchange rate and assuming a 2.5% fee.

    euro_con()

    William Carden euro_con function - Final Question 21 Part 1
    EGR 101-02
    Due Date: 05/01/2025
    """

    rate = 0

    # Keep asking for inputs until a valid number has been sent
    while rate == 0:
        try:
            rate = float(input("Enter the Euro to Dollar conversion rate? ")) # Try converting to float
        except:
            print("Please enter the rate as a value.") # Or else try again

    v = []; e = []; d = []

    # Start Table
    print("Dollars to Euros\t Euros   to Dollars")

    n = 0
    for i in range(20, 220, 20):
        v.append(i)
        e.append(i / rate * 1.025) # Convert to Euro
        d.append(i * rate * 1.025) # Convert to Dollar

        # Print each row of the table.
        print("$%-6.2f = %2s%-12.2f %s%-6.2f =  $%.2f" %(v[n], chr(8364), e[n], chr(8364), v[n], d[n]))
        n += 1

def Rstat(name, n):
    """
    Writes a spreadsheet to the given filename with (n x n) rows and columns consisting of random numbers between 0 and 10.
    Returns the average value of all the entries.

    av = Rstat(name, n)

    Inputs:
        name: name of file to write contents to
        n: number of rows and columns (n x n)

    Outputs:
        av: average of all values in spreadsheet

    William Carden euro_con function - Final Question 21 Part 2
    EGR 101-02
    Due Date: 05/01/2025
    """

    import random, csv

    # Open CSV file
    with open(name, 'w', newline='') as output_file:
        writer = csv.writer(output_file, delimiter=',')
        total_sum = 0

        # Loop through each row
        for i in range(n):
            rand_row = []
            
            # Loop through each column in row
            for j in range(n):
                # Generate random number and add it to random list.
                rand_row.append(10 * random.random())
            
            # Add sum of row to total.
            total_sum += sum(rand_row)
            # Write random number to CSV.
            writer.writerow(rand_row)
    
    # Calculate and return average.
    av = total_sum / (n ** 2)
    return av