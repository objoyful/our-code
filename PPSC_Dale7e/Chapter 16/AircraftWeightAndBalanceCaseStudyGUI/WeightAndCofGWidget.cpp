#include "WeightAndCofGWidget.h"

WeightAndCofGWidget::WeightAndCofGWidget(QWidget *parent) : QWidget(parent) {
  QLabel *totalWeightDisplayedLabel = new QLabel("Total Weight:", this);
  QLabel *cofgDisplayedLabel = new QLabel("Center of Gravity:", this);

  totalWeightLabel = new QLabel("", this);
  cofgLabel = new QLabel("", this);

  QGridLayout *layout = new QGridLayout(this);

  layout->addWidget(totalWeightDisplayedLabel, 0, 0);
  layout->addWidget(totalWeightLabel, 0, 1);
  layout->addWidget(cofgDisplayedLabel, 1, 0);
  layout->addWidget(cofgLabel, 1, 1);

  setLayout(layout);
}

void WeightAndCofGWidget::SetTotalWeight(float weight) {
  QString qweight = QString::number(weight);
  totalWeightLabel->setText(qweight);
}

void WeightAndCofGWidget::SetCofG(float cofg) {
  QString qcofg = QString::number(cofg);
  cofgLabel->setText(qcofg);
}
