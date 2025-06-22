//******************************************************************
// IMPLEMENTATION FILE (List.cpp)
// This file implements the List class member functions
// List representation: A linked list with head and tail
// pointers, a length field, and a current position pointer.
//******************************************************************
#include "SortedList.h"

#include <cstddef>  // For NULL
#include <iostream>

using namespace std;

typedef NodeType* NodePtr;
struct NodeType {
  ItemType component;
  NodePtr link;
};

SortedList::SortedList()
// Post: dataPtr == NULL
{
  dataPtr = NULL;
  currentPos = dataPtr;
  length = 0;
  lastPtr = NULL;
}

//****************************************************************

SortedList::SortedList(const SortedList& otherList)
// Post: A deep copy of otherList is created and the external pointer
//       now points to this list
{
  NodePtr fromPtr;  // Pointer into list being copied from
  NodePtr toPtr;    // Pointer into new list being built
  if (otherList.dataPtr == NULL) {
    dataPtr = NULL;
    return;
  }
  // Copy first node
  fromPtr = otherList.dataPtr;
  dataPtr = new NodeType;
  dataPtr->component = fromPtr->component;
  // Copy remaining nodes
  toPtr = dataPtr;
  fromPtr = fromPtr->link;
  while (fromPtr != NULL)
  // Copy nodes from original to duplicate
  {
    toPtr->link = new NodeType;             // Store new node in link of
                                            //   last node added to new list
    toPtr = toPtr->link;                    // toPtr points to new node
    toPtr->component = fromPtr->component;  // Copy component to new node
    fromPtr = fromPtr->link;                // fromPtr points to next node
                                            //   of original list
  }
  toPtr->link = NULL;
  lastPtr = toPtr;  // Set last pointer
}

//****************************************************************

SortedList::~SortedList()
// Post: All linked list nodes have been deallocated
{
  NodePtr tempPtr;
  NodePtr currPtr = dataPtr;
  while (currPtr != NULL) {
    tempPtr = currPtr;
    currPtr = currPtr->link;
    delete tempPtr;
  }
}

void SortedList::Insert(ItemType item)
// Post: New node containing item is in its proper place and
//       component members of list nodes are in ascending order

{
  NodePtr currPtr;     // Moving pointer
  NodePtr prevPtr;     // Trailing pointer
  NodePtr newNodePtr;  // Pointer to new node

  newNodePtr = new NodeType;
  newNodePtr->component = item;
  newNodePtr->link = NULL;

  if (dataPtr == NULL)  // Empty list
  {
    dataPtr = newNodePtr;
    lastPtr = newNodePtr;
  } else {  // Find previous insertion point
    currPtr = dataPtr;
    prevPtr = NULL;
    while (currPtr != NULL && currPtr->component.ComparedTo(item) == BEFORE) {
      prevPtr = currPtr;
      currPtr = currPtr->link;
    }

    // Insert new node
    newNodePtr->link = currPtr;
    if (prevPtr == NULL)  // Insert as first?
      dataPtr = newNodePtr;
    else
      prevPtr->link = newNodePtr;
    if (currPtr == NULL)  // Insert as last?
      lastPtr = newNodePtr;
  }
  length++;
}

//***************************************************************

void SortedList::Delete(ItemType item) {
  NodePtr prevPtr = NULL;     // Trailing pointer
  NodePtr currPtr = dataPtr;  // Loop control pointer
  while (currPtr != NULL && currPtr->component.ComparedTo(item) != SAME &&
         currPtr->component.ComparedTo(item) == BEFORE) {
    prevPtr = currPtr;
    currPtr = currPtr->link;
  }
  if (currPtr != NULL &&
      currPtr->component.ComparedTo(item) == SAME) {  // item is found
    if (currPtr == dataPtr)
      dataPtr = currPtr->link;  // item is in first node
    else
      prevPtr->link = currPtr->link;
    if (currPtr == lastPtr) lastPtr = prevPtr;  // item is in last node
    delete currPtr;
    length--;
  }
}

//***************************************************************

void SortedList::ResetList() { currentPos = dataPtr; }

//***************************************************************

ItemType SortedList::GetNextItem() {
  ItemType item;
  item = currentPos->component;
  currentPos = currentPos->link;
  return item;
}

//***************************************************************

int SortedList::GetLength() const { return length; }

//***************************************************************

bool SortedList::IsEmpty() const { return (dataPtr == NULL); }

//***************************************************************

bool SortedList::HasNext() const { return (currentPos != NULL); }
//***************************************************************

bool SortedList::IsFull() const { return false; }

//***************************************************************

bool SortedList::IsThere(ItemType item) const {
  NodePtr currPtr = dataPtr;  // Loop control pointer

  while (currPtr != NULL && currPtr->component.ComparedTo(item) != SAME)
    currPtr = currPtr->link;

  if (currPtr != NULL)
    return true;
  else
    return false;
}
