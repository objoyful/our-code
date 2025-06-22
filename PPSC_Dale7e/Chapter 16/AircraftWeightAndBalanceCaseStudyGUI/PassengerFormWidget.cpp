#include "PassengerFormWidget.h"

PassengerFormWidget::PassengerFormWidget(
    Aircraft &aircraftInit,
    PassengerManifestWidget *passengerManifestWidgetInit,
    CrewManifestWidget *crewManifestWidgetInit,
    WeightAndCofGWidget *weightAndCofGWidgetInit, QWidget *parent)
    : aircraft(aircraftInit),  // Initializer list
      passengerManifestWidget(passengerManifestWidgetInit),
      crewManifestWidget(crewManifestWidgetInit),
      weightAndCofGWidget(weightAndCofGWidgetInit),
      QWidget(parent) {
  // Initialize the labels first.
  QLabel *firstNameLabel = new QLabel("First Name", this);
  QLabel *lastNameLabel = new QLabel("Last Name", this);
  QLabel *weightLabel = new QLabel("Weight", this);
  QLabel *weightBaggageLabel = new QLabel("Baggage Weight", this);
  QLabel *passengerTypeLabel = new QLabel("Passenger Type", this);
  QLabel *rowLabel = new QLabel("Row", this);

  // Set up the text boxes
  firstNameLineEdit = new QLineEdit(this);
  lastNameLineEdit = new QLineEdit(this);
  weightLineEdit = new QLineEdit(this);
  weightBaggageLineEdit = new QLineEdit(this);

  // Set up the passenger type drop-down menu
  passengerTypeComboBox = new QComboBox(this);
  passengerTypeComboBox->setEditable(false);
  passengerTypeComboBox->addItem("Passenger");
  passengerTypeComboBox->addItem("Crew");

  // Set up the row number drop-down meny
  rowComboBox = new QComboBox(this);
  rowComboBox->addItem("0");
  rowComboBox->addItem("1");
  rowComboBox->addItem("2");
  rowComboBox->addItem("3");

  // Create the Add button
  QPushButton *addButton = new QPushButton("Add", this);

  // Create a label for warning messages
  messages = new QLabel("");

  // Create a grid layout
  QGridLayout *layout = new QGridLayout(this);

  // Insert labels, text boxes, and drop downs using row and column
  layout->addWidget(firstNameLabel, 0, 0);
  layout->addWidget(lastNameLabel, 1, 0);
  layout->addWidget(weightLabel, 2, 0);
  layout->addWidget(weightBaggageLabel, 3, 0);
  layout->addWidget(rowLabel, 4, 0);
  layout->addWidget(passengerTypeLabel, 5, 0);
  layout->addWidget(firstNameLineEdit, 0, 1);
  layout->addWidget(lastNameLineEdit, 1, 1);
  layout->addWidget(weightLineEdit, 2, 1);
  layout->addWidget(weightBaggageLineEdit, 3, 1);
  layout->addWidget(rowComboBox, 4, 1);
  layout->addWidget(passengerTypeComboBox, 5, 1);

  // Insert button and message using row, column, row span, column span
  layout->addWidget(addButton, 6, 0, 1, 2);
  layout->addWidget(messages, 7, 0, 1, 2);

  // Make this the layout for the widget
  setLayout(layout);

  // Connect events from the widgets in the form to their handlers
  connect(passengerTypeComboBox, SIGNAL(textActivated(const QString &)), this,
          SLOT(HandleComboBoxActivated(const QString &)));

  connect(addButton, SIGNAL(clicked()), this, SLOT(HandleAddButtonClicked()));
}

void PassengerFormWidget::HandleComboBoxActivated(const QString &text) {
  if (text == "Crew") {
    // Disable the widgets
    weightBaggageLineEdit->setEnabled(false);
    rowComboBox->setEnabled(false);
    // Make background color light grey
    weightBaggageLineEdit->setStyleSheet("background-color: lightgrey");
    rowComboBox->setStyleSheet("background-color: lightgrey");
  } else {
    // Enable the widgets
    weightBaggageLineEdit->setEnabled(true);
    rowComboBox->setEnabled(true);
    // Make background color white
    weightBaggageLineEdit->setStyleSheet("background-color: white");
    rowComboBox->setStyleSheet("background-color: white");
  }
}

void PassengerFormWidget::HandleAddButtonClicked() {
  if (passengerTypeComboBox->currentText() == "Passenger") {
    HandleAddingPassenger();
  } else {
    HandleAddingCrew();
  }

  weightAndCofGWidget->SetTotalWeight(aircraft.GetTotalWeight());
  weightAndCofGWidget->SetCofG(aircraft.GetCenterOfGravity());

  firstNameLineEdit->setText("");
  lastNameLineEdit->setText("");
  weightLineEdit->setText("");
  weightBaggageLineEdit->setText("");
  rowComboBox->setCurrentIndex(0);

  CheckWeightOfAircraft();
  CheckCofGOfAircraft();
}

void PassengerFormWidget::HandleAddingPassenger() {
  if (!IsValidPassenger()) {
    messages->setText("Missing passenger form data. Try again.");
    return;
  }

  // Convert form data from QString to C++ types
  string firstName = firstNameLineEdit->text().toStdString();
  string lastName = lastNameLineEdit->text().toStdString();
  Name name(firstName, " ", lastName);
  float weight = weightLineEdit->text().toFloat();
  float weightBaggage = weightBaggageLineEdit->text().toFloat();
  int row = rowComboBox->currentText().toInt();

  // Add passenger to aircraft and displayed manifest, catching error of row
  // full
  try {
    aircraft.InsertPassenger(name, weight, weightBaggage, row);
    passengerManifestWidget->AddPassenger(firstName, lastName, row, weight,
                                          weightBaggage);
    messages->setText("Passenger added.");
  } catch (RowOverflow) {
    messages->setText("Not enough room in that row. Try again.");
    return;
  }
}

void PassengerFormWidget::HandleAddingCrew() {
  if (!IsValidCrew()) {
    messages->setText("Missing crew form data. Try again.");
    return;
  }

  // Convert form data from QString to C++ types
  string firstName = firstNameLineEdit->text().toStdString();
  string lastName = lastNameLineEdit->text().toStdString();
  Name name(firstName, " ", lastName);
  float weight = weightLineEdit->text().toFloat();

  // Add crew to aircraft and displayed manifest
  aircraft.InsertCrew(name, weight);
  crewManifestWidget->AddCrew(firstName, lastName, weight);

  messages->setText("Crew member added.");
}

void PassengerFormWidget::CheckWeightOfAircraft() {
  float weight = aircraft.GetTotalWeight();
  if (weight > 14440) {
    messages->setText("Cancel flight: Weight is too heavy.");
    setDisabled(true);
  }
}

void PassengerFormWidget::CheckCofGOfAircraft() {
  float cofg = aircraft.GetCenterOfGravity();
  if (cofg < 307 || cofg > 321) {
    messages->setText("Cancel flight: Center of Gravity is wrong.");
    setDisabled(true);
  }
}

bool PassengerFormWidget::IsValidPassenger() {
  if (firstNameLineEdit->text() == "" || lastNameLineEdit->text() == "" ||
      weightLineEdit->text() == "" || weightBaggageLineEdit->text() == "")
    return false;
  return true;
}

bool PassengerFormWidget::IsValidCrew() {
  if (firstNameLineEdit->text() == "" || lastNameLineEdit->text() == "" ||
      weightLineEdit->text() == "")
    return false;
  return true;
}
