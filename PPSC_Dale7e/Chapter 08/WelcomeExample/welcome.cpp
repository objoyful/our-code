//******************************************************************
// Welcome program
// This program outputs a "Welcome Home" message
//******************************************************************
#include <iostream>
using namespace std;

void Print2Lines();  // Function prototypes
// This function prints two lines of asterisks

void Print4Lines();
// This function prints four lines of asterisks

int main() {
  Print2Lines();  // Function call
  cout << " Welcome Home!" << endl;
  Print4Lines();  // Function call
  return 0;
}

//******************************************************************

void Print2Lines()  // Function heading
{
  cout << "***************" << endl;
  cout << "***************" << endl;
}

//******************************************************************

void Print4Lines()  // Function heading
{
  cout << "***************" << endl;
  cout << "***************" << endl;
  cout << "***************" << endl;
  cout << "***************" << endl;
}
