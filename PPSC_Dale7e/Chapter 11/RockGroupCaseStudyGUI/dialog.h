#ifndef DIALOG_H
#define DIALOG_H

#include <string>
#include <QMainWindow>
#include <QPushButton>
#include <QFormLayout>

using namespace std;

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
  FloatDialog(string prompt, float start = 0, float min = -2147483647,
              float max = 2147483647, int step = 1);

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

// NOTE FOR NOW: this will not come into play until
// chapter 15 when inheritance and hopefully overloading
// is discussed.
namespace Ui {
   class FormWindow;
}

// NOTE FOR NOW: this will not come into play until
// chapter 15 when inheritance and hopefully overloading
// is discussed.
class FormWindow : public QMainWindow
{
   Q_OBJECT
public:
   explicit FormWindow(QWidget *parent = 0);
   void addFloatFormField(string label);
private slots:
   void handleButton();
private:
   QPushButton *m_button;
   QFormLayout *layout;

// This is how you create and run this in main:
//   QApplication app(argc, argv);
//   FormWindow form;
//   form.addFloatFormField("Weight in pounds:");
//   form.showNormal();
//   return app.exec();
};

#endif  // DIALOG_H
