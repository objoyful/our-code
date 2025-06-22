//**************************************************************
// CharCounts program
// This program counts the number of letters, periods, question
// marks, and exclamation marks found in the first 100 input
// characters.
// Assumption: Input consists of at least 100 characters.
//**************************************************************
#include <cctype>  // For isalpha()
#include <iostream>

using namespace std;

int main() {
  char inChar;          // Current input character
  int loopCount;        // Loop control variable
  int letterCount = 0;  // Number of letters
  int periodCount = 0;  // Number of periods
  int questCount = 0;   // Number of question marks
  int exclamCount = 0;  // Number of exclamation marks

  cout << "Enter your text:" << endl;
  for (loopCount = 1; loopCount <= 100; loopCount++) {
    cin.get(inChar);
    if (isalpha(inChar))
      letterCount++;
    else
      switch (inChar) {
        case '.':
          periodCount++;
          break;
        case '?':
          questCount++;
          break;
        case '!':
          exclamCount++;
          break;
        default:;  // Unnecessary, but OK
      }
  }
  cout << endl;
  cout << "Input contained" << endl
       << letterCount << " letters" << endl
       << periodCount << " periods" << endl
       << questCount << " question marks" << endl
       << exclamCount << " exclamation marks" << endl;
  return 0;
}
