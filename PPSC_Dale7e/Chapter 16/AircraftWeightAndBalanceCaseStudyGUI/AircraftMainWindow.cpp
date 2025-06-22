#include "AircraftMainWindow.h"

#include "Aircraft.h"
#include "ClosetWeightAndFuelFormWidget.h"
#include "CrewManifestWidget.h"
#include "PassengerFormWidget.h"
#include "PassengerManifestWidget.h"
#include "WeightAndCofGWidget.h"

AircraftMainWindow::AircraftMainWindow(Aircraft &aircraft, QWidget *parent)
    : QMainWindow(parent) {
  // Initialize the major widgets in this GUI application.
  PassengerManifestWidget *passengerManifestWidget =
      new PassengerManifestWidget(this);
  CrewManifestWidget *crewManifestWidget = new CrewManifestWidget(this);
  WeightAndCofGWidget *cofg = new WeightAndCofGWidget(this);

  PassengerFormWidget *form = new PassengerFormWidget(
      aircraft, passengerManifestWidget, crewManifestWidget, cofg, this);

  ClosetWeightAndFuelFormWidget *closetFuelWidget =
      new ClosetWeightAndFuelFormWidget(aircraft, cofg, this);

  // Create a new general widget
  QWidget *mainWidget = new QWidget(this);

  // Create a vertical layout for the new widget and fill it with the major
  // widgets
  QVBoxLayout *layout = new QVBoxLayout(mainWidget);
  layout->addWidget(form);
  layout->addWidget(passengerManifestWidget);
  layout->addWidget(crewManifestWidget);
  layout->addWidget(closetFuelWidget);
  layout->addWidget(cofg);

  // Ensure the empty widget begins at a reasonable size and put it in the
  // window
  setMinimumSize(500, 500);
  setCentralWidget(mainWidget);
}
