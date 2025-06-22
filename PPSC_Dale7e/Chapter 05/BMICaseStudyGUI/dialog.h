#ifndef DIALOG_H
#define DIALOG_H

#include <string>

using namespace std;

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
