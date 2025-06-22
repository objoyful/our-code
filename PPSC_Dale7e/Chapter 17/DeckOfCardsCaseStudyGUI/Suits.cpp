//******************************************************
// IMPLEMENTATION FILE for class Suits
//******************************************************

#include "Suits.h"

#include <algorithm>  // For transform
#include <cctype>     // For toupper
#include <map>
#include <string>

Suits::Suits() { mySuit = CLUBS; }

//******************************************************

Suits::Suits(string initString) {
  // Create a mapping between strings and enums
  map<string, Suit> lookup;
  lookup["CLUBS"] = CLUBS;
  lookup["DIAMONDS"] = DIAMONDS;
  lookup["HEARTS"] = HEARTS;
  lookup["SPADES"] = SPADES;
  // Convert the string to uppercase
  transform(initString.begin(), initString.end(), initString.begin(), toupper);
  // Get the corresponding enum
  mySuit = lookup[initString];
}

//******************************************************

Suits::Suits(int initInt) { mySuit = Suit(initInt); }

//******************************************************

string Suits::toString() const {
  string suitString[4] = {"CLUBS", "DIAMONDS", "HEARTS", "SPADES"};
  return suitString[mySuit];
}
//******************************************************

int Suits::toInt() const { return int(mySuit); }

//******************************************************

bool Suits::operator<(Suits otherSuit) const {
  return mySuit < otherSuit.toInt();
}

//******************************************************

bool Suits::operator==(Suits otherSuit) const {
  return mySuit == otherSuit.toInt();
}
