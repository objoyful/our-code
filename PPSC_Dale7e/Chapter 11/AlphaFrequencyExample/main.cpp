//****************************************************
// This program counts and outputs the frequency of
// occurrence of alphabetic characters in a file
//****************************************************
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main() {
  // Declarations
  int counters[26];
  ifstream inFile;
  inFile.open("text.dat");
  string line;
  int limit;  // Number of characters in a line
  int index;

  // Zero out the array of counters
  for (int counter = 0; counter < 26; counter++) counters[counter] = 0;

  getline(inFile, line);  // Read a line
  while (inFile) {
    cout << "hello" << endl;
    limit = line.length();
    for (int counter = 0; counter < limit; counter++) {
      // Access each character in the line
      if (isalpha(line.at(counter))) {
        // Increment the character's counter
        index = toupper(line.at(counter)) - 'A';
        counters[index]++;
      }
    }
    getline(inFile, line);  // Read a line
  }

  for (int counter = 0; counter < 26; counter++)
    cout << static_cast<char>(counter + 'A') << ": " << counters[counter]
         << endl;
  return 0;
}
