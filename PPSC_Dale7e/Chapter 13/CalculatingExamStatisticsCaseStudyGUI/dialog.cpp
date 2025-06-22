#include "dialog.h"

#include <QApplication>
#include <QCoreApplication>
#include <QtWidgets>
#include <string>

using namespace std;

TimeOfDayWindow::TimeOfDayWindow(QWidget *parent) : QMainWindow(parent) {
  this->resize(275, 100);

  dateTime = QDateTime::currentDateTime();

  dateEdit = new QDateTimeEdit(dateTime, this);
  dateEdit->setGeometry(5, 5, 80, 30);
  dateEdit->setDisplayFormat("hh:mm:ss");

  button = new QPushButton("Enter", this);
  button->setGeometry(100, 5, 150, 30);

  label = new QLabel(toString(), this);
  label->setGeometry(50, 50, 200, 30);

  connect(dateEdit, SIGNAL(dateTimeChanged(QDateTime)), this,
          SLOT(editDateTimeChanged(QDateTime)));

  connect(button, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));
}

void TimeOfDayWindow::display() {
  show();
  QApplication::instance()->exec();
}

QString TimeOfDayWindow::toString() {
  QTime time = dateTime.time();
  int hour = time.hour();
  int minute = time.minute();
  int second = time.second();
  QString text = QString::fromStdString(
      "Selected Time: " + std::to_string(hour) + ":" + std::to_string(minute) +
      ":" + std::to_string(second));
  return text;
}

int TimeOfDayWindow::getHour() { return dateTime.time().hour(); }

int TimeOfDayWindow::getMinute() { return dateTime.time().minute(); }

int TimeOfDayWindow::getSecond() { return dateTime.time().second(); }

void TimeOfDayWindow::editDateTimeChanged(const QDateTime &datetime) {
  this->dateTime = datetime;
  label->setText(toString());
}

TimeOfDayWindow::~TimeOfDayWindow() {}

RunAnotherTestDialog::RunAnotherTestDialog() {
  this->message = "Run another test?";
}

int RunAnotherTestDialog::display() {
  QMessageBox msgBox;
  msgBox.setText(message);
  msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
  msgBox.setDefaultButton(QMessageBox::Yes);
  int ret = msgBox.exec();
  if (ret == QMessageBox::Yes) {
    return 1;
  } else {
    return 0;
  }
}

int DateTimeDialog::getHours() { return 0; }

int DateTimeDialog::getMinutes() { return 0; }

int DateTimeDialog::getSeconds() { return 0; }

IntDialog::IntDialog(string prompt, int start, int min, int max, int step) {
  this->prompt = prompt;
  this->start = start;
  this->min = min;
  this->max = max;
  this->step = step;
}

int IntDialog::display() {
  // This indicates if "OK" or "Cancel" is clicked
  bool ok;

  // Need to convert a C++ string to a QString
  QString label = QString::fromStdString(this->prompt);

  // Finally, create the QInputDialog
  int value =
      QInputDialog::getInt(Q_NULLPTR, "Integer Dialog", label, this->start,
                           this->min, this->max, this->step, &ok);

  // Convert the QString result to C++ string
  return value;
}

FloatDialog::FloatDialog(string prompt, float start, float min, float max,
                         int step) {
  this->prompt = prompt;
  this->start = start;
  this->min = min;
  this->max = max;
  this->step = step;
}

float FloatDialog::display() {
  // This indicates if "OK" or "Cancel" is clicked
  bool ok;

  // Need to convert a C++ string to a QString
  QString label = QString::fromStdString(this->prompt);

  // Finally, create the QInputDialog
  float value =
      QInputDialog::getDouble(Q_NULLPTR, "Float Dialog", label, this->start,
                              this->min, this->max, this->step, &ok);

  // Convert the QString result to C++ string
  return value;
}

DoubleDialog::DoubleDialog(string prompt, double start, double min, double max,
                           int step) {
  this->prompt = prompt;
  this->start = start;
  this->min = min;
  this->max = max;
  this->step = step;
}

double DoubleDialog::display() {
  // This indicates if "OK" or "Cancel" is clicked
  bool ok;

  // Need to convert a C++ string to a QString
  QString label = QString::fromStdString(this->prompt);

  // Finally, create the QInputDialog
  double value =
      QInputDialog::getDouble(Q_NULLPTR, "Double Dialog", label, this->start,
                              this->min, this->max, this->step, &ok);

  // Convert the QString result to C++ string
  return value;
}

TextDialog::TextDialog(string prompt) { this->prompt = prompt; }

string TextDialog::display() {
  // This indicates if "OK" or "Cancel" is clicked
  bool ok;

  // Need to convert a C++ string to a QString
  QString label = QString::fromStdString(this->prompt);

  // Finally, create the QInputDialog
  QString text =
      QInputDialog::getText(Q_NULLPTR, "Text Dialog", label, QLineEdit::Normal,
                            QDir::home().dirName(), &ok);

  // Convert the QString result to C++ string
  return text.toUtf8().constData();
}

MultiLineTextDialog::MultiLineTextDialog(string prompt) {
  this->prompt = prompt;
}

string MultiLineTextDialog::display() {
  // This indicates if "OK" or "Cancel" is clicked
  bool ok;

  // Need to convert a C++ string to a QString
  QString label = QString::fromStdString(this->prompt);

  // Finally, create the QInputDialog
  QString text = QInputDialog::getMultiLineText(
      Q_NULLPTR, "Multiline Text Dialog", label, "", &ok);

  // Convert the QString result to C++ string
  return text.toUtf8().constData();
}

FileDialog::FileDialog(string prompt) { this->prompt = prompt; }

string FileDialog::display() {
  // Need to convert a C++ string to a QString
  QString label = QString::fromStdString(this->prompt);

  // Finally, create the QFileDialog
  QString text = QFileDialog::getOpenFileName(Q_NULLPTR, label, NULL, NULL);

  // Convert the QString result to C++ string
  return text.toUtf8().constData();
}

NewFileDialog::NewFileDialog(string prompt) { this->prompt = prompt; }

string NewFileDialog::display() {
  // Need to convert a C++ string to a QString
  QString label = QString::fromStdString(this->prompt);

  // Finally, create the QFileDialog
  QString text = QFileDialog::getSaveFileName(Q_NULLPTR, label, NULL, NULL);

  // Convert the QString result to C++ string
  return text.toUtf8().constData();
}

DirectoryDialog::DirectoryDialog(string prompt) { this->prompt = prompt; }

string DirectoryDialog::display() {
  // Need to convert a C++ string to a QString
  QString label = QString::fromStdString(this->prompt);

  // Finally, create the QFileDialog
  QString text = QFileDialog::getExistingDirectory(
      Q_NULLPTR, label, NULL,
      QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

  // Convert the QString result to C++ string
  return text.toUtf8().constData();
}

OutputDialog::OutputDialog(string output) { this->output = output; }

void OutputDialog::SetOutput(string output) { this->output = output; }

string OutputDialog::display() {
  // This indicates if "OK" or "Cancel" is clicked
  bool ok;

  // Need to convert a C++ string to a QString
  QString output_text = QString::fromStdString(this->output);

  // Finally, create the QInputDialog
  QString text = QInputDialog::getMultiLineText(
      Q_NULLPTR, "Multiline Text Dialog", "Output:", output_text, &ok);

  // Convert the QString result to C++ string
  return text.toUtf8().constData();
}

YesNoDialog::YesNoDialog(string prompt) { this->prompt = prompt; }

bool YesNoDialog::display() {
  QMessageBox::StandardButton response;
  QString prompt = QString::fromStdString(this->prompt);
  response = QMessageBox::question(Q_NULLPTR, prompt, prompt,
                                   QMessageBox::Yes | QMessageBox::No);

  if (response == QMessageBox::Yes) {
    return true;
  } else {
    return false;
  }
}

MessageDialog::MessageDialog(string prompt) { this->prompt = prompt; }

void MessageDialog::display() {
  QString prompt = QString::fromStdString(this->prompt);
  QMessageBox::warning(Q_NULLPTR, "Message Dialog", prompt, QMessageBox::Ok);
}
