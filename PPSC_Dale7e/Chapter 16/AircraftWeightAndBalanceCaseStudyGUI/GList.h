#ifndef GLIST_H
#define GLIST_H

//******************************************************************
// SPECIFICATION (glist.h)
// This is the specification of a generic List ADT.
// The list components are not assumed to be in order by value,
// the maximum length of the list is 100 components, and the
// components must be comparable with the relational operators.
//******************************************************************

const int MAX_LENGTH = 100;  // Maximum number of components

template <class ItemType>  // Type of each component
class GList {
 public:
  GList();
  // Action responsibilities
  void Insert(const ItemType& item);
  void Delete(const ItemType& item);
  void ResetList();
  ItemType GetNextItem();
  // Knowledge responsibilities
  int GetLength() const;
  bool IsEmpty() const;
  bool IsFull() const;
  bool IsThere(const ItemType& item) const;
  bool HasNext() const;

 private:
  int length;
  int currentPos;
  ItemType data[MAX_LENGTH];
};

//******************************************************************
// IMPLEMENTATION Code
// Following is the implementation of the GList member functions
// List representation: a one-dimensional array and a length
//  variable
//******************************************************************

#include <iostream>

using namespace std;

template <class ItemType>
GList<ItemType>::GList()  // Constructor
{
  length = 0;
  currentPos = 0;
}
//******************************************************************

template <class ItemType>
bool GList<ItemType>::IsEmpty() const {
  return (length == 0);
}

//******************************************************************

template <class ItemType>
bool GList<ItemType>::IsFull() const {
  return (length == MAX_LENGTH);
}

//******************************************************************

template <class ItemType>
int GList<ItemType>::GetLength() const {
  return length;
}

//******************************************************************

template <class ItemType>
void GList<ItemType>::Insert(const ItemType& item) {
  data[length] = item;
  length++;
}

//******************************************************************

template <class ItemType>
void GList<ItemType>::Delete(const ItemType& item) {
  int index = 0;

  while (index < length && item != data[index]) index++;
  if (index < length) {
    data[index] = data[length - 1];
    length--;
  }
}

//******************************************************************

template <class ItemType>
bool GList<ItemType>::IsThere(const ItemType& item) const {
  int index = 0;

  while (index < length && item != data[index]) index++;
  return (index < length);
}

//******************************************************************

template <class ItemType>
void GList<ItemType>::ResetList() {
  currentPos = 0;
}

//******************************************************************

template <class ItemType>
bool GList<ItemType>::HasNext() const {
  return (currentPos != length);
}

//******************************************************************

template <class ItemType>
ItemType GList<ItemType>::GetNextItem() {
  ItemType item;
  item = data[currentPos];
  currentPos++;
  return item;
}

#endif  // GLIST_H
