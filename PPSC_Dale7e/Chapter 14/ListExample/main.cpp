//***********************************************************
// This program creates a linked list of four values read
// from the keyboard.  The list is then output.
//***********************************************************

#include <iostream>
using namespace std;
typedef int ItemType;

struct NodeType;  // Forward declaration
typedef NodeType* NodePtr;

struct NodeType {
  ItemType component;
  NodePtr link;
};

int main() {
  NodePtr head;        // External pointer to list
  NodePtr newNodePtr;  // Pointer to newest node
  NodePtr currPtr;     // Pointer to last node

  cout << "Enter 4 integer values." << endl;
  head = new NodeType;
  cin >> head->component;
  currPtr = head;

  for (int count = 1; count <= 3; count++) {
    newNodePtr = new NodeType;     // Create new node
    cin >> newNodePtr->component;  // Set its component value
    currPtr->link = newNodePtr;    // Link node into list
    currPtr = newNodePtr;          // Set currPtr to last node
  }
  currPtr->link = NULL;  // Mark end of list
  currPtr = head;
  for (int count = 0; count <= 3; count++) {
    cout << currPtr->component << endl;
    currPtr = currPtr->link;
  }
  return 0;
}
