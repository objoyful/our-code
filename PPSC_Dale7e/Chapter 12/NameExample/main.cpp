//******************************************************************
// This program creates two name objects and manipulates them
//******************************************************************
#include <iostream>
#include <string>

#include "Name.h"
using namespace std;

int main() {
  Name herName("Susy", "Sunshine", "Smith");
  Name hisName("Marvin", "Moonlight", "Morgan");
  cout << "Her name is " << herName.GetFirstName() << " "
       << herName.GetMiddleName() << " " << herName.GetLastName() << endl;
  cout << "Her middle initial is " << herName.GetMiddleInitial() << endl;
  cout << "His name is " << hisName.GetFirstName() << " "
       << hisName.GetMiddleName() << " " << hisName.GetLastName() << endl;
  switch (hisName.ComparedTo(herName)) {
    case BEFORE:
      cout << "His name comes before her name" << endl;
      break;
    case SAME:
      cout << "His name and her name are the same" << endl;
      break;
    case AFTER:
      cout << "His name comes after her name" << endl;
  }
  return 0;
}
