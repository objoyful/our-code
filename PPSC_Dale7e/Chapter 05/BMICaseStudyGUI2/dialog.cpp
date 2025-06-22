#include "dialog.h"

#include <QApplication>
#include <QtWidgets>
#include <string>

using namespace std;

FloatDialog::FloatDialog(string prompt, float start, float min, float max,
                         int step) {
  this->prompt = prompt;
  this->start = start;
  this->min = min;
  this->max = max;
  this->step = step;
}

float FloatDialog::display() {
  // We need to setup bogus argv and argc for QApplication constructor
  char *arg = (char *)"dialog";
  char *argv[] = {arg, NULL};
  int argc = 1;

  // Create the QApplication object. Required for displaying the prompt.
  QApplication app(argc, argv);

  // This indicates if "OK" or "Cancel" is clicked
  bool ok;

  // Need to convert a C++ string to a QString
  QString label = QString::fromStdString(this->prompt);

  // Finally, create the QInputDialog
  float value =
      QInputDialog::getDouble(Q_NULLPTR, "Float Dialog", label, this->start,
                              this->min, this->max, this->step, &ok);

  // Kill the window.
  app.exit();

  // Convert the QString result to C++ string
  return value;
}

TextDialog::TextDialog(string prompt) { this->prompt = prompt; }

string TextDialog::display() {
  // We need to setup bogus argv and argc for QApplication constructor
  char *arg = (char *)"dialog";
  char *argv[] = {arg, NULL};
  int argc = 1;

  // Create the QApplication object. Required for displaying the prompt.
  QApplication app(argc, argv);

  // This indicates if "OK" or "Cancel" is clicked
  bool ok;

  // Need to convert a C++ string to a QString
  QString label = QString::fromStdString(this->prompt);

  // Finally, create the QInputDialog
  QString text =
      QInputDialog::getText(Q_NULLPTR, "Text Dialog", label, QLineEdit::Normal,
                            QDir::home().dirName(), &ok);

  // Kill the window.
  app.exit();

  // Convert the QString result to C++ string
  return text.toUtf8().constData();
}

FileDialog::FileDialog(string prompt) { this->prompt = prompt; }

string FileDialog::display() {
  // We need to setup bogus argv and argc for QApplication constructor
  char *arg = (char *)"dialog";
  char *argv[] = {arg, NULL};
  int argc = 1;

  // Create the QApplication object. Required for displaying the prompt.
  QApplication app(argc, argv);

  // Need to convert a C++ string to a QString
  QString label = QString::fromStdString(this->prompt);

  // Finally, create the QFileDialog
  QString text = QFileDialog::getOpenFileName(Q_NULLPTR, label, NULL, NULL);

  // Kill the window.
  app.exit();

  // Convert the QString result to C++ string
  return text.toUtf8().constData();
}

DirectoryDialog::DirectoryDialog(string prompt) { this->prompt = prompt; }

string DirectoryDialog::display() {
  // We need to setup bogus argv and argc for QApplication constructor
  char *arg = (char *)"dialog";
  char *argv[] = {arg, NULL};
  int argc = 1;

  // Create the QApplication object. Required for displaying the prompt.
  QApplication app(argc, argv);

  // Need to convert a C++ string to a QString
  QString label = QString::fromStdString(this->prompt);

  // Finally, create the QFileDialog
  QString text = QFileDialog::getExistingDirectory(
      Q_NULLPTR, label, NULL,
      QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

  // Kill the window.
  app.exit();

  // Convert the QString result to C++ string
  return text.toUtf8().constData();
}

OutputDialog::OutputDialog(string output) { this->output = output; }

void OutputDialog::SetOutput(string output) { this->output = output; }

string OutputDialog::display() {
  // We need to setup bogus argv and argc for QApplication constructor
  char *arg = (char *)"dialog";
  char *argv[] = {arg, NULL};
  int argc = 1;

  // Create the QApplication object. Required for displaying the prompt.
  QApplication app(argc, argv);

  // app.setStyleSheet("QPlainTextEdit { font-family: courier; }");

  // This indicates if "OK" or "Cancel" is clicked
  bool ok;

  // Need to convert a C++ string to a QString
  QString output_text = QString::fromStdString(this->output);

  // Finally, create the QInputDialog
  QString text = QInputDialog::getMultiLineText(
      Q_NULLPTR, "Multiline Text Dialog", "Output:", output_text, &ok);

  // Kill the window.
  app.exit();

  // Convert the QString result to C++ string
  return text.toUtf8().constData();
}

YesNoDialog::YesNoDialog(string prompt) { this->prompt = prompt; }

bool YesNoDialog::display() {
  // We need to setup bogus argv and argc for QApplication constructor
  char *arg = (char *)"getDirectoryDialog";
  char *argv[] = {arg, NULL};
  int argc = 1;

  // Create the QApplication object. Required for displaying the prompt.
  QApplication app(argc, argv);

  QMessageBox::StandardButton response;
  QString prompt = QString::fromStdString(this->prompt);
  response = QMessageBox::question(Q_NULLPTR, prompt, prompt,
                                   QMessageBox::Yes | QMessageBox::No);

  // Kill the window.
  app.exit();

  if (response == QMessageBox::Yes) {
    return true;
  } else {
    return false;
  }
}
