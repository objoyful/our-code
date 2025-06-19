// Chapter 6  - program 7
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Loop subtask - summing loop
// Use a loop to sum a number of values
// Also include the use of an event counter

int main() {
    // This loop will use an iteration counter to keep
    // track of the number of times the loop is executed
    // and it will use an event counter to keep track of
    // specific events that occur in the loop.

    ifstream InFile;	// input file stream
    bool lessThanTen; 	// boolean flag for loop control
    string file;		// file to open for input

    int num_sum = 0; // holds the count of the positive entries 
    int sum = 0;  // sum of the positive entries

    int num_loop = 0;  // number of times the loop is executed
    int number;  // input value

    lessThanTen = true;	// initialize loop control flag


    cout << "If Input2_5.txt is used, an infinite loop will occur.\n";
    cout << "Press ctrl-c to exit out of the loop\n";
    cout << "Enter the name of the input file: (Input2_5.txt or Input2_10.txt): ";
    cin >> file;
    cout << "\nReading numbers from file: "<< file << "\n\n";

    InFile.open(file.c_str());

    // as long as the input stream is valid and the boolean
    // variable lessThanTen is true, perform the loop
    // This loop will require 10 positive numbers to terminate
    // provided the input stream does not go into the fail state
    // Once 10 positive numbers have been entered, the loop terminates

    InFile >> number;	// read a value from the input file

    // the test below is what is needed to make sure that the loop exits
    // when the input file stream goes into the fail state before 
    // lessThanTen goes false.

    while (lessThanTen) {
    //while (lessThanTen && InFile.good()) {
        num_loop ++;	// increment number of times the loop is executed
        cout << "Number read: " << number << endl;
        if (number > 0) {
            // sum all positive values and keep track of how many numbers are
            // positive.
            num_sum ++; 
            sum = sum + number;
            // once 10 positive numbers have been read, terminate the loop
            // by changing the flag variable to false
            lessThanTen = (num_sum < 10);
        }
        if (lessThanTen)
            InFile >> number;	// read a value from the input file
    }

    cout << boolalpha;  // print out true or false for boolean variables or values
    cout << "The loop executed " << num_loop << " times and\n";
    cout << "There were " << num_sum << " numbers greater than 0\n\n";
    cout << "Status of the flag lessThanTen and the file stream\n";
    cout << "lessThanTen: " << lessThanTen << "  InFile: " << bool(InFile) << endl;
//         cout << "   File stream value: " << InFile << endl;
         //cout << "   File stream value: " << cout << endl;

    return 0;
}
