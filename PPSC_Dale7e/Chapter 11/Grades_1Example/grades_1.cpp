//*****************************************************
// This program manipulates an array of grade records
//*****************************************************
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
const int MAX_STUDENTS = 5;
enum GradeType { A, B, C, D, F };
struct StudentRec {
  string stuName;
  float gpa;
  int examScore[4];
  GradeType courseGrade;
};
StudentRec gradeBook[MAX_STUDENTS];

void ReadValues(ifstream& inFile, StudentRec& record) {
  char letter;
  char throwAway;
  getline(inFile, record.stuName);
  inFile >> record.gpa >> record.examScore[0] >> record.examScore[1] >>
      record.examScore[2] >> record.examScore[3] >> letter;
  inFile.get(throwAway);
  switch (letter)  // Convert from char to GradeType
  {
    case 'A':
      record.courseGrade = A;
      break;
    case 'B':
      record.courseGrade = B;
      break;
    case 'C':
      record.courseGrade = C;
      break;
    case 'D':
      record.courseGrade = D;
      break;
    case 'F':
      record.courseGrade = F;
      break;
  }
}

void PrintValues(ofstream& outFile, StudentRec& record) {
  outFile << record.stuName << endl;
  outFile << record.gpa << ' ' << record.examScore[0] << ' '
          << record.examScore[1] << ' ' << record.examScore[2] << ' '
          << record.examScore[3] << ' ';
  switch (record.courseGrade) {
    case A:
      outFile << 'A';
      break;
    case B:
      outFile << 'B';
      break;
    case C:
      outFile << 'C';
      break;
    case D:
      outFile << 'D';
      break;
    case F:
      outFile << 'F';
      break;
  }
  outFile << endl;
}

int main() {
  StudentRec record[MAX_STUDENTS];
  ofstream outFile;
  outFile.open("rec.out");
  ifstream inFile;
  inFile.open("rec.in");
  for (int count = 0; count < MAX_STUDENTS; count++)
    ReadValues(inFile, record[count]);
  for (int count = 0; count < MAX_STUDENTS; count++)
    PrintValues(outFile, record[count]);
  inFile.close();
  outFile.close();
  return 0;
}
