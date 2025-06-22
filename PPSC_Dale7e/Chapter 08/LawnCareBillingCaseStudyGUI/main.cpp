//*********************************************************************
// Program LawnCare GUI calculates and writes the bills for a lawn care
// service company. The names of the input and output files are
// prompted for and read from the keyboard.
//*********************************************************************

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>  // Access ostringstream
#include <string>
#include "dialog.h"  // Access GUI components

using namespace std;

// Function prototypes

void GetInputFileName(string& fileName);
// Prompts the user to choose an input file.

void GetOutputFileName(string& fileName);
// Prompts the user to create a new output file.

void GetHourlyRate(float& hourlyRate);
// Prompts the user for the hourly rate.

void OpenFiles(ifstream& infile, ofstream& outfile, bool& filesOK);
// OpenFiles reads in the names of the input file and the
// output file and opens them for processing. If there is an
// error filesOK will be false.

void ProcessClients(ifstream& inFile, ofstream& outfile, float hourlyRate);
// ProcessClients writes bills for all of the clients
// whose records are on inFile.

void ProcessAClient(ifstream& inFile, ofstream& outFile, int& totalTime,
                    float hourlyRate);
// ProcessAClient writes the bill for one client

void GetAndPrintAddress(ifstream& inFile, ofstream& outFile);
// GetAndPrintAddress reads the address from inFile and
// prints it on outFile.

void PrintResults(int numberOfBills, int totalMinutes, float hourlyRate);
// PrintResults prints total billed, average time per job,
// and average bill.

int main() {
  float hourlyRate;
  ifstream inFile;
  ofstream outFile;
  bool filesOK;

  OpenFiles(inFile, outFile, filesOK);

  if (!filesOK) {
    MessageDialog errorDialog("Error opening files");
    errorDialog.display();
    return 1;
  }

  GetHourlyRate(hourlyRate);
  ProcessClients(inFile, outFile, hourlyRate);

  inFile.close();
  outFile.close();

  return 0;
}

//********************************************************************

void GetInputFileName(string& fileName) {
  // Post: fileName is assigned the name of an input file
  //       chosen by the user
  FileDialog chooseFile("Choose an existing input file.");
  fileName = chooseFile.display();
}

//********************************************************************

void GetOutputFileName(string& fileName) {
  // Post: fileName is assigned the name of an an output file
  //       created by the user
  NewFileDialog chooseFile("Create a new output file.");
  fileName = chooseFile.display();
}

//********************************************************************

void GetHourlyRate(float& hourlyRate) {
  // Post: hourlyRate is assigned the hourly rate
  //       provided by the user
  FloatDialog hourlyRateDialog("Provide the hourly rate.");
  hourlyRate = hourlyRateDialog.display();
}

//********************************************************************

void OpenFiles(ifstream& inFile, ofstream& outFile, bool& filesOK) {
  // Post: Files have been opened and filesOK reflects the result
  //       of the opening process
  string inFileName;   // User-specified input file name
  string outFileName;  // User-specified output file name

  GetInputFileName(inFileName);
  inFile.open(inFileName.c_str());

  GetOutputFileName(outFileName);
  outFile.open(outFileName.c_str());

  if (!inFile || !outFile) {
    filesOK = false;
    return;
  }

  filesOK = true;

  outFile << "Billing for clients on file " << inFileName << endl;
  outFile << fixed;
}

//********************************************************************

void ProcessClients(ifstream& inFile, ofstream& outFile, float hourlyRate) {
  // Pre:  Files have been opened and the hourly rate has been set
  // Post: Each bill has been written and the summary values have
  //       been written to the screen.
  int totalTime = 0;
  int numberOfBills = 0;
  string name;

  getline(inFile, name);

  while (inFile) {
    outFile << name << endl;
    ProcessAClient(inFile, outFile, totalTime, hourlyRate);
    numberOfBills++;
    getline(inFile, name);
  }

  // Print summary information
  PrintResults(numberOfBills, totalTime, hourlyRate);
}

//********************************************************************

void PrintResults(int numberOfBills, int totalMinutes, float hourlyRate) {
  // Pre:  number of bills and total minutes have been calculated
  // Post: total billing and average time and bill have been printed
  ostringstream output;
  float minutes = static_cast<float>(totalMinutes);
  output << "Total amount billed this month is " << minutes / 60.0 * hourlyRate
         << endl;
  output << "Average time worked per job is "
         << minutes / float(numberOfBills) / 60.0 << endl;
  output << "Average customer bill is "
         << minutes / 60.0 * hourlyRate / float(numberOfBills) << endl;

  OutputDialog results(output.str());
  results.display();
}

//********************************************************************

void GetAndPrintAddress(ifstream& inFile, ofstream& outFile) {
  // Pre:  files have been opened and name has been read
  // Post: address has been read from inFile and
  //       written on outFile
  string line;
  getline(inFile, line);
  outFile << line << endl;
  getline(inFile, line);
  outFile << line << endl << endl;
}

//********************************************************************

void ProcessAClient(ifstream& inFile, ofstream& outFile, int& totalTime,
                    float hourlyRate) {
  // Pre:  Files have been opened, totalTime is total minutes
  //       billed so far, and hourlyRate has been set
  // Post: Bill has been written to outFile
  int time = 0;
  int hours;
  int minutes;
  float cost;
  int numberOfJobs;

  // Process
  GetAndPrintAddress(inFile, outFile);

  inFile >> numberOfJobs;
  outFile << "Number of jobs: " << numberOfJobs << endl;

  for (int count = 1; count <= numberOfJobs; count++) {
    inFile >> hours >> minutes;
    time = hours * 60 + minutes + time;
    outFile << "Job " << count << ": " << hours << " hours and " << minutes
            << " minutes " << endl;
  }

  cost = static_cast<float>(time) / 60.0 * hourlyRate;
  totalTime = totalTime + time;

  outFile << "Amount of bill: $" << setprecision(2) << cost << endl << endl;

  string skip;
  getline(inFile, skip);
}
