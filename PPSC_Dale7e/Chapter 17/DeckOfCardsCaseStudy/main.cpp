//******************************************************
// Driver for class Deck
//******************************************************
#include <iostream>

#include "Deck.h"
using namespace std;
int main() {
  // Create a deck of 52 cards in order
  Deck myDeck;
  cout << "The deck has " << myDeck.size() << " cards." << endl << endl;
  // Deal out the first ten in order
  for (int i = 1; i <= 10; ++i) {
    Card aCard = myDeck.Deal();
    cout << aCard.GetValue().toString() << " of " << aCard.GetSuit().toString()
         << endl;
  }
  cout << endl << "The deck has " << myDeck.size() << " cards." << endl;
  // Shuffle the remaining cards
  cout << "Shuffling" << endl << endl;
  myDeck.Shuffle();
  // Input a card
  cout << "Enter the name of a suit: ";
  string suit;
  cin >> suit;
  cout << "Enter the name of a card (ace, two,..., king): ";
  string value;
  cin >> value;
  // Check if card is in the deck
  Card card(value, suit);
  if (myDeck.isThere(card))
    cout << "The card is in the deck." << endl;
  else
    cout << "The card has already been dealt." << endl;
  // Deal out the remaining cards
  cout << "The remaining contents of the deck are:" << endl;
  while (!myDeck.empty()) {
    Card aCard = myDeck.Deal();
    cout << aCard.GetValue().toString() << " of " << aCard.GetSuit().toString()
         << endl;
  }
  cout << endl << "The deck has " << myDeck.size() << " cards." << endl;
}
