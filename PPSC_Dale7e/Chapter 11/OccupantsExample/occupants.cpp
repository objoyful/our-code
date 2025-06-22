//******************************************************************
// This program allows a building owner to look up how many
// occupants are in a given apartment
//******************************************************************
#include <fstream>  // For file I/O
#include <iostream>
using namespace std;

const int BUILDING_SIZE = 10;  // Number of apartments

int main() {
  int occupants[BUILDING_SIZE];  // occupants[i] is the number of
                                 //   occupants in apartment i
  int totalOccupants;            // Total number of occupants
  int counter;                   // Loop control and index variable
  int apt;                       // An apartment number
  ifstream inFile;               // File of occupant data (one
                                 //   integer per apartment)
  inFile.open("apt.dat");
  totalOccupants = 0;
  for (counter = 0; counter < BUILDING_SIZE; counter++) {
    inFile >> occupants[counter];
    totalOccupants = totalOccupants + occupants[counter];
  }
  cout << "No. of apts. is " << BUILDING_SIZE << endl
       << "Total no. of occupants is " << totalOccupants << endl;

  cout << "Begin apt. lookup..." << endl;
  do {
    cout << "Apt. number (1 through " << BUILDING_SIZE << ", or 0 to quit): ";
    cin >> apt;
    if (apt > 0)
      cout << "Apt. " << apt << " has " << occupants[apt - 1] << " occupants"
           << endl;
  } while (apt > 0);
  return 0;
}
