// Chpater 06 program 6: Ch_06_06.cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Loop subtask - Counting loop
// Count the number of lines in a file

int main() {
    // Loop keeps track of how many times it has
    // been executed
    // Use an Iteration Counter - a variable that is incremented
    // with each iteration of the loop

    // Note: The sub task counting does not mean the loop has to
    // be a count-controlled loop.

    // This program is an example of an EOF loop which counts the
    // number of lines in a file

    ifstream InFile;	// input file stream variable
    int num_lines;		// number of lines in the file	
    string line;		// holds the line read from the file
    char ch1;			// flow control variable

    cout << "\n\nFollowing is the result when a file has no lines\n\n";
    cout << "press enter/return key to continue: ";
    cin.get(ch1);

    InFile.open("Input0.txt");// <======

    num_lines = 0;  // initialize the line count variable to zero

    getline(InFile, line, '\n'); // Perform a priming read  
    // could test here on eof status bit for empty file

    cout << "counting the number of lines in Input0.txt\n";
    cout << "\n\nBefore the while loop \n";

    while (InFile) {
        // input stream is valid, so increment the number of lines by one
        // output the line and then read the next line from the file
        num_lines++;
        cout << "Line " << num_lines << ": " << line << endl;
        getline(InFile, line, '\n');
    }
    cout << "After the while loop \n";
    cout << "The number of lines in the file is: " << num_lines << endl;
    // can test for empty file here based on num_lines not on eof status bit
    // if num_lines == 0, then loop body never executed which means the priming
    // read put us in the fail state.
    if (num_lines == 0)
        cout << "Input file was empty\n";
    cout << endl;
    return 0;
}
