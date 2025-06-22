//******************************************************
// This program demonstrates various stack methods
//******************************************************
#include <iostream>
#include <stack>
using namespace std;

int main() {
  stack<string> strStack;  // Create an empty stack
  string word;
  cout << "Enter a line with six words:" << endl;
  for (int i = 1; i <= 6; i++) {
    cin >> word;
    strStack.push(word);  // Insert elements at top
  }
  // Access top and size
  cout << "Top element: " << strStack.top() << endl
       << "Size of stack: " << strStack.size() << endl;
  // Output the stack
  cout << "Stack contents:" << endl;
  while (!strStack.empty()) {
    cout << strStack.top() << endl;
    strStack.pop();  // Remove elements from top
  }
  return 0;
}
