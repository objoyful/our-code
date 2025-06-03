//
// *****   Program Ch03_2c.cpp   ***********
// Example of arithmetic operations, increment and decrement
// operators
#include <iostream>
#include <iomanip>
#include <cmath>
#include <climits>

using namespace std;

int main()
{
	int num1 = 10; // variable used for increment and decrement operations

	// Perform prefix and postfix increment and decrement operations
	// on the num1 variable.  These operations are performed in an output
	// statement to illustrate the difference between the two methods

	// increment and decrement operators - POSTFIX
	cout << "POSTFIX incremennt and decrement operations\n";
	cout << "*******************************************\n";
	cout << "Perform Postfix increment:\n";
	cout << "\tnum1 before postfix ++ operation: " << num1 << endl;
	cout << "\tnum1 during postfix ++ operation: " << num1++ <<endl;
	cout << "\tnum1 after postfix ++ operation: " << num1 << endl;
	cout << "*******************************************\n";

	cout << "Perform Postfix decrement:\n";
	cout << "\tnum1 before postfix -- operation: " << num1 << endl;
	cout << "\tnum1 during postfix -- operation: " << num1-- <<endl;
	cout << "\tnum1 after postfix -- operation: " << num1 << endl;
	cout << "*******************************************\n";

    cout << "Press Enter to continue.";
    string line;
    getline(cin,line,'\n');

	// increment and decrement operators - PREFIX 
	cout << "PREFIX increment and decrement operations\n";
	cout << "*******************************************\n";
	cout << "Perform Prefix increment:\n";
	cout << "\tnum1 before prefix ++ operation: " << num1 << endl;
	cout << "\tnum1 during prefix ++ operation: " << ++num1 <<endl;
	cout << "\tnum1 after prefix ++ operation: " << num1 << endl;
	cout << "*******************************************\n";

	cout << "Perform Prefix decrement:\n";
	cout << "\tnum1 before prefix -- operation: " << num1 << endl;
	cout << "\tnum1 during prefix -- operation: " << --num1 <<endl;
	cout << "\tnum1 after prefix -- operation: " << num1 << endl;
	cout << "*******************************************\n";

	return 0;
}
