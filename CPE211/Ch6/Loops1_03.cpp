// Chapter 6  - program 3
#include <iostream>
using namespace std;

// Event controlled loops
// 1) Sentinel loops - Loop is executed until a special value
//    is used (typically read) indicating the termination of the loop
// 2) End-of-File controlled loops - Loop is executed until the
//    End-of-File(EOF) is reached.
// 3) Flag-controlled loops - The loop is executed until a 
//    Boolean variable is changed (from true to false or false
//    to true) such that the loop is exited.  

int main() {
    char ch1;
    int var1, var2;
    bool moreData;

    // Sentinel-controlled loop example

    // A special data value (called the sentinel) is used to 
    // signal the program that there is no more data to process
    // A sentinel must be a value that is not expected as a
    // normal input to the program.
    // The problem usually dictates the sentinel that is used

    // Should use a Priming Read with these loops.
    cout << "\n\nSentinel controlled loop\n";
    cout << "The test is !(var1 > 0 && var2 < 0)\n";
    cout << "What values of var1 and var2 will cause\n";
    cout << "Termination of the loop?\n\n";


    cout << "\nEnter two integers: ";
    cin >> var1 >> var2;  // Priming Read 

    // with the priming read, we can test the first data set to see if we
    // are to enter the loop and perform those statements.  If the sentinels
    // make up the first data set, then the loop body is never executed.

    // the condition necessary to terminate this loop is var1>0 && var2 < 0 must evaluate
    // as true.  Then !true will give us the false.  Therefore, to terminate var1>0 and var2 <0
    // should be the values entered.
    while (!(var1 > 0 && var2 < 0)) {
        // print out testing information
        cout << "The test is !(var1 > 0 && var2 < 0)\n";
        cout << "What values of var1 and var2 will cause\n";
        cout << "Termination of the loop?\n\n";

        cout << "Enter two integers: ";
        cin >> var1 >> var2;  // Input the next set of points
    }

    cout << "\nThe loop has terminated.  the values entered\n";
    cout << "were the correct ones to use for termination.\n";

    return 0;
}
