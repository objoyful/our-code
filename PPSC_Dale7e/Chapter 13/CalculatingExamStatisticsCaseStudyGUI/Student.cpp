#include "Student.h"

#include "RelationType.h"

Student::Student(float initGrade, string initName) {
  grade = initGrade;
  name = initName;
}

Student::Student() {
  grade = 0.0;
  name = "";
}

string Student::GetName() const { return name; }

float Student::GetGrade() const { return grade; }

RelationType Student::ComparedTo(Student otherStudent) const {
  if (otherStudent.grade > grade) {
    return BEFORE;
  } else if (grade == otherStudent.grade) {
    return SAME;
  } else {
    return AFTER;
  }
}
