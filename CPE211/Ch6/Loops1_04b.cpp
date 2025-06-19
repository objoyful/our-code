// Chapter 6  - program 4: 
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

// Event controlled loops
// 1) Sentinel loops - Loop is executed until a special value
//    is used (typically read) indicating the termination of the loop
// 2) End-of-File controlled loops - Loop is executed until the
//    End-of-File(EOF) is reached.
// 3) Flag-controlled loops - The loop is executed until a 
//    Boolean variable is changed (from true to false or false
//    to true) such that the loop is exited.  

int main() {
    char ch1;    // used for flow control
    int value;  // number read from the file
    int line_num;    // number of lines read from the file
    ifstream InData;// input stream variable

    // End-of-File controlled loop
    // After the last piece of data has been read from a file,
    // the input stream associated with that file is at the 
    // end-of-file (EOF)

    // If any more attempts to read from the stream are made,
    // the input stream goes into the fail state mode.

    // Can use the fact that the stream has entered the fail state
    // as a sentinel when reading from a file of unknown length.
    // Input file can be anywhere from 0 lines to an infinite number 

    // Should use a Priming Read with these loops. <== **********

    cout << "\n\nEnd-of-file examples of loop control\n";
    cout << "\n\nThis program tries reading from the " <<
            "empty file: data_file2.txt\n";
    cout << "press enter/return key to continue: ";
    cin.get(ch1);
    cout << endl;

    // Open another file.  This file has no lines in it.
    // The loop should not be executed.  InData will go
    // into the fail state because of the first read

    line_num = 0;

    InData.open("data_file2.txt");

    cout << left << boolalpha; // print true or false 

    cout << "Before priming read before while loop," << endl;
    cout << "File stream status: " << bool(InData) << "\n";
    cout <<   "good: " << InData.good() 
         <<  "  bad: " << InData.bad() 
         << "  fail: " << InData.fail() 
         <<  "  eof: " << InData.eof() << endl;
    //while (InData >> value, if(InData.eof()) cout << "eof in while\n", cout << "help\n");

    InData >> value;  // Priming read to read the first value
    if (InData.eof()) {
        cout << "\nEmpty file detected after priming read.\n";
        cout << "Loop will be skipped\n";
    }

    while (InData) { // As long as the input stream is valid
        //while (InData >> value) {  // As long as the input stream is valid
        line_num++;
        cout << "Line " << line_num << ": " << setw(5) 
             << left <<  value << setw(25) << right 
             << "File stream status: " << bool(InData) << endl;

        // Read the next value
        InData >> value;
    }
    cout << "\nAfter loop," << endl;
    cout << "File stream status: " << bool(InData) << "\n";
    cout <<   "good: " << InData.good() 
         <<  "  bad: " << InData.bad() 
         << "  fail: " << InData.fail() 
         <<  "  eof: " << InData.eof() << endl;

    InData.close(); // close the file used for the input stream

    return 0;
}
