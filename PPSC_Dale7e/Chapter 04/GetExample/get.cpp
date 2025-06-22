//*******************************************************
// This program demonstrates the use of the get function.
//*******************************************************

#include <iostream>
using namespace std;
int main() {
  char ch1, ch2, ch3;
  cout << "Enter three characters including a space." << endl;
  cin.get(ch1);
  cin.get(ch2);
  cin.get(ch3);
  cout << "You entered: " << ch1 << ch2 << ch3 << endl;
  return 0;
}
