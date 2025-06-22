#include <QApplication>
#include <fstream>
#include <iostream>

#include "AircraftMainWindow.h"

using namespace std;

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);
  Aircraft aircraft;
  AircraftMainWindow window(aircraft);
  window.show();
  return app.exec();
}
