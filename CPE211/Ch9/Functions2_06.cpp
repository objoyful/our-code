// Functions 2 program 6 : Functions2_06.cpp

#include <iostream>
#include <fstream>
#include <cstdlib> // for using the exit function
using namespace std;

// This is an example of stubs and a driver.  This technique
// is used when writing a program with several functions

// function prototypes

bool GetInputStream (ifstream &);  // file contains input data
bool GetInputStream2 (ifstream &);  // file contains input data

int main() {
    // Main contains two drivers that may be used to
    // test the two functions once they have been written
    // The tests are done after each function is written.
    // There are actually two driver programs shown here
    // Normally it is just a single driver to test a 
    // single function.  

    // ONCE A FUNCTION IS WRITTEN, AND THE DRIVER INDICATES
    // THAT IT IS WORKING CORRECTLY, THE DRIVER CODE CAN BE 
    // REPLACED WITH THE ACTUAL CODE THAT WILL BE USED

    ifstream inData;  // file that contains values to read`

    // DRIVER #1
    // Test the ability to obtain the input stream

    cout << "\n===========================================\n";
    cout << "Stub and Driver Test #1\n\n";
    if (!GetInputStream(inData)) {
        cout << "Failed to successfully open the input stream\n";
        cout << "Terminating program\n";
        return 1; // or use exit(1);
    } else {
        cout << "Input stream successfully opened\n";
    }
    cout << endl;

    // reset input stream variable so that it can be reused

    inData.close();
    inData.clear();

    // DRIVER #2
    // Another way to perform the test using a while loop

    cout << "\n===========================================\n";
    cout << "Stub and Driver Test #2 - use a while loop\n\n";

    while (!GetInputStream2(inData)) {
        cout << "Failed to successfully open the input stream\n";
        cout << "Please try again!!\n";
        inData.clear(); // file stream in fail state, so reset it.
    }
    cout << "Input stream successfully opened\n";

    // close the file stream so it can be used again
    inData.close(); 

    return 0;
}

// The following function definition is a Stub example
bool GetInputStream (ifstream & inStream) {
    int value;  // holds value entered
    string name; // file name to open
    // This function will obtain the input stream to use
    // for data values.  It returns true if the
    // stream is successfully opened.

    cout << "In the function GetInputStream - no code yet\n\n";
    cout << "Enter in a value of 0 to return false\n"
         << "and a value of 1 to return true: ";
    cin >> value;
    return bool(value);
}

bool GetInputStream2 (ifstream & inStream) {
    string name; // file name to open
    // This function will obtain the input stream to use
    // for data values.  It returns true if the
    // stream is successfully opened.

    cout << "Enter file name: ";
    cin >> name;
    inStream.open(name.c_str());
    return inStream.good(); // or return bool(inStream);
}
