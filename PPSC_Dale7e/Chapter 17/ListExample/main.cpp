//******************************************************
// This program demonstrates various list methods
//******************************************************
#include <iostream>
#include <list>
using namespace std;

int main() {
  list<string> demo;  // Create an empty list
  string word;
  cout << "Enter a line with six words:" << endl;
  for (int i = 1; i <= 6; i++) {
    cin >> word;
    demo.push_back(word);  // Insert elements at back
  }
  // Access front, back, and size
  cout << "Front element: " << demo.front() << endl
       << "Back element: " << demo.back() << endl
       << "Size of list: " << demo.size() << endl;
  // Create a forward iterator
  list<string>::iterator place;
  cout << "List contents from beginning to end: " << endl;
  // Traverse list in forward direction
  for (place = demo.begin(); place != demo.end(); place++)
    cout << *place << " ";
  // Create a reverse iterator
  list<string>::reverse_iterator rplace;
  cout << endl << "List contents from end to beginning: " << endl;
  // Traverse list in backward direction
  for (rplace = demo.rbegin(); rplace != demo.rend(); ++rplace)
    cout << *rplace << " ";
  cout << endl << "Enter a word to insert after the first word: ";
  cin >> word;
  place = demo.begin();      // Point forward iterator to front
  ++place;                   // Advance one place
  demo.insert(place, word);  // Insert an element
  place = demo.end();        // Point forward iterator past end
  --place;                   // Move back to last element
  --place;                   // Move back one more place
  demo.erase(place);         // Delete element
  cout << "Next to last word has been erased." << endl;
  cout << "Enter a word to add at the front: ";
  cin >> word;
  demo.push_front(word);  // Insert at front
  cout << "List contents from beginning to end: " << endl;
  for (place = demo.begin(); place != demo.end(); ++place)
    cout << *place << " ";
  demo.sort();  // Sort the elements
  cout << endl
       << "After sorting, list contents from beginning to end: " << endl;
  for (place = demo.begin(); place != demo.end(); ++place)
    cout << *place << " ";
  // Create a three element list from an array of strings
  string init[] = {"large", "medium", "small"};
  list<string> demo2(init, init + sizeof(init) / sizeof(string));
  cout << endl << "After merging with: ";
  for (place = demo2.begin(); place != demo2.end(); ++place)
    cout << *place << " ";
  demo.merge(demo2);  // Merge the two lists
  cout << endl << "List contents are: " << endl;
  for (place = demo.begin(); place != demo.end(); ++place)
    cout << *place << " ";
  return 0;
}
