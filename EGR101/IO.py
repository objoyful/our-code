def IO(input_filename, output_filename):
    """
    Creates an output file with moving averages from an input file.
    The amount of data points to average is determined by the user.
    Statistics about the filename, number of rows, columns, and the min, max, avaerage, and standard deviation of each column is printed.
    Header information is ignored. The length of the moving averages is included in the output file.

    IO(input_filename, output_filename)

    Inputs:
        input_filename: The input file name.
        output_filename: The output file name.

    William Carden IO function
    EGR 101-02
    Due Date: 04/15/2025
    """

    import os

    # If input file does exist, create moving average file.
    if os.path.exists(input_filename):
        # Gather input data and statistics
        header, data = ReadCSV(input_filename)
        num_row, num_col, min_val, max_val, avg_val, std_val = find_statistics(data)

        # Print statistics
        print("The file", input_filename, "has", num_row, "rows and", num_col, "columns.")
        print("%s%10s%10s%10s%10s" %("Column", "Min", "Max", "Average", "Std Dev"))
    
        for col in range(num_col):
            print("%6g%10.4f%10.4f%10.4f%10.4f" %(col + 1, min_val[col], max_val[col], avg_val[col], std_val[col]))

        # Gather input for size of moving average
        good_input = False
        while not good_input:
            try:
                m = int(input("What is the size of the moving average? "))

                if m > num_row:
                    print("Size is larger than the number of rows, please pick another number.")
                elif m < 1:
                    print("Size is less than 1, please pick another number.")
                else:
                    good_input = True
            except:
                print("Input must be a number please try again.")
        
        # Gather and write moving average data
        mavg_data = MovingAverage(data, m)
        WriteCSV(output_filename, header, m, mavg_data)
    
    # If input file does not exist, say so.
    else:
        print("Input file does not exist.")
        

def ReadCSV(input_filename):
    """
    Reads CSV file and returns header information and data.

    header, data = ReadFile(input_filename)

    Inputs:
        input_filename: The input file name.

    Outputs:
        header: Header information.
        data: Data from file in 2D array.

    William Carden ReadCSV function
    EGR 101-02
    Due Date: 04/15/2025
    """
    import csv

    # Read input file
    with open(input_filename, newline='') as input_file:
        readfile = csv.reader(input_file, delimiter=',')

        # Create a list to store header data
        header = []
        data = []
        
        in_header = True

        for row in readfile:
            if in_header: # If we are in the header
                try:
                    # Attempt to convert first item to float
                    float(row[0])
                    
                    new_row = []
                    for col in row:
                        new_row.append(float(col))
                    
                    data.append(new_row)
                    
                    # We are no longer in the header if successful
                    in_header = False

                except:
                    # If we can't convert to float, add row to header
                    header.append(row)
            else: # If we are not in the header
                # Append row
                new_row = []
                for col in row:
                    new_row.append(float(col))
                
                data.append(new_row)

    return header, data

def find_statistics(data):
    """
    Finds the number of rows, columns, and the min, max, avaerage, and standard deviation of each column in the given data.

    num_row, num_col, min_val, max_val, avg_val, std_val = find_statistics(data)

    Inputs:
        data: Input data.

    Outputs:
        num_row: Number of rows in data.
        num_col: Number of columns in data.
        min_val: Minimum value in each column.
        max_val: Maximum value in each column.
        avg_val: Average value in each column.
        std_val: Standard deviation in each column.

    William Carden find_statistics function
    EGR 101-02
    Due Date: 04/15/2025
    """

    import statistics

    # Find number of rows and columns
    num_row = len(data)
    num_col = len(data[0])


    # Convert to column arrays
    cols = []
    first_row = True


    for row in data:
        col_num = 0
        for col in row:
            # If first row, append empty list
            if first_row:
                cols.append([])
            
            cols[col_num].append(col)
            col_num += 1

        first_row = False

    # Find minimum value in each column
    min_val = []
    for col in cols:
        min_val.append(min(col))

    # Find maximum value in each column
    max_val = []
    for col in cols:
        max_val.append(max(col))
    
    # Find average value in each column
    avg_val = []
    for col in cols:
        avg_val.append(sum(col) / len(col))
    
    # Find standard deviation in each column
    std_val = []
    for col in cols:
        std_val.append(statistics.stdev(col))
    
    return num_row, num_col, min_val, max_val, avg_val, std_val

def MovingAverage(data, m):
    """
    Calculates the moving average of m rows given the data.

    mavg_data = MopvingAverage(data, m)

    Inputs:
        data: Input data.
        m: Size of moving average.

    Outputs:
        mavg_data: Moving average data.

    William Carden MovingAverage function
    EGR 101-02
    Due Date: 04/15/2025
    """
    mavg_data = []

    for row_num in range(len(data) - m + 1): # There will be n - m + 1 new rows
        col_num = 0
        row = []
        
        for col_num in range(len(data[0])):
            # The moving average window
            cols = []
            for m_row in data[row_num: row_num + m]:
                cols.append(m_row[col_num])
            
            # Calculate average
            mavg = sum(cols) / m
            row.append(mavg)
        
        mavg_data.append(row)
    
    return mavg_data

def WriteCSV(output_filename, header, m, mavg_data):
    """
    Writes the header, information about the size of the moving average, and the new moving average data to the output file.

    WriteCSV(output_filename, header, m, mavg_data)

    Inputs:
        output_filename: Name of the output file.
        header: Header information.
        m: Size of the moving average.
        mavg_data: Moving average data.

    William Carden WriteCSV function
    EGR 101-02
    Due Date: 04/15/2025
    """

    import csv

    # Write to output file
    with open(output_filename, 'w', newline='') as output_file:
        output_data = csv.writer(output_file, delimiter=',')

        # Write header information
        for row in header:
            output_data.writerow(row)
        
        # Write moving average size information
        output_data.writerow(["The moving average window size of this data is " + str(m)])

        # Write data
        for row in mavg_data:
            output_data.writerow(row)