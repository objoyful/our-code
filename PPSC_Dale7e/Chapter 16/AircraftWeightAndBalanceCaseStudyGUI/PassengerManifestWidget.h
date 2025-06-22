#ifndef PASSENGERMANIFESTWIDGET_H
#define PASSENGERMANIFESTWIDGET_H

#include <QtWidgets>

using namespace std;

class PassengerManifestWidget : public QWidget {
  Q_OBJECT
 public:
  PassengerManifestWidget(QWidget* parent = nullptr);
  void AddPassenger(string firstName, string lastName, int row, int weight,
                    int baggageWeight);

 private:
  QTableWidget* table;
  int rowCount;
};

#endif  // PASSENGERMANIFESTWIDGET_H
