//***********************************************************
// This program demonstrates a count-controlled loop
//***********************************************************
#include <iostream>

using namespace std;

int main() {
  int loopCount;  // Loop control variable

  loopCount = 1;           // Initialization
  while (loopCount <= 10)  // Test
  {
    cout << "Hello!" << endl;
    loopCount = loopCount + 1;  // Incrementation
  }
  return 0;
}
