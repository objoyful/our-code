#include "CardDeckMainWindow.h"

#include "Deck.h"

CardDeckMainWindow::CardDeckMainWindow(QWidget *parent) : QMainWindow(parent) {
  table = nullptr;

  InitTable();
  InitLabel();
  QPushButton *shuffleButton = new QPushButton("Shuffle");

  QGridLayout *layout = new QGridLayout;
  layout->addWidget(table, 0, 0);
  layout->addWidget(image, 0, 1);
  layout->addWidget(shuffleButton, 1, 0);

  QWidget *deckWidget = new QWidget(this);
  deckWidget->setLayout(layout);

  setCentralWidget(deckWidget);

  connect(table, SIGNAL(cellClicked(int, int)), this,
          SLOT(HandleClickOnCard(int, int)));

  connect(shuffleButton, SIGNAL(clicked()), this,
          SLOT(HandleShuffleButtonClicked()));
}

void CardDeckMainWindow::InitTable() {
  Deck deck;
  deck.Shuffle();

  if (table == nullptr) {
    table = new QTableWidget(this);
    table->setColumnCount(2);
    table->setRowCount(deck.size());
  } else {
    table->clear();
  }

  for (int i = 0; i < 52; i++) {
    Card card = deck.Deal();
    QString value = QString::fromStdString(card.GetValue().toString());
    QString suit = QString::fromStdString(card.GetSuit().toString());

    QTableWidgetItem *cardValueItem = new QTableWidgetItem(value);
    QTableWidgetItem *cardSuitItem = new QTableWidgetItem(suit);

    cardValueItem->setFlags(cardValueItem->flags() & ~Qt::ItemIsEditable);
    cardSuitItem->setFlags(cardSuitItem->flags() & ~Qt::ItemIsEditable);

    if (card.GetSuit() == Suits::DIAMONDS || card.GetSuit() == Suits::HEARTS) {
      QBrush brush(Qt::red);
      cardValueItem->setForeground(brush);
      cardSuitItem->setForeground(brush);
    }

    table->setItem(i, 0, cardValueItem);
    table->setItem(i, 1, cardSuitItem);
  }
}

void CardDeckMainWindow::DisplayImage(int row) {
  QString value = table->item(row, 0)->text();
  QString suit = table->item(row, 1)->text();
  QPixmap cardImage(":CardImages/" + value + "_" + suit + ".png");
  image->setPixmap(cardImage.scaled(300, 300, Qt::KeepAspectRatio));
}

void CardDeckMainWindow::InitLabel() {
  image = new QLabel("", this);
  DisplayImage(0);
}

void CardDeckMainWindow::HandleClickOnCard(int row, int column) {
  DisplayImage(row);
}

void CardDeckMainWindow::HandleShuffleButtonClicked() { InitTable(); }

CardDeckMainWindow::~CardDeckMainWindow() {}
