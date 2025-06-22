//***********************************************************
// LeapYear program
// This program inputs a year and outputs whether the year
// is a leap year
//***********************************************************

#include <iostream>  // Access output stream

using namespace std;

bool IsLeapYear(int year);  // Prototype for subalgorithm

int main() {
  int year;  // Will hold year to be tested
  cout << "Enter a year AD, for example, 1997." << endl;  // Prompt for input
  cin >> year;  // Read value into year

  if (IsLeapYear(year))  // Test for leap year
    cout << year << " is a leap year." << endl;
  else
    cout << year << " is not a leap year." << endl;

  return 0;  // Indicate successful completion
}

//**********************************************************

bool IsLeapYear(int year)

// IsLeapYear returns true if year is a leap year and
// false otherwise.

{
  if (year % 4 != 0)    // Is year not divisible by 4?
    return false;       // If so, can't be a leap year
                        // Must be divisible by 4 at this point
  if (year % 100 != 0)  // Is year not a multiple of 100?
    return true;        // If so, is a leap year
                        // Must be divisible by 100 at this point
  if (year % 400 != 0)  // Is year not a multiple of 400?
    return false;       // If so, is not a leap year
                        // Must be divisible by 400 at this point
  return true;          // Is a leap year
}
