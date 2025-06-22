//******************************************************
// IMPLEMENTATION FILE for class EntryWithDate
//******************************************************

#include "EntryWithDate.h"

#include <sstream>

EntryWithDate::EntryWithDate(){};

//******************************************************

EntryWithDate::EntryWithDate(Date initDate, TimeOfDay initTime, Name initName)
    : Entry(initName.GetFirstName(), initName.GetMiddleName(),
            initName.GetLastName(), initTime.GetHours(), initTime.GetMinutes(),
            initTime.GetSeconds()) {
  date = initDate;
}

//******************************************************
Date EntryWithDate::GetDate() const { return date; }

//******************************************************

RelationType EntryWithDate::ComparedTo(EntryWithDate otherDate) const {
  if (GetDate().ComparedTo(otherDate.GetDate()) == SAME &&
      GetName().ComparedTo(otherDate.GetName()) == SAME)
    return SAME;
  else if (GetDate().ComparedTo(otherDate.GetDate()) == BEFORE)
    return BEFORE;
  else
    return AFTER;
}

string EntryWithDate::ToString() const {
  ostringstream oss;
  Name name = GetName();
  Date date = GetDate();
  TimeOfDay time = GetTime();

  oss << name.GetFirstName() << " " << name.GetMiddleName() << " "
      << name.GetLastName() << " ";

  oss << date.GetMonth() << " " << date.GetDay() << " " << date.GetYear()
      << " ";

  oss << time.GetHours() << " " << time.GetMinutes() << " "
      << time.GetSeconds();

  return oss.str();
}

EntryWithDate EntryWithDate::FromString(string entryString) {
  istringstream iss(entryString);

  string first, middle, last;
  int month, day, year;
  int hour, minute, second;

  iss >> first >> middle >> last;
  iss >> month >> day >> year;
  iss >> hour >> minute >> second;

  Date date(month, day, year);
  TimeOfDay time(hour, minute, second);
  Name name(first, middle, last);

  EntryWithDate entry(date, time, name);

  return entry;
}
