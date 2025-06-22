//******************************************
// A program to create two time objects
// and manipulate them
//******************************************
#include <iostream>

#include "TimeOfDay.h"  // For TimeOfDay class
using namespace std;

int main() {
  TimeOfDay time1(5, 30, 0);  // Instantiate two TimeOfDay objects
  TimeOfDay time2;
  int loopCount;

  cout << "time1: ";  // Output them and compare them
  time1.Write();
  cout << "  time2: ";
  time2.Write();
  cout << endl;
  if (time1.Equal(time2))
    cout << "Times are equal" << endl;
  else
    cout << "Times are NOT equal" << endl;

  time2 = time1;  // Set them equal

  cout << "time1: ";  // Output them and compare them
  time1.Write();
  cout << "  time2: ";
  time2.Write();
  cout << endl;

  if (time1.Equal(time2))
    cout << "Times are equal" << endl;
  else
    cout << "Times are NOT equal" << endl;

  time2.Increment();  // Increment one, output and compare
  cout << "New time2: ";
  time2.Write();
  cout << endl;
  if (time1.LessThan(time2))
    cout << "time1 is less than time2" << endl;
  else
    cout << "time1 is NOT less than time2" << endl;

  if (time2.LessThan(time1))
    cout << "time2 is less than time1" << endl;
  else
    cout << "time2 is NOT less than time1" << endl;

  TimeOfDay time4(23, 59, 55);  // Instantiate one near the maximum
  cout << "Incrementing time1 from 23:59:55:" << endl;
  for (loopCount = 1; loopCount <= 10; loopCount++) {
    time4.Write();
    cout << ' ';
    time4 = time4.Increment();  // Check that it overflows properly
  }
  cout << endl;
  return 0;
}
