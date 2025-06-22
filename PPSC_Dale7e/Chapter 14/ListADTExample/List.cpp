//******************************************************************
// IMPLEMENTATION FILE (List.cpp)
// This file implements the List class member functions
// List representation: A linked list with head and tail
// pointers, a length field, and a current position pointer
//******************************************************************
#include "List.h"

#include <cstddef>  // For NULL
#include <iostream>

using namespace std;

typedef NodeType* NodePtr;
struct NodeType {
  ItemType component;
  NodePtr link;
};

List::List()
// Post: dataPtr == NULL
{
  dataPtr = NULL;
  currentPos = dataPtr;
  length = 0;
  lastPtr = NULL;
}

//****************************************************************

List::List(const List& otherList)
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

List::~List()
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

void List::Insert(ItemType item)
// Post: New node containing item is at the end of the linked list
//       and lastPtr points to the new node
{
  NodePtr newNodePtr = new NodeType;
  newNodePtr->component = item;
  newNodePtr->link = NULL;
  if (lastPtr == NULL)
    dataPtr = newNodePtr;
  else
    lastPtr->link = newNodePtr;
  lastPtr = newNodePtr;
  length++;
}

//***************************************************************

void List::Delete(ItemType item) {
  NodePtr prevPtr = NULL;     // Trailing pointer
  NodePtr currPtr = dataPtr;  // Loop control pointer
  while (currPtr != NULL && currPtr->component != item) {
    prevPtr = currPtr;
    currPtr = currPtr->link;
  }
  if (currPtr != NULL) {  // item is found
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

void List::ResetList() { currentPos = dataPtr; }

//***************************************************************

ItemType List::GetNextItem() {
  ItemType item;
  item = currentPos->component;
  currentPos = currentPos->link;
  return item;
}

//***************************************************************

int List::GetLength() const { return length; }

//***************************************************************

bool List::IsEmpty() const { return (dataPtr == NULL); }

//***************************************************************

bool List::HasNext() const { return (currentPos != NULL); }
//***************************************************************

bool List::IsFull() const { return false; }

//***************************************************************

bool List::IsThere(ItemType item) const {
  NodePtr currPtr = dataPtr;  // Loop control pointer

  while (currPtr != NULL && currPtr->component != item) currPtr = currPtr->link;
  if (currPtr != NULL)
    return true;
  else
    return false;
}
