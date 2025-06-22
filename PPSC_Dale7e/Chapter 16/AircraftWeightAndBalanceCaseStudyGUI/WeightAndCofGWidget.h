#ifndef WEIGHTANDCOFGWIDGET_H
#define WEIGHTANDCOFGWIDGET_H

#include <QtWidgets>

class WeightAndCofGWidget : public QWidget {
  Q_OBJECT
 public:
  WeightAndCofGWidget(QWidget *parent = nullptr);
  void SetTotalWeight(float weight);
  void SetCofG(float cofg);

 private:
  QLabel *totalWeightLabel;
  QLabel *cofgLabel;
};

#endif  // WEIGHTANDCOFGWIDGET_H
