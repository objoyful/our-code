// Structures - program 5: Structures_05.cpp

#include <iostream>
#include <iomanip>
using namespace std;

// Example showing the use of functions with structures
// and functions without structures for performing the same 
// tasks.

// In this example, input the 3 values for a time 
// (hours, minutes, seconds)
// In main, The program is broken up into two parts 
// the first part is using a structure, and 
// the second part does not use a structure.

// declare a Time structure to hold the hours, minutes and seconds
struct Time {
    int hours;    
    int minutes;
    int seconds;
};
// function prototypes - one using structures one does not

// read in time values into the structure parameter 
void GetTime1(Time &);	

// read time values into integer parameters
void GetTime2(int &, int &, int &);  

int main() {
    // first part of the program reads the time 
    // using a function with a structure parameter.  
    // All statements for this part of the program occur here.

    Time myTime;

    cout << "Read in a time using a structure\n";

    // function call with the structure to get the time
    GetTime1(myTime);	

    // ######################################################

    // Second part of the program - 
    // read a time with a function using integer parameters.

    // variables to hold the values
    int hours, minutes, seconds;  

    cout << "Read in a time using variables\n";

    GetTime2(hours, minutes, seconds);

    // ####################################################

    // output the two times
    
    cout << "Time contained in the structure: ";
    cout << myTime.hours << ":" << myTime.minutes 
         << ":" << myTime.seconds << endl;

    cout << "Time contained in the individual variables: ";
    cout << hours << ":" << minutes << ":" << seconds << endl;

    return 0;
}

void GetTime1(Time & time) {
    // read in the time of the day

    cout << "Enter the hours: ";
    cin >> time.hours;

    cout << "Enter the minutes: ";
    cin >> time.minutes;

    cout << "Enter the seconds: ";
    cin >> time.seconds;
}

void GetTime2(int & hours, int & minutes, int & seconds) {
    cout << "Enter the hours: ";
    cin >> hours;

    cout << "Enter the minutes: ";
    cin >> minutes;

    cout << "Enter the seconds: ";
    cin >> seconds;
}