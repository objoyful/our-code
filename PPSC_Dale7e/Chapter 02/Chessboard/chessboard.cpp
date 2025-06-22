//******************************************************************
// Chessboard program
// This program outputs a chessboard pattern that is built up from
// basic strings of white and black characters.
//******************************************************************
#include <iostream>  // For cout, endl
#include <string>
using namespace std;

const string BLACK = "********";  // Define a line of a black square
const string WHITE = "        ";  // Define a line of a white square

int main() {
  string whiteRow;  // A row beginning with a white square
  string blackRow;  // A row beginning with a black square

  // Create a white-black row by concatenating the basic strings
  whiteRow = WHITE + BLACK + WHITE + BLACK + WHITE + BLACK + WHITE + BLACK;
  // Create a black-white row by concatenating the basic strings
  blackRow = BLACK + WHITE + BLACK + WHITE + BLACK + WHITE + BLACK + WHITE;
  // Output five white-black rows
  cout << whiteRow << endl;
  cout << whiteRow << endl;
  cout << whiteRow << endl;
  cout << whiteRow << endl;
  cout << whiteRow << endl;
  // Output five black-white rows
  cout << blackRow << endl;
  cout << blackRow << endl;
  cout << blackRow << endl;
  cout << blackRow << endl;
  cout << blackRow << endl;
  // Output five white-black rows
  cout << whiteRow << endl;
  cout << whiteRow << endl;
  cout << whiteRow << endl;
  cout << whiteRow << endl;
  cout << whiteRow << endl;
  // Output five black-white rows
  cout << blackRow << endl;
  cout << blackRow << endl;
  cout << blackRow << endl;
  cout << blackRow << endl;
  cout << blackRow << endl;
  // Output five white-black rows
  cout << whiteRow << endl;
  cout << whiteRow << endl;
  cout << whiteRow << endl;
  cout << whiteRow << endl;
  cout << whiteRow << endl;
  // Output five black-white rows
  cout << blackRow << endl;
  cout << blackRow << endl;
  cout << blackRow << endl;
  cout << blackRow << endl;
  cout << blackRow << endl;
  // Output five white-black rows
  cout << whiteRow << endl;
  cout << whiteRow << endl;
  cout << whiteRow << endl;
  cout << whiteRow << endl;
  cout << whiteRow << endl;
  // Output five black-white rows
  cout << blackRow << endl;
  cout << blackRow << endl;
  cout << blackRow << endl;
  cout << blackRow << endl;
  cout << blackRow << endl;

  return 0;
}
