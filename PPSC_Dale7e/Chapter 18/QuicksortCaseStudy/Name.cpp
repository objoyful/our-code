//*****************************************************************
// IMPLEMENTATION FILE (Name.cpp)
// The file implements the Name member functions.
//*****************************************************************
#include "Name.h"

#include <iostream>
Name::Name() {
  first = " ";
  middle = " ";
  last = " ";
}

//******************************************************************
Name::Name(string firstName, string middleName, string lastName) {
  first = firstName;  // Assign parameters
  last = lastName;
  middle = middleName;
}

//******************************************************************

string Name::GetFirstName() const { return first; }

//******************************************************************

string Name::GetLastName() const { return last; }
//******************************************************************

string Name::GetMiddleName() const { return middle; }

//******************************************************************

char Name::GetMiddleInitial() const { return middle.at(0); }

//******************************************************************

RelationType Name::ComparedTo(Name otherName) const {
  if (last < otherName.last)
    return BEFORE;
  else if (otherName.last < last)
    return AFTER;
  else if (first < otherName.first)
    return BEFORE;
  else if (otherName.first < first)
    return AFTER;
  else if (middle < otherName.middle)
    return BEFORE;
  else if (otherName.middle < middle)
    return AFTER;
  else
    return SAME;
}
