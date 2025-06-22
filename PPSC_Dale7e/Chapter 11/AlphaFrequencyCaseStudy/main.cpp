//*******************************************************
// This program counts and outputs the frequency of
// occurrence of alphabetic characters in a file.
// Three functions are used, which take array parameters.
//*******************************************************
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void ZeroOut(int intArray[], int numElements);
// Pre: numElements is assigned
// Post: intArray[0..numElements-1] are zero
void ProcessText(int counters[], istream& inFile);
// Post: counters[0..25] contain the frequency of each
//       character in inFile
void Print(int counters[]);
// Post: counters[0..25] have been output

int main() {
  // Declarations
  int counters[26];
  ifstream inFile;
  inFile.open("text.dat");
  ZeroOut(counters, 25);
  ProcessText(counters, inFile);
  Print(counters);
  return 0;
}

//********************************************************

void ZeroOut(int intArray[], int numElements) {
  for (int i = 0; i <= numElements; i++) intArray[i] = 0;
}

//********************************************************

void ProcessText(int counters[], istream& inFile) {
  string line;
  int limit;  // Number of characters in a line
  int index;

  getline(inFile, line);  // Read a line
  while (inFile) {
    limit = line.length();
    for (int counter = 0; counter < limit;
         counter++) {  // Access each character in the line
      if (isalpha(line[counter])) {
        index = toupper(line[counter]) - 'A';
        counters[index]++;
      }
    }
    getline(inFile, line);
  }
}

//*******************************************************

void Print(int counters[]) {
  for (int counter = 0; counter < 26; counter++)
    cout << static_cast<char>(counter + 'A') << ": " << counters[counter]
         << endl;
}
