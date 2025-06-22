#ifndef APPOINTMENTCALENDAR_H
#define APPOINTMENTCALENDAR_H

//****************************************************
// SPECIFICATION FILE for class AppointmentCalendar
//****************************************************

#include <fstream>
#include <list>

#include "EntryWithDate.h"
using namespace std;

class AppointmentCalendar {
 public:
  // Constructor
  AppointmentCalendar(ifstream& inFile);
  // Knowledge responsibility
  bool IsThere(Name name, Date date);
  // Returns true if an entry exists with the given name and date

  // Action responsibilities
  EntryWithDate GetEntry(Name name, Date date);
  // Returns entry with time field equal to time
  // Pre:  entry with time field equal to time exists
  void InsertEntry(EntryWithDate initEntry);
  // Inserts entry into list
  void WriteListToFile(ofstream& outFile);
  // Writes list to outFile

 private:
  list<EntryWithDate> entryList;
};

#endif  // APPOINTMENTCALENDAR_H
