//********************************************************************
// Rich Uncle Program (GUI Version)
// Percentage of characters in the file that belong to five categories:
// uppercase characters,lowercase characters, decimal digits, blanks,
// and end-of-sentence punctuation marks
// Assumptions: Input file is not empty and percentages are based
// on total number of characters in the file
//******************************************************************

#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>   // Access ostringstream
#include "dialog.h"  // Access GUI components

using namespace std;
int main() {
  // Prepare file for reading
  ifstream text;
  char character;

  // Declare and initialize counters
  int uppercaseCounter = 0;    // Number of uppercase letters
  int lowercaseCounter = 0;    // Number of lowercase letters
  int blankCounter = 0;        // Number of blanks
  int digitCounter = 0;        // Number of digits
  int punctuationCounter = 0;  // Number of end '.', '?', '!'
  int allElseCounter = 0;      // Remaining characters

  ostringstream output;  // Output to be displayed to user.

  FileDialog dataInputFile("Choose the file to be processed");
  string inFileName = dataInputFile.display();

  text.open(inFileName.c_str());

  text.get(character);  // Input one character

  do {
    // Process each character
    if (isupper(character))
      uppercaseCounter++;
    else if (islower(character))
      lowercaseCounter++;
    else if (isdigit(character))
      digitCounter++;
    else
      switch (character) {
        case ' ':
          blankCounter++;
          break;
        case '.':
        case '?':
        case '!':
          punctuationCounter++;
          break;
        default:
          allElseCounter++;
          break;
      }
    text.get(character);
  } while (text);

  text.close();

  // Calculate total number of characters
  float total = uppercaseCounter + lowercaseCounter + blankCounter +
                digitCounter + punctuationCounter + allElseCounter;
  output << "Analysis of characters on input file " << inFileName << endl;

  // Write output on standard output device
  output << fixed << setprecision(3) << "Percentage of uppercase characters: "
         << uppercaseCounter / total * 100 << endl;
  output << fixed << setprecision(3) << "Percentage of lowercase characters: "
         << lowercaseCounter / total * 100 << endl;
  output << fixed << setprecision(3)
         << "Percentage of blanks: " << blankCounter / total * 100 << endl;
  output << fixed << setprecision(3)
         << "Percentage of digits: " << digitCounter / total * 100 << endl;
  output << fixed << setprecision(3) << "Percentage of end-of-sentence "
         << "punctuation " << punctuationCounter / total * 100 << endl;

  OutputDialog outputDialog(output.str());
  outputDialog.display();

  return 0;
}
