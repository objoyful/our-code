//*****************************************************************
// DRIVER for class SortedList of Entry objects
//*****************************************************************
#include <iostream>
#include <string>

#include "Entry.h"
#include "RelationType.h"
#include "SortedList.h"

using namespace std;

int main() {
  SortedList list;
  Entry entry1("Sally", "Jane", "Smith", 12, 20, 0);
  Entry entry2("Mary", "Beth", "Jones", 10, 30, 0);
  Entry entry3("Bill", "John", "Baker", 8, 25, 30);
  list.Insert(entry1);
  list.Insert(entry2);
  list.Insert(entry3);
  if (list.IsThere(entry2))
    cout << "Duplicate: " << entry2.GetNameStr() << " not inserted" << endl;
  list.ResetList();
  while (list.HasNext()) {
    entry1 = list.GetNextItem();
    cout << entry1.GetNameStr() << " " << entry1.GetTimeStr() << endl;
  }
}
