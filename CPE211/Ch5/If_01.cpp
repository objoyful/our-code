// Ch_05_1.cpp program
// Program showing boolean values and data type
// declaration.  Also shows that integers can
// be used to contain boolean data.
#include <iostream>
using namespace std;

int main() {
    int i_assert_value; // integer variable to hold a boolean value
    bool b_verify;      // boolean variable to hold a boolean value
    int x,y;

    cout << endl << endl;  // put in 2 blank lines
    cout << "In this program, i_assert_value is an int,\n";
    cout << "and b_verify is a bool\n";
    cout << "--------------------------------------------------\n";
    x = y = 10;  // assign a value of 10 to x and y for testing

    // assigns result of is x == y to i_assert_value
    i_assert_value = x == y;

    // If x is equal to y, then b_verify should be true
    b_verify = x == y;  

    // output the information for verification
    // Look at the value contained in the integer and 
    // the value in the boolean variable
    cout << "x = " << x << " y = " << y << endl;
    cout << "Does x equal y?\n";
    cout << "a value of 1 => True, a value of 0 => False.\n";
    cout << "i_assert_value: " << i_assert_value << endl;
    cout << "b_verify: " << b_verify << endl;

    // the boolalpha manipulator causes all 
    // boolean values to be printed as
    // true or false instead of 1 or 0
    cout << "\n==== use manipulator boolalpha ====\n";
    cout << boolalpha;
    cout << "x = " << x << " y = " << y << endl;
    cout << "Does x equal y?\n";
    cout << "a value of 1 => True, a value of 0 => False.\n";
    cout << "i_assert_value: " << i_assert_value << endl;
    cout << "b_verify: " << b_verify << endl;

    return 0;
}

