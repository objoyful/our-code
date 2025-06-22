#ifndef NAME_H
#define NAME_H
//*****************************************************************
// SPECIFICATION FILE (Name.h)
// This file gives the specification of the Name abstract
// data type. There are two constructors: one takes the first,
// middle, and last name as parameters and the second sets first,
// middle, and last to blanks
//*****************************************************************

#include <iostream>
#include <string>

#include "RelationType.h"
using namespace std;

class Name {
 public:
  Name();
  // Default constructor
  // Post: first, middle, and last have been set to blanks
  Name(string firstName, string middleName, string lastName);
  // Parameterized constructor
  // Post: Data fields have been set to parameters

  // Knowledge Responsibilities
  string GetFirstName() const;
  // Post: Return value is this person's first name
  string GetLastName() const;
  // Post: Return value is this person's last name
  string GetMiddleName() const;
  // Post:  Return value is this person's middle name
  char GetMiddleInitial() const;
  // Post: Return value is this person's middle initial

  RelationType ComparedTo(Name otherName) const;
  // Post: Return value is
  //       BEFORE, if this name comes before otherName
  //       SAME, if this name and otherName are the same
  //       AFTER, if this name is after otherName

 private:
  string first;   // Person's first name
  string last;    // Person's last name
  string middle;  // Person's middle name
};
#endif
