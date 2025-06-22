#ifndef CLOSETWEIGHTANDFUELFORMWIDGET_H
#define CLOSETWEIGHTANDFUELFORMWIDGET_H

#include <QtWidgets>

#include "Aircraft.h"
#include "WeightAndCofGWidget.h"

class ClosetWeightAndFuelFormWidget : public QWidget {
  Q_OBJECT
 public:
  ClosetWeightAndFuelFormWidget(Aircraft &aircraftInit,
                                WeightAndCofGWidget *cofgWidgetInit,
                                QWidget *parent = nullptr);

 private:
  Aircraft &aircraft;
  WeightAndCofGWidget *cofgWidget;

  QLineEdit *closetWeightLineEdit;
  QLineEdit *gallonsOfFuelLineEdit;
  QPushButton *setWeightAndFuelButton;

 private slots:
  void HandleButtonClick();
};

#endif  // CLOSETWEIGHTANDFUELFORMWIDGET_H
