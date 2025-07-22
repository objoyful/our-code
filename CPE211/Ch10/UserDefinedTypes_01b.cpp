//  Chpater 10 program 1: Ch_10_01b.cpp

#include <iostream>
#include <string>
using namespace std;

// example of the conditional operator.
int main() {
    int num1, num2; // hold values for testing with conditional operator
    int num;
    string line;

    /*
    // can we make a delcaration as part of the expressions 2 or 3?
        num1 = 5; num2 = 2;
   		num = (num1 >= num2) ? int num3 = 2: num2;
        cout << "conditional declaration: num = " << num << endl;
    //    */

    cout << "\n\nIllustration of the conditional operator\n\n";
    // conditional operator use inside a loop
    // loop through values until -99 and -99 are entered
    // user must enter a set of values, and with the do-while loop
    // all numbers entered will be processed.  If a priming read
    // were used, then termination would occur without processing -99 -99
    // only if they were not the first set of numbers
    do {
        cout << "enter in 2 integers to test (-99 -99 to exit): ";
        cin >> num1 >> num2;  // read in the two numbers

        // test the two numbers to determine which is larger
        // use the conditional operator to determine a phrase to output
        // alose use a conditional operator to assign the correct value

        //line = (num1 >= num2)? "first number greater":"second number greater";

        line = (num1 > num2)  ? "first number greater":
               (num1 == num2) ? "numbers are equal": "second number greater";

        num = (num1 >= num2) ? num1: num2;
        cout << line << " and largest number is: " << num << endl;

        num = (num1 >= 0)? num1:-num1;
        cout << "Absolute value of first number: " << num << endl << endl;
    } while (num1 != -99 || num2 != -99);
    // it is tempting to use num1 != -99 && num2 != -99 for
    // the while expression.  however, that test results in 
    // loop termination when num1 or num2 is equal to -99
    // to terminate when both are -99, the || operator is required
    // Also, could rewrite the expression as:
    // !(num1 == -99 && num2 == -99)

    return 0;
}
