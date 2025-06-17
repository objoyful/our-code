// Chpater 06 program 1: Ch_06_01.cpp
#include <iostream>
using namespace std;

// Simple while loop example

int main() {
    // Typical use of the while loop is with a block body
    // If the expression in the while loop is false, the
    // body of the while loop is not executed.

    int a = 0;	// initialize loop control variable to zero
    char ch1;

    cout << "\n\n";
    cout << "testing on a < 3\n";
    cout << "Before the while loop: a = " << a << endl << endl;
    
    while (a < 3) {
        cout << "The square of a = " << a << " is " << a * a << endl;
        a++;  // NOTE this line is important!  Why?
    }
    cout << "\nAfter the while loop a = " << a << "\n\n";

    // **********************************************************************
    // put in a pause here
    cout << "press enter/return key to continue: ";
    cin.get(ch1);

    // What does the output look like if a typo occurs and we use
    // while (a > 3) instead of while (a < 3)?

    a = 0;	// initialize loop control variable to zero
    
    cout << endl;
    cout << "testing on a > 3\n";
    cout << "Before the while loop - modified a = " << a << " \n";
    
    while (a > 3) {
        cout << "The square of: " << a << " is " << a * a << endl;
        a++;  // NOTE this line is important!  Why?
    }
    cout << "After the while loop a = " << a << "\n";

    return 0;
}
