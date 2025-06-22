//******************************************************************
// This program calculates the average, high score, low score,
// number above the average, and number below the average for
// a file of test scores.
// Assumption: File contains at least one non-zero value
//******************************************************************

#include <fstream>
#include <iomanip>
#include <iostream>

#include "dialog.h"

using namespace std;

struct GradeStatistics {
  int numGrades;     // Number of grades
  float average;     // Average grade
  int highest;       // Highest grade
  int lowest;        // Lowest grade
  int aboveAverage;  // Number of grades above the average
  int belowAverage;  // Number of grades below the average
  int grades[101];   // Array of grades
};

// Declare function prototypes
void CalculateStatistics(GradeStatistics &statistics, ifstream &inData);
// Post: Data has been read and statistics calculated.
void OpenFiles(ifstream &inData, ofstream &outData);
// Post: File names have been prompted for and files are opened.
//       Input file name has been written on output file
void InputGrades(GradeStatistics &statistics, ifstream &inData);
// Pre:  inData is assigned and not empty
// Post: Grades have been read from inData,
//       numGrades is the number of grades in inData
void CalculateAverage(GradeStatistics &statistics);
// Post: Average grade has been calculated
void CalculateHighest(GradeStatistics &statistics);
// Post: Hightest grade has been calculated
void CalculateLowest(GradeStatistics &statistics);
// Post: Return value is the lowest grade
void CalculateAboveAverage(GradeStatistics &statistics);
// Post: Number of grades above the average has been calculated
void CalculateBelowAverage(GradeStatistics &statistics);
// Post: Number of grades below the average has been calculated
void PrintResults(GradeStatistics statistics, ofstream &outData);
// Pre:  outData has been opened
// Post: Output has been written on outData

int main() {
  GradeStatistics statistics;
  // Declare and open files
  ifstream inData;
  ofstream outData;
  OpenFiles(inData, outData);
  if (!inData || !outData) {
    cout << "Files not opened successfully." << endl;
    return 1;
  }
  CalculateStatistics(statistics, inData);
  PrintResults(statistics, outData);
  inData.close();
  outData.close();
  return 0;
}

//*********************************************************************

void OpenFiles(ifstream &text, ofstream &outFile) {
  string outFileName;  // User specified output file name
  string inFileName;   // User specified input file name

  // Add a GUI widget for input
  FileDialog chooseInput("Choose the file to be processed");
  inFileName = chooseInput.display();
  text.open(inFileName.c_str());

  // Add a GUI widget for output
  NewFileDialog chooseOutput("Choose the name of the output file");
  outFileName = chooseOutput.display();
  outFile.open(outFileName.c_str());
}

//*********************************************************************

void CalculateAverage(GradeStatistics &statistics) {
  int sum = 0;
  // Sum number of grades times index
  for (int index = 0; index <= 100; index++)
    sum = sum + statistics.grades[index] * index;
  statistics.average = float(sum) / float(statistics.numGrades);
}

//*********************************************************************

void InputGrades(GradeStatistics &statistics, ifstream &inData) {
  int grade;
  // Zero out the array of counters
  for (int index = 0; index <= 100; index++) statistics.grades[index] = 0;
  statistics.numGrades = 0;
  inData >> grade;  // Priming read
  while (inData) {  // Process data
    statistics.grades[grade]++;
    statistics.numGrades++;
    inData >> grade;  // Subsequent reads
  }
}

//*********************************************************************

void CalculateLowest(GradeStatistics &statistics) {
  // Index of first nonzero grade is the low grade
  int lowGrade = 0;
  while (statistics.grades[lowGrade] == 0) lowGrade++;
  statistics.lowest = lowGrade;
}

//*********************************************************************

void CalculateHighest(GradeStatistics &statistics) {
  // Index of first nonzero grade is the low grade
  int highGrade = 100;
  while (statistics.grades[highGrade] == 0) highGrade--;
  statistics.highest = highGrade;
}

//*********************************************************************
void CalculateAboveAverage(GradeStatistics &statistics) {
  int averagePlus = (int)(statistics.average) + 1;
  int index;
  int number = 0;
  for (index = averagePlus; index <= 100; index++)
    number = number + statistics.grades[index];
  statistics.aboveAverage = number;
}
//*********************************************************************

void CalculateBelowAverage(GradeStatistics &statistics) {
  int truncatedAverage = (int)(statistics.average);
  int index;
  int number = 0;
  // Sum number of grades below average
  for (index = 0; index <= truncatedAverage; index++)
    number = number + statistics.grades[index];
  statistics.belowAverage = number;
}

//*********************************************************************

void CalculateStatistics(GradeStatistics &statistics, ifstream &inData) {
  // Read and process grades
  InputGrades(statistics, inData);
  CalculateAverage(statistics);
  CalculateHighest(statistics);
  CalculateLowest(statistics);
  CalculateAboveAverage(statistics);
  CalculateBelowAverage(statistics);
}

//******************************************************************

void PrintResults(GradeStatistics statistics, ofstream &outData) {
  outData << "The number of grades is " << statistics.numGrades << endl;
  outData << fixed << setprecision(2) << "The average grade is "
          << statistics.average << endl;
  outData << "The highest grade is " << statistics.highest << endl;
  outData << "The lowest grade is " << statistics.lowest << endl;
  outData << "The number of grades above the average is "
          << statistics.aboveAverage << endl;
  outData << "The number of grades below the average is "
          << statistics.belowAverage << endl;
}
