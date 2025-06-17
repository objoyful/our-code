// Chpater 06 program 2: Ch_06_02.cpp
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// Sample count controlled loop

int main() {
    // Count controlled loops use a loop control variable that
    // must be initialized before it is tested.  This variable
    // must be incremented in the body of the loop.  If the 
    // counting variable is not incremented, an infinite loop 
    // is created.
    //
    // This version of Loops1_02 will write output to an output
    // file.  This file becomes very large.  Do not run this
    // program unless you know what is needed to delete the
    // large file and stop the program
    ofstream out;
    out.open("oops.txt");
    if (!out)
        cout << "did not open output file\n";

    short count = 1;  // loop control variable
    char ch1;  // flow control variable
    short num;  // infinite loop counter variable to show number of iterations

    cout << "\n\nBefore the while loopV \n";
    cout << "count starting at 1 testing on count <= 5 \n\n";
    while (count <= 5) {
        cout << "The loop control variable is: " << count << endl;
        // Other statements 
        count++; // same as count = count + 1;
    }
    cout << "After the while loop count = " << count << "\n\n";


    // same loop without the increment operation performed
    // example of an infinite loop
    // ***************************************************
    // put in a pause here
    cout << "\n\nFollowing is an example of what happens when the\n";
    cout << "Increment operation is left out.  to terminate, press ctrl-c\n\n";
    cout << "This version of the program writes to an output file, and\n";
    cout << "the output file becomes very large very quickly.\n";
    cout << "nothing is written to the terminal and ctrl-c must be \n";
    cout << "pressed to stop the program from running.\n";
    cout << "press enter/return key to continue: ";
    cin.get (ch1);
    cout << "The following is running in an infinite loop\n\n";

    count = 1; // loop control variable that is not incremented
    num = 0;  // number of times loop has executed
    cout << left;
    while (count <= 5) {
        // output information to a file that gets large quick
        out << "Infinite loop: The loop control variable is: " 
            << count << " number of executions: " << setw(7) << num ;
        // Other statements 
        // comment out this line:: count++; // same as count = count + 1;
        num++;  //increment the execution variable
    }

    out.close();

    return 0;
}
