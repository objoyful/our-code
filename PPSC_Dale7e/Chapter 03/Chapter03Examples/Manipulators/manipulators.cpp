//**************************************************************
// This program demonstrates the use of manipulators.
//**************************************************************

#include <iomanip>
#include <iostream>

using namespace std;
int main() {
  const int num1 = 1066;
  const int num2 = 1492;
  cout << setw(3) << num1 << setw(5) << num2 << endl;
  cout << num1 << num2;
  cout << setw(4) << num1 << setw(6) << num2 << num1 << endl;
  return 0;
}
