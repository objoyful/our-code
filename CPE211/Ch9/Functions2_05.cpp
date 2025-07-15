// Functions2_05.cpp

#include <iostream>
#include <string>
using namespace std;

// Boolean function example
bool GoodMonth (string month); // test a month for validity
bool IsMonthBad (string month); // same as GoodMonth with reversed logic

int main() {
    string month = "";
    cout << "\nEnter a month(exit to terminate): ";
    cin >> month;
    
    while (month != "exit") {
        if (!GoodMonth(month)) { // positive logic.  !goodmonth means month is bad
            cout << "Function GoodMonth: " << month 
                 << " is a bad month." << endl;
            // normally would use return 1 or exit(1) here to terminate
            // the program.  However, that is not desirable for the example
            // return 1; // or exit(1);
        } else {
            cout << "Function GoodMonth: " << month 
                 << " is a good month" << endl;
        }

        // perform same test with same output for the month using reversed logic
        if (IsMonthBad(month)) { // isMonthBad means the month is bad 
            cout << "Function IsMonthBad: " << month 
                << " is a bad month." << endl;
            // return 1; // or exit(1);
        } else {
            cout << "Function IsMonthBad: " << month 
                 << " is a good month" << endl;
        }
        
        cout << "\nEnter a month(exit to terminate): ";
        cin >> month;
    }
    return 0;
}

bool GoodMonth (string month) {
    if (month == "January" || month == " February" ||  month == "March")
        return true; // the month is good 
    else 
        return false; // the month is not good 
}

bool IsMonthBad (string month) {
    if (month == "January" || month == " February" ||  month == "March")
        return false; // the month is not bad - it is a good month 
    else 
        return true; // the month is bad 
}