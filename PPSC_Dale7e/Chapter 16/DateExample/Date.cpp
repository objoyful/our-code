#include "Date.h"

Date::Date(int initMonth, int initDay, int initYear) {
  month = initMonth;
  day = initDay;
  year = initYear;
}

bool Date::operator<(const Date& otherDate) const {
  if (year < otherDate.year)
    return true;
  else if (year > otherDate.year)
    return false;
  else if (month < otherDate.month)
    return true;
  else if (month > otherDate.month)
    return false;
  else if (day < otherDate.day)
    return true;
  else
    return false;
}

//*****************************************

bool Date::operator>(const Date& otherDate) const {
  if (year > otherDate.year)
    return true;
  else if (year < otherDate.year)
    return false;
  else if (month > otherDate.month)
    return true;
  else if (month < otherDate.month)
    return false;
  else if (day > otherDate.day)
    return true;
  else
    return false;
}

//*****************************************

bool Date::operator==(const Date& otherDate) const {
  return (month == otherDate.month) && (day == otherDate.day) &&
         (year == otherDate.year);
}
