//***********************************************************
// EchoLine program
// This program reads and echoes the characters from one line
// of an input file
//***********************************************************
#include <fstream>  // For file I/O
#include <iostream>

using namespace std;

int main() {
  char inChar;      // An input character
  ifstream inFile;  // Data file

  inFile.open("text.dat");  // Attempt to open input file
  if (!inFile)              // Was it opened?
  {
    cout << "Can't open the input file.";  // No--display message
    return 1;                              // Terminate program
  }
  inFile.get(inChar);  // Get first character
  while (inChar != '\n') {
    cout << inChar;      // Echo it
    inFile.get(inChar);  // Get next character
  }
  cout << endl;
  return 0;
}
