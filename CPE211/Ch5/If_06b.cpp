// ch_05_7.cpp
// example for if-then-else-if, dangling else
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    int grade;
    string name;

    // *************************  DANGLING ELSE ***********************
    cout << endl;
    cout << "dangling else example\n\n";

    // Each else is associated with the nearest if statement not already
    // associated with an else statement.  In this example, the else is 
    // intended to be associated with the first if statement (can tell
    // that by the indentation).  However, it is associated with the
    // second if statement, and this association results in a logic error.
    // input suggestions: Key 90, Key 100, name 100

    cout << "Enter a name: ";
    cin >> name;
    cout << "enter a grade: ";
    cin >> grade;

    cout << "\nExample with a Dangling Else\n\n";
    if (name == "Key")
        if (grade == 100)
            cout << "The key grade was entered\n";
        //else 
            //cout << "The key grade was not entered\n";
    else 
        cout << "The name entered was not Key\n";
    
    cout << "===================================================\n\n";

    // the dangling else problem can be solved by using braces to form a block statement
    // to ensure that the else is associated with the first if
    // statement which is the intent indicated by the indentation used

    // corrected version

    cout << "\nExample with the Dangling Else corrected\n\n";
    if (name == "Key") {
        if (grade == 100)
            cout << "The key grade was entered\n";
        else 
            cout << "The key grade was not entered\n";
    }
    
    else 
        cout << "The name entered was not Key\n";

    return 0;
}
