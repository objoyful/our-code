//*********************************************
// IMPLEMENTATION FILE for class Aircraft
//*********************************************
#include "Aircraft.h"

#include <fstream>

const float EMPTY_WEIGHT = 9887.0;     // Weight of empty airplane
const float EMPTY_MOMENT = 3153953.0;  // Moment of empty airplane
const float FUEL_WEIGHT = 6.7;         // Fuel weight per gallon

static int rows[4] = {0, 0, 0, 0};                 // Number in row
static int rowDistance[4] = {219, 265, 295, 341};  // Distance of row

Aircraft::Aircraft() {
  weight = EMPTY_WEIGHT;
  moment = EMPTY_MOMENT;
}

float Aircraft::GetTotalWeight() { return weight; }

float Aircraft::GetCenterOfGravity() { return moment / weight; }

void Aircraft::SetClosetAndFuel(float closetWgt, float fuel) {
  int fuelWgt = fuel * FUEL_WEIGHT;
  weight = weight + closetWgt + fuelWgt;
  moment = moment + closetWgt * 182;
  if (fuel < 60)
    moment = moment + 314.6 * fuel * fuelWgt;
  else if (fuel < 361)
    moment = moment + (305.8 + (-0.01233 * (fuel - 60))) * fuelWgt;
  else if (fuel < 521)
    moment = moment + (303.0 + (-0.12500 * (fuel - 361))) * fuelWgt;
  else
    moment = moment + (323.0 + (-0.0444 * (fuel - 521))) * fuelWgt;
}

void Aircraft::InsertPassenger(Name initName, float pWeight, float bWeight,
                               int rowNo) {
  weight = weight + pWeight + bWeight;
  rows[rowNo - 1]++;
  if (rows[rowNo - 1] > 2) throw RowOverflow();
  moment = moment + pWeight * rowDistance[rowNo - 1] + bWeight * 386;
  People passenger(initName, 'P');
  list.Insert(passenger);
}

void Aircraft::InsertCrew(Name initName, float cWeight) {
  weight = weight + cWeight;
  moment = moment + cWeight * 143;
  People person(initName, 'C');
  list.Insert(person);
}

void Aircraft::WriteNamesOnBoard(ofstream &outFile) {
  list.ResetList();
  People person;
  while (list.HasNext()) {
    person = list.GetNextItem();
    outFile << person.GetName().GetFirstName() << " "
            << person.GetName().GetLastName();
    if (person.GetRole() == 'C')
      outFile << " (Crew)" << endl;
    else
      outFile << " (Passenger)" << endl;
  }
}
