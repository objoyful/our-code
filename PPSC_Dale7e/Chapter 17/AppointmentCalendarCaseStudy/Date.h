#ifndef DATE_H
#define DATE_H

//****************************************
// SPECIFICATION File for a Date ADT
//****************************************

class Date {
 public:
  Date();
  Date(int initMonth, int initDay, int initYear);
  // Knowledge responsibilities
  int GetMonth() const;
  int GetDay() const;
  int GetYear() const;
  bool operator<(const Date& otherDate) const;
  bool operator>(const Date& otherDate) const;
  bool operator==(const Date& otherDate) const;

 private:
  int month;
  int day;
  int year;
};

#endif  // DATE_H
