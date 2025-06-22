#include "ClosetWeightAndFuelFormWidget.h"

ClosetWeightAndFuelFormWidget::ClosetWeightAndFuelFormWidget(
    Aircraft& aircraftInit, WeightAndCofGWidget* cofgWidgetInit,
    QWidget* parent)
    : aircraft(aircraftInit), cofgWidget(cofgWidgetInit), QWidget(parent) {
  // Labels for text boxes
  QLabel* closetWeightLabel = new QLabel("Closet Weight:", this);
  QLabel* gallonsOfFuelLabel = new QLabel("Fuel (gallons):", this);

  // Text boxes for data and entry button
  closetWeightLineEdit = new QLineEdit(this);
  gallonsOfFuelLineEdit = new QLineEdit(this);
  setWeightAndFuelButton = new QPushButton("Set", this);

  // Create a horizontal layout and fill it
  QHBoxLayout* layout = new QHBoxLayout(this);
  layout->addWidget(closetWeightLabel);
  layout->addWidget(closetWeightLineEdit);
  layout->addWidget(gallonsOfFuelLabel);
  layout->addWidget(gallonsOfFuelLineEdit);
  layout->addWidget(setWeightAndFuelButton);

  // Make it the layout for this widget
  setLayout(layout);

  // Connect the button's event to its handler
  connect(setWeightAndFuelButton, SIGNAL(clicked()), this,
          SLOT(HandleButtonClick()));
}

// Event handler for the button
void ClosetWeightAndFuelFormWidget::HandleButtonClick() {
  // Convert QString to C++ types
  float weight = closetWeightLineEdit->text().toFloat();
  float fuel = gallonsOfFuelLineEdit->text().toFloat();

  // Add the values to the aircraft weight and CofG calculation
  aircraft.SetClosetAndFuel(weight, fuel);

  // Update the weight and CofG values in the UI
  cofgWidget->SetTotalWeight(aircraft.GetTotalWeight());
  cofgWidget->SetCofG(aircraft.GetCenterOfGravity());

  // Disable this widget to prevent repeated addition
  setEnabled(false);
}
