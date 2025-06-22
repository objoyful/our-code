//*****************************************************************
// DRIVER for class StatisticsList of Student objects
//*****************************************************************
#include <fstream>
#include <iostream>
#include <string>

#include "StatisticsList.h"

using namespace std;
void OpenFiles(ifstream& inFile, ofstream& outFile);
// Post: Files have been opened

int main() {
  ofstream outFile;
  ifstream inFile;

  OpenFiles(inFile, outFile);
  if (!inFile || !outFile) {
    cout << "Error opening files " << endl;
    return 1;
  }

  StatisticsList grades(inFile);

  outFile << "Average: " << grades.GetAverage() << endl;
  outFile << "Minimum grade: " << grades.GetMinGrade() << endl;
  outFile << "Maximum grade: " << grades.GetMaxGrade() << endl;
  outFile << grades.GetBelowAverage()
          << " students had grades below the average. " << endl;
  outFile << grades.GetAboveAverage()
          << " students had grades above the average." << endl;

  grades.StudentsMaxGrade(outFile);
  grades.StudentsAbove(outFile);
  grades.StudentsBelow(outFile);

  inFile.close();
  outFile.close();
}

//*****************************************************************

void OpenFiles(ifstream& inFile, ofstream& outFile)
// Post: Files have been opened
{
  string inFileName;   // User specified input file name
  string outFileName;  // User specified output file name

  cout << "Enter the name of the input file: ";
  cin >> inFileName;
  inFile.open(inFileName.c_str());

  cout << "Enter the name of the output file: ";
  cin >> outFileName;
  outFile.open(outFileName.c_str());

  outFile << "Statistics for grades in file " << inFileName << endl;
  outFile << fixed;
}
