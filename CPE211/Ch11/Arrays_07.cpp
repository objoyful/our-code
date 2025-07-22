// Arrays program 07: Arrays_07.cpp

#include <iostream>
#include <string>
using namespace std;

// Example showing an array of structures
// expand on the previous example by 
// addding in an array in the structure

const int MAX_RECORDS = 5;  // maximum size of the array

// declare a structure with the name MachineRec
// This structure contains a string and an integer.
// It also contains an array of floats with 3 elements

struct MachineRec {
    string mach_name; // holds the name of the machine
    int id;  // id number of the machine
    float speeds[3];  // three operating speeds of the machine
};

int main() {
    int k, j; // loop control variables

    // declare a variable MachLog to be an array whose elements
    // are structures of the type MachineRec
    // Therefore, MachLog is a variable that is a one-d array with MAX_RECORDS elements
    // and each element of the array is a structure variable of data type MachineRec

    MachineRec MachLog[MAX_RECORDS];

    // initalize the variable MachLog
    // since it is an array, use a loop

    for (k = 0; k < MAX_RECORDS; k++) {
        // initialize each name to "No Machine"
        MachLog[k].mach_name = "No Machine";
        // initialize the id to an invalid number
        MachLog[k].id = -1;
        // initialize the speeds array to an invalid safe number
        for (j = 0; j < 3; j++)
            MachLog[k].speeds[j] = 0.0;
    }

    // enter some information for a couple of entries.
    // note since indexes start at 0, an index of 4 
    // corresponds to the 5th array element

    cout << "out of bounds: " << MachLog[5].speeds[3] << endl;

    cout << "Enter in the name of the 5th machine: ";
    cin >> MachLog[4].mach_name;
    cout << "Enter the id of the 4th machine: ";
    cin >> MachLog[3].id;


    // use a loop to read in three speeds for a machine

    cout << "Enter in the three speeds for the 3rd machine: ";
    for (j = 0; j < 3; j++)
        cin >> MachLog[2].speeds[j];

    MachLog[1] = MachLog[2];

    // Now print out the information for all machines in the array.

    for (k = 0; k < MAX_RECORDS; k++) {
        cout << "\nIndex " << k << ":  Machine: " << k + 1 << endl;
        cout << "\tname: " <<  MachLog[k].mach_name << endl;
        cout << "\tId: " << MachLog[k].id << endl;
        cout << "\tAvailable speeds: ";
        // must use a loop to print out all values of the speeds array
        for (j = 0; j < 3; j++) {
            cout << MachLog[k].speeds[j];
            if (j < 2)
                cout << ", ";
        }

        cout << endl;
    }
    return 0;
}