//************************************************
// Program Stars reads in a number and displays that
// many asterisks.
//************************************************
#include <iostream>
using namespace std;

int main() {
  int starCount;
  int loopCount;
  cout << "Enter the number of stars;" << endl
       << "'Q' ends the program." << endl;
  cin >> starCount;  // 1
  while (cin)        // 2
  {
    loopCount = 1;                  // 3
    while (loopCount <= starCount)  // 4
    {
      cout << '*';  // 5
      loopCount++;  // 6
    }
    cout << endl;                          // 7
    cout << "Enter the number of stars; "  // 8
         << "'Q' ends the program." << endl;
    cin >> starCount;  // 9
  }
  cout << "Goodbye" << endl;  // 10
  return 0;
}
