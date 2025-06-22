//******************************************************************
// This program calculates and outputs the tuition refund
// owed a student given the beginning and ending dates of the
// semester and the withdrawal date
//******************************************************************

#include <iomanip>
#include <iostream>
using namespace std;

const float TUITION = 35000.0;

bool IsLeapYear(int year);  // Prototype for subalgorithm
// Returns true if the year is a leap year

int Day(int month, int dayOfMonth, int year);
// This function computes and returns the day number within a year,
// given the date. It accounts correctly for leap years
// Pre:  The month, day, and year are within the proper range

int main() {
  int month, day, year;
  int start, last, withdraw;
  float fraction;
  float refund;

  cout << "Enter the month, day, and year of beginning of semester." << endl;
  cin >> month >> day >> year;
  start = Day(month, day, year);

  cout << "Enter the month, day, and year of end of semester." << endl;
  cin >> month >> day >> year;
  last = Day(month, day, year);

  cout << "Enter the month, day, and year of withdrawal." << endl;
  cin >> month >> day >> year;
  withdraw = Day(month, day, year);

  fraction = static_cast<float>(last - withdraw + 1) /
             static_cast<float>(last - start + 1);
  refund = TUITION * fraction;
  cout << "The student gets a refund of $" << fixed << setprecision(2) << refund
       << endl;

  return 0;
}

//****************************************************************

int Day(int month, int dayOfMonth, int year)
// This function computes and returns the day number within a year,
// given the date. It accounts correctly for leap years
// Pre:  The month, day, and year are within the proper range
{
  int correction = 0;  // Correction factor to account for leap year

  if (IsLeapYear(year)) correction = 1;  // Then add one for leap year
  // Correct for different-length months
  switch (month) {
    case 3:
      correction = correction - 1;
      break;
    case 8:
      correction = correction + 2;
      break;
    case 2:
    case 6:
    case 7:
      correction = correction + 1;
      break;
    case 9:
    case 10:
      correction = correction + 3;
      break;
    case 11:
    case 12:
      correction = correction + 4;
      break;
  }
  return (month - 1) * 30 + correction + dayOfMonth;
}

//******************************************************

bool IsLeapYear(int year)
// IsLeapYear returns true if year is a leap year and
// false otherwise

{
  if (year % 4 != 0)         // Is year not divisible by 4?
    return false;            // If so, can't be a leap year
  else if (year % 100 != 0)  // Is year not a multiple of 100?
    return true;             // If so, is a leap year
  else if (year % 400 != 0)  // Is year not a multiple of 400?
    return false;            // If so, then is not a leap year
  else
    return true;  // Is a leap year
}
