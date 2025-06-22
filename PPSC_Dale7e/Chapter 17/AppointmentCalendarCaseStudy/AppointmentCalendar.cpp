//****************************************************
// IMPLEMENTATION FILE for AppointmentCalendar
//****************************************************

#include "AppointmentCalendar.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

AppointmentCalendar::AppointmentCalendar(ifstream& inFile) {
  int hours, minutes, seconds;  // for class TimeOfDay
  int month, day, year;         // for class Date
  string first, middle, last;   // for class Name
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
    entryList.push_back(entry);
  }
}

//*******************************************************
bool AppointmentCalendar::IsThere(Name name, Date date) {
  TimeOfDay time;
  EntryWithDate entry(date, time, name);
  //  return list.IsThere(entry);
  return find(entryList.begin(), entryList.end(), entry) != entryList.end();
}

//******************************************************

EntryWithDate AppointmentCalendar::GetEntry(Name name, Date date) {
  TimeOfDay time;
  EntryWithDate searchEntry(date, time, name);
  list<EntryWithDate>::iterator location =
      find(entryList.begin(), entryList.end(), searchEntry);
  EntryWithDate entry = *location;
  entryList.erase(location);
  return entry;
}

//******************************************************

void AppointmentCalendar::InsertEntry(EntryWithDate entry) {
  entryList.push_back(entry);
}

//******************************************************

void AppointmentCalendar::WriteListToFile(ofstream& outFile) {
  EntryWithDate entry;
  Name name;
  Date date;
  TimeOfDay time;
  outFile << entryList.size() << endl;
  list<EntryWithDate>::iterator location;

  for (location = entryList.begin(); location != entryList.end(); location++) {
    entry = *location;
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
