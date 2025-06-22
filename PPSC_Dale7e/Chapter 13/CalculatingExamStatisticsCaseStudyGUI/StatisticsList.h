#ifndef STATISTICSLIST_H
#define STATISTICSLIST_H

#include <sstream>

#include "SortedList.h"

class StatisticsList {
 public:
  StatisticsList(ifstream& inFile);
  // Parameterized constructor
  // Pre: inFile contains no more than 100 student records
  // Post: List of students has been created from file inFile
  //       Has calculated average, maxGrade, number below the average
  // Knowledge responsibilities
  float GetAverage() const;
  // Post: Returns average of the grades
  float GetMaxGrade() const;
  // Post: Returns maximum grade
  int GetAboveAverage() const;
  // Post: Returns the number of students whose grade was above the average
  int GetBelowAverage() const;
  // Post: Returns the number of students whose grade was below the average
  float GetMinGrade();
  // Post: Returns the minimum grade

  // Action responsibilities
  void StudentsMaxGrade(ostringstream& outString);
  // Post: Student(s) with the maximum grade output on file outString
  void StudentsAbove(ostringstream& outString);
  // Post: Students whose grades were average or above output on outString
  void StudentsBelow(ostringstream& outString);
  // Post: Students whose grades were below average output on outString
  void AllStudents(ostringstream& outString);
  // Post: Students and grades of all students output on outString
 private:
  float average;
  float maxGrade;
  int numBelow;
  SortedList list;  // List of grade/name pairs
};

#endif  // STATISTICSLIST_H
