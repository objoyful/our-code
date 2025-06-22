//******************************************************************
// FreezeBoil program
// This program computes the midpoint between
// the freezing and boiling points of water
//******************************************************************
#include <iostream>

using namespace std;

const float FREEZE_PT = 32.0;  // Freezing point of water
const float BOIL_PT = 212.0;   // Boiling point of water

int main() {
  float avgTemp;  // Holds the result of averaging
                  //   FREEZE_PT and BOIL_PT

  cout << "Water freezes at " << FREEZE_PT << endl;
  cout << " and boils at " << BOIL_PT << " degrees." << endl;

  avgTemp = FREEZE_PT + BOIL_PT;
  avgTemp = avgTemp / 2.0;

  cout << "Halfway between is ";
  cout << avgTemp << " degrees." << endl;

  return 0;
}
