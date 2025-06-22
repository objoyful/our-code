//******************************************************************
// Test driver for class ExtTime that inherits from TimeOfDay
//******************************************************************
#include <iostream>

#include "ExtTime.h"  // For ExtTime class
#include "RelationType.h"

using namespace std;
string TZString(ExtTime time);
// Returns a string representing the time zone
void Compare(ExtTime time1, ExtTime time2);
// Prints the result of comparison of time1 and time2

int main() {
  ExtTime time1(5, 30, 0, EST);  // Parameterized constructor used
  ExtTime time2;                 // Create a time of 0:00:00 PST

  Compare(time1, time2);
  time2 = time1;
  Compare(time1, time2);
  ExtTime time3(5, 15, 0, CST);
  Compare(time1, time3);
  Compare(time3, time1);
  ExtTime time4(3, 5, 0, MST);
  Compare(time1, time4);
  Compare(time4, time1);
  ExtTime time5(3, 30, 0, PST);
  Compare(time1, time5);
  Compare(time5, time1);
}

string TZString(ExtTime time) {
  switch (time.GetZone()) {
    case PST:
      return "PST";
    case MST:
      return "MST";
    case CST:
      return "CST";
    case EST:
      return "EST";
  }
}

void Compare(ExtTime time1, ExtTime time2) {
  cout << "Time1: " << time1.GetHours() << ":" << time1.GetMinutes() << " "
       << TZString(time1) << endl;
  cout << "Time2: " << time2.GetHours() << ":" << time2.GetMinutes() << " "
       << TZString(time2) << endl;
  switch (time1.ExtTime::ComparedTo(time2)) {
    case BEFORE:
      cout << "Time1 comes before time2" << endl;
      break;
    case SAME:
      cout << "Time1 is the same as time2" << endl;
      break;
    case AFTER:
      cout << "Time1 comes after time2" << endl;
      break;
  }
}
