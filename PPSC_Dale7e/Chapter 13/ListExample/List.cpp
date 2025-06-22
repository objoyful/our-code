//******************************************************************
// IMPLEMENTATION FILE (List.cpp)
// This file implements the List class member functions
//******************************************************************
#include "List.h"

#include <iostream>
using namespace std;

List::List() {
  length = 0;
  currentPos = 0;
}

bool List::IsEmpty() const { return (length == 0); }

bool List::IsFull() const { return (length == MAX_LENGTH); }

int List::GetLength() const { return length; }

void List::Insert(ItemType item) {
  data[length] = item;
  length++;
}

void List::Delete(ItemType item) {
  int index = 0;
  while (index < length && item != data[index]) index++;
  if (index < length)  // item found
  {
    data[index] = data[length - 1];
    length--;
  }
}

bool List::IsThere(ItemType item) const {
  int index = 0;  // Index variable
  while (index < length && item != data[index]) index++;
  return (index < length);
}

void List::ResetList() { currentPos = 0; }

bool List::HasNext() const { return (currentPos != length); }

ItemType List::GetNextItem() {
  ItemType item;
  item = data[currentPos];
  currentPos++;
  return item;
}
