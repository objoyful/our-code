//*****************************************************************
// IMPLEMENTATION FILE (ExpandedEntry.cpp)
// This file gives the implementation for the ExpandedEntry ADT
//*****************************************************************
#include "ExpandedEntry.h"

#include <iostream>
#include <string>
using namespace std;

//*****************************************************************

ExpandedEntry::ExpandedEntry() {}

//*****************************************************************

ExpandedEntry::ExpandedEntry(Name newName, TimeOfDay newTime)
    : Entry(newName.GetFirstName(), newName.GetMiddleName(),
            newName.GetLastName(), newTime.GetHours(), newTime.GetMinutes(),
            newTime.GetSeconds()) {}

//*****************************************************************

RelationType ExpandedEntry::ComparedTo(ExpandedEntry otherEntry) const {
  return (GetTime().ComparedTo(otherEntry.GetTime()));
}
