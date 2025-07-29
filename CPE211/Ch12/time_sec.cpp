//********* time.cpp Standard CPE212 Implementation Header Here ********
//
// Note:  On an actual project, you write and submit an implementation file such as this one
//
#include <iostream>
#include <iomanip>

#include "time_sec.h"     // Preprocessor directive which inserts the contents of the
                        // specified file at this location prior to compile

using namespace std;

Time::Time() {  // Default constructor - Sets hrs == 0  &&  mins == 0  &&  secs == 0
    hrs = 0;
    mins = 0;
    secs = 0;

    objNum = ++objectNumber;
    cout << "Default constructor for object #" << objNum << endl;
} // End Default Constructor


Time::Time(int initHrs, int initMins, int initSecs) { // Parameterized Constructor
    // Makes hrs == initHrs  &&  mins == initMins  &&  secs == initSecs
    // Assumes values are in allowable range

    hrs = initHrs;
    mins = initMins;
    secs = initSecs;

    objNum = ++objectNumber;
    cout << "3 Parameterized constructor for object #" << objNum << endl;

} // End Parameterized Constructor

Time::Time(int initHrs, int initMins) { // another parameterized constructor
    hrs = initHrs;
    mins = initMins;
    secs = 0;

    objNum = ++objectNumber;
    cout << "2 Parameterized constructor for object #" << objNum << endl;
}

Time::Time(int initHrs) {
    hrs = initHrs;
    mins = 0;
    secs = 0;
    
    objNum = ++objectNumber;
    cout << "1 Parameterized constructor for object #" << objNum << endl;
}

void Time::Set(int hours, int minutes, int seconds) {  // Set
// Sets hrs == hours  &&  mins == minutes  &&  secs == seconds assuming values in range
    hrs = hours;
    mins = minutes;
    secs = seconds;
} // End Time::Set(...)


void Time::Increment() {  // Increment
// Advances time by one second, with 23:59:59 wrapping around to 0:0:0
    secs++;
    if (secs > 59) {
        secs = 0;
        mins++;
        if (mins > 59) {
            mins = 0;
            hrs++;
            if (hrs > 23)
                hrs = 0;
        }
    }    
} // End Time::Increment()

void Time::Increment(int numSecs) {
    secs += numSecs;

    if (secs > 59) {
        mins += secs / 60;
        secs = secs % 60;
    }

    if (mins > 59) {
        hrs += mins / 60;
        mins = mins % 60;
    }

    if (hrs > 23) {
        hrs = hrs % 24;
    }
}   // Increment by number of seconds provided

void Time::Increment(int numSecs, int numMins) {
    numSecs = numSecs + numMins * 60;  // convert minutes to seconds
    Increment(numSecs);
}   // Increment by number of seconds and minutes provided

void Time::Increment(int numSecs, int numMins, int numHrs) {
    numSecs = numSecs + numMins * 60 + numHrs * 3600;
    Increment(numSecs);
}   // Increment by number of seconds, minutes and hours provided

void Time::Increment(float numHrs) {
    int numSecs = numHrs * 3600;
    Increment(numSecs);
}

void Time::Write() const {  // Write()
//     Time has been output in the form HH:MM:SS
    cout << setw(15) << left <<  "original: ";
    
    if (hrs < 10)
        cout << '0';
    
    cout << hrs << ':';
    
    if (mins < 10)
        cout << '0';
    
    cout << mins << ':';
    
    if (secs < 10)
        cout << '0';
    
    cout << secs;
    cout << endl;

    cout << setw(15) << "Alternative: ";
    
    cout << setfill('0') << right;
    cout << setw(2) << hrs << ":" <<setw(2) <<  mins << ":" 
         << setw(2) << secs << endl;
    cout << setfill(' ') << endl;
} // End Time::Write()

bool Time::Equal(Time otherTime) const {  // Equal
//     Function value == true, if this time equals otherTime; value == false otherwise
//                    == false, otherwise
    return (hrs == otherTime.hrs && mins == otherTime.mins && secs == otherTime.secs);
} // End Time::Equal(...)


bool Time::LessThan(Time otherTime) const {  // LessThan
// Assume this time and otherTime represent times in the same day
//     Function value == true, if this time is earlier in the day than otherTime; value == false otherwise
    return (hrs < otherTime.hrs ||
            hrs == otherTime.hrs && mins < otherTime.mins ||
            hrs == otherTime.hrs && mins == otherTime.mins
                                 && secs < otherTime.secs);
} // End LessThan(...)

Time::~Time() {
    cout << "Destroying class object #" << objNum << endl;
}