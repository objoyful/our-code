//*****************************************************
// DRIVER for AppointmentCalendar problem
// Implements UserInterface class in design
//*****************************************************

#include <cctype>  // For toupper
#include <fstream>
#include <iostream>
#include <string>

#include "AppointmentCalendar.h"
using namespace std;

char GetInputCode();
// Prompts for and reads input code
TimeOfDay GetTime();
// Prompts for and reads a time object
Date GetDate();
// Prompts for and reads a date object
Name GetName();
// Prompts for and reads a name object
void GetEntryToChange(Name& name, Date& date);
// Prompts for and reads name and date of object to change

int main() {
  ifstream inFile;
  inFile.open("CalendarFile");
  if (!inFile) {
    cout << "File not found." << endl;
    return 1;
  }
  char inputCode;
  TimeOfDay time;
  Date date;
  Name name;
  EntryWithDate entry;
  char yesOrNo;
  AppointmentCalendar calendar(inFile);

  GetEntryToChange(name, date);
  do {
    if (calendar.IsThere(name, date)) {
      entry = calendar.GetEntry(name, date);
      TimeOfDay time = entry.GetTime();
      cout << "Entry retrieved:" << endl;
      cout << "Time  " << entry.GetTime().GetHours() << ':'
           << entry.GetTime().GetMinutes() << endl;
      cout << "Date  " << entry.GetDate().GetMonth() << '/'
           << entry.GetDate().GetDay() << '/' << entry.GetDate().GetYear()
           << endl;
      cout << "Name " << entry.GetName().GetFirstName() << ' '
           << entry.GetName().GetLastName() << endl
           << endl;
      inputCode = GetInputCode();
      switch (inputCode) {
        case 'T':
          time = GetTime();
          break;
        case 'D':
          date = GetDate();
          break;
        case 'N':
          name = GetName();
          break;
      }
      EntryWithDate entry(date, time, name);
      calendar.InsertEntry(entry);
    } else
      cout << "No entry exists with this name and date" << endl;
    cout << "Do you wish to continue changing entries? 'Y' or 'N'" << endl;
    cin >> yesOrNo;
    if (toupper(yesOrNo) == 'Y') GetEntryToChange(name, date);
  } while ((toupper(yesOrNo == 'Y')));
  inFile.close();
  ofstream outFile;
  outFile.open("CalendarFile");
  calendar.WriteListToFile(outFile);
  outFile.close();
  return 0;
}

//*************************************************************

char GetInputCode() {
  char inputCode;
  cout << "Enter field to change: 'T' (time) 'D' (date) 'N' (name)" << endl;
  cin >> inputCode;
  return toupper(inputCode);
}

//************************************************************

TimeOfDay GetTime() {
  int hours, minutes, seconds;
  cout << "Enter time as hours, minutes, seconds " << endl;
  cin >> hours >> minutes >> seconds;
  TimeOfDay time(hours, minutes, seconds);
  return time;
}

//***********************************************************

Date GetDate() {
  int month, day, year;
  cout << "Enter date as month, day, and year " << endl;
  cin >> month >> day >> year;
  Date date(month, day, year);
  return date;
}

//***********************************************************

Name GetName() {
  string first, middle, last;
  cout << "Enter name as first, middle, last" << endl;
  cin >> first >> middle >> last;
  Name name(first, middle, last);
  return name;
}

//***********************************************************

void GetEntryToChange(Name& name, Date& date) {
  cout << "Enter name of entry to change:" << endl;
  name = GetName();
  cout << "Enter date of entry to change" << endl;
  date = GetDate();
}
