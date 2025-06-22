#ifndef DECK_H
#define DECK_H

//****************************************
// SPECIFICATION File for class Deck
//****************************************
#include <deque>

#include "Card.h"

class Deck {
 public:
  // Constructor
  Deck();
  // Observers
  bool empty() const;
  bool isThere(Card aCard) const;
  int size() const;
  // Action responsibilities
  void Shuffle();  // Reorders the cards
  Card Deal();     // Takes one card from deck

 private:
  deque<Card> theDeck;
};

#endif  // DECK_H
