//*****************************************************************
// DRIVER for class Entry
// This program tests the constructors and return functions
//*****************************************************************
#include <iostream>
#include <string>

#include "Entry.h"
using namespace std;
int main() {
  Entry entry1("Sally", "Jane", "Smith", 12, 20, 0);
  Entry entry2("Mary", "Beth", "Jones", 10, 30, 0);

  cout << "Entry 1: " << entry1.GetNameStr() << " " << entry1.GetTimeStr()
       << endl;
  cout << "Entry 2: " << entry2.GetNameStr() << " " << entry2.GetTimeStr()
       << endl;
  return 0;
}
