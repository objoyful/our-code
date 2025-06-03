//
// Chpater 03 program 4b: Ch_03_04b.cpp
#include <iostream>
#include <iomanip>
using namespace std;
main()
{

    // illustration of left and right maintaining the settings from cout to cout
    //
    cout << "Set up left justification for output\n" << left;
    cout << setw(10) << "Hello" << setw(10) << "There" << setw(10) << "World" << "End" << endl;
    cout << "no setw for this phrase.." << setw(30) << "Setw(30) for this phrase" << "End" << endl;

    cout << "Set up right justification for output\n" << right;
    cout << setw(10) << "Hello" << setw(10) << "There" << setw(10) << "World" << "End" << endl;

    // look at a tab character in string output in setw
    cout << "\nEffect of Tab character in a string output when using setw\n";
    cout << setw(10) << left << "He\tllo\t" << "End" << endl << endl;

    // Look at effects of using \n with setw
    cout << "Effect of using \\n for line termination with setw\n";
    cout << "12345678901234567890\n";
    cout << right;
    cout << setw(10) << "Hello" << endl;
    cout << setw(10) << "Hello\n" ;
    cout << setw(10) << "Hello" << endl;


    return 0;
}
