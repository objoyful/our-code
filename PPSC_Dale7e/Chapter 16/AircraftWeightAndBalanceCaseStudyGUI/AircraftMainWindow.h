#ifndef AIRCRAFTMAINWINDOW_H
#define AIRCRAFTMAINWINDOW_H

#include <QMainWindow>

#include "Aircraft.h"

class AircraftMainWindow : public QMainWindow {
  Q_OBJECT
 public:
  AircraftMainWindow(Aircraft &aircraft, QWidget *parent = nullptr);
};

#endif  // AIRCRAFTMAINWINDOW_H
