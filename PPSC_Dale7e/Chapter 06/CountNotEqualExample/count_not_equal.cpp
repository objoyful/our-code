//***********************************************************
// This program counts the occurrences of "!=" in a data file
//***********************************************************
#include <fstream>  // For file I/O
#include <iostream>
using namespace std;

int main() {
  int count;        // Number of != operators
  char prevChar;    // Last character read
  char currChar;    // Character read in this iteration
  ifstream inFile;  // Data file

  inFile.open("myfile.dat");  // Attempt to open file
  if (!inFile) {  // If file wouldn't open, display message, terminate program
    cout << "Can't open input file" << endl;
    return 1;
  }
  count = 0;             // Initialize counter
  inFile.get(prevChar);  // Initialize previous value
  inFile.get(currChar);  // Initialize current value
  while (inFile)         // While input succeeds . . .
  {
    if (currChar == '=' &&  // Test for !=
        prevChar == '!')
      count++;             // Increment counter
    prevChar = currChar;   // Update previous value to current
    inFile.get(currChar);  // Get next value
  }
  cout << count << " != operators were found." << endl;
  return 0;
}
