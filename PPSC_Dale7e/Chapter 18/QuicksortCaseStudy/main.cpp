//******************************************************************
//  Driver for the Quicksort algorithm.
//******************************************************************
#include <iostream>
#include <string>

#include "Name.h"
#include "Quicksort.h"
using namespace std;
Name ReadName();
// Prompts for and reads a name from the standard input device

int main() {
  Name data[15];
  Name name;
  // Read in 15 names
  for (int index = 0; index < 15; index++) {
    name = ReadName();
    data[index] = name;
  }
  // Sort 15 names
  Quicksort(data, 0, 14);
  // Output first and last name in sorted order
  for (int index = 0; index < 15; index++)
    cout << data[index].GetFirstName() << " " << data[index].GetLastName()
         << endl;
  return 0;
}

//***********************************************************

Name ReadName() {
  string first, middle, last;
  cout << "Enter first name: ";   // Prompt for first name
  cin >> first;                   // Get first name
  cout << "Enter middle name: ";  // Prompt for middle name
  cin >> middle;                  // Get middle name
  cout << "Enter last name: ";    // Prompt for last name
  cin >> last;                    // Get last name
  Name name(first, middle, last);
  return name;
}
