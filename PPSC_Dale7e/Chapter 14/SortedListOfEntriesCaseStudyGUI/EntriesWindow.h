#ifndef ENTRIESWINDOW_H
#define ENTRIESWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

#include "EventHandlers.h"

class EntriesWindow : public QMainWindow {
  Q_OBJECT

 public:
  EntriesWindow(EventHandlers &handlers, QWidget *parent = nullptr);
  ~EntriesWindow();

 private slots:
  void insertEntry();
  void deleteEntry();

 private:
  QLabel *firstNameLabel;
  QLineEdit *firstNameLineEdit;

  QLabel *middleNameLabel;
  QLineEdit *middleNameLineEdit;

  QLabel *lastNameLabel;
  QLineEdit *lastNameLineEdit;

  QLabel *timeOfDayLabel;
  QDateTimeEdit *timeOfDayTime;

  QPushButton *insertButton;
  QPushButton *deleteButton;

  QLabel *entriesListLabel;
  QTextEdit *entriesTextEdit;

  QLabel *messageLabel;

  EventHandlers &handlers;
};
#endif  // ENTRIESWINDOW_H
