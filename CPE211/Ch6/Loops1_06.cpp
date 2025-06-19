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
    int numLines;		// number of lines in the file	
    string line;		// holds the line read from the file
    char ch1;			// flow control variable

    InFile.open("Input1.txt"); // <======

    numLines = 0;  //initialize the line count variable to zero

    getline(InFile, line, '\n'); // Perform a priming read - Why?

    cout << "counting the number of lines in Input1.txt\n";
    cout << "\n\nBefore the while loop \n";

    while (InFile) {

        // input stream is valid, so increment the number of lines by one
        // output the line and then read the next line from the file
        //getline(InFile,line,'\n');
        numLines++;
        cout << "Line " << numLines << ": " << line << endl;
        getline(InFile, line, '\n');
    }
    cout << "After the while loop \n";
    cout << "The number of lines in the file is: " << numLines << endl;
    cout << endl;
    InFile.close();

    return 0;
}
