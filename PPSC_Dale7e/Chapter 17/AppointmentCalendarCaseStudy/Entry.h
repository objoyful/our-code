#ifndef ENTRY_H
#define ENTRY_H

//*****************************************************************
// SPECIFICATION FILE (Entry.h)
// This file contains the specification of the Entry ADT, which has
// two contained classes, Name and Time.
// A ComparedTo function has been added to this class.
//*****************************************************************

#include "Name.h"
#include "RelationType.h"
#include "TimeOfDay.h"

class Entry {
 public:
  Entry();
  // Default constructor
  // Post: Entry object has been constructed
  //       Name and TimeOfDay objects have been constructed using
  //       their default constructors
  Entry(string firstName, string middleName, string lastName, int initHours,
        int initMinutes, int initSeconds);
  // Parameterized constructor
  // Post: Entry object has been constructed
  //       Name and TimeOfDay objects have been constructed using
  //       their parameterized constructors
  // Knowledge responsibilities
  TimeOfDay GetTime() const;
  // The function returns the time attribute
  Name GetName() const;
  // This function returns the name attribute
 private:
  Name name;
  TimeOfDay time;
};

#endif  // ENTRY_H
