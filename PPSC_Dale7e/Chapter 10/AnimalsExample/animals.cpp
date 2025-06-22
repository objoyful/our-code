//*********************************************************
// This program demonstrates input/output of enumerated
// types
//*********************************************************
#include <cctype>  // For toupper()
#include <iostream>
#include <string>  // For string type
using namespace std;

enum Animals { RODENT, CAT, DOG, BIRD, REPTILE, HORSE, BOVINE, SHEEP };
int main() {
  string animalName;
  Animals inPatient;
  cout << "Enter the name of an animal." << endl;
  cout << "Enter Quit to stop." << endl;

  cin >> animalName;
  while ((toupper(animalName.at(0))) != 'Q') {
    switch (toupper(animalName.at(0))) {
      case 'R':
        if (toupper(animalName.at(1)) == 'O')
          inPatient = RODENT;
        else
          inPatient = REPTILE;
        break;
      case 'C':
        inPatient = CAT;
        break;
      case 'D':
        inPatient = DOG;
        break;

      case 'B':
        if (toupper(animalName.at(1)) == 'I')
          inPatient = BIRD;
        else
          inPatient = BOVINE;
        break;
      case 'H':
        inPatient = HORSE;
        break;
      default:
        inPatient = SHEEP;
    }
    cout << "You entered ";
    switch (inPatient) {
      case RODENT:
        cout << "Rodent";
        break;
      case CAT:
        cout << "Cat";
        break;
      case DOG:
        cout << "Dog";
        break;
      case BIRD:
        cout << "Bird";
        break;
      case REPTILE:
        cout << "Reptile";
        break;
      case HORSE:
        cout << "Horse";
        break;
      case BOVINE:
        cout << "Bovine";
        break;
      case SHEEP:
        cout << "Sheep";
    }
    cout << endl;
    cout << "Enter the name of an animal." << endl;
    cout << "Enter Quit to stop." << endl;
    cin >> animalName;
  }
  return 0;
}
