//*************************************************************
// This program reads and sums odd numbers until 10 numbers
// have been read.
//*************************************************************
#include <iostream>
using namespace std;

int main() {
  int count = 0;            // Initialize event counter
  int sum = 0;              // Initialize sum
  bool lessThanTen = true;  // Initialize loop control flag
  int number;               // Used for reading
  cout << "Enter a data set that contains at least 10 odd numbers" << endl;
  while (lessThanTen) {
    cin >> number;        // Get the next value
    if (number % 2 == 1)  // Is the value odd?
    {
      count++;                     // Yes--increment counter
      sum = sum + number;          // Add value to sum
      lessThanTen = (count < 10);  // Update loop control flag
    }
  }
  cout << "The sum of the first 10 odd numbers is " << sum << "." << endl;
  return 0;
}
