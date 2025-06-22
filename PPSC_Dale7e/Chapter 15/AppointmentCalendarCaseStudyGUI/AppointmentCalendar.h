#ifndef APPOINTMENTCALENDAR_H
#define APPOINTMENTCALENDAR_H

//****************************************************
// SPECIFICATION FILE for class AppointmentCalendar
//****************************************************

#include <fstream>

#include "EntryWithDate.h"
#include "List.h"

using namespace std;

class AppointmentCalendar {
 public:
  // Constructor
  AppointmentCalendar(ifstream& inFile);
  // Knowledge responsibility
  EntryWithDate GetEntry(Name name, Date date);
  // Returns entry with time field equal to time
  // Pre:  entry with time field equal to time exists

  bool IsThere(Name name, Date date);
  // Post: Returns true if an entry is in the list and false otherwise

  // Iterator methods
  void ResetList();
  bool HasNext();
  EntryWithDate GetNextItem();

  // Action responsibilities
  void InsertEntry(EntryWithDate initEntry);
  // Inserts entry into list
  void WriteListToFile(ofstream& outFile);
  // Writes list to outFile

 private:
  List list;
};

#endif  // APPOINTMENTCALENDAR_H
