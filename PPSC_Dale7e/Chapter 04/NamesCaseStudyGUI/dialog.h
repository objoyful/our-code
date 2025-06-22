#ifndef DIALOG_H
#define DIALOG_H

#include <QDateTimeEdit>
#include <QFormLayout>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QString>
#include <string>

using namespace std;

class TextDialog {
 public:
  TextDialog(string prompt);

  string display();

 private:
  string prompt;
};

class FileDialog {
 public:
  FileDialog(string prompt);

  string display();

 private:
  string prompt;
};

class DirectoryDialog {
 public:
  DirectoryDialog(string prompt);

  string display();

 private:
  string prompt;
};

class OutputDialog {
 public:
  OutputDialog(string output);
  void SetOutput(string output);
  string display();

 private:
  string output;
};

#endif  // DIALOG_H
