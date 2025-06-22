//****************************************
// IMPLEMENTATION File for a Date ADT
// Month, day, and year are kept as integers
//****************************************
#include "Date.h"

#include <iostream>

bool IsLeapYear(int year);
using namespace std;
Date::Date() {
  month = 1;
  day = 1;
  year = 1582;
}

//****************************************

Date::Date(int initMonth, int initDay, int initYear) {
  static int daysInMonth[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (initMonth <= 0 || initMonth > 12) throw MonthError();
  month = initMonth;
  if (month == 2 && initDay == 29 && !IsLeapYear(initYear)) throw DayError();
  if (initDay <= 0 || initDay > daysInMonth[initMonth - 1]) throw DayError();
  day = initDay;
  if (initYear < 1582) throw YearError();
  year = initYear;
}

//*****************************************

int Date::GetMonth() const { return month; }

//*****************************************

int Date::GetDay() const { return day; }

//****************************************

int Date::GetYear() const { return year; }

//****************************************

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

bool Date::operator>(const Date& otherDate) const { return otherDate < *this; }

//*****************************************

bool Date::operator==(const Date& otherDate) const {
  return (month == otherDate.month) && (day == otherDate.day) &&
         (year == otherDate.year);
}

//*******************************************

bool IsLeapYear(int year)
// IsLeapYear returns true if year is a leap year and
// false otherwise
{
  if (year % 4 != 0)    // Is year not divisible by 4?
    return false;       // If so, can't be a leap year
                        // Must be divisible by 4 at this point
  if (year % 100 != 0)  // Is year not a multiple of 100?
    return true;        // If so, is a leap year
                        // Must be divisible by 100 at this point
  if (year % 400 != 0)  // Is year not a multiple of 400?
    return false;       // If so, then is not a leap year
                        // Must be divisible by 400 at this point
  return true;          // Is a leap year
}
