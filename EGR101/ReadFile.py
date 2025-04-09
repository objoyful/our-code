def ReadFile(filename):
    """
    Calculates the minimum, maximum, average, and standard deviation of the columns of a CSV file.
    Prints a table with the results.

    ReadFile(filename)

    Input:
    filename: name of csv file

    William Carden ReadFile function
    EGR 101-02
    Due Date: 04/08/2025
    """

    import csv, statistics

    # Open the input file
    with open(filename, newline='') as input_file:
        filedata = csv.reader(input_file, delimiter=',')

        data = [] # Create empty data array
        first_row = True # Create first row flag

        # Loop through rows in file
        for row in filedata:
            column_num = 0 # Reset column num
            
            # Loop through columns in row
            for column in row:
                # Add empty arrays the first iteration
                if first_row:
                    data.append([])
                
                # Append data to list
                data[column_num].append(float(column))
                column_num += 1
            
            first_row = False
    
    # Calculate the number of columns and rows
    num_columns = len(data)
    num_rows = len(data[0])

    print(filename, "has", num_rows, "rows of data in", num_columns, "columns")
    print("%s%10s%10s%10s%10s" %("Column","Min", "Max", "Average", "Std Dev"))
    
    column_num = 1
    for column in data:
        # Calculate min, max, average, and standard deviation
        min_val = min(column)
        max_val = max(column)
        avg_val = sum(column) / len(column)
        std_dev = statistics.stdev(column)

        print("%6g%10.4f%10.4f%10.4f%10.4f" %(column_num, min_val, max_val, avg_val, std_dev))  

        column_num += 1