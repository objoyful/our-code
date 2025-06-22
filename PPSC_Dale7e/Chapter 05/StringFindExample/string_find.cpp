//************************************************************
// This program demonstrates the string function find with
// with one successful and one unsuccessful application.
//***********************************************************
#include <iostream>
#include <string>
using namespace std;

int main() {
  string myString = "CAT";
  int pos;
  pos = myString.find('A');
  if (pos == string::npos)
    cout << "No 'A' was found" << endl;
  else
    cout << "An 'A' was found in position " << pos << endl;
  pos = myString.find('B');
  if (pos == string::npos)
    cout << "No 'B' was found" << endl;
  else
    cout << "A 'B' was found in position " << pos << endl;
  return 0;
}
