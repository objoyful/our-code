//******************************************************************
// IMPLEMENTATION FILE (SortedList.cpp)
// This file implements the SortedList class member functions
//******************************************************************
#include "SortedList.h"

#include "RelationType.h"

SortedList::SortedList() {
  length = 0;
  currentPos = 0;
}

bool SortedList::IsEmpty() const { return (length == 0); }

bool SortedList::IsFull() const { return (length == MAX_LENGTH); }

int SortedList::GetLength() const { return length; }

void SortedList::Insert(ItemType item)
// Search for insertion point begins at the end. Items are compared
// and shifted until insertion place is found
{
  int index;
  index = length - 1;
  while (index >= 0 && item.ComparedTo(data[index]) == BEFORE) {
    data[index + 1] = data[index];
    index--;
  }
  data[index + 1] = item;  // Insert item
  length++;
}

void SortedList::Delete(ItemType item)
// Calls helper function BinarySearch to find if the item is in the list
// and the index position if there
{
  bool found;    // True if item is found
  int position;  // Position of item, if found
  int index;     // Index and loop control variable

  BinarySearch(item, found, position);
  if (found) {
    // Shift data[position..length-1] up one position
    for (index = position; index < length - 1; index++)
      data[index] = data[index + 1];
    length--;
  }
}

bool SortedList::IsThere(ItemType item) const
// Calls helper function BinarySearch to look for item
{
  bool found;
  int position;  // Not used but required for BinarySearch
  BinarySearch(item, found, position);
  return found;
}

void SortedList::ResetList() { currentPos = 0; }

bool SortedList::HasNext() const { return (currentPos != length); }

ItemType SortedList::GetNextItem() {
  ItemType item;
  item = data[currentPos];
  currentPos++;
  return item;
}

void SortedList::BinarySearch(ItemType item, bool& found, int& position) const
// Uses binary search algorithm to search list for item.
// If item is found, found is true and position is its index;
// else found is false and position is undefined
{
  int first = 0;          // Lower bound on list
  int last = length - 1;  // Upper bound on list
  int middle;             // Middle index
  found = false;
  while (last >= first && !found) {
    middle = (first + last) / 2;
    switch (item.ComparedTo(data[middle])) {
      case BEFORE:
        last = middle - 1;
        break;
      case SAME:
        found = true;
        position = middle;
        break;
      case AFTER:
        first = middle + 1;
        break;
    }
  }
}
