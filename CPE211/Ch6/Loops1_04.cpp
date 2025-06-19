// Chapter 6  - program 4: 
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include <string>
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
    int value;      // number read from the input file
    int line_num;	// counter for number of lines in the input file
    ifstream InData;// file stream variable for the input stream
    char ch;
    string line;    // for removing new line character

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
    cout << "First use a file that has information: data_file1.txt\n\n";
    cout << "File stream status of true means the stream is valid\n";
    cout << "File stream status of false means the stream is in the fail state\n\n";

    cout << boolalpha << left;  // prints out true or false for boolean values.

    // Set up column headers

    cout <<  setw(7) << "Line#" << setw(8) << "value" 
         <<  setw(15) << "Stream Status" 
         <<  setw(8) << "good()" << setw(8) << "bad()" 
         <<  setw(8) << "fail()" << setw(8) << "eof()" << endl;

    cout <<  setw(7) << "-----" << setw(8) << "-----" 
         <<  setw(15) << "-------------" 
         <<  setw(8) << "------" << setw(8) << "-----" 
         <<  setw(8) << "------" << setw(8) << "-----" << endl;

    line_num = 0;  // initialize the counter for the line count

    //  open the input stream;
    InData.open("data_file1.txt");

    //  the following two lines can be used in place of the while statement
    //  shown below
    //while (InData>> value )  // Acts as priming read and then input stream is tested
    // while (cout << "reading a value from file: ", InData >> value) { // Acts as priming read and then input stream is tested

    //InData >> value;  // Priming read to read the first value

    //while (!InData.eof())  // not a good way to test for end of file loop condition
    //while (!InData.eof() && !InData.fail())  
    
    while (!InData.fail()) { // As long as the input stream is valid
        line_num++;
        // output some information about the information 
        // read and the status 
        // of the input file stream.  use a counter 
        // variable to list out the line 
        // number, followed by the value read from the 
        // file followed by the file stream status.

        // This line will remove all content from the current line in the input 
        // file.  so when the last line is read, this read will ensure that there
        // is no more data in the input file.  We will use this information to
        // determine when the eof bit is set.  
        
        getline(InData, line, '\n');  // read the new line character to check eof function

        // the file stream status is converted to its boolean equivalent for printing as true/false
        cout <<  setw(7) << line_num <<  setw(8) << value 
             <<  setw(15) << bool (InData)  
             <<  setw(8) << InData.good()  << setw(8) << InData.bad()  
             <<  setw(8) << InData.fail()  << setw(8) << InData.eof()  << endl;


        // If the two lines shown before the while statement are used, then
        // the next data value needs to be read here so that the file stream
        // can be tested in the while statement to see if the loop continuesRead the next value
        InData >> value;
    }
    cout << string(60,'=') << endl;

    cout <<  setw(7) << line_num <<  setw(8) << value 
         <<  setw(15) << bool (InData)  
         <<  setw(8) << InData.good()  << setw(8) << InData.bad()  
         <<  setw(8) << InData.fail()  << setw(8) << InData.eof()  << endl;

    InData.close(); // close the file used for the input stream
    return 0;
}
