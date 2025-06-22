#ifndef USERINTERFACE_H
#define USERINTERFACE_H

//***********************************************
// SPECIFICATION FILE for class UserInterface
// This class acts as the gate agent.
//***********************************************

#include <iostream>

#include "Aircraft.h"
class UserInterface {
 public:
  UserInterface();
  // Action responsibilities
  void InputClosetAndFuel();
  void InputCrew();
  void InputPassenger();
  void CloseDoors(ofstream& outFile);

 private:
  Aircraft plane;
};

#endif  // USERINTERFACE_H
