def fileRW(input_filename, output_filename):
    """
    Takes the average of a group of data points from an input file and outputs it into an output file.
    Any lines at the beginning of the file that are not numbers are ignored.
    Asks the user for the number of data points to average. The first line of the output file explains the group size.
    If there's less data points than the group size, the leftover points are ignored.

    fileIO()

    Inputs:
        input_file: The input file name.
        output_file: The output file name.

    William Carden fileRW function
    EGR 101-02
    Due Date: 04/10/2025
    """

    import csv

    # Open the input file
    with open(input_filename, newline='') as input_file:
        readfile = csv.reader(input_file, delimiter='*')

        # Create a list to store header data
        header = []
        in_header = True

        for row in readfile:
            if in_header: # If we are in the header
                try:
                    # Attempt to convert first item to float
                    col = float(row[0])
                    col1 = []; col2 = []
                    
                    # We are no longer in the header if successful
                    in_header = False

                except:
                    # If we can't convert to float, add row to header
                    header.append(row)
            else: # If we are not in the header
                col1.append(float(row[0]))
                col2.append(float(row[1]))

    # Find amount of data points
    num_len = len(col1)

    while True:
        try:
            # Prompt user for group size
            m = int(input("How many points do you want to average? "))

            # If the group size is too large, prompt again
            if m > num_len:
                print("Group size is too large please pick again.")
            else:
                break

        except:
            print("Invalid input, please try again.")


    # Open the output file
    with open(output_filename, 'w', newline='') as output_file:
        output_data = csv.writer(output_file, delimiter=',')

        # Write group size information
        output_data.writerow(["Data file with " + str(m) + " point averages."])

        # Write the header to the output file
        for row in header:
            output_data.writerow(row)

        # Write averages to output file
        for i in range(int(len(col1)/m)): # Loop through each group of 10 data points
            
            avg1 = 0; avg2 = 0

            for j in range(m): # Loop therough each data point in the group
                avg1 += col1[i*m + j]
                avg2 += col2[i*m + j]


            avg1 /= m
            avg2 /= m

            # Write the averages to the output file
            output_data.writerow([avg1, avg2])