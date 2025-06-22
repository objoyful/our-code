#include "CrewManifestWidget.h"

CrewManifestWidget::CrewManifestWidget(QWidget *parent) : QWidget(parent) {
  rowCount = 0;                                 // Initialize rows to 0
  QLabel *label = new QLabel("Crew Manifest");  // Create a label

  // Create a table widget and set the number of columns and rows
  table = new QTableWidget;
  table->setColumnCount(2);
  table->setRowCount(rowCount);

  // Create a list of strings to use for column headings
  QStringList headers = {"Name", "Weight"};
  table->setHorizontalHeaderLabels(headers);

  // Put the label and table in a vertical layout
  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(label);
  layout->addWidget(table);

  // Make this widget use the layout
  setLayout(layout);
}

void CrewManifestWidget::AddCrew(string firstName, string lastName,
                                 int weight) {
  // Convert strings to QStrings
  QString qfirstName = QString::fromStdString(firstName);
  QString qlastName = QString::fromStdString(lastName);
  QString qweight = QString::number(weight);

  // Build table entry objects
  QTableWidgetItem *nameItem =
      new QTableWidgetItem(qfirstName + " " + qlastName);
  QTableWidgetItem *weightItem = new QTableWidgetItem(qweight);

  // Add the objects to the table in the current row and appropriate column
  table->insertRow(rowCount);
  table->setItem(rowCount, 0, nameItem);
  table->setItem(rowCount, 1, weightItem);

  // Go to the next row
  rowCount++;
}
