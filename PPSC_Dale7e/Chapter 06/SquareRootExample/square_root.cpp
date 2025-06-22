//************************************************************
// This program calculates a square root using approximations.
//************************************************************
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  float square;
  float guess;
  cout << "Enter a floating-point value" << endl;
  cin >> square;
  guess = square / 4.0;
  bool goodEnough = false;
  while (!goodEnough) {
    guess = ((square / guess) + guess) / 2.0;
    cout << guess << endl;
    goodEnough = fabs(square - guess * guess) < 0.001;
  }
  cout << "The square root of " << square << " is " << guess << endl;
  return 0;
}
