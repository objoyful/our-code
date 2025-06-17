// ch_05_7.cpp
// example for if-then-else-if compared to several if statements
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    int grade;  // value entered in for testing 

    cout << endl;
    cout << "Enter a grade (0 to exit): ";
    cin >> grade;

    // process the grade value entered for its 
    // corresponding letter equivalent

    // create a loop until a 0 or negative number is entered
    while (grade > 0) {
        cout << endl;

        cout << "use if statements to print out the letter\n";
        cout << "equivalent for the grade entered.\n"
             << "Only want one letter grade\n";
        cout << endl;

        // in this example, want only one cout statement printed 
        // depending on what the value of grade is.  
        // This first part is just one if statement 
        // after another which results in each one being executed.
        // Sample input to use for testing, 95, 85, 75, 65

        if (grade > 90)
            cout << "Grade is A\n";
        if (grade > 80)
            cout << "Grade is B\n";
        if (grade > 70)
            cout << "Grade is C\n";
        else
            cout << "Grade is too low, repeat course\n";
        
        cout << "=========================================\n\n";

        if (grade > 90 )
            cout << "Grade is A\n";
        if (grade > 80 && grade <= 90)
            cout << "Grade is B\n";
        if (grade > 70 && grade <= 80)
            cout << "Grade is C\n";
        if (grade <= 70)
            cout << "Grade is too low, repeat course\n";
        cout << "=========================================\n\n";

        // *************************************************
        // Now correct the above example by using 
        // the if-then-else-if format
        cout << endl;
        cout << "corrected version of previous example\n\n";

        if (grade > 90)
            cout << "Grade is A\n";
        else if (grade > 80)
            cout << "Grade is B\n";
        else if (grade > 70)
            cout << "Grade is C\n";
        else
            cout << "Grade is too low, repeat course\n";
        cout << "==========================================\n\n";
        
        if (grade > 90)
            cout << "Grade is A\n";
        else 
            if (grade > 80)
                cout << "Grade is B\n";
            else 
                if (grade > 70)
                    cout << "Grade is C\n";
                else
                    cout << "Grade is too low, repeat course\n";

        cout << endl;
        cout << "Enter a grade (0 to exit): ";
        cin >> grade;
    } // end of while loop
    return 0;
}
