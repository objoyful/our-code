// Chapter 6  - program 3
#include <iostream>
using namespace std;

// This is an example of poor programming(intentionally done)
// some code to improve this code is shown in comments

int main() {
    int var1, var2;
    bool moreData;


    cout << "\nA common source of error example that\n";
    cout << "Creates an infinite loop\n\n";

    cout << "\nThe loop should terminate when the first number\n";
    cout << "is greater than the second number\n\n";

    moreData = true;	// initialize the flag variable

    cout << "\nPriming Read: Enter 2 integers: "; 
    cin >> var1 >> var2;  // Priming read
    cout << endl;

    if (var1 > var2) moreData = false;
    // should use moreData = !(var1 > var2);
    // or moreData = var1 <= var2;
    // or just use the relational expression as the while expression
    // while(var1 <= var2)

    // This type of loop could be either a flag controlled
    // or sentinel controlled loop
    // NOTE: There is an error somewhere.  What is it

    cout << boolalpha;

    // Error here is a single = instead of == in the comparison
    // this error creates an infinite loop

    while (moreData = true) {// should use while (moreData)
        cout << "====================  START LOOP  =====================\n";
        cout << "moreData = " << moreData  << endl;

        // processing statements asociated with var1 and var2
        cout << "\n==> Due to logic mistake in the while expression, this is an\n";
        cout << "==> infinite loop.  Enter ctrl-c to terminate the loop\n\n";

        // Obtain the next set of numbers
        cout << "In loop: enter 2 integers: "; 
        cin >>var1 >> var2;

        if (var1 > var2) moreData = false;
        // should use moreData = !(var1 > var2)
        // or moreData = var1 <= var2;
        cout << "moreData = " << moreData << endl;
        cout << "=====================  END LOOP  ======================\n\n";
    }
    return 0;
}
