//******************************************************************
// This program inputs one month's temperature readings from a file,
// stores unique readings in a list, outputs the list, removes a value
// of 200, and outputs the resulting list.
//******************************************************************
#include <fstream>  // For file I/O
#include <iostream>

#include "SortedList.h"  // For List class
using namespace std;

int main() {
  SortedList temps;  // List of temperature readings
  int oneTemp;       // One temperature reading
  ifstream inData;   // File of temperature readings
  ofstream outData;  // Output file

  inData.open("temps.dat");
  if (!inData) {
    outData << "Can't open file temps.dat" << endl;
    return 1;
  }

  outData.open("temps.ans");

  inData >> oneTemp;  // Get a temperature
  while (inData && !temps.IsFull()) {
    if (!temps.IsThere(oneTemp)) {  // Reject duplicates
      temps.Insert(oneTemp);
    }
    inData >> oneTemp;
  }

  // Output original list
  // Set up for an iteration
  outData << "No. of unique readings: " << temps.GetLength() << endl;
  while (temps.HasNext()) {
    oneTemp = temps.GetNextItem();
    outData << oneTemp << endl;
  }

  temps.Delete(200);  // Remove 200 if there, cannot be more than one
  temps.ResetList();
  outData << "Readings without value of 200. " << endl;

  while (temps.HasNext()) {
    oneTemp = temps.GetNextItem();
    outData << oneTemp << endl;
  }

  inData.close();
  outData.close();
  return 0;
}
