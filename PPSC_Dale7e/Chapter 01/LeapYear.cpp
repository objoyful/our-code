//********************************************************
// LeapYear program
// This program inputs a year and outputs whether the year
// is a leap year
//********************************************************

#include <iostream> // For input/soutput stream.

using namespace std;
bool isLeapYear(int year); // Sets up subalgorithm.

int main() {
    int year; // Holds year value.

    cout << "Enter a year AD, for example 2027." // Prompt
         << endl;
    cin >> year; // Read into year.

    if(isLeapYear((year))) // Leap year test
        cout << year << " is a leap year." << endl;
    else
        cout << year << " is not a leap year." << endl;

    return 0; // Return with success.
}

bool isLeapYear(int year) {
    // Return true if year is a leap year, false otherwise.
    
    if (year % 4 != 0) // Is year divisible by 4?
        return false;    // If not, not a leap year.

    // Must be divisible by 4.
    if (year % 100 != 0) // Is year divisible by 100?
        return true; // If not, it is a leap year.
    
    // Must be divisible by 100.
    if (year % 400 != 0) // Is year divisible by 400?
        return false; // If not, not a leap year.
    
    return true; // Must be divisible by 400, so it is a leap year.

}