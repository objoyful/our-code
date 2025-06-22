//***************************************************
// This program reads words from a file, storing
// them into an array.  The array is sorted.
// The user is prompted to enter a word.  The program
// reports whether or not the word was in the array
// of words.
//**************************************************

#include <fstream>  // For ifstream
#include <iostream>
#include <string>  // For string class
using namespace std;

void sort(string grades[], int numGrades);
// Post: Values in grades have been put into numeric order

bool BinarySearch(string words[], string aWord, int first, int last);
// Post: Returns true if aWord is in words; false otherwise

int main() {
  ifstream inFile;
  inFile.open("Words.in");
  string words[30];
  int numWords = 0;
  string aWord;
  inFile >> words[0];
  while (inFile) {
    numWords++;
    inFile >> words[numWords];
  }
  sort(words, numWords);
  cout << "Enter a word; enter Quit to stop processing" << endl;
  cin >> aWord;
  while (aWord != "Quit") {
    if (BinarySearch(words, aWord, 0, numWords))
      cout << aWord << " was found" << endl;
    else
      cout << aWord << " was not found" << endl;
    cout << "Enter a word; enter Quit to stop processing" << endl;
    cin >> aWord;
  }

  return 0;
}

//*****************************************************************

void sort(string grades[], int numGrades)
// Post:  Straight selection sort has been used to sort the values
{
  string temp;
  int passCount;    // Outer loop control variable
  int searchIndex;  // Inner loop control variable
  int minIndex;     // Index of minimum so far

  for (passCount = 0; passCount < numGrades - 1; passCount++) {
    minIndex = passCount;
    // Find the index of the smallest component
    // in grades[passCount..numGrades-1]
    for (searchIndex = passCount + 1; searchIndex < numGrades; searchIndex++)
      if (grades[searchIndex] < grades[minIndex]) minIndex = searchIndex;
    // Swap data[minIndex] and data[passCount]

    temp = grades[minIndex];
    grades[minIndex] = grades[passCount];
    grades[passCount] = temp;
  }
}

//*****************************************************************

bool BinarySearch(string words[], string aWord, int first, int last)
// Binary search is used
{
  int middle;
  if (first > last)
    return false;
  else {
    middle = (first + last) / 2;
    if (words[middle] == aWord)
      return true;
    else if (words[middle] > aWord)
      return BinarySearch(words, aWord, first, middle - 1);
    else
      return BinarySearch(words, aWord, middle + 1, last);
  }
}
