#ifndef ENTRY_H
#define ENTRY_H

//*****************************************************************
// SPECIFICATION FILE (Entry.h)
// This file contains the specification of the Entry ADT, which has
// two contained classes, Name and Time.
// A ComparedTo function has been added to this class
//*****************************************************************

#include <sstream>
#include <string>

#include "Name.h"
#include "RelationType.h"
#include "TimeOfDay.h"

using namespace std;

class Entry {
 public:
  string GetNameStr() const;
  // Post: Returns the first and last name of Name object
  //       with a blank in between
  string GetTimeStr() const;
  // Post: Returns the hours and minutes from TimeOfDay object
  //       with a colon in between
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
  RelationType ComparedTo(Entry otherEntry) const;
  // Post: Returns
  //       BEFORE if instance's time object is earlier than otherEntry's
  //       SAME if they are identical
  //       AFTER if instance's time object is later than otherEntry's
 private:
  Name name;
  TimeOfDay time;
};

#endif  // ENTRY_H
