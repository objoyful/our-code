//*****************************************************
// IMPLEMENTATION File for a Date ADT
// Month, day, and year are kept as integers
//*****************************************************
#include "Date.h"

#include <iostream>

#include "RelationType.h"
using namespace std;

Date::Date() {
  month = 1;
  day = 1;
  year = 1582;
}

//*****************************************************
Date::Date(int initMonth, int initDay, int initYear) {
  month = initMonth;
  day = initDay;
  year = initYear;
}

//*****************************************************

int Date::GetMonth() const { return month; }

//*****************************************************

int Date::GetDay() const { return day; }

//*****************************************************

int Date::GetYear() const { return year; }

//*****************************************************

RelationType Date::ComparedTo(Date otherDate) const {
  if (year < otherDate.year)
    return BEFORE;
  else if (year > otherDate.year)
    return AFTER;
  else if (month < otherDate.month)
    return BEFORE;
  else if (month > otherDate.month)
    return AFTER;
  else if (day < otherDate.day)
    return BEFORE;
  else if (day > otherDate.day)
    return AFTER;
  else
    return SAME;
}
