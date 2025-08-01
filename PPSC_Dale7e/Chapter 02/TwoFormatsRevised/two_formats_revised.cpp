//***********************************************************
// PrintName program
// This program outputs a name in two different formats
//***********************************************************
#include <iostream>  // For cout, endl
#include <string>

using namespace std;

const string FIRST = "Herman";  // Person's first name
const string LAST = "Smith";    // Person's last name
const char MIDDLE = 'G';        // Person's middle initial
const string TITLE = "Mr.";
int main() {
  string firstLast;  // Name in first-last format
  string lastFirst;  // Name in last-first format

  firstLast = TITLE + " " + FIRST + " " + LAST;
  cout << "Name in first-last format is " << firstLast << endl;

  lastFirst = LAST + ", " + TITLE + " " + FIRST + ", ";
  cout << "Name in last-first-initial format is ";
  cout << lastFirst << MIDDLE << '.' << endl;
  return 0;
}
