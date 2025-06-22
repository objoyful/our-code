//*****************************************************
// DRIVER for AppointmentCalendar GUI program
//*****************************************************

#include <QApplication>
#include <fstream>
#include <iostream>

#include "AppointmentCalendarWindow.h"
using namespace std;

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  ifstream inFile;
  inFile.open("CalendarFile");
  if (!inFile) {
    cout << "File not found." << endl;
    return 1;
  }

  AppointmentCalendar calendar(inFile);
  AppointmentCalendarWindow window(calendar);

  window.show();

  return app.exec();
}
