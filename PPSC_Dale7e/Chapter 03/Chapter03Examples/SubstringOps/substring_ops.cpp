//***********************************************************
// SubstrOps program
// This program demonstrates find and substr operations
//***********************************************************
#include <iostream>
#include <string>  // For string type

using namespace std;

int main() {
  string name = "Olivia Johnson Peterson";
  int index;
  index = name.find(' ');
  cout << "First Name: " << name.substr(0, index) << endl;
  name = name.substr(index + 1, name.length() - 1);
  index = name.find(' ');
  cout << "Middle Name: " << name.substr(0, index) << endl;
  name = name.substr(index + 1, name.length() - 1);
  cout << "Last Name: " << name;
  return 0;
}
