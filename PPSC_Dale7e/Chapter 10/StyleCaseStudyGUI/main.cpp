//***********************************************************************
// Style Program
// The program calculates number of words, average word length, number of
// sentences, average sentence length, number of uppercase letters,
// number of lowercase letters, and number of digits in a file of text
//***********************************************************************
#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>  // Access ostringstream

#include "dialog.h"  // Access GUI components

using namespace std;

enum Features { UPPER, LOWER, DIGIT, IGNORE, EOW, EOS };

struct Counters {
  int uppercase;
  int lowercase;
  int digit;
  int word;
  int sentence;
  int ignore;
};

// Function prototypes
void OpenFile(ostringstream&, ifstream&);
// This shows a dialog requesting a file name and opens the file.
// If the file is not found, an error code is returned

Features Decode(char character);
// This function examines the character and returns its type

void IncrementCounters(Counters& counters, char character);
// This function increments the appropriate character counter

void PrintTable(ostringstream&, Counters counters);
// Table is displayed

void InitializeCounters(Counters& counters);
// This function initializes the counters

int main() {
  // A string output stream to gather output
  ostringstream output;

  // Prepare files for reading and writing
  ifstream text;
  Counters counters;
  OpenFile(output, text);

  if (!text) {
    cout << "Files did not open successfully." << endl;
    return 1;
  }

  InitializeCounters(counters);
  char character;  // Input character

  text.get(character);  // Input one character
  do {                  // Process each character
    IncrementCounters(counters, character);
    text.get(character);  // Input one character
  } while (text);

  PrintTable(output, counters);
  OutputDialog outputDialog(output.str());
  outputDialog.display();

  text.close();
  return 0;
}

//******************************************************************

Features Decode(char character)
// This function examines the character and returns its type
{
  if (isupper(character))
    return UPPER;
  else if (islower(character))
    return LOWER;
  else if (isdigit(character))
    return DIGIT;
  else
    switch (character) {
      case '.':
      case '?':
      case '!':
        return EOS;

      case ' ':
      case ',':
      case ';':
      case ':':
      case '\n':
        return EOW;
    }
  return IGNORE;
}

//******************************************************************

void OpenFile(ostringstream& output, ifstream& text) {
  string inFileName;  // User-specified input file name
  FileDialog chooseAFileDialog("Choose the file to be processed");
  inFileName = chooseAFileDialog.display();
  text.open(inFileName.c_str());
  output << "Analysis of characters on input file " << inFileName << endl
         << endl;
}

//******************************************************************

void PrintTable(ostringstream& output, Counters counters)
// Function PrintTable shows the percentages represented by each
// of the five categories
{
  int totalAlphaNum;
  totalAlphaNum = counters.uppercase + counters.lowercase + counters.digit;

  // Put results in output string stream
  output << "Total number of alphanumeric characters: " << totalAlphaNum
         << endl;
  output << "Number of uppercase letters: " << counters.uppercase << endl;
  output << "Number of lowercase letters: " << counters.lowercase << endl;
  output << "Number of digits: " << counters.digit << endl;
  output << "Number of characters ignored: " << counters.ignore << endl;

  // Add number of end-of-sentence markers to the word count
  counters.word = counters.word + counters.sentence;

  // Write rest of results in output string stream
  output << "Number of Words: " << counters.word << endl;
  output << "Number of Sentences: " << counters.sentence << endl;
  output << "Average word length: " << fixed << setprecision(2)
         << float(totalAlphaNum) / counters.word << endl;
  output << "Average sentence length: " << fixed << setprecision(2)
         << float(counters.word) / counters.sentence << endl;
}

//*****************************************************************

void IncrementCounters(Counters& counters, char character)
// This function examines character and increments the
// appropriate counter
{
  static bool endOfWord = false;

  switch (Decode(character)) {
    case UPPER:
      counters.uppercase++;
      endOfWord = false;
      break;
    case LOWER:
      counters.lowercase++;
      endOfWord = false;
      break;
    case DIGIT:
      counters.digit++;
      endOfWord = false;
      break;
    case EOW:
      if (!endOfWord) {
        counters.word++;
        endOfWord = true;
      }
      break;
    case EOS:
      counters.sentence++;
      endOfWord = true;
      break;
    case IGNORE:
      counters.ignore++;
      break;
  }
}

//***********************************************************

void InitializeCounters(Counters& counters) {
  counters.uppercase = 0;
  counters.lowercase = 0;
  counters.digit = 0;
  counters.word = 0;
  counters.sentence = 0;
  counters.ignore = 0;
}
