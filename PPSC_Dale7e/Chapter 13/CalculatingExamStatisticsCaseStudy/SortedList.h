#ifndef SORTEDLIST_H
#define SORTEDLIST_H

#include <string>

#include "Student.h"

using namespace std;

//******************************************************************
// SPECIFICATION FILE (SortedList.h)
// This file gives the specification of a SortedList abstract data
// type. The components are assumed to be in order by value.
//******************************************************************
const int MAX_LENGTH = 100;  // Maximum number of components
typedef Student ItemType;    // Type of each component

class SortedList {
 public:
  // Action responsibilities
  void Insert(ItemType item);
  // Pre:  List is not full, item is not in the list, and
  //       the list items are sorted in ascending order
  // Post: item is in the list, length has been incremented, and
  //       the list items are sorted in ascending order
  void Delete(ItemType item);
  // Pre:  The list items are sorted in ascending order
  // Post: item is not in the list and the list items are sorted
  //       in ascending order
  void ResetList();
  // The current position is reset to access the first item in the list
  ItemType GetNextItem();
  // Assumptions:  No transformers are called during the iteration.
  // There is an item to be returned; that is, HasNext is true when
  // this method is invoked.
  // Pre:  ResetList has been called if this is not the first iteration.
  // Post: Returns item at the current position.
  // Knowledge responsibilities
  bool IsEmpty() const;
  // Post: Returns true if list is empty; false otherwise
  bool IsFull() const;
  // Post: Returns true if list if full; false otherwise
  int GetLength() const;
  // Post: Returns the length of the list
  bool IsThere(ItemType item) const;
  // Post: Returns true if item is in the list and false otherwise
  bool HasNext() const;
  // Returns true if there is another item to be returned; false
  // otherwise

  SortedList();
  // Constructor
  // Post: Empty list has been created

 private:
  int length;
  int currentPos;
  ItemType data[MAX_LENGTH];
  void BinarySearch(ItemType item, bool& found, int& position) const;
};

#endif  // SORTEDLIST_H
