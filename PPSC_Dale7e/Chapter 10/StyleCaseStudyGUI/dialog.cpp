#include "dialog.h"

#include <QApplication>
#include <QCoreApplication>
#include <QtWidgets>
#include <string>

using namespace std;

IntDialog::IntDialog(string prompt, int start, int min, int max, int step) {
  this->prompt = prompt;
  this->start = start;
  this->min = min;
  this->max = max;
  this->step = step;
}

int IntDialog::display() {
  // We need to setup bogus argv and argc for QApplication constructor
  char *arg = (char *)"getIntDialog";
  char *argv[] = {arg, NULL};
  int argc = 1;

  // Create the QApplication object. Required for displaying the prompt.
  QApplication app(argc, argv);

  // This indicates if "OK" or "Cancel" is clicked
  bool ok;

  // Need to convert a C++ string to a QString
  QString label = QString::fromStdString(this->prompt);

  // Finally, create the QInputDialog
  int value =
      QInputDialog::getInt(Q_NULLPTR, "Integer Dialog", label, this->start,
                           this->min, this->max, this->step, &ok);

  // Kill the window.
  app.exit();

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
  // We need to setup bogus argv and argc for QApplication constructor
  char *arg = (char *)"getFloatDialog";
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

DoubleDialog::DoubleDialog(string prompt, double start, double min, double max,
                           int step) {
  this->prompt = prompt;
  this->start = start;
  this->min = min;
  this->max = max;
  this->step = step;
}

double DoubleDialog::display() {
  // We need to setup bogus argv and argc for QApplication constructor
  char *arg = (char *)"getDoubleDialog";
  char *argv[] = {arg, NULL};
  int argc = 1;

  // Create the QApplication object. Required for displaying the prompt.
  QApplication app(argc, argv);

  // This indicates if "OK" or "Cancel" is clicked
  bool ok;

  // Need to convert a C++ string to a QString
  QString label = QString::fromStdString(this->prompt);

  // Finally, create the QInputDialog
  double value =
      QInputDialog::getDouble(Q_NULLPTR, "Double Dialog", label, this->start,
                              this->min, this->max, this->step, &ok);

  // Kill the window.
  app.exit();

  // Convert the QString result to C++ string
  return value;
}

TextDialog::TextDialog(string prompt) { this->prompt = prompt; }

string TextDialog::display() {
  // We need to setup bogus argv and argc for QApplication constructor
  char *arg = (char *)"getTextDialog";
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

MultiLineTextDialog::MultiLineTextDialog(string prompt) {
  this->prompt = prompt;
}

string MultiLineTextDialog::display() {
  // We need to setup bogus argv and argc for QApplication constructor
  char *arg = (char *)"getMultilineTextDialog";
  char *argv[] = {arg, NULL};
  int argc = 1;

  // Create the QApplication object. Required for displaying the prompt.
  QApplication app(argc, argv);

  // This indicates if "OK" or "Cancel" is clicked
  bool ok;

  // Need to convert a C++ string to a QString
  QString label = QString::fromStdString(this->prompt);

  // Finally, create the QInputDialog
  QString text = QInputDialog::getMultiLineText(
      Q_NULLPTR, "Multiline Text Dialog", label, "", &ok);

  // Kill the window.
  app.exit();

  // Convert the QString result to C++ string
  return text.toUtf8().constData();
}

FileDialog::FileDialog(string prompt) { this->prompt = prompt; }

string FileDialog::display() {
  // We need to setup bogus argv and argc for QApplication constructor
  char *arg = (char *)"getFileDialog";
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

NewFileDialog::NewFileDialog(string prompt) { this->prompt = prompt; }

string NewFileDialog::display() {
  // We need to setup bogus argv and argc for QApplication constructor
  char *arg = (char *)"getNewFileDialog";
  char *argv[] = {arg, NULL};
  int argc = 1;

  // Create the QApplication object. Required for displaying the prompt.
  QApplication app(argc, argv);

  // Need to convert a C++ string to a QString
  QString label = QString::fromStdString(this->prompt);

  // Finally, create the QFileDialog
  QString text = QFileDialog::getSaveFileName(Q_NULLPTR, label, NULL, NULL);

  // Kill the window.
  app.exit();

  // Convert the QString result to C++ string
  return text.toUtf8().constData();
}

DirectoryDialog::DirectoryDialog(string prompt) { this->prompt = prompt; }

string DirectoryDialog::display() {
  // We need to setup bogus argv and argc for QApplication constructor
  char *arg = (char *)"getDirectoryDialog";
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
  char *arg = (char *)"displayOutput";
  char *argv[] = {arg, NULL};
  int argc = 1;

  // Create the QApplication object. Required for displaying the prompt.
  QApplication app(argc, argv);

  app.setStyleSheet("QPlainTextEdit { font-family: courier; }");

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

MessageDialog::MessageDialog(string prompt) { this->prompt = prompt; }

void MessageDialog::display() {
  // We need to setup bogus argv and argc for QApplication constructor
  char *arg = (char *)"getDirectoryDialog";
  char *argv[] = {arg, NULL};
  int argc = 1;

  // Create the QApplication object. Required for displaying the prompt.
  QApplication app(argc, argv);

  QString prompt = QString::fromStdString(this->prompt);
  QMessageBox::warning(Q_NULLPTR, "Message Dialog", prompt, QMessageBox::Ok);

  // Kill the window.
  app.exit();
}

// NOTE FOR NOW: this will not come into play until
// chapter 15 when inheritance and hopefully overloading
// is discussed.
FormWindow::FormWindow(QWidget *parent) : QMainWindow(parent) {
  // Create a form layout to add buttons and form fields.
  layout = new QFormLayout;

  // Create the button, make "this" the parent
  m_button = new QPushButton("My Button", this);
  // set size and location of the button
  m_button->setGeometry(QRect(QPoint(100, 100), QSize(200, 50)));

  // Connect button signal to appropriate slot
  connect(m_button, SIGNAL(released()), this, SLOT(handleButton()));

  layout->addRow(m_button);

  // It turns out that in order to set a layout you need to have a
  // central widget in Qt. So, we create a "central" widget, set its
  // layout, and then set the "central widget" for the MainWindow to
  // be the central widget we created.
  QWidget *central = new QWidget;
  central->setLayout(layout);
  setCentralWidget(central);

  resize(800, 800);
}

// NOTE FOR NOW: this will not come into play until
// chapter 15 when inheritance and hopefully overloading
// is discussed.
void FormWindow::addFloatFormField(string label) {
  QLineEdit *field = new QLineEdit();
  QDoubleValidator *validator = new QDoubleValidator(1, 2147483647, 2);
  field->setValidator(validator);
  layout->addRow(tr(label.c_str()), field);
}

// NOTE FOR NOW: this will not come into play until
// chapter 15 when inheritance and hopefully overloading
// is discussed.
void FormWindow::handleButton() {
  // change the text
  m_button->setText("Example");
  // resize button
  m_button->resize(100, 100);
}
