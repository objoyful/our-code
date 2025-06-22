//***********************************************************
// Triangle program
// This program uses the IsTriangle function
//***********************************************************
#include <cmath>  // For fabs()
#include <iostream>

using namespace std;

bool IsTriangle(float, float, float);

int main() {
  float angleA;  // Three angles of a potential triangle
  float angleB;
  float angleC;
  cout << "Triangle testing program; "
       << "a negative first angle ends the processing." << endl;
  cout << "Enter 3 angles: ";
  cin >> angleA;
  while (angleA >= 0) {
    cin >> angleB >> angleC;
    if (IsTriangle(angleA, angleB, angleC))
      cout << "The 3 angles form a valid triangle." << endl;
    else
      cout << "The 3 angles do not form a triangle." << endl;
    cout << "Enter 3 angles: ";
    cin >> angleA;
  }
  return 0;
}

//**********************************************************

bool IsTriangle(float angle1, float angle2, float angle3) {
  return (fabs(angle1 + angle2 + angle3 - 180.0) < 0.00000001);
}
