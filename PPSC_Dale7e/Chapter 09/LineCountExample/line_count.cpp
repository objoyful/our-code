//*****************************************************
// This program reads a file and outputs the line number
// and the number of characters for each line
//*****************************************************
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void LetterCount(string line);
// The number of characters in line is output

int LineCount(istream& file);
// Number of lines in file is returned

int main() {
  ifstream inFile;
  inFile.open("test.dat");
  cout << "Number of lines: " << LineCount(inFile) << endl;
  return 0;
}

//*****************************************************

void LetterCount(string line) {
  int count = line.length();
  cout << " has " << count << " characters: " << endl;
}

//******************************************************
int LineCount(istream& file) {
  int count = 0;
  string line;
  getline(file, line);

  while (file) {
    count++;
    cout << "Line " << count;
    LetterCount(line);
    getline(file, line);
  }
  return count;
}
