//******************************************************************
// This program creates two time objects and manipulates them using
// get functions and a comparison function
//******************************************************************
#include <iostream>

#include "TimeOfDay.h"  // For TimeOfDay class
using namespace std;

int main() {
  TimeOfDay time1(5, 30, 0);
  TimeOfDay time2;

  cout << "time1: " << time1.GetHours() << ':' << time1.GetMinutes() << '/'
       << time1.GetSeconds() << endl;
  cout << "time2: " << time1.GetHours() << ':' << time2.GetMinutes() << ':'
       << time2.GetSeconds() << endl;

  switch (time1.ComparedTo(time2)) {
    case BEFORE:
      cout << "first time comes before second time" << endl;
      break;
    case SAME:
      cout << "times are the same" << endl;
      break;
    case AFTER:
      cout << "second time comes before first time" << endl;
      break;
  }

  switch (time2.ComparedTo(time1)) {
    case BEFORE:
      cout << "first time comes before second time" << endl;
      break;
    case SAME:
      cout << "times are the same" << endl;
      break;
    case AFTER:
      cout << "second time comes before first time" << endl;
      break;
  }

  switch (time1.ComparedTo(time1)) {
    case BEFORE:
      cout << "first time comes before second time" << endl;
      break;
    case SAME:
      cout << "times are the same" << endl;
      break;
    case AFTER:
      cout << "second time comes before first time" << endl;
      break;
  }
  return 0;
}
