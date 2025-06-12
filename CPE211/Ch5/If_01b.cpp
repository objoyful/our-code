// Ch_05_1.cpp program
// Program showing boolean values and data type
// declaration.  Also shows that integers can
// be used to contain boolean data.
#include <iostream>
using namespace std;

int main() {
    int i_assert_value;
    bool b_verify;
    int x, y;
    //int true;  // can we declare a variable named true or false?

    cout << endl << endl;  // put in 2 blank lines
    cout << "In this program, i_assert_value is an int,\n";
    cout << "and b_verify is a bool\n";
    cout << "--------------------------------------------------\n";

    cout << boolalpha;  // setup output stream to print true/false

    x = y = 10;  // assign a value of 10 to x and y for testing

    x = 9;  // change x value to 9

    // now test for equality when x =9 and y = 10
    i_assert_value = x == y; 
    b_verify = x == y;

    // output the information for verification
    cout << "x = " << x << " y = " << y << endl;
    cout << "Does x equal y?\n";
    cout << "a value of 1 => True, a value of 0 => False.\n";
    cout << "i_assert_value: " << i_assert_value << endl;
    cout << "b_verify: " << b_verify << endl;

    // showing that bools are integers and that 
    // implicit coercion takes place
    // assign a value of 10 to both i_assert_value 
    // and b_verify, then output them
    i_assert_value = 10;
    b_verify = -10;  // negative 10 shows that any non-zero value is true
    cout << "---------------------------------\n";
    cout << "assign 10 to an int and -10 to a bool and output result.\n";
    cout << "i_assert_value: " << i_assert_value << endl;
    cout << "b_verify: " << b_verify << endl;

    // remove boolalpha output
    cout << noboolalpha;
    cout << "b_verify: " << b_verify << endl;
    return 0;
}

