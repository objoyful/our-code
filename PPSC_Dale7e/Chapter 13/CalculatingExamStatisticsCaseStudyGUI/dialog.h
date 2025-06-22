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

class TimeOfDayWindow : public QMainWindow {
  Q_OBJECT

 public:
  TimeOfDayWindow(QWidget *parent = nullptr);
  ~TimeOfDayWindow() override;
  int getHour();
  int getMinute();
  int getSecond();
  void display();

 private slots:
  void editDateTimeChanged(const QDateTime &datetime);

 private:
  QDateTimeEdit *dateEdit;
  QPushButton *button;
  QLabel *label;
  QDateTime dateTime;
  int hour;
  int minute;
  int seconds;

  QString toString();
};

class RunAnotherTestDialog {
 public:
  RunAnotherTestDialog();
  int display();

 private:
  QString message;
};

class DateTimeDialog {
 public:
  DateTimeDialog();
  void display();
  int getHours();
  int getMinutes();
  int getSeconds();
};

class IntDialog {
 public:
  IntDialog(string prompt, int start = 0, int min = -2147483647,
            int max = 2147483647, int step = 1);

  int display();

 private:
  string prompt;
  int start;
  int min;
  int max;
  int step;
};

class DoubleDialog {
 public:
  DoubleDialog(string prompt, double start = 0, double min = -2147483647,
               double max = 2147483647, int step = 1);

  double display();

 private:
  string prompt;
  double start;
  double min;
  double max;
  int step;
};

class FloatDialog {
 public:
  FloatDialog(string prompt, float start = 0, float min = -2147483647.0,
              float max = 2147483647.0, int step = 1);

  float display();

 private:
  string prompt;
  float start;
  float min;
  float max;
  int step;
};

class TextDialog {
 public:
  TextDialog(string prompt);

  string display();

 private:
  string prompt;
};

class MultiLineTextDialog {
 public:
  MultiLineTextDialog(string prompt);

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

class NewFileDialog {
 public:
  NewFileDialog(string prompt);

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

class YesNoDialog {
 public:
  YesNoDialog(string prompt);
  bool display();

 private:
  string prompt;
};

class MessageDialog {
 public:
  MessageDialog(string prompt);
  void display();

 private:
  string prompt;
};

#endif  // DIALOG_H
