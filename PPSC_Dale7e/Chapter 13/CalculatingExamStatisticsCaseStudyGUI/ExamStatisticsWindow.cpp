#include "ExamStatisticsWindow.h"

#include <QtWidgets>
#include <sstream>
#include <string>

ExamStatisticsWindow::ExamStatisticsWindow(StatisticsList &list,
                                           QWidget *parent)
    : QMainWindow(parent), list(list) {
  QLabel *averageGrade = new QLabel("Average:");
  averageLine = new QLineEdit;
  averageLine->setReadOnly(true);

  QLabel *maxGrade = new QLabel("Max:");
  maxLine = new QLineEdit;
  maxLine->setReadOnly(true);

  QLabel *minGrade = new QLabel("Min:");
  minLine = new QLineEdit;
  minLine->setReadOnly(true);

  QWidget *statsWidget = new QWidget(this);
  QVBoxLayout *statsLayout = new QVBoxLayout;
  statsLayout->addWidget(averageGrade);
  statsLayout->addWidget(averageLine);
  statsLayout->addWidget(maxGrade);
  statsLayout->addWidget(maxLine);
  statsLayout->addWidget(minGrade);
  statsLayout->addWidget(minLine);
  statsWidget->setLayout(statsLayout);

  averageLine->setText(QString::number(list.GetAverage()));
  maxLine->setText(QString::number(list.GetMaxGrade()));
  minLine->setText(QString::number(list.GetMinGrade()));

  maxGradeButton = new QPushButton("Max Grade");
  aboveAverageButton = new QPushButton("Above Average Grades");
  belowAverageButton = new QPushButton("Below Average Grades");
  QWidget *buttonsWidget = new QWidget(this);
  QHBoxLayout *buttonsLayout = new QHBoxLayout;
  buttonsLayout->addWidget(maxGradeButton);
  buttonsLayout->addWidget(aboveAverageButton);
  buttonsLayout->addWidget(belowAverageButton);
  buttonsWidget->setLayout(buttonsLayout);

  QLabel *statListLabel = new QLabel("Student List:");
  statListText = new QTextEdit;
  statListText->setReadOnly(true);
  ostringstream students;
  list.AllStudents(students);
  statListText->setText(QString::fromStdString(students.str()));

  QLabel *outputLabel = new QLabel("Output:");
  outputText = new QTextEdit;
  outputText->setReadOnly(true);

  QGridLayout *mainLayout = new QGridLayout;
  mainLayout->addWidget(statListLabel, 0, 0, Qt::AlignTop);
  mainLayout->addWidget(statListText, 0, 1);
  mainLayout->addWidget(outputLabel, 1, 0, Qt::AlignTop);
  mainLayout->addWidget(outputText, 1, 1);
  mainLayout->addWidget(statsWidget, 0, 2);
  mainLayout->addWidget(buttonsWidget, 2, 0, 1, 3);

  QWidget *mainWidget = new QWidget();
  mainWidget->setLayout(mainLayout);

  connect(maxGradeButton, SIGNAL(clicked()), this,
          SLOT(updateOutputMaxGrade()));
  connect(aboveAverageButton, SIGNAL(clicked()), this,
          SLOT(updateOutputAboveAverageGrade()));
  connect(belowAverageButton, SIGNAL(clicked()), this,
          SLOT(updateOutputBelowAverageGrade()));

  setCentralWidget(mainWidget);
  setWindowTitle("Statistics List");
}

void ExamStatisticsWindow::show() {
  QWidget::show();
  QApplication::instance()->exec();
}

void ExamStatisticsWindow::updateOutputMaxGrade() {
  ostringstream students;
  list.StudentsMaxGrade(students);
  outputText->setText(QString::fromStdString(students.str()));
}

void ExamStatisticsWindow::updateOutputAboveAverageGrade() {
  ostringstream students;
  list.StudentsAbove(students);
  outputText->setText(QString::fromStdString(students.str()));
}

void ExamStatisticsWindow::updateOutputBelowAverageGrade() {
  ostringstream students;
  list.StudentsBelow(students);
  outputText->setText(QString::fromStdString(students.str()));
}
