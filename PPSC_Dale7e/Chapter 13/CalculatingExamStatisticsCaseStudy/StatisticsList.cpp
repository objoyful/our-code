//******************************************************
// Implementation file for class StatisticsList
//******************************************************

#include "StatisticsList.h"

#include <fstream>

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

void StatisticsList::StudentsMaxGrade(ofstream& outFile) {
  list.ResetList();
  Student aStudent = list.GetNextItem();
  outFile << endl << "The following student(s) had the maximum score: " << endl;
  while (maxGrade > aStudent.GetGrade()) aStudent = list.GetNextItem();
  outFile << aStudent.GetName() << endl;
  while (list.HasNext()) outFile << list.GetNextItem().GetName() << endl;
}

//*********************************************************

void StatisticsList::StudentsAbove(ofstream& outFile) {
  list.ResetList();
  for (int count = 1; count <= numBelow; count++) list.GetNextItem();
  outFile << endl << "Students who scored above the average:" << endl;
  for (int count = numBelow + 1; count < list.GetLength() + 1; count++)
    outFile << list.GetNextItem().GetName() << endl;
}

//********************************************************

void StatisticsList::StudentsBelow(ofstream& outFile) {
  list.ResetList();
  outFile << endl << "Students who scored below the average: " << endl;
  for (int count = 1; count <= numBelow; count++)
    outFile << list.GetNextItem().GetName() << endl;
}
