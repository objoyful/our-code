//*************************************************
// This program creates an array of four
// items, stores values into the four
// places, and overruns the array by two places
// ************************************************

#include <iostream>
using namespace std;
int main() {
  int data[4];
  for (int i = 1; i <= 4; i++)  // Fill all 4 elements of array
    data[i] = i;
  for (int i = 1; i <= 6; i++)  // Output 6 elements--error
    cout << data[i] << endl;
  return 0;
}
