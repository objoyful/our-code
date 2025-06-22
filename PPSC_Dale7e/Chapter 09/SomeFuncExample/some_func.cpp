//************************************************************
// This program demonstrates global and local variables
//************************************************************
#include <iostream>
using namespace std;

void SomeFunc(float);

const int A = 17;  // A global constant
int b;             // A global variable
int c;             // Another global
int main() {
  b = 4;  // Assignment to global b
  c = 6;  // Assignment to global c
  SomeFunc(42.8);
  return 0;
}

//*******************************************************

void SomeFunc(float c)  // Prevents access to global c
{
  float b;  // Prevents access to global b

  b = 2.3;               // Assignment to local b
  cout << " A = " << A;  // Output global A (17)
  cout << " b = " << b;  // Output local b (2.3)
  cout << " c = " << c;  // Output local c (42.8)
}
