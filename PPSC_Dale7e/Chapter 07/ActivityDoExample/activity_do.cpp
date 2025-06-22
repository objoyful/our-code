//*****************************************************************
// Activity program
// This program outputs an appropriate activity
// for a given temperature
//******************************************************************
#include <iostream>
#include <string>
using namespace std;

int main() {
  int temperature;  // The outside temperature
  int raining;
  char signal;
  do  // Repeat while signal is 'c'
  {
    // Read and echo temperature
    cout << "Enter the outside temperature:" << endl;
    cin >> temperature;
    cout << "Enter 1 if it is raining and 0 if it is not." << endl;
    cin >> raining;
    cout << "The current temperature is " << temperature;

    switch (raining) {
      case 0:
        cout << " and it is not raining." << endl;
        if (temperature > 60)
          cout << "Go for a walk." << endl;
        else
          cout << "Read a good book." << endl;
        break;
      case 1:
        cout << " and it is raining." << endl;
        if (temperature > 60)
          cout << "Go to a movie." << endl;
        else
          cout << "Read a good book." << endl;
        break;
    }
    cout << "Enter a 'c' to continue or a 'q' to quit." << endl;
    cin >> signal;
  } while (signal == 'c');
  return 0;
}
