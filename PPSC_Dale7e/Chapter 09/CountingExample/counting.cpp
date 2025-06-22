//********************************************************
// This program demonstrates the use of a static variable
//********************************************************
#include <iostream>
using namespace std;

void counting();

void Counting();
// Function Counting outputs the value of a counter
// each time it is called
int main() {
  for (int count = 1; count <= 10; count++) counting();
  return 0;
}

//********************************************************

void counting() {
  static int counter = 0;  // counter is defined once, and its
                           // value is not reinitialized to 0 on
                           // subsequent calls to counting()
  counter++;
  cout << "count: " << counter << endl;
}  // counter is not deallocated here
