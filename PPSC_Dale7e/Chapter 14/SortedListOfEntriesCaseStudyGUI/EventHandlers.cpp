#include "EventHandlers.h"

#include <sstream>

EventHandlers::EventHandlers(SortedList &entriesInit) : entries(entriesInit) {}

void EventHandlers::insertButtonPushed(string firstName, string middleName,
                                       string lastName, int hours, int minutes,
                                       int seconds) {
  Entry entry(firstName, middleName, lastName, hours, minutes, seconds);
  entries.Insert(entry);
}

bool EventHandlers::deleteButtonPushed(string firstName, string middleName,
                                       string lastName, int hours, int minutes,
                                       int seconds) {
  Entry entry(firstName, middleName, lastName, hours, minutes, seconds);
  if (!entries.IsThere(entry)) {
    return false;
  }

  entries.Delete(entry);
  return true;
}

string EventHandlers::fillTextBox() {
  ostringstream str;
  entries.ResetList();
  while (entries.HasNext()) {
    Entry entry = entries.GetNextItem();
    str << entry.GetNameStr() << " - " << entry.GetTimeStr() << endl;
  }
  return str.str();
}
