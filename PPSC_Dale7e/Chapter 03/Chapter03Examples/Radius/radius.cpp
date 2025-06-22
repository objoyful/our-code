//**********************************************
// This program computes the radius of a circle
//*********************************************

#include <iostream>
using namespace std;

int main() {
  const double CIRCUMFERENCE = 10.0;
  double radius;
  radius = CIRCUMFERENCE / 2.0 * 3.14159265;
  cout << "The radius is " << radius;
  return 0;
}
