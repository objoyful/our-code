//********************************************************
// IMPLEMENTATION FILE for class AppointmentCalendarWindow
//********************************************************

#include "AppointmentCalendarWindow.h"

#include "RelationType.h"

AppointmentCalendarWindow::AppointmentCalendarWindow(
    AppointmentCalendar &calendarInit, QWidget *parent)
    : QMainWindow(parent), calendar(calendarInit) {
  QWidget *buttonsWidget = BuildButtonsWidget();
  QWidget *formWidget = BuildFormWidget();
  QWidget *listWidget = BuildListWidget();
  messageLabel = new QLabel("");
  QWidget *mainWidget =
      BuildMainWidget(listWidget, formWidget, buttonsWidget, messageLabel);

  LoadListWidget();
  InitializeEventHandlers();

  // Finally, set the main widget and window title
  setCentralWidget(mainWidget);
  setWindowTitle("Calendar Appointment App");
}

QWidget *AppointmentCalendarWindow::BuildButtonsWidget() {
  QWidget *buttonsWidget = new QWidget;
  QHBoxLayout *buttonsLayout = new QHBoxLayout;
  buttonsWidget->setLayout(buttonsLayout);

  saveButton = new QPushButton("Save");
  exitButton = new QPushButton("Exit");

  buttonsLayout->addWidget(saveButton);
  buttonsLayout->addWidget(exitButton);

  return buttonsWidget;
}

QWidget *AppointmentCalendarWindow::BuildFormWidget() {
  QWidget *formWidget = new QWidget;
  QGridLayout *formLayout = new QGridLayout;
  formWidget->setLayout(formLayout);

  firstNameLabel = new QLabel("First Name");
  firstNameLineEdit = new QLineEdit;
  middleNameLabel = new QLabel("Middle Name");
  middleNameLineEdit = new QLineEdit;
  lastNameLabel = new QLabel("Last Name");
  lastNameLineEdit = new QLineEdit;
  timeOfDayLabel = new QLabel("Time of Day");
  timeOfDayTime = new QDateTimeEdit(QDateTime::currentDateTime());
  timeOfDayTime->setDisplayFormat("MM/dd/yyyy h:mm:ss ap");
  timeOfDayTime->setCalendarPopup(true);

  formLayout->addWidget(firstNameLabel, 0, 0, Qt::AlignLeft);
  formLayout->addWidget(firstNameLineEdit, 0, 1, Qt::AlignLeft);
  formLayout->addWidget(middleNameLabel, 1, 0, Qt::AlignLeft);
  formLayout->addWidget(middleNameLineEdit, 1, 1, Qt::AlignLeft);
  formLayout->addWidget(lastNameLabel, 2, 0, Qt::AlignLeft);
  formLayout->addWidget(lastNameLineEdit, 2, 1, Qt::AlignLeft);
  formLayout->addWidget(timeOfDayLabel, 3, 0, Qt::AlignLeft);
  formLayout->addWidget(timeOfDayTime, 3, 1, Qt::AlignLeft);

  return formWidget;
}

QWidget *AppointmentCalendarWindow::BuildListWidget() {
  QWidget *listWidget = new QWidget;
  QVBoxLayout *listLayout = new QVBoxLayout;
  listWidget->setLayout(listLayout);

  nameListWidget = new QListWidget;
  entriesListLabel = new QLabel("Entries");

  listLayout->addWidget(entriesListLabel);
  listLayout->addWidget(nameListWidget);

  return listWidget;
}

QWidget *AppointmentCalendarWindow::BuildMainWidget(QWidget *entriesWidget,
                                                    QWidget *formWidget,
                                                    QWidget *buttonsWidget,
                                                    QWidget *messageLabel) {
  QWidget *mainWidget = new QWidget;
  QGridLayout *mainLayout = new QGridLayout;
  mainWidget->setLayout(mainLayout);

  mainLayout->addWidget(entriesWidget, 0, 0);
  mainLayout->addWidget(formWidget, 0, 1);
  mainLayout->addWidget(buttonsWidget, 1, 1);
  mainLayout->addWidget(messageLabel, 2, 0, 1, 2, Qt::AlignCenter);

  return mainWidget;
}

void AppointmentCalendarWindow::LoadListWidget() {
  calendar.ResetList();
  while (calendar.HasNext()) {
    EntryWithDate entry = calendar.GetNextItem();

    QListWidgetItem *item = new QListWidgetItem;

    Name name = entry.GetName();
    string displayName = name.GetFirstName() + " " + name.GetLastName();
    QString qname = QString::fromStdString(displayName);
    item->setText(qname);

    string entryString = entry.ToString();
    QString qstring = QString::fromStdString(entryString);
    QVariant entryData(qstring);
    item->setData(Qt::UserRole, entryData);

    nameListWidget->addItem(item);
  }
}

void AppointmentCalendarWindow::InitializeEventHandlers() {
  // Connect events to their handlers (signals to their slots)
  connect(nameListWidget, SIGNAL(itemClicked(QListWidgetItem *)), this,
          SLOT(HandleEntryItemClickedEvent(QListWidgetItem *)));

  connect(saveButton, SIGNAL(clicked()), this,
          SLOT(HandleSaveButtonClickedEvent()));

  connect(exitButton, SIGNAL(clicked()), this,
          SLOT(HandleExitButtonClickedEvent()));
}

void AppointmentCalendarWindow::HandleExitButtonClickedEvent() {
  this->close();
}

void AppointmentCalendarWindow::HandleEntryItemClickedEvent(
    QListWidgetItem *item) {
  messageLabel->setText("");

  // Convert the data from the item into an entry
  QVariant entryData = item->data(Qt::UserRole);
  QString qstring = entryData.toString();
  string entryString = qstring.toStdString();
  EntryWithDate entry = EntryWithDate::FromString(entryString);

  SetFormFromEntry(entry);

  // Remember the item loaded from the list widget
  currentItemLoaded = item;

  // Remember the current entry that is loaded
  currentEntry = entry;
}

void AppointmentCalendarWindow::HandleSaveButtonClickedEvent() {
  messageLabel->setText("");

  if (AreAnyFormFieldsEmpty()) {
    messageLabel->setText("All form fields must be filled in. Nothing saved.");
    return;
  }

  EntryWithDate newEntry = GetEntryFromForm();

  if (newEntry.ComparedTo(currentEntry) == SAME) {
    messageLabel->setText(
        "There are no changes to this appointment. Nothing saved.");
    return;
  }

  // Delete the old entry by calling GetEntry
  calendar.GetEntry(currentEntry.GetName(), currentEntry.GetDate());

  calendar.InsertEntry(newEntry);

  // Set the text of the currently loaded item to the new entry
  Name name = newEntry.GetName();
  string displayName = name.GetFirstName() + " " + name.GetLastName();
  QString qname = QString::fromStdString(displayName);
  currentItemLoaded->setText(qname);

  // Save the entry string to the currently loaded item
  string entryString = newEntry.ToString();
  QString qstring = QString::fromStdString(entryString);
  QVariant entryData(qstring);
  currentItemLoaded->setData(Qt::UserRole, entryData);

  // Remember the new entry
  currentEntry = newEntry;

  SaveCalendarToFile();
}

bool AppointmentCalendarWindow::AreAnyFormFieldsEmpty() {
  string firstName = firstNameLineEdit->text().toStdString();
  string middleName = middleNameLineEdit->text().toStdString();
  string lastName = lastNameLineEdit->text().toStdString();
  if (firstName == "" || middleName == "" || lastName == "") {
    return true;
  }
  return false;
}

EntryWithDate AppointmentCalendarWindow::GetEntryFromForm() {
  string firstName = firstNameLineEdit->text().toStdString();
  string middleName = middleNameLineEdit->text().toStdString();
  string lastName = lastNameLineEdit->text().toStdString();
  Name name(firstName, middleName, lastName);

  QDate qdate = timeOfDayTime->date();
  QTime qtime = timeOfDayTime->time();
  Date date = Date(qdate.month(), qdate.day(), qdate.year());
  TimeOfDay time = TimeOfDay(qtime.hour(), qtime.minute(), qtime.second());

  EntryWithDate entry(date, time, name);

  return entry;
}

void AppointmentCalendarWindow::SetFormFromEntry(EntryWithDate entry) {
  Name name = entry.GetName();
  Date date = entry.GetDate();
  TimeOfDay time = entry.GetTime();

  QString qs;

  qs = QString::fromStdString(name.GetFirstName());
  firstNameLineEdit->setText(qs);

  qs = QString::fromStdString(name.GetMiddleName());
  middleNameLineEdit->setText(qs);

  qs = QString::fromStdString(name.GetLastName());
  lastNameLineEdit->setText(qs);

  QDate qdate(date.GetYear(), date.GetMonth(), date.GetDay());
  QTime qtime(time.GetHours(), time.GetMinutes(), time.GetSeconds());
  QDateTime qdatetime(qdate, qtime);
  timeOfDayTime->setDateTime(qdatetime);
}

void AppointmentCalendarWindow::SaveCalendarToFile() {
  ofstream outFile;
  outFile.open("CalendarFile");
  if (!outFile) {
    messageLabel->setText("File not found. Error.");
    return;
  }

  calendar.WriteListToFile(outFile);

  outFile.close();
}

AppointmentCalendarWindow::~AppointmentCalendarWindow() {}
