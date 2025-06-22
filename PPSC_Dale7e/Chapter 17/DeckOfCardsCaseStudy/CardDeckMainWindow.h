#ifndef CARDDECKMAINWINDOW_H
#define CARDDECKMAINWINDOW_H

#include <QMainWindow>

class CardDeckMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    CardDeckMainWindow(QWidget *parent = nullptr);
    ~CardDeckMainWindow();
};
#endif // CARDDECKMAINWINDOW_H
