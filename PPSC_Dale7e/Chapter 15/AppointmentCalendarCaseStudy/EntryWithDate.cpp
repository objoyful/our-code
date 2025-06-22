//******************************************************
// IMPLEMENTATION FILE for class EntryWithDate
//******************************************************

#include "EntryWithDate.h"

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
