#ifndef PASSENGERFORMWIDGET_H
#define PASSENGERFORMWIDGET_H

#include <QtWidgets>

#include "Aircraft.h"
#include "CrewManifestWidget.h"
#include "PassengerManifestWidget.h"
#include "WeightAndCofGWidget.h"

class PassengerFormWidget : public QWidget {
  Q_OBJECT
 public:
  PassengerFormWidget(Aircraft &aircraftInit,
                      PassengerManifestWidget *passengerManifestWidgetInit,
                      CrewManifestWidget *crewManifestWidgetInit,
                      WeightAndCofGWidget *weightAndCofGWidgetInit,
                      QWidget *parent = nullptr);

 private:
  QLineEdit *firstNameLineEdit;
  QLineEdit *lastNameLineEdit;
  QLineEdit *weightLineEdit;
  QLineEdit *weightBaggageLineEdit;
  QComboBox *rowComboBox;
  QComboBox *passengerTypeComboBox;
  QLabel *messages;
  Aircraft &aircraft;
  PassengerManifestWidget *passengerManifestWidget;
  CrewManifestWidget *crewManifestWidget;
  WeightAndCofGWidget *weightAndCofGWidget;

  void HandleAddingPassenger();
  void HandleAddingCrew();
  bool IsValidPassenger();
  bool IsValidCrew();
  void CheckWeightOfAircraft();
  void CheckCofGOfAircraft();

 private slots:
  void HandleComboBoxActivated(const QString &text);
  void HandleAddButtonClicked();
};

#endif  // PASSENGERFORMWIDGET_H
