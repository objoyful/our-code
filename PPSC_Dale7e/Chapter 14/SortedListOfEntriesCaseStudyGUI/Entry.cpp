//*****************************************************************
// IMPLEMENTATION FILE (Entry.cpp)
// This file contains the specification of the Entry ADT,
// which has two contained classes, Name and Time
//*****************************************************************
#include "Entry.h"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

Entry::Entry() {}

Entry::Entry(string firstName, string middleName, string lastName,
             int initHours, int initMinutes, int initSeconds)
    : name(firstName, middleName, lastName),
      time(initHours, initMinutes, initSeconds) {}

Entry::Entry(Name newName, TimeOfDay newTime) {
  name = newName;
  time = newTime;
}

string Entry::GetNameStr() const {
  return (name.GetFirstName() + ' ' + name.GetLastName());
}

string Entry::GetTimeStr() const
// This function makes use of class sstream to create and return
// a string containing numeric values
{
  string outStr;
  ostringstream tempOut;  // Declare an ostringstream

  if (time.GetHours() < 10) tempOut << '0';
  tempOut << time.GetHours() << ":";
  if (time.GetMinutes() < 10) tempOut << '0';
  tempOut << time.GetMinutes() << ":";
  if (time.GetSeconds() < 10) tempOut << '0';
  tempOut << time.GetSeconds();
  outStr = tempOut.str();
  return outStr;
}

RelationType Entry::ComparedTo(Entry otherEntry) const {
  return (time.ComparedTo(otherEntry.time));
}
