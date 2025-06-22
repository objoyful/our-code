//******************************************************************
// Format Names program
// This program reads in a Social Security number, a first name, a
// middle name or initial, and a last name from file inData.
// The name is written to file outData in three formats:
//  1. First name, middle name, last name, and Social Security number.
//  2. Last name, first name, middle name, and Social Security number
//  3. Last name, first name, middle initial, and Social Security number
//  4. First name, middle initial, last name
//******************************************************************
#include <fstream>  // Access ofstream
#include <string>   // Access string

using namespace std;

int main() {
  // Declare and open files
  ifstream inData;
  ofstream outData;
  inData.open("name.in");
  outData.open("name.out");

  // Declare variables
  string socialNum;   // Social Security number
  string firstName;   // First name
  string lastName;    // Last name
  string middleName;  // Middle name
  char initial;       // Middle initial

  // Read in data from file inData
  inData >> socialNum >> firstName >> middleName >> lastName;

  // Access middle initial and append a period
  initial = middleName.at(0);

  // Output information in required formats
  outData << firstName << ' ' << middleName << ' ' << lastName << ' '
          << socialNum << endl;
  outData << lastName << ", " << firstName << ' ' << middleName << ' '
          << socialNum << endl;
  outData << lastName << ", " << firstName << ' ' << initial << ". "
          << socialNum << endl;
  outData << firstName << ' ' << initial << ". " << lastName;

  // Close files
  inData.close();
  outData.close();
  return 0;
}
