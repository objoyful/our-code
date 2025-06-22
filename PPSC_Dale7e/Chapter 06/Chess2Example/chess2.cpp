//*****************************************************************
// Chessboard program
// This program displays a chessboard pattern that is built up from
// basic strings of white and black characters.
//*****************************************************************
#include <iostream>
#include <string>
using namespace std;

const string BLACK = "********";  // Define a line of a black square
const string WHITE = "        ";  // Define a line of a white square

int main() {
  string whiteRow;  // A row beginning with a white square
  string blackRow;  // A row beginning with a black square
  int loopCount;    // A loop counter
  int loopCount2;   // Second loop counter

  // Create a white-black row by concatenating the basic strings
  whiteRow = WHITE + BLACK + WHITE + BLACK + WHITE + BLACK + WHITE + BLACK;
  // Create a black-white row by concatenating the basic strings
  blackRow = BLACK + WHITE + BLACK + WHITE + BLACK + WHITE + BLACK + WHITE;
  loopCount = 0;
  while (loopCount < 4)
  // Output four copies of white-black/black-white
  {
    // Output five white-black rows
    loopCount2 = 0;
    while (loopCount2 < 5) {
      cout << whiteRow << endl;
      loopCount2++;
    }
    loopCount2 = 0;
    // Output five black-white rows
    while (loopCount2 < 5) {
      cout << blackRow << endl;
      loopCount2++;
    }
    loopCount++;
  }
  return 0;
}
