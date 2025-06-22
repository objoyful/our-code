//*****************************************************************
// SPECIFICATION FILE (Entry.h)
// This file contains the specification of the Entry ADT, which has
// two contained classes, Name and Time
//*****************************************************************

#include <string>

#include "Name.h"
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
  string GetNameStr() const;
  // Post: Returns the first and last name of Name object
  //       with a blank in between
  string GetTimeStr() const;
  // Post: Returns the hours and minutes from TimeOfDay object
  //       with a colon in between
 private:
  Name name;
  TimeOfDay time;
};
