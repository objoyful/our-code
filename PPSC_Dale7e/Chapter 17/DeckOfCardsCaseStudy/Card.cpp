//******************************************************
// IMPLEMENTATION FILE for class Card
//******************************************************

#include "Card.h"

Card::Card() {}

//******************************************************

Card::Card(Values initValue, Suits initSuit) {
  myValue = initValue;
  mySuit = initSuit;
}

//******************************************************

Values Card::GetValue() const { return myValue; }

//******************************************************

Suits Card::GetSuit() const { return mySuit; }

//******************************************************

bool Card::operator<(const Card& otherCard) const {
  return rank() < otherCard.rank();
}

//******************************************************

bool Card::operator>(const Card& otherCard) const {
  return rank() > otherCard.rank();
}

//******************************************************

bool Card::operator==(const Card& otherCard) const {
  return rank() == otherCard.rank();
}

//******************************************************

bool Card::operator<=(const Card& otherCard) const {
  return rank() <= otherCard.rank();
}

//******************************************************
bool Card::operator>=(const Card& otherCard) const {
  return rank() >= otherCard.rank();
}

//******************************************************

bool Card::operator!=(const Card& otherCard) const {
  return rank() != otherCard.rank();
}

//******************************************************

int Card::rank() const { return mySuit.toInt() * 13 + myValue.toInt(); }
