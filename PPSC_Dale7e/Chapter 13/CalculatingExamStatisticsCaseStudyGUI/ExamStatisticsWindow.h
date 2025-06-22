#ifndef EXAMSTATISTICSWINDOW_H
#define EXAMSTATISTICSWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

#include "StatisticsList.h"

class ExamStatisticsWindow : public QMainWindow {
  Q_OBJECT
 public:
  explicit ExamStatisticsWindow(StatisticsList &list,
                                QWidget *parent = nullptr);
  void show();

 private slots:
  void updateOutputMaxGrade();
  void updateOutputAboveAverageGrade();
  void updateOutputBelowAverageGrade();

 private:
  QTextEdit *statListText;
  QTextEdit *outputText;
  QLineEdit *averageLine;
  QLineEdit *minLine;
  QLineEdit *maxLine;
  QPushButton *maxGradeButton;
  QPushButton *aboveAverageButton;
  QPushButton *belowAverageButton;
  StatisticsList &list;
};

#endif  // EXAMSTATISTICSWINDOW_H
