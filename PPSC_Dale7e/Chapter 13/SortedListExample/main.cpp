//******************************************************************
// This program inputs a file of words, stores the words, removing
// duplicates, and outputs the list.
//******************************************************************
#include <fstream>  // For file I/O
#include "SortedList.h"  // For List class

using namespace std;

int main() {
  SortedList words;  // List of words
  string oneWord;    // One word
  ifstream inData;   // File of temperature readings
  ofstream outData;  // Output file

  inData.open("words.dat");
  if (!inData) {
    outData << "Can't open file words.dat" << endl;
    return 1;
  }
  outData.open("words.ans");
  inData >> oneWord;  // Get a word
  while (inData && !words.IsFull()) {
    if (!words.IsThere(oneWord)) words.Insert(oneWord);
    inData >> oneWord;
  }

  // Output original list
  // Set up for an iteration
  outData << words.GetLength() << " unique words." << endl;
  while (words.HasNext()) {
    oneWord = words.GetNextItem();
    outData << oneWord << endl;
  }

  inData.close();
  outData.close();
  return 0;
}
