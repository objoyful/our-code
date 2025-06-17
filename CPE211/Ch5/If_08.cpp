// Ch_05_8.cpp
// Testing status of an input/output stream, and fail state mode

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <climits>

using namespace std;

int main() {
    int num1, num2;// numbers entered for processing
    string name;// holds a string value entered 

    cout << endl << "Test on the input stream for fail state\n";

    // to put the input stream into the fail state enter # # string or
    // string # #.Trying to read an integer when letters are present
    // will do the job.

    cout << "Enter an integer, a name, an integer: ";
    cin >> num1 >> name >> num2;

    // test the status of the stream.the input stream 
    // stays valid until an invallid data match occurs.

    if (cin.eof()) { // for control-d test
        cout << "Control-d used for eof\n";
        return 1;
    }

    if (cin)
        cout <<"Entered: " << num1 << "" 
             << name << "" << num2 << endl;
    else
        cout << "input stream is in the fail state due to bad entry\n";

    // If the input stream is in the fail state, 
    // the extraction from cin associated with
    // this prompt will be ignored.

    cout << "\nenter an integer: ";
    cin >> num1;
    cout << "Entered value is: " << num1 << endl;

    // or use if (cin.fail())
    //
    if (!cin) { // true when the input stream is in fail state
        // clear cin from the fail state
        cin.clear();
        
        string word;
        cin >> word;
        cout <<"cin contained: " << word << endl;
        
        // ignore any characters that may be on the input stream
        cin.ignore(INT_MAX,'\n'); 
        cout << "\nInput stream has been reset\n";
    }

    cout << "\nEnter anotherinteger,name, integer set: ";
    cin >> num1 >> name >> num2;

    if (cin.good())
        cout <<"Entered: " << num1 << "" << name 
             << "" << num2 << endl;
    else
        if(cin.fail()) cout << "input stream is in the fail state due to bad entry\n";

    cout << "===================================================\n\n";

    return 0;
}
