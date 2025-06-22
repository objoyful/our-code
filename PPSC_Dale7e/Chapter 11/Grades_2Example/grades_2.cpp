//*****************************************************
// This program manipulates an array of grade records
//*****************************************************
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 150;
enum GradeType { A, B, C, D, F };
struct StudentRec {
  string stuName;
  float gpa;
  int examScore[4];
  GradeType courseGrade;
};

struct GradeBook {
  StudentRec grades[MAX_STUDENTS];
  int numElements;
};

void ReadValues(ifstream& inFile, GradeBook& book);
// Pre:  inFile has been opened
// Post: Values have been read from inFile and stored into the
//       proper fields of record
void PrintValues(ofstream& outFile, GradeBook& book);
// Pre:  outFile has been opened and record contains valid data
// Post: Values in record have been written on outFile

int main() {
  ofstream outFile;
  outFile.open("rec.out");
  ifstream inFile;
  inFile.open("rec.in");
  GradeBook book;
  ReadValues(inFile, book);
  cout << book.numElements;
  PrintValues(outFile, book);
  return 0;
}

//*******************************************************
void ReadValues(ifstream& inFile, GradeBook& book) {
  char letter;
  char throwAway;
  int count = 0;
  getline(inFile, book.grades[count].stuName);
  while (inFile) {
    inFile >> book.grades[count].gpa >> book.grades[count].examScore[0] >>
        book.grades[count].examScore[1] >> book.grades[count].examScore[2] >>
        book.grades[count].examScore[3] >> letter;
    inFile.get(throwAway);
    switch (letter) {
      case 'A':
        book.grades[count].courseGrade = A;
        break;
      case 'B':
        book.grades[count].courseGrade = B;
        break;
      case 'C':
        book.grades[count].courseGrade = C;
        break;
      case 'D':
        book.grades[count].courseGrade = D;
        break;
      case 'F':
        book.grades[count].courseGrade = F;
        break;
    }
    count++;
    getline(inFile, book.grades[count].stuName);
  }
  book.numElements = count;
}

//********************************************************

void PrintValues(ofstream& outFile, GradeBook& book) {
  for (int count = 0; count < book.numElements; count++) {
    outFile << book.grades[count].stuName << endl;
    outFile << book.grades[count].gpa << ' ' << book.grades[count].examScore[0]
            << ' ' << book.grades[count].examScore[1] << ' '
            << book.grades[count].examScore[2] << ' '
            << book.grades[count].examScore[3] << ' ';
    switch (book.grades[count].courseGrade) {
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
}
