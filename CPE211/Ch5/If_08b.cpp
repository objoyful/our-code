// Ch_05_8.cpp
// Testing status of an input/output stream, and fail state mode

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main() {
    int num1, num2; // hold values entered in for testing
    string name;  // holds the string value used for testing
    ifstream InFile;    // input file stream variable 
    ofstream OutFile;   // output file stream variable

    // Open a file for input and one for output
    InFile.open("mydata.txt");  
    if (!InFile) { // if file not opened, terminate program
        cout << "open of mydata.txt failed\n"; 
        return 1; 
    } else
        cout << "mydata.txt opened successfully\n";
    
    OutFile.open("output.txt");
    
    if (OutFile)
        cout << "\noutput.txt was successfully opened\n"; 
    else {
        cout << "open of the output file failed\n";
        return 1;
    }

    cout << endl;

    cout << "Put file stream in fail state to show it does not\n";
    cout << "affect other input/output streams\n";
    cout << "\nUse cin to read an integer,  name, integer set: ";
    cin >> num1 >> name >> num2;

    if (cin)
        cout <<"cin is valid.  Entered: " << num1 << "  " << name << "  " << num2 << endl;
    else
        cout << "input stream - cin - is in the fail state due to bad data entry\n";

    cout << "===================================================\n\n";

    // if cin is in the fail state mode, it has no effect on other
    // streams.  This can be verified by puttting cin into the fail
    // state mode in the above entry, and then seeing that the following
    // streams are not effected - provided mydata.dat does exist.

    // Examples showing testing of input file and output file streams
    cout << "testing status of files opened\n\n";


    if (!InFile) { // if file not opened, terminate program
        cout << "open of mydata.txt failed\n"; 
        // the return statement below will cause the program to terminate if executed 
        // from within main.  if executed from within a function, you must
        // use exit(1); to terminate the program.  Use of return in a funciton
        // just returns control from the funciton back to the caller of the 
        // function.
        //return 1; 
    } else {
        // normally this else is not present.  Usually just more lines of code
        // would follow the above if statement
        // however, since I do not terminate if the input file is not
        // opened, I need the else for this example

        //This input line will show that while the cin input stream may
        // be in the fail state, it does not effect other input streams

        cout << "mydata.txt was successfully opened as an input file\n"; 
        InFile >> name;
        cout << "The name read from the input file is: " << name << endl;
    }

    // test the status of the output file
    // In most cases, the opening of an output file should not fail
    if (OutFile)
        cout << "\noutput.txt was successfully opened\n"; 
    else {
        cout << "open of the output file failed\n";
        return 1;
    }

    OutFile.close();
    InFile.close();

    return 0;
}
