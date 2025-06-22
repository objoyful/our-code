//*****************************************************************
// Activity program
// This program outputs an appropriate activity
// for a given temperature
//*****************************************************************
#include <iostream>
using namespace std;

int main() {
  int temperature;  // The outside temperature

  // Read and echo temperature
  cout << "Enter the outside temperature:" << endl;
  cin >> temperature;
  cout << "The current temperature is " << temperature << endl;

  // Display activity
  cout << "The recommended activity is ";
  if (temperature > 85)
    cout << "swimming." << endl;
  else if (temperature > 70)
    cout << "tennis." << endl;
  else if (temperature > 32)
    cout << "golf." << endl;
  else if (temperature > 0)
    cout << "skiing." << endl;
  else
    cout << "dancing indoors." << endl;
  return 0;
}
