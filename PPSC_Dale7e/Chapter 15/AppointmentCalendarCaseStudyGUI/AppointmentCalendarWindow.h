#ifndef APPOINTMENTCALENDARWINDOW_H
#define APPOINTMENTCALENDARWINDOW_H

//*******************************************************
// SPECIFICATION FILE for class AppointmentCalendarWindow
// This class inherits from QMainWindow
//*******************************************************

#include <QMainWindow>
#include <QtWidgets>

#include "AppointmentCalendar.h"

class AppointmentCalendarWindow : public QMainWindow {
  Q_OBJECT

 public:
  AppointmentCalendarWindow(AppointmentCalendar &calendarInit,
                            QWidget *parent = nullptr);
  ~AppointmentCalendarWindow();

 private:
  // GUI state.
  AppointmentCalendar &calendar;

  // GUI widgets.
  QLabel *firstNameLabel;
  QLineEdit *firstNameLineEdit;

  QLabel *middleNameLabel;
  QLineEdit *middleNameLineEdit;

  QLabel *lastNameLabel;
  QLineEdit *lastNameLineEdit;

  QLabel *timeOfDayLabel;
  QDateTimeEdit *timeOfDayTime;

  QPushButton *saveButton;
  QPushButton *exitButton;

  QLabel *entriesListLabel;
  QListWidget *nameListWidget;

  QLabel *messageLabel;

  // GUI initialization methods
  QWidget *BuildListWidget();
  QWidget *BuildFormWidget();
  QWidget *BuildButtonsWidget();
  QWidget *BuildMainWidget(QWidget *entriesWidget, QWidget *formWidget,
                           QWidget *buttonsWidget, QWidget *messageLabel);

  // Remembers the currently loaded item in the form.
  QListWidgetItem *currentItemLoaded;
  EntryWithDate currentEntry;

  // Initializes the GUI list display and event handlers.
  void LoadListWidget();
  void InitializeEventHandlers();

  // Utility methods.
  bool AreAnyFormFieldsEmpty();
  EntryWithDate GetEntryFromForm();
  void SetFormFromEntry(EntryWithDate entry);
  void SaveCalendarToFile();

  // Event Handlers
 private slots:
  void HandleEntryItemClickedEvent(QListWidgetItem *item);
  void HandleSaveButtonClickedEvent();
  void HandleExitButtonClickedEvent();
};
#endif  // APPOINTMENTCALENDARWINDOW_H
