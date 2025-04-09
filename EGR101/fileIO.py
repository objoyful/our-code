def fileIO():
    """
    Takes the average of a group of 10 data points at a time from an input file and outputs it into an output file.
    Any lines at the beginning of the file that are not numbers are ignored.
    If there's less than 10 data point left at the end of the file, they are ignored.

    fileIO()

    William Carden fileIO function
    EGR 101-02
    Due Date: 04/08/2025
    """

    import csv

    # Open the input file
    with open('ExData3.csv', newline='') as input_file:
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

    # Open the output file
    with open('ExOut.csv', 'w', newline='') as output_file:
        output_data = csv.writer(output_file, delimiter=',')

        # Write the header to the output file
        for row in header:
            output_data.writerow(row)

        # Write averages to output file
        for i in range(int(len(col1)/10)): # Loop through each group of 10 data points
            
            avg1 = 0; avg2 = 0

            for j in range(10): # Loop therough each data point in the group
                avg1 += col1[i*10 + j]
                avg2 += col2[i*10 + j]


            avg1 /= 10
            avg2 /= 10

            # Write the averages to the output file
            output_data.writerow([avg1, avg2])