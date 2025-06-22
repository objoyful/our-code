//******************************************************************
// TestTowers program
// This program, a test driver for the DoTowers function, reads in
// a value from standard input and passes this value to DoTowers
//******************************************************************
#include <iomanip>  // For setw()
#include <iostream>
using namespace std;
void DoTowers(int circleCount, int beginPeg, int auxPeg, int endPeg);
// This function moves circleCount circles from beginPeg to
// endPeg, using auxPeg as a temporary holding peg
int main() {
  int circleCount;  // Number of circles on starting peg

  cout << "Input number of circles: ";
  cin >> circleCount;
  cout << "OUTPUT WITH " << circleCount << " CIRCLES" << endl << endl;
  cout << "CALLED FROM  #CIRCLES" << setw(8) << "BEGIN" << setw(8) << "AUXIL."
       << setw(5) << "END"
       << "    INSTRUCTIONS" << endl
       << endl;
  cout << "Original   :";
  DoTowers(circleCount, 1, 2, 3);
  return 0;
}

//******************************************************************
void DoTowers(int circleCount, int beginPeg, int auxPeg, int endPeg)
// This recursive function moves circleCount circles from beginPeg
// to endPeg.  All but one of the circles are moved from beginPeg
// to auxPeg, then the last circle is moved from beginPeg to endPeg,
// and then the circles are moved from auxPeg to endPeg.
// The subgoals of moving circles to and from auxPeg are what
// involve recursion
// Pre:  circleCount >= 0
{
  cout << setw(6) << circleCount << setw(9) << beginPeg << setw(7) << auxPeg
       << setw(7) << endPeg << endl;
  if (circleCount > 0) {
    cout << "From  first:";
    DoTowers(circleCount - 1, beginPeg, endPeg, auxPeg);
    cout << setw(58) << "Move circle " << circleCount << " from " << beginPeg
         << " to " << endPeg << endl;
    cout << "From second:";
    DoTowers(circleCount - 1, auxPeg, beginPeg, endPeg);
  }
}
