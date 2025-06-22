#include <fstream>
#include <iostream>

#include "UserInterface.h"
using namespace std;
int main() {
  UserInterface gateAgent;
  ofstream outFile;
  int crew;        // Number of crew members
  int passengers;  // Number of passengers
  outFile.open("PassengerList");
  cout << "Enter number of crew members" << endl;
  cin >> crew;
  cout << "Enter number of passengers" << endl;
  cin >> passengers;
  try {
    gateAgent.InputClosetAndFuel();
    for (int number = 1; number <= crew; number++) gateAgent.InputCrew();
    for (int number = 1; number <= passengers; number++)
      gateAgent.InputPassenger();
    gateAgent.CloseDoors(outFile);
  } catch (TooHeavy) {
    cout << "Cancel flight: Weight is too heavy" << endl;
  } catch (CofGWrong) {
    cout << "Cancel flight: Center of Gravity is wrong " << endl;
  } catch (RowOverflow) {
    cout << "Too many passengers assigned to one row" << endl;
  }
  return 0;
}
