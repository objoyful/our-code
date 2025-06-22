//******************************************************
// IMPLEMENTATION FILE for class Values
//******************************************************

#include "Values.h"

#include <algorithm>  // For transform
#include <cctype>     // For toupper
#include <map>
#include <string>

Values::Values() { myValue = ACE; }

//******************************************************

Values::Values(string initString) {
  // Create a mapping between strings and enums
  map<string, Value> lookup;
  lookup["ACE"] = ACE;
  lookup["TWO"] = TWO;
  lookup["THREE"] = THREE;
  lookup["FOUR"] = FOUR;
  lookup["FIVE"] = FIVE;
  lookup["SIX"] = SIX;
  lookup["SEVEN"] = SEVEN;
  lookup["EIGHT"] = EIGHT;
  lookup["NINE"] = NINE;

  lookup["TEN"] = TEN;
  lookup["JACK"] = JACK;
  lookup["QUEEN"] = QUEEN;
  lookup["KING"] = KING;
  // Convert the string to uppercase
  transform(initString.begin(), initString.end(), initString.begin(), toupper);
  // Get the corresponding enum
  myValue = lookup[initString];
}

//******************************************************

Values::Values(int initInt) { myValue = Value(initInt); }

//******************************************************

string Values::toString() const {
  string valueString[13] = {"ACE",  "TWO",   "THREE", "FOUR", "FIVE",
                            "SIX",  "SEVEN", "EIGHT", "NINE", "TEN",
                            "JACK", "QUEEN", "KING"};
  return valueString[myValue];
}

//******************************************************

int Values::toInt() const { return int(myValue); }

//******************************************************

bool Values::operator<(Values otherValue) const {
  return myValue < otherValue.toInt();
}

//******************************************************

bool Values::operator==(Values otherValue) const {
  return myValue == otherValue.toInt();
}
