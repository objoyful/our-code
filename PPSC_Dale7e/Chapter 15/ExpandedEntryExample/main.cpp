//*****************************************************************
// DRIVER for class ExpandedEntry
// This program tests the constructors and return functions
//*****************************************************************

#include <iostream>
#include <string>

#include "ExpandedEntry.h"
#include "RelationType.h"

using namespace std;

int main() {
  Name name1("Sally", "Jane", "Smith");
  TimeOfDay time1(12, 20, 0);
  Name name2("Mary", "Beth", "Jones");
  TimeOfDay time2(10, 30, 0);
  ExpandedEntry entry1(name1, time1);
  ExpandedEntry entry2(name2, time2);
  cout << "Entry 1: " << entry1.GetName().GetLastName() << endl
       << entry1.GetTime().GetHours() << ":" << entry1.GetTime().GetMinutes()
       << endl;
  cout << "Entry 2: " << entry2.GetName().GetLastName() << endl
       << entry2.GetTime().GetHours() << ":" << entry2.GetTime().GetMinutes()
       << endl;
  switch (entry1.ComparedTo(entry2)) {
    case BEFORE:
      cout << "entry1 comes before entry2" << endl;
      break;
    case SAME:
      cout << "two entries are the same" << endl;
      break;
    case AFTER:
      cout << "entry1 comes after entry2" << endl;
      break;
  }
  switch (entry2.ComparedTo(entry1)) {
    case BEFORE:
      cout << "entry2 comes before entry1" << endl;
      break;
    case SAME:
      cout << "two entries are the same" << endl;
      break;
    case AFTER:
      cout << "entry2 comes after entry1" << endl;
      break;
  }
  switch (entry1.ComparedTo(entry1)) {
    case BEFORE:
      cout << "entry1 comes before entry2" << endl;
      break;
    case SAME:
      cout << "two entries are the same" << endl;
      break;
    case AFTER:
      cout << "entry1 comes after entry2" << endl;
      break;
  }

  return 0;
}
