// Chpater 06 program 5: Ch_06_05.cpp
#include <iostream>
#include <fstream>
#include <iomanip> 
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
    bool finished;    // flag used for loop control
    int value;    // number read from the input file
    int sum;        // sum of the numbers read from the file
    int line_num;    // number of lines read from the file
    ifstream InData;    // input file stream variable

    // Flag Controlled Loop - uses a flag which is a boolean variable.
    // The flag records whether or not the event that controls
    // the loop has occurred.

    // Flags can be initialized to true or false.  The value
    // used is usuall decided by the variable name so that 
    // reading the statement indicates the desired action.

    // Examples while (!negative), while (DataOk)

    // In this example, integers are read from a file until one
    // of the following occurs: Either the end of the file is
    // reached, or the sum of the integers exceeds 300.

    cout << "\n\nFlag controlled loop example.  In this case, the\n";
    cout << "flag is changed when the sum of integers entered\n";
    cout << "exceeds 300.  The loop terminates when the EOF is\n";
    cout << "reached or the sum exceeds 300\n\n";

    cout << "File: data_file1.txt has integers that sum to > 300.\n\n";

    line_num = 0;
    sum = 0;
    finished = false; // initialize this to false since we are not done

    cout << boolalpha;

    // open the input file stream
    InData.open("data_file1.txt");

    cout << left << setw(17) << "Line and Value"
         << setw(20) << "      sum" << right << setw(10) << "finished" << setw(10)
         << "InData" << endl;
    cout << left << setw(17) << "--------------"
         << setw(20) << "-------------" << right << setw(10) << "--------" << setw(10)
         << "------" << endl;

    InData >> value;  // Priming read to read the first value

    // Loop executes As long as the input stream is valid and the sum is less than 300

    while (InData && !finished ) {
        line_num++;
        sum += value;
        
        cout << "Line " <<  line_num << ": " << left << setw(9) << value;
        cout << ":: sum is " << setw(10) << sum << right << setw(10)<< finished << setw(10)
             << bool(InData) << endl;

        // test the sum to see if we have reached 301 or higher 
        // could use finished = sum > 300 this sets the value false 
        // to finished until sum exceeds 300
        if (sum > 300) 
            finished = true; //finished = sum > 300;
        else
            InData >> value; // Read the next value
    }

    // print out the status of the input stream and finished

    cout << boolalpha;  // prints out true or false for boolean variables.
    cout << "finished is : " << finished << endl;
    cout << "The status of the input stream is: " << bool(InData) << endl;

    InData.close(); // close the file used for the input stream
    return 0;
}
