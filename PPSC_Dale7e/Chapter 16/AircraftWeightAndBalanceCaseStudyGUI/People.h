#ifndef PEOPLE_H
#define PEOPLE_H

//**************************************************
// SPECIFICATION FILE for People Class
//**************************************************

#include "Name.h"

class People {
 public:
  People();
  People(Name initName, char initRole);
  Name GetName() const;
  char GetRole() const;

 private:
  Name name;
  char role;
};

#endif  // PEOPLE_H
