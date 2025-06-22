//****************************************************
// IMPLEMENTATION FILE for AppointmentCalendar
//****************************************************

#include "AppointmentCalendar.h"

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

AppointmentCalendar::AppointmentCalendar(ifstream& inFile) {
  int hours, minutes, seconds;  // For class TimeOfDay
  int month, day, year;         // For class Date
  string first, middle, last;   // For class Name
  int numberEntries;
  inFile >> numberEntries;
  for (int counter = 0; counter < numberEntries; counter++) {
    inFile >> hours >> minutes >> seconds;
    TimeOfDay time(hours, minutes, seconds);
    inFile >> month >> day >> year;
    Date date(month, day, year);
    inFile >> first >> middle >> last;
    Name name(first, middle, last);
    EntryWithDate entry(date, time, name);
    list.Insert(entry);
  }
}

//*******************************************************
bool AppointmentCalendar::IsThere(Name name, Date date) {
  TimeOfDay time;
  EntryWithDate entry(date, time, name);
  return list.IsThere(entry);
}

//******************************************************

EntryWithDate AppointmentCalendar::GetEntry(Name name, Date date) {
  TimeOfDay time;
  EntryWithDate otherEntry(date, time, name);
  EntryWithDate entry;
  list.ResetList();
  entry = list.GetNextItem();
  while (entry.ComparedTo(otherEntry) != SAME) entry = list.GetNextItem();
  list.Delete(entry);
  return entry;
}

//******************************************************

void AppointmentCalendar::InsertEntry(EntryWithDate entry) {
  list.Insert(entry);
}

//******************************************************

void AppointmentCalendar::WriteListToFile(ofstream& outFile) {
  EntryWithDate entry;
  Name name;
  Date date;
  TimeOfDay time;
  list.ResetList();
  outFile << list.GetLength() << endl;
  while (list.HasNext()) {
    entry = list.GetNextItem();
    time = entry.GetTime();
    outFile << time.GetHours() << ' ' << time.GetMinutes() << ' '
            << time.GetSeconds() << ' ';
    date = entry.GetDate();
    outFile << date.GetMonth() << ' ' << date.GetDay() << ' ' << date.GetYear()
            << ' ';
    name = entry.GetName();
    outFile << name.GetFirstName() << ' ' << name.GetMiddleName() << ' '
            << name.GetLastName() << endl;
  }
  outFile.close();
}

//******************************************************

void AppointmentCalendar::ResetList() { list.ResetList(); }

//******************************************************

bool AppointmentCalendar::HasNext() { return list.HasNext(); }

//******************************************************

EntryWithDate AppointmentCalendar::GetNextItem() { return list.GetNextItem(); }
