//******************************************************
// This program demonstrates various set methods
//******************************************************
#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
using namespace std;

int main() {
  set<string> strSet;  // Create an empty set
  string word;
  cout << "Enter a line with six words:" << endl;
  for (int i = 1; i <= 6; i++) {
    cin >> word;
    strSet.insert(word);  // Insert elements
  }
  // Access size
  cout << "Size of set: " << strSet.size() << endl;
  // Output the set
  set<string>::iterator place;
  cout << "Set contents from beginning to end: " << endl;
  // Traverse set in forward order
  for (place = strSet.begin(); place != strSet.end(); place++)
    cout << *place << " ";
  // Create a reverse iterator
  set<string>::reverse_iterator rplace;
  cout << endl << "Set contents from end to beginning: " << endl;
  // Traverse set in reverse order
  for (rplace = strSet.rbegin(); rplace != strSet.rend(); ++rplace)
    cout << *rplace << " ";
  // Prepare to illustrate set difference
  set<string> strSet2(strSet);     // Create a copy of strSet
  strSet2.erase(strSet2.begin());  // Delete first element
  strSet2.erase(--strSet2.end());  // Delete last element
  set<string> strSet3;             // Create a set for the result
  // Need to use inserter because set doesn't allow copy iterator
  set_difference(strSet.begin(), strSet.end(),       // First set
                 strSet2.begin(), strSet2.end(),     // Second set
                 inserter(strSet3, strSet3.end()));  // Result set
  // Output result set
  cout << endl << "Set difference from beginning to end: " << endl;
  for (place = strSet3.begin(); place != strSet3.end(); place++)
    cout << *place << " ";
  return 0;
}
