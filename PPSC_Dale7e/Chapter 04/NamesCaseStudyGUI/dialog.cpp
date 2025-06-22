#include "dialog.h"

#include <QCoreApplication>
#include <QtWidgets>
#include <string>

using namespace std;

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

  // This indicates if "OK" or "Cancel" is clicked
  bool ok;

  // Need to convert a C++ string to a QString
  QString output_text = QString::fromStdString(this->output);

  // Finally, create the QInputDialog
  QString text = QInputDialog::getMultiLineText(
      Q_NULLPTR, "Multiline Text Dialog", "Output:", output_text, &ok);

  app.exit();

  // Convert the QString result to C++ string
  return text.toUtf8().constData();
}
