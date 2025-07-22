// Arrays Program 6: Arrays_06.cpp    

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_RECORDS = 10; // maximum array size

// declare a structure with the name MachineRec
// structure holds information on a machine

struct MachineRec {
    string mach_name;  // holds a name for the machine
    int id;			// id number of the machine
};

int main() {
    int k;  // loop index value

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
    }


    // enter some information for a couple of entries.
    // note since indexes start at 0, an index of 4 
    // corresponds to the 5th array element

    cout << "Enter in the name of the 5th machine: ";
    cin >> MachLog[4].mach_name;
    cout << "Enter the id of the 10th machine: ";
    cin >> MachLog[9].id;

    MachLog[1] = MachLog[9];

    // Now print out the information

    for (k = 0; k < MAX_RECORDS; k++) {
        cout << "Index " << k << ":\tname: " 
             <<  setw(15) << left << MachLog[k].mach_name;
        cout << " Id: " << MachLog[k].id << endl;
    }

    return 0;
}