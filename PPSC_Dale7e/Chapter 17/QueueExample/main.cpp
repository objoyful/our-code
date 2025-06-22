//******************************************************
// This program demonstrates various queue methods
//******************************************************
#include <iostream>
#include <queue>
using namespace std;
int main() {
  queue<string> strQueue;  // Create an empty queue
  string word;
  cout << "Enter a line with six words:" << endl;
  for (int i = 1; i <= 6; i++) {
    cin >> word;
    strQueue.push(word);  // Insert elements at back
  }
  // Access front, back, and size
  cout << "Front element: " << strQueue.front() << endl
       << "Back element: " << strQueue.back() << endl
       << "Size of queue: " << strQueue.size() << endl;
  // Output the queue
  cout << "Queue contents:" << endl;
  while (!strQueue.empty()) {
    cout << strQueue.front() << endl;
    strQueue.pop();  // Remove elements from front
  }
  return 0;
}
