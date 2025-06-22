//*********************************************************
// This program demonstrates various priority_queue methods
//*********************************************************
#include <iostream>
#include <queue>
using namespace std;

int main() {
  priority_queue<string> strQueue;  // Create an empty priority_queue
  string word;
  cout << "Enter a line with six words:" << endl;
  for (int i = 1; i <= 6; i++) {
    cin >> word;
    strQueue.push(word);  // Insert elements in place
  }
  // Access top and size
  cout << "Top element: " << strQueue.top() << endl
       << "Size of priority_queue: " << strQueue.size() << endl;
  // Output the priority_queue
  cout << "Priority queue contents:" << endl;
  while (!strQueue.empty()) {
    cout << strQueue.top() << endl;
    strQueue.pop();  // Remove elements from top
  }
  return 0;
}
