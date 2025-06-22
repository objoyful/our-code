#ifndef CARDDECKMAINWINDOW_H
#define CARDDECKMAINWINDOW_H

#include <QtWidgets>

class CardDeckMainWindow : public QMainWindow {
  Q_OBJECT

 public:
  CardDeckMainWindow(QWidget *parent = nullptr);
  ~CardDeckMainWindow();

 private slots:
  void HandleClickOnCard(int row, int column);
  void HandleShuffleButtonClicked();

 private:
  QTableWidget *table;
  QLabel *image;
  void InitTable();
  void InitLabel();
  void DisplayImage(int row);
};
#endif  // CARDDECKMAINWINDOW_H
