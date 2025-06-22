//*****************************************
// This is a test driver for class Date
//****************************************
#include <iostream>

#include "Date.h"
using namespace std;

int main() {
  Date date1(1, 1, 2023);
  Date date2(2, 2, 2022);
  if (date1 > date2) cout << "date1 is greater than date2" << endl;
  if (date2 < date1) cout << "date2 is less than date1" << endl;
  if (date1 == date1) cout << "date1 is equal to date1" << endl;
  return 0;
}
