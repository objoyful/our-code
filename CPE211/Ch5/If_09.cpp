// Program Ch_05_09.cpp
// Material comes from Chapter 10
// corresponds to Chapter 10 program 1: Ch_10_01.cpp

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// This program contains various additional C++ operations
int main() {
    int num;        // holds result of conditional test of num1, num2
    int num1, num2; // hold values tested with conditional operator
    string line;    // phrase indicating which number is greater

    // Use a loop to test two integers with the 
    // conditional operator. continue in the loop 
    // until the sentinels are entered to terminate the loop.

    cout << "\n\nIllustration of the conditional operator\n";

    do {
        cout << "\nEnter in 2 integers to test (-99 -99 to exit): ";
        cin >> num1 >> num2;
        cout << endl;

        // show that string assignments can be 
        // made with the conditional operator
        // just like number assignments can be made.
        line = (num1 >= num2)? "first number greater": "second number greater";

        // determine the larger of the two numbers
        num = (num1 >= num2)? num1: num2;

        cout << line << " and largest number is: " << num << endl;

        // determine the absolute value of the first number 
        // by using the conditional operator.
        num = (num1 >= 0)? num1: -num1;
        cout << "Absolute value of first number: " << num << endl;

    } while (num1 != -99 || num2 != -99);
    // it is tempting to use num1 != -99 && num2 != -99 for
    // the while expression.  however, that test results in 
    // loop termination when num1 or num2 is equal to -99
    // to terminate when both are -99, the || operator is required
    // Also, could rewrite the expression as:
    // !(num1 == -99 && num2 == -99)

    return 0;
}
