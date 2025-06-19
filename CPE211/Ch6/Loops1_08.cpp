// Chapter 6  - program 8
#include <iostream>
#include <iomanip>
using namespace std;

// For Loop demonstration program for various conditions

int main() {
    int i = 30;		// for loop control variable
    int j = 500;	// for loop control variable
    int k = -10;	// for loop control variable
    float a;		// for loop control variable
    char ch1;		// flow control variable

    // output a couple of blank lines to separate output from the command
    cout << endl << endl;

    cout << left;
    cout << "int size: " << sizeof(int) << endl;

    // this for loop has expression 1 and 2 swapped.  This will compile,
    // but the value of x is tested as a boolean value, so expression 1 is
    // true until the time when x = 0.  Then the loop exits
    // I put in a loop to slow down the speed at which the infinite loop 
    // runs.  the second for loop inside the first is just to slow the s
    // speed of writing to the terminal down

    cout << "\nBelow is a pseudo-infinite loop that starts with\n";
    cout << "x=1 and goes to 32767 then to -32768 and then towards 0.\n";
    cout << "Once 0 is reached for the value of x, the loop terminates\n\n";
    for (short x = 1; x ++; x < 10) {
        cout << "\rInfinite Loop? " << setw(8) << x;
        
        // extra loop to slow down writing of the above line.
        // the body of this loop is the null statement (the ; at the
        // end of the for statement)
        for (int yy = 0; yy < 50000; yy ++);

    }

    // show that i above and i declared in the for loop below are
    // separate variables
    cout << "\n\nShow that the scope of a variable declared in a for loop is\n";
    cout << "confined to that loop only.\n";
    cout << "Before loop, i = " << i << endl;

    // there are two instances of the variable i.  one for the for loop, and
    // one for the program outside fo the for loop.

    for (int i = 5; i > 0 ; i--)
    {
        cout << endl;
        cout << "  In Loop:  Value of i is: " << i << endl;
        cout << "  In Loop:  Value of j is: " << j << endl;
        cout << "  In Loop:  Value of k is: " << k << endl;
    }

    cout << "After Loop, i is: " << i <<  endl;


    // put in a pause here
    cout << "\n\nFollowing shows when the loop counter is\n";
    cout << "tested in a for loop\n\n";
    cout << "press enter/return key to continue: ";
    cin.get(ch1);


    // indication of when testing is done on the for loop
    // i here is 30 before the loop
    cout << "\n\nIf the test expression fails upon entry to the loop,\n";
    cout << "is the loop executed?\n";
    cout << "Before the loop:  i = " << i << " and i < 20 is the test\n";

    for (; i < 20; i ++)
        cout << "  In Loop: i is " << i << endl;
    cout << "after Loop, i is " << i << endl;

    return 0;
}
