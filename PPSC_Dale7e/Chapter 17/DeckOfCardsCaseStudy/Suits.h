#ifndef SUITS_H
#define SUITS_H

//****************************************
// SPECIFICATION File for class Suits
//****************************************
#include <string>
using namespace std;

class Suits {
 public:
  // Constructors
  Suits();
  Suits(string initString);
  Suits(int initInt);
  // Observers
  string toString() const;
  int toInt() const;
  // Relational operators
  bool operator<(Suits otherSuit) const;
  bool operator==(Suits otherSuit) const;

  enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };

 private:
  Suit mySuit;
};

#endif  // SUITS_H
