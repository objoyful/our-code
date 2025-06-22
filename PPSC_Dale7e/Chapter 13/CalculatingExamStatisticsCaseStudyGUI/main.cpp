//*****************************************************************
// DRIVER for class StatisticsList of Student objects
//*****************************************************************
#include <QApplication>
#include <fstream>
#include <iostream>
#include <string>

#include "ExamStatisticsWindow.h"
#include "StatisticsList.h"
#include "dialog.h"

using namespace std;
void OpenFile(ifstream& inFile);
// Post: Files have been opened

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  ifstream inFile;
  OpenFile(inFile);
  if (!inFile) {
    cout << "Error opening file " << endl;
    return 1;
  }

  StatisticsList grades(inFile);
  ExamStatisticsWindow statWindow(grades);
  statWindow.show();
  app.exit();
  return 0;
}

//*****************************************************************

void OpenFile(ifstream& text) {
  string inFileName;  // User-specified input file name
  // Add a GUI widget for input
  FileDialog chooseInput("Choose the file to be processed");
  inFileName = chooseInput.display();
  text.open(inFileName.c_str());
}
