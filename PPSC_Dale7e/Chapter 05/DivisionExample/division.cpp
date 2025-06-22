//*******************************************************
// Division program
// Dividend and divisor are prompted for and read.
// If divisor is 0, division is not performed;
// otherwise, division is performed and result is output.
//*******************************************************
#include <iostream>
using namespace std;

int main() {
  int dividend;
  int divisor;
  int result;
  cout << "Enter dividend and divisor" << endl;
  cin >> dividend >> divisor;

  if (divisor != 0) {
    result = dividend / divisor;
    cout << "Result is " << result << endl;
  } else {
    cout << "Division by zero is not allowed." << endl;
    result = 9999;
  }
  return 0;
}
