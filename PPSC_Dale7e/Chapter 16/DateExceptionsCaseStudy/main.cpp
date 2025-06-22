//******************************************
// Test driver for class Date, which
// is the Date class with exception handling
//******************************************
#include <iostream>

#include "Date.h"
using namespace std;
int main() {
  int month;
  int day;
  int year;

  cout << "Enter month. Negative month stops test." << endl;
  cin >> month;
  while (month >= 0) {
    cout << "Enter day and year" << endl;
    cin >> day >> year;
    try {
      Date date1(month, day, year);
      cout << "Valid date." << endl;
    } catch (MonthError error) {
      cout << "Attempt to create date with invalid month." << endl;
    } catch (DayError error) {
      cout << "Attempt to create date with invalid day." << endl;
    } catch (YearError error) {
      cout << "Attempt to create date with invalid year." << endl;
    }
    cout << "Enter month.  Negative month stops test." << endl;
    cin >> month;
  }
  return 0;
}
