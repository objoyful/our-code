//********************************************************
// IMPLEMENTATION FILE for class UserInterface
//********************************************************

#include "UserInterface.h"

#include <fstream>
#include <iostream>
#include <string>
using namespace std;
UserInterface::UserInterface() {}

//********************************************************

void UserInterface::InputClosetAndFuel() {
  float closet;
  float fuel;
  cout << "Enter the closet weight and the gallons of fuel" << endl;
  cin >> closet >> fuel;
  plane.SetClosetAndFuel(closet, fuel);
}

//********************************************************

void UserInterface::InputCrew() {
  string first;
  string last;
  float weight;
  cout << "Enter first name, last name, weight of crew member" << endl;
  cin >> first >> last >> weight;
  Name name(first, " ", last);
  plane.InsertCrew(name, weight);
}

//*******************************************************

void UserInterface::InputPassenger() {
  string first;
  string last;
  float weight;
  float baggage;
  int rowNo;
  cout << "Enter first name, last name of passenger, " << endl;
  cout << "passenger's weight, and weight of luggage." << endl;
  cin >> first >> last >> weight >> baggage;
  cout << "Enter row number" << endl;
  cin >> rowNo;
  Name name(first, " ", last);
  plane.InsertPassenger(name, weight, baggage, rowNo);
}

//******************************************************
void UserInterface::CloseDoors(ofstream& outFile) {
  float weight = plane.GetTotalWeight();
  cout << "Weight: " << weight << endl;
  ;
  float CofG = plane.GetCenterOfGravity();
  cout << "Center of Gravity: " << CofG << endl;
  if (weight > 14440)
    throw TooHeavy();
  else if (CofG < 307 || CofG > 321)
    throw CofGWrong();
  else
    plane.WriteNamesOnBoard(outFile);
}
