#ifndef STUDENT_H
#define STUDENT_H

#include <string>

#include "RelationType.h"

using namespace std;

class Student
// This class represents a student's name with a grade
{
 public:
  Student(float initGrade, string initName);
  // Parameterized constructor
  // Post: Student object has been constructed with grade and name

  Student();

  // Knowledge responsibilities
  string GetName() const;
  // Post: Returns the name from the Student object
  float GetGrade() const;
  // Post: Returns the grade from the Student object
  RelationType ComparedTo(Student otherStudent) const;
  // Post: Returns
  //       BEFORE if instance's grade is greater than otherStudent's
  //       SAME if they are identical
  //       AFTER if instance's grade is less than otherStudent's
 private:
  string name;  // First and last name in string form
  float grade;
};

#endif  // STUDENT_H
