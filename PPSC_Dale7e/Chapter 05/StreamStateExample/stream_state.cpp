//*********************************************************
// StreamState program
// This program demonstrates testing the state of a stream
//*********************************************************
#include <fstream>  // For file I/O
#include <iostream>
using namespace std;
int main() {
  int height;
  int width;
  ifstream inFile;

  inFile.open("measures.dat");  // Attempt to open file
  if (!inFile)                  // Was it opened?
  {
    cout << "Can't open the input file.";  // No--display message
    return 1;                              // Terminate program
  }
  inFile >> height >> width;
  cout << "For a height of " << height << endl
       << "and a width of " << width << endl
       << "the area is " << height * width << endl;
  return 0;
}
