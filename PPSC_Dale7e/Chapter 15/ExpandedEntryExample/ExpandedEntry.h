#ifndef EXPANDEDENTRY_H
#define EXPANDEDENTRY_H

//******************************************************************
// SPECIFICATION FILE (ExpandedEntry.h)
// This file gives the specification of an ExpandedEntry abstract
// data type. The Entry class is a public base class of
// ExpandedEntry, so public operations of Entry are also public
// operations of ExpandedEntry
//******************************************************************
#include "Entry.h"

class ExpandedEntry : public Entry {
 public:
  // Constructors
  ExpandedEntry();
  // Default constructor
  ExpandedEntry(Name newName, TimeOfDay newTime);
  // Creates an entry object with newName as the name attribute and
  // newTime as the TimeOfDay attribute
  RelationType ComparedTo(ExpandedEntry otherEntry) const;
  // Post: Returns
  //       BEFORE if instance's time object is earlier than entry's
  //       SAME if they are identical
  //       AFTER if instance's time object is later than entry's
};

#endif  // EXPANDEDENTRY_H
