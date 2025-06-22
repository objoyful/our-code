#include <iomanip>
#include <iostream>

using namespace std;
int main() {
  double num = 1000;
  cout << setw(3) << 1776 << ' ' << 44 << endl;
  cout << setw(4) << showpoint << num << ' ' << 44.55 << endl;
  cout << setprecision(5) << 1776.12 << ' ' << num << endl;
  cout << num;
  return 0;
}
