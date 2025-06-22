#ifndef EVENTHANDLERS_H
#define EVENTHANDLERS_H

//******************************************************************
// SPECIFICATION FILE (EventHandlers.h)
// This file gives the specification of event handlers for a GUI.
// This is used to define methods that are called when certain
// events occur in the GUI
//******************************************************************

#include "SortedList.h"

class EventHandlers {
 public:
  EventHandlers(SortedList &entriesInit);

  void insertButtonPushed(string firstName, string middleName, string lastName,
                          int hours, int minutes, int seconds);
  // Adds a new Entry to the sorted list when the insert button is pressed
  // in the GUI

  bool deleteButtonPushed(string firstName, string middleName, string lastName,
                          int hours, int minutes, int seconds);
  // Deletes an Entry in the sorted list whose hours, minutes, and seconds
  // are identical to that Entry. This methods returns a Boolean. If it
  // returns true, then their was deleted; if it returns false,
  // an entry was not found.

  string fillTextBox();
  // Returns a string representation of all entries that is used by the GUI
  // to fill in a textbox showing the list of all entries.

 private:
  SortedList &entries;
};

#endif  // EVENTHANDLERS_H
