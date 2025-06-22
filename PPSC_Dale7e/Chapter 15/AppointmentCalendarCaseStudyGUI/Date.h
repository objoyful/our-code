#ifndef DATE_H
#define DATE_H

//****************************************
// SPECIFICATION File for a Date ADT
//****************************************

#include "RelationType.h"
class Date {
 public:
  Date();
  Date(int initMonth, int initDay, int initYear);
  // Knowledge responsibilities
  int GetMonth() const;
  int GetDay() const;
  int GetYear() const;
  RelationType ComparedTo(Date otherDate) const;
  // Post: Returns BEFORE if instance comes before otherEntry;
  //       Returns SAME if instance and otherEntry are the same;
  //       Returns AFTER if instance comes after otherEntry

 private:
  int month;
  int day;
  int year;
};

#endif  // DATE_H
