def RFile3(infile,dlim):
  """
Reads in header of unknown length and any number of columns
The first input string is the input file name
The second input string delimiter
Solutions by Dr. Daniel Armentrout
EGR 101-02
Due Date: 4/22/2025
IO Assignment
  """
  import csv,statistics
  D=[]     # Initialize empty lists for later use
  HD=[]
  with open(infile, newline='') as I_file:
    reader = csv.reader(I_file, delimiter=dlim)
    check=True
    Header=True  # rowinf is a flag for header information
    for row in reader:
      if Header:
        try:
          test=float(row[0])
          Header=False  # If row has data initialize data setup
          # Make sure D has enough data slots for each column of data
          m=len(row)
          for i in range(m):
            D.append([])
        except ValueError:  # Save header information for output
          HD.append(row)
      if not Header:      
        # Append data to D by column
        for i in range(m):
          D[i].append(float(row[i]))
  return HD,D

def DispData(infile,D):
  """Function to display file specifications
Inputs infile and Data
Displays a Table with the min, max, average,
and standard deviation of every column
code first used in ReadFile assignment
Solutions by Dr. Daniel Armentrout
EGR 101-02
Due Date: 4/22/2025
IO Assignment
   """
  import statistics
  r=len(D[0])
  c=len(D)
  print('The file',infile,'has',str(r),'rows and',str(c),'columns.')
  print('Column  Minimum  Maximum  Average  Std Dev')
  for i in range(c):
    Dmin=min(D[i])
    Dmax=max(D[i])
    Ave=statistics.mean(D[i])  # Average of ith column
    Std=statistics.stdev(D[i]) # Standard Deviation of ith column
    # print out table
    print('%6d %8.4f %8.4f %8.4f %8.4f' %(i+1,Dmin,Dmax,Ave,Std))

def I_input(s,n):
  """Function to input integer value between 1 and
second input. First input is the string to print when
asking for input. Function keeps asking until user
enters valid input. Output is the integer input
used first in FileRW assignment
Solutions by Dr. Daniel Armentrout
EGR 101-02
Due Date: 4/22/2025
IO Assignment
   """
  Good_Input=False
  while not Good_Input: # Repeat loop until valid input
    ss=input(s)
    try:
      m=int(float(ss)) # Truncate floating point number
      if m>0:
        if m<=n:
          Good_Input=True
        else:          # Input too large
          print("Value needs to be less than",n)          
      else:            # Input negative or 0
        print("Please enter a positive integer!")
    except ValueError: # Input not a number
      print("Input cannot be a string!")
  return m    

def W_Mave(o_file,HD,D,q):
  """Function to write moving average data to unknown columns
Input1: Output Data file
Input2: Head data array
Input3: Data array
Input4: Number of points to average together
second input. First input is the string to print when
asking for input. Function keeps asking until user
enters valid input. Output is the integer input
Solutions by Dr. Daniel Armentrout
EGR 101-02
Due Date: 4/22/2025
IO Assignment
   """
  import csv
  # Open output data file
  m=len(D)
  with open(o_file, 'w', newline='') as Ofile:
    writer = csv.writer(Ofile, delimiter=",")
    for row in HD:
      writer.writerow(row)
    L=len(D[0])-q+1        # L is number of data rows
    for i in range(L):     # Calculate for current row i
      ave=[]               # Clear ave for next row
      avestr=[]            # Clear avestr for next row
      for a in range(m):   # Set ave to zero
        ave.append(0) 
      for j in range(q):   # Loop through every j in the average
        for k in range(m): # Sum up data before average for k column
          ave[k]+=D[k][i+j]
      for k in range(m):   # Divide sum by number of data points for average
        ave[k]/=q
        avestr.append(str(ave[k]))
      writer.writerow(avestr)  # Output data row to file

def IO(infile,outfile):
  """
Averages row data together for any number of columns
The first input string is the input file name
The second input string is the output file name
Solutions by Dr. Daniel Armentrout
EGR 101-02
Due Date: 4/22/2025
IO Assignment
  """
  import os
  ave=[]         # Initialize empty lists for later use
  avestr=[]
  if os.path.exists(infile):
    HData,Data=RFile3(infile,',')  # Read file
    DispData(infile,Data)          # Display Data
    # Get number of points for moving average
    q=I_input('Number of data points for the moving average? ',len(Data[0]))
    # Add line to the header about the moving average
    Hnew='This file is a moving average of '+str(q)+' points.'    
    HData.append([Hnew])
    W_Mave(outfile,HData,Data,q)   # Output the data file
  else:
    print('Input file does not exist.')


# Comment out for submission
# Remove comments for testing
IO('EGR101/ExData2.csv','ExOut_trout.csv')
