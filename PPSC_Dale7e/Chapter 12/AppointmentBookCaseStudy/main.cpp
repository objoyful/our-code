//**************************************************
// This program reads a file of Name objects and
// writes the hours from 0..23 and the associated
// name. Duplicate hours are not recorded.
// ************************************************
#include <fstream>
#include <iostream>
#include "Name.h"

using namespace std;

void OpenFiles(ifstream& inFile, ofstream& outFile);
// Prompts for and reads file names.
// Opens files
Name GetName(ifstream& inFile);
// Reads and returns Name object from inFile
void WriteTimeName(ofstream& outFile, Name names[]);
// Writes each hour and the corresponding name

int main() {
  // Declarations
  ifstream inFile;
  ofstream outFile;
  Name names[24];
  Name blankName;
  Name name;
  int hours, dummy;
  for (int index = 0; index < 24; index++) names[index] = blankName;
  OpenFiles(inFile, outFile);
  if (!(inFile && outFile)) {
    cout << "Files did not open properly" << endl;
    return 1;
  }

  // Process file
  name = GetName(inFile);
  while (inFile) {
    inFile >> hours >> dummy >> dummy;
    if (names[hours].GetFirstName() == " ")
      names[hours] = name;
    else
      outFile << hours << " is already taken." << endl;
    name = GetName(inFile);
  }
  WriteTimeName(outFile, names);
  outFile.close();
  inFile.close();
  return 0;
}

//******************************************************************

void OpenFiles(ifstream& inFile, ofstream& outFile) {
  string inFileName;   // User-specified input file name
  string outFileName;  // User-specified output file name
  cout << "Enter the name of the file to be processed" << endl;
  cin >> inFileName;
  inFile.open(inFileName.c_str());
  cout << "Enter the name of the output file" << endl;
  cin >> outFileName;
  outFile.open(outFileName.c_str());
}

//******************************************************************

Name GetName(ifstream& inFile) {
  string first, middle, last;
  inFile >> first >> middle >> last;
  Name name(first, middle, last);
  return name;
}

//******************************************************************

void WriteTimeName(ofstream& outFile, Name names[]) {
  outFile << "A listing of the hour and the corresponding name" << endl;
  for (int hour = 0; hour < 24; hour++) {
    if (names[hour].GetFirstName() != " ")
      outFile << "Hour " << hour << ":  " << names[hour].GetFirstName() << " "
              << names[hour].GetMiddleName() << " " << names[hour].GetLastName()
              << endl;
    else
      outFile << "Hour " << hour << ":  None was scheduled." << endl;
  }
}
