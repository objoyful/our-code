//*********************************************
// Example program containing declarations,
// string assignment statements, and output
// statements
//*********************************************
#include <iostream>  // For cout, endl
#include <string>
using namespace std;
int main() {
  const string BORDER = "***********************************";
  const string NAME = "Susy Sunshine";
  const string MESSAGE = "Good Morning";
  string outMessage;
  cout << BORDER << endl;
  outMessage = MESSAGE + " to " + "Miss " + NAME;
  cout << outMessage << '!' << endl;
  cout << BORDER << endl;
  return 0;
}
