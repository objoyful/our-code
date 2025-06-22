//******************************************************************
// Acoustic Program GUI
// This program inputs 12 sound-level readings, taken in a room
// at different frequencies.  The first reading is used as a base
// value.  For each reading, a value relative to the base is
// calculated and printed.  The program ends by printing the
// lowest dip in the readings, where a dip is defined as a reading
// followed by a higher reading.
//******************************************************************

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>  // Access ostringstream

#include "dialog.h"  // Access GUI components

using namespace std;

int main() {
  // Declare variables
  float baseValue;          // First reading
  float preceding;          // Reading preceding current
  float precedingRelative;  // Relative preceding current
  float current;            // Input during each iteration
  float relative;           // Current minus base value
  float high;               // Highest value input
  float highRelative;       // High minus base value
  float low;                // Lowest dip in the readings
  float lowRelative;        // Relative value of low
  int highNumber;           // Sequence number of high
  int lowNumber;            // Sequence number of lowest dip
  int readingNumber;        // Sequence number of current reading

  ostringstream output;  // Output to be displayed to user.

  // Initialize output.
  output << setw(14) << "Reading Number" << setw(15) << "Actual Reading"
         << setw(18) << "Relative Reading" << endl;

  // Create a GUI to ask the user how to get the frequency data.
  YesNoDialog choice("Would you like to choose an acoustic data file?");
  bool response = choice.display();

  // Initialize starting values that are not dependent on the base.
  precedingRelative = 0.0;
  highNumber = 1;
  lowNumber = 1;
  highRelative = 0.0;
  lowRelative = 0.0;
  readingNumber = 1;
  relative = 0.0;

  if (response == true) {
    // Create the GUI to get the name of the input file.
    FileDialog dataInputFile("Acoustic Frequency Data File");
    string inputFile = dataInputFile.display();

    // Declare and open input file
    ifstream inData;  // Input file of readings
    inData.open(inputFile);

    // Initialize variables dependent on the base value.
    inData >> baseValue;
    preceding = baseValue;
    high = baseValue;
    low = baseValue;

    // Write first line of output
    output << fixed << showpoint << setprecision(2) << setw(7) << readingNumber
           << setw(19) << baseValue << setw(15) << relative << endl;

    readingNumber = 2;  // Initialize loop end
    while (readingNumber <= 12) {
      inData >> current;               // Input new reading
      relative = current - baseValue;  // Calculate new relative
      output << setw(7) << readingNumber << setw(19) << current << setw(15)
             << relative << endl;

      if (current > high)  // Check for new high
      {
        high = current;
        highNumber = readingNumber;
        highRelative = relative;
      }

      if (current > preceding)  // Check for new low
      {
        if (preceding < low) {
          low = preceding;
          lowNumber = readingNumber - 1;
          lowRelative = precedingRelative;
        }
      }
      preceding = current;
      precedingRelative = relative;
      readingNumber++;
    }

    inData.close();
  } else {
    // Create a GUI to ask how many frequencies will be provided.
    IntDialog numberOfFrequencies("How many frequencies will be provided?");
    int frequencyNumber = numberOfFrequencies.display();

    // Create a GUI to ask the user for the base value.
    FloatDialog weightDialog("What is the base frequency value?");
    baseValue = weightDialog.display();

    // Initialize variables dependent on the base value.
    preceding = baseValue;
    high = baseValue;
    low = baseValue;

    // Write first line of output
    output << fixed << showpoint << setprecision(2) << setw(7) << readingNumber
           << setw(19) << baseValue << setw(15) << relative << endl;

    // Loop to read in each of the frequency values.
    readingNumber = 2;
    while (readingNumber <= frequencyNumber) {
      // Create a GUI to read in each frequency value.
      FloatDialog frequency("Enter Frequency Value " +
                            std::to_string(readingNumber) + ":");
      current = frequency.display();

      relative = current - baseValue;  // Calculate new relative
      output << setw(7) << readingNumber << setw(19) << current << setw(15)
             << relative << endl;

      if (current > high)  // Check for new high
      {
        high = current;
        highNumber = readingNumber;
        highRelative = relative;
      }

      if (current > preceding)  // Check for new low
      {
        if (preceding < low) {
          low = preceding;
          lowNumber = readingNumber - 1;
          lowRelative = precedingRelative;
        }
      }
      preceding = current;
      precedingRelative = relative;

      readingNumber++;
    }
  }

  // Print high and low readings
  output << endl;
  output << "Highest reading number is " << highNumber << endl;
  output << "Highest reading is " << high << endl;
  output << "Highest relative value is " << highRelative << endl;
  output << endl;
  output << "Lowest dip is number " << lowNumber << endl;
  output << "Lowest dip reading is " << low << endl;
  output << "Lowest relative dip is " << lowRelative << endl;

  OutputDialog outputDialog(output.str());
  outputDialog.display();

  return 0;
}
