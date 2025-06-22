//*********************************************************
// This program demonstrates the use of three functions.
//*********************************************************

#include <iostream>

using namespace std;

int Square(int);
int Cube(int);

int main() {  // Start of main function body
  cout << "The square of 27 is " << Square(27) << endl;
  cout << "and the cube of 27 is " << Cube(27) << endl;
  return 0;
}  // End of main function body

int Square(int n) {  // Start of Square function body
  return n * n;
}  // End of Square function body

int Cube(int n) {  // Start of Cube function body
  return n * n * n;
}
