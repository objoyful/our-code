//******************************************************************
// Style Program
// The program calculates number of words, average word length,
// number of sentences, average sentence length, number of
// uppercase letters, number of lowercase letters, and number of
// digits in a file of text
//******************************************************************

#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>

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
void OpenFile(ifstream&);
// This function reads in a file name and opens the file.
// If the file is not found, an error code is returned
Features Decode(char character);
// This function examines the character and returns its type
void IncrementCounters(Counters& counters, char character);
// This function increments the appropriate character counter
void PrintTable(Counters counters);
// Table is output
void InitializeCounters(Counters& counters);
// This function initializes the counters

int main() {
  // Prepare files for reading and writing
  ifstream text;
  Counters counters;
  OpenFile(text);
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

  PrintTable(counters);
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

void OpenFile(ifstream& text) {
  string inFileName;  // User-specified input file name
  cout << "Enter the name of the file to be processed" << endl;
  cin >> inFileName;
  text.open(inFileName.c_str());
  cout << "Analysis of characters on input file " << inFileName << endl << endl;
}

//******************************************************************

void PrintTable(Counters counters)
// Function PrintTable outputs the percentages represented by each
// of the five categories
{
  int totalAlphaNum;
  totalAlphaNum = counters.uppercase + counters.lowercase + counters.digit;

  // Output results on file cout
  cout << "Total number of alphanumeric characters: " << totalAlphaNum << endl;
  cout << "Number of uppercase letters: " << counters.uppercase << endl;
  cout << "Number of lowercase letters: " << counters.lowercase << endl;
  cout << "Number of digits: " << counters.digit << endl;
  cout << "Number of characters ignored: " << counters.ignore << endl;

  // Add number of end-of-sentence markers to the word count
  counters.word = counters.word + counters.sentence;

  // Write rest of results on file cout
  cout << "Number of words: " << counters.word << endl;
  cout << "Number of sentences: " << counters.sentence << endl;
  cout << "Average word length: " << fixed << setprecision(2)
       << static_cast<float>(totalAlphaNum) / counters.word << endl;

  cout << "Average sentence length: " << fixed << setprecision(2)
       << static_cast<float>(counters.word) / counters.sentence << endl;
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
