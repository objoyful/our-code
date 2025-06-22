//******************************************************
// IMPLEMENTATION FILE for class Deck
//******************************************************

#include "Deck.h"

#include <algorithm>
#include <chrono>
#include <random>

Deck::Deck() {
  for (Suits::Suit suit = Suits::CLUBS; suit <= Suits::SPADES;
       suit = Suits::Suit(suit + 1))
    for (Values::Value value = Values::ACE; value <= Values::KING;
         value = Values::Value(value + 1)) {
      theDeck.push_back(Card(value, suit));
    }
}
//******************************************************

bool Deck::empty() const { return theDeck.empty(); }

//******************************************************

bool Deck::isThere(Card aCard) const {
  return find(theDeck.begin(), theDeck.end(), aCard) != theDeck.end();
}

//******************************************************

int Deck::size() const { return theDeck.size(); }

//******************************************************

void Deck::Shuffle() {
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  shuffle(theDeck.begin(), theDeck.end(), std::default_random_engine(seed));
}

//******************************************************

Card Deck::Deal() {
  Card next = theDeck.front();  // Get the next card
  theDeck.pop_front();          // Delete it from the deck
  return next;                  // Return it
}
