// Chapter 6  - program 8
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// For Loop demonstration program for various conditions
// The conditions shown are all valid and show the versatility of
// programming for loops in C++.  

int main()
{
    int i = 30;		// for loop control variable
    int j = 500;	// for loop control variable
    int k = -10;	// for loop control variable
    float a;		// for loop control variable
    char ch1;		// flow control variable
    string str1;	// flow control variable

    cout << "\n\nFollowing shows multiple assignments and increments\n\n"; 

    // Show multiple assignments and increments and testing of the for loop
    cout << "\n\nShow three variables declared and incremented in a for loop\n";
    cout << "and a multi-variable test\n";
    cout << "Before loop: i = " << i << "   j = " << j ;
    cout << "   k = " << k << endl;

    for (int i = 0, j = 10, k = 30; (i <= 10 && j <= 15 && k <= 40); i ++, j ++, k ++)
        cout << "  In Loop:  i: "<< i << "  j: " << j << "   k: " << k << endl;

    cout << "After Loop, i is: " << i << "  j: " << j << "   k: " << k << endl;

    // put in a pause here
    cout << "\n\nFollowing shows different incrementation\n\n"; 
    cout << "press enter/return key to continue: ";
    getline(cin, str1, '\n');

    // show different way to increment in a for loop
    // the expresion i += 2 is the same as i = i + 2 
    // that same format can be used with -,* and / as well
    cout << "\n\nshow loop increments by 2\n";
    cout << "In this example, i is a declared variable for the program\n";
    cout << "and not a declared variable to be used just by the for loop\n";

    for (i = 0; i < 12; i += 2)
        cout << "  In Loop: i = " << i << endl;
    cout << "After Loop, i = " << i << endl;

    // put in a pause here
    cout << "\n\nUse of float variables in a for loop? Possible?\n\n";
    cout << "press enter/return key to continue: ";
    getline(cin, str1, '\n');

    // can we use floats in a for loop?
    cout << "\n\ntrying to use float variables in a for loop\n";
    cout << "initial value of a is 3.5 increment by 1.5\n";
    cout << fixed << showpoint;

    for (a = 3.5 ; a < 10.0 ; a += 1.5)
        cout << "  In Loop: a = " << a << endl;
    cout << "After Loop, a = " << a << endl;

    // put in a pause here
    cout << "\n\nUse of char variables in a for loop? Possible?\n\n";
    cout << "press enter/return key to continue: ";
    getline(cin, str1, '\n');

    // can we use chars in a for loop?
    cout << "\n\ntrying to use char variables in a for loop\n";
    cout << "initial value is the letter a, try to output to h\n";

    for (ch1 ='a'; ch1 <= 'h' ; ch1 ++)
        cout << "  In Loop: char is: " << ch1 << endl;
    return 0;
}
