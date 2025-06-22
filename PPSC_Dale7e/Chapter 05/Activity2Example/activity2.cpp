//*****************************************************************
// Activity program
// This program outputs an appropriate activity
// for a given temperature
//*****************************************************************
#include <iostream>
#include <string>
using namespace std;

int main() {
  int temperature;  // The outside temperature
  bool raining;
  bool walk;
  bool movie;
  bool book;

  // Read and echo temperature
  cout << "Enter the outside temperature:" << endl;
  cin >> temperature;
  cout << "Enter 1 if it is raining and 0 if it is not.";
  cin >> raining;
  cout << "The current temperature is " << temperature;
  if (raining)
    cout << " and it is raining." << endl;
  else
    cout << " and it is not raining." << endl;

  // Output activity
  walk = temperature > 60 && !raining;
  movie = temperature > 60 && raining;
  book = temperature < 60;
  if (walk)
    cout << "Go for a walk." << endl;
  else if (movie)
    cout << "Go to a movie." << endl;
  else
    cout << "Read a good book." << endl;
  return 0;
}
