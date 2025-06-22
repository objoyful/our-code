//******************************************************************
// Acoustic Program
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

  // Declare and open input file
  ifstream inData;  // Input file of readings
  inData.open("acoustic.dat");

  // Initialize variables and output
  cout << setw(14) << "Reading Number" << setw(15) << "Actual Reading"
       << setw(18) << "Relative Reading" << endl;
  inData >> baseValue;
  preceding = baseValue;
  precedingRelative = 0.0;
  highNumber = 1;
  lowNumber = 1;
  high = baseValue;
  low = baseValue;
  highRelative = 0.0;
  lowRelative = 0.0;
  readingNumber = 1;
  relative = 0.0;

  // Write first line of output
  cout << fixed << showpoint << setprecision(2) << setw(7) << readingNumber
       << setw(19) << baseValue << setw(15) << relative << endl;

  readingNumber = 2;  // Initialize loop end
  while (readingNumber <= 12) {
    inData >> current;               // Input new reading
    relative = current - baseValue;  // Calculate new relative
    cout << setw(7) << readingNumber << setw(19) << current << setw(15)
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

  // Print high and low readings
  cout << endl;
  cout << "Highest reading number is " << highNumber << endl;
  cout << "Highest reading is " << high << endl;
  cout << "Highest relative value is " << highRelative << endl;
  cout << endl;
  cout << "Lowest dip is number " << lowNumber << endl;
  cout << "Lowest dip reading is " << low << endl;
  cout << "Lowest relative dip is " << lowRelative << endl;

  inData.close();
  return 0;
}
