#include "EntriesWindow.h"

EntriesWindow::EntriesWindow(EventHandlers &handlers, QWidget *parent)
    : QMainWindow(parent), handlers(handlers) {
  // Entries label and text editor
  entriesListLabel = new QLabel("Entries");
  entriesTextEdit = new QTextEdit;
  entriesTextEdit->setReadOnly(true);
  QWidget *entriesWidget = new QWidget(this);
  QVBoxLayout *entriesLayout = new QVBoxLayout;
  entriesLayout->addWidget(entriesListLabel);
  entriesLayout->addWidget(entriesTextEdit);
  entriesWidget->setLayout(entriesLayout);

  // Form Labels and text lines and their layout.
  firstNameLabel = new QLabel("First Name");
  firstNameLineEdit = new QLineEdit;
  middleNameLabel = new QLabel("Middle Name");
  middleNameLineEdit = new QLineEdit;
  lastNameLabel = new QLabel("Last Name");
  lastNameLineEdit = new QLineEdit;
  timeOfDayLabel = new QLabel("Time of Day");
  timeOfDayTime = new QDateTimeEdit(QTime::currentTime());
  timeOfDayTime->setDisplayFormat("h:m:s ap");
  QWidget *formWidget = new QWidget(this);
  QGridLayout *formLayout = new QGridLayout;
  formLayout->addWidget(firstNameLabel, 0, 0, Qt::AlignLeft);
  formLayout->addWidget(firstNameLineEdit, 0, 1, Qt::AlignLeft);
  formLayout->addWidget(middleNameLabel, 1, 0, Qt::AlignLeft);
  formLayout->addWidget(middleNameLineEdit, 1, 1, Qt::AlignLeft);
  formLayout->addWidget(lastNameLabel, 2, 0, Qt::AlignLeft);
  formLayout->addWidget(lastNameLineEdit, 2, 1, Qt::AlignLeft);
  formLayout->addWidget(timeOfDayLabel, 3, 0, Qt::AlignLeft);
  formLayout->addWidget(timeOfDayTime, 3, 1, Qt::AlignLeft);
  formWidget->setLayout(formLayout);

  // Buttons and their layout.
  insertButton = new QPushButton("Insert Entry");
  deleteButton = new QPushButton("Delete Entry");
  QWidget *buttonsWidget = new QWidget(this);
  QHBoxLayout *buttonsLayout = new QHBoxLayout;
  buttonsLayout->addWidget(insertButton);
  buttonsLayout->addWidget(deleteButton);
  buttonsWidget->setLayout(buttonsLayout);

  // Message label - used for messages to user.
  messageLabel = new QLabel("");

  // Main widget and layout.
  QGridLayout *mainLayout = new QGridLayout;
  mainLayout->addWidget(entriesWidget, 0, 0);
  mainLayout->addWidget(formWidget, 0, 1);
  mainLayout->addWidget(buttonsWidget, 1, 1);
  mainLayout->addWidget(messageLabel, 2, 0, 1, 0, Qt::AlignCenter);
  QWidget *mainWidget = new QWidget(this);
  mainWidget->setLayout(mainLayout);

  // Connect events to their handlers (signals to their slots).
  connect(insertButton, SIGNAL(clicked()), this, SLOT(insertEntry()));
  connect(deleteButton, SIGNAL(clicked()), this, SLOT(deleteEntry()));

  // Set the main widget and window title.
  setCentralWidget(mainWidget);
  setWindowTitle("Sorted Entries List");
}

void EntriesWindow::insertEntry() {
  QString firstNameLineEditString = this->firstNameLineEdit->text();
  string firstName = firstNameLineEditString.toStdString();
  QString middleNameLineEditString = this->middleNameLineEdit->text();
  string middleName = middleNameLineEditString.toStdString();
  QString lastNameLineEditString = this->lastNameLineEdit->text();
  string lastName = lastNameLineEditString.toStdString();

  if (firstName == "" || middleName == "" || lastName == "") {
    messageLabel->setText("The entry has missing information.");
    return;
  } else {
    // We reset the message label to the empty string in case it
    // the user did not enter the complete entry before.
    messageLabel->setText("");
  }

  QTime time = timeOfDayTime->time();
  int hour = time.hour();
  int minute = time.minute();
  int second = time.second();
  handlers.insertButtonPushed(firstName, middleName, lastName, hour, minute,
                              second);
  string entriesText = handlers.fillTextBox();

  entriesTextEdit->setText(QString::fromStdString(entriesText));
  firstNameLineEdit->setText("");
  middleNameLineEdit->setText("");
  lastNameLineEdit->setText("");
  timeOfDayTime->setTime(QTime::currentTime());

  messageLabel->setText("Entry inserted successfully.");
}

void EntriesWindow::deleteEntry() {
  QString firstNameLineEditString = this->firstNameLineEdit->text();
  string firstName = firstNameLineEditString.toStdString();
  QString middleNameLineEditString = this->middleNameLineEdit->text();
  string middleName = middleNameLineEditString.toStdString();
  QString lastNameLineEditString = this->lastNameLineEdit->text();
  string lastName = lastNameLineEditString.toStdString();

  if (firstName == "" || middleName == "" || lastName == "") {
    messageLabel->setText("The entry has missing information.");
    return;
  } else {
    // We reset the message label to the empty string in case it
    // the user did not enter the complete entry before.
    messageLabel->setText("");
  }

  QTime time = timeOfDayTime->time();
  int hour = time.hour();
  int minute = time.minute();
  int second = time.second();
  bool deleted = handlers.deleteButtonPushed(firstName, middleName, lastName,
                                             hour, minute, second);

  if (deleted) {
    string entriesText = handlers.fillTextBox();

    entriesTextEdit->setText(QString::fromStdString(entriesText));
    firstNameLineEdit->setText("");
    middleNameLineEdit->setText("");
    lastNameLineEdit->setText("");
    timeOfDayTime->setTime(QTime::currentTime());
    messageLabel->setText("Entry successfully deleted.");
  } else {
    messageLabel->setText("Entry does not exist so it couldn't be deleted.");
  }
}

EntriesWindow::~EntriesWindow() {}
