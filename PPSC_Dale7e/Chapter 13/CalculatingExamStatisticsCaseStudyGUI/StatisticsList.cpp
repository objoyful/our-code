//******************************************************
// Implementation file for class StatisticsList
//******************************************************

#include "StatisticsList.h"

#include <fstream>
#include <sstream>

#include "Student.h"

StatisticsList::StatisticsList(ifstream& inFile) {
  float grade;
  float sum = 0;
  maxGrade = 0;
  numBelow = 0;
  string name;
  inFile >> grade;
  // Build list and calculate maxGrade
  while (inFile) {
    getline(inFile, name);
    Student aStudent(grade, name);
    list.Insert(aStudent);
    sum = sum + grade;
    if (grade > maxGrade) maxGrade = grade;
    inFile >> grade;
  }

  average = sum / list.GetLength();
  // Calculate number of grades below average
  while (list.GetNextItem().GetGrade() < average) numBelow++;
}

//*******************************************************

float StatisticsList::GetAverage() const { return average; }

//*******************************************************

float StatisticsList::GetMaxGrade() const { return maxGrade; }

//*******************************************************

int StatisticsList::GetBelowAverage() const { return numBelow; }

//*******************************************************

int StatisticsList::GetAboveAverage() const {
  return list.GetLength() - numBelow;
}

//*******************************************************

float StatisticsList::GetMinGrade() {
  list.ResetList();
  return list.GetNextItem().GetGrade();
}

//*******************************************************

void StatisticsList::StudentsMaxGrade(ostringstream& outString) {
  list.ResetList();
  Student aStudent = list.GetNextItem();
  outString << "The following student(s) had the maximum score: " << endl;
  while (maxGrade > aStudent.GetGrade()) aStudent = list.GetNextItem();
  outString << aStudent.GetName() << endl;
  while (list.HasNext()) outString << list.GetNextItem().GetName() << endl;
}

//*********************************************************

void StatisticsList::StudentsAbove(ostringstream& outString) {
  list.ResetList();
  for (int count = 1; count <= numBelow; count++) list.GetNextItem();
  outString << "Students who scored above the average:" << endl;
  for (int count = numBelow + 1; count < list.GetLength() + 1; count++)
    outString << list.GetNextItem().GetName() << endl;
}

//********************************************************

void StatisticsList::StudentsBelow(ostringstream& outString) {
  list.ResetList();
  outString << "Students who scored below the average: " << endl;
  for (int count = 1; count <= numBelow; count++)
    outString << list.GetNextItem().GetName() << endl;
}

//********************************************************

void StatisticsList::AllStudents(ostringstream& outString) {
  list.ResetList();
  while (list.HasNext()) {
    Student student = list.GetNextItem();
    outString << student.GetName() << " (" << student.GetGrade() << ")" << endl;
  }
}
