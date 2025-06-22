//*****************************************************************
// DRIVER for class sorted list of class Entry
// This program tests the constructors and return functions
//*****************************************************************
#include <iostream>
#include <string>

#include "SortedList.h"

using namespace std;

int main() {
  SortedList list;
  Entry entry1("Sally", "Jane", "Smith", 12, 20, 0);  // Create 1st entry
  if (!list.IsThere(entry1)) list.Insert(entry1);     // Insert 1st entry
  Entry entry2("Mary", "Beth", "Jones", 10, 30, 0);   // Create 2nd entry
  if (!list.IsThere(entry2)) list.Insert(entry2);     // Insert 2nd entry
  if (!list.IsThere(entry2)) list.Insert(entry2);     // Try insert again
  Name name("Susy", "Nell", "Baxter");                // Create name
  TimeOfDay time(8, 30, 0);                           // Create time
  Entry entry3(name, time);                           // Test constructor
  if (!list.IsThere(entry3)) list.Insert(entry3);     // Insert 3rd entry
  list.ResetList();                                   // Reset position
  while (list.HasNext())                              // Output list items
  {
    entry1 = list.GetNextItem();
    cout << entry1.GetNameStr() << " " << entry1.GetTimeStr() << endl;
  };

  return 0;
}
