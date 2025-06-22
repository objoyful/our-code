#ifndef CREWMANIFESTWIDGET_H
#define CREWMANIFESTWIDGET_H

#include <QtWidgets>

using namespace std;

class CrewManifestWidget : public QWidget {
  Q_OBJECT
 public:
  CrewManifestWidget(QWidget* parent = nullptr);
  void AddCrew(string firstName, string lastName, int weight);

 private:
  QTableWidget* table;
  int rowCount;
};

#endif  // PASSENGERMANIFESTWIDGET_H
