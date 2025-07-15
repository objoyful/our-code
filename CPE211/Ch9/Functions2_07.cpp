// Functions2 program 7 : Functions2_07.cpp

#include <iostream>
#include <fstream> // for filestream use
#include <string> // for use of string variables
#include <cstdlib> // for exit function
using namespace std;

// This program is an example of using a boolean function
// It also shows the use of the exit feature in a function

bool OpenInput (ifstream &, string &);
void OpenInput2(ifstream &);

int main() {
    ifstream InFile;
    string file_name;

    // open a file for input using a function that 
    // returns a boolean value on the status of the file.
    // use that information to proceed or terminate the program

    cout << "*****************************\n";
    cout << "Testing file stream status with a boolean function\n";

    if (!OpenInput(InFile,file_name)) {
        cout << "Error in opening input file: " << file_name << endl;
        cout << "Program is terminating in the main function\n";
        return 1;
    } else
        cout << "File: " << file_name << " opened successfully!!\n";

    // reset the file stream variable so that it 
    // can be used again.

    InFile.close(); // close the successfully opened file
    InFile.clear();

    cout << "*****************************\n";
    cout << "*****************************\n";

    // Now try the other function where the testing is
    // performed in the function itself.

    cout << "Test of file stream performed in the function\n";
    OpenInput2(InFile);
    cout << "*****************************\n";
    cout << "End of program in main\n";

    // other statements
    return 0;
}

bool OpenInput(ifstream & Input, string & name) {
    // This function illustrates returning the boolean
    // status of the file stream opened so that the caller
    // can decide what to do with a success or failure.

    // the function name entered and the input file stream 
    // are returned via reference parameters

    cout << "Enter the name of the file to open for input: ";
    cin >> name;
    Input.open(name.c_str());
    cout << "File stream opened, but not tested.\n";
    cout << "Return to main\n";

    /* the following if-then-else is replaced by the single
       return statement shown below this comment block
       if (Input.fail())
           return false;
       else
           return true;
       */

    return Input.good();  // or could use return bool(Input);
}



// could make the following function a boolean function 
// and return true or false for success so that 
// main can terminate the program if necessary.

void OpenInput2(ifstream &InFile) {
    // file stream performed in the function
    // exit is used to terminate the program when 
    // the input file is incorrect
    string file_name;
    cout << "enter the name of the file to open: ";
    cin >> file_name;
    
    InFile.open(file_name.c_str());
    cout << "EOF? " << boolalpha << InFile.eof() << endl;
    
    if (InFile.fail()) {
        cout << "Error: file: " << file_name ;
        cout << " was not found\n";
        cout << "Terminating the program!!!\n";
        exit(1); // exit the program
    }
    // These statements are not executed if the file is
    // not successfully opened since the program will exit.

    cout << "Input file successfully opened!!!\n";
    cout << "Returning control to main\n";
}
