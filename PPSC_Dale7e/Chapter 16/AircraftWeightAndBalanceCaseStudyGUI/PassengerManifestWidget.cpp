#include "PassengerManifestWidget.h"

PassengerManifestWidget::PassengerManifestWidget(QWidget *parent)
    : QWidget(parent) {
  rowCount = 0;                                      // Initialize rows to 0
  QLabel *label = new QLabel("Passenger Manifest");  // Create a label

  // Create a table widget and set the number of columns and rows
  table = new QTableWidget;
  table->setColumnCount(4);
  table->setRowCount(rowCount);

  // Create a list of strings to use for column headings
  QStringList headers = {"Name", "Row", "Weight", "Baggage Weight"};
  table->setHorizontalHeaderLabels(headers);

  // Put the label and table in a vertical layout
  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(label);
  layout->addWidget(table);

  // Make this widget use the layout
  setLayout(layout);
}

void PassengerManifestWidget::AddPassenger(string firstName, string lastName,
                                           int row, int weight,
                                           int baggageWeight) {
  // Convert strings to QStrings
  QString qfirstName = QString::fromStdString(firstName);
  QString qlastName = QString::fromStdString(lastName);
  QString qrow = QString::number(row);
  QString qweight = QString::number(weight);
  QString qbaggageWeight = QString::number(baggageWeight);

  // Build table entry objects
  QTableWidgetItem *nameItem =
      new QTableWidgetItem(qfirstName + " " + qlastName);
  QTableWidgetItem *rowItem = new QTableWidgetItem(qrow);
  QTableWidgetItem *weightItem = new QTableWidgetItem(qweight);
  QTableWidgetItem *baggageWeightItem = new QTableWidgetItem(qbaggageWeight);

  // Add the objects to the table in the current row and appropriate column
  table->insertRow(rowCount);
  table->setItem(rowCount, 0, nameItem);
  table->setItem(rowCount, 1, rowItem);
  table->setItem(rowCount, 2, weightItem);
  table->setItem(rowCount, 3, baggageWeightItem);

  // Go to the next row
  rowCount++;
}
