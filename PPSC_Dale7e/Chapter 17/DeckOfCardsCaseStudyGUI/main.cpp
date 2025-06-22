#include <QApplication>
#include <QtWidgets>
#include <iostream>

#include "CardDeckMainWindow.h"
#include "Deck.h"

using namespace std;

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  Deck deck;
  CardDeckMainWindow window;
  window.show();
  return a.exec();
}
