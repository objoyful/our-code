#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <climits>

using namespace std;
int main() {
    ifstream inFile;  string filename;

    cout << "\nEnter the name of the input file (ctrl-c to exit):"; 
    cin >> filename;  
    
    cin.ignore(INT_MAX,'\n'); // remove any extraneous characters
    inFile.open(filename.c_str());

    cout << left << boolalpha;
    while (!inFile) {  // file stream in the fail state cause loop entry
        cout << "\nStart of loop body:\n";
        cout << "File failed to open properly - status bits are:\n";
        cout << setw(7) << "good:" << inFile.good() << endl 
             << setw(7) <<  "bad:" << inFile.bad()  << endl 
             << setw(7) << "fail:" << inFile.fail() << endl 
             << setw(7) <<  "eof:" << inFile.eof()  << endl;

        inFile.clear();  // clear the file stream variable for reuse

        cout << "\nAfter Clear (resets the status bits):\n";
        cout << setw(7) << "good:" << inFile.good() << endl 
             << setw(7) <<  "bad:" << inFile.bad()  << endl 
             << setw(7) << "fail:" << inFile.fail() << endl 
             << setw(7) <<  "eof:" << inFile.eof()  << endl;
        cout << endl;

        cout << "input file " << filename 
             << " would not open.  Try Again...\n\n";

        cout << "Enter the name of the input file (ctrl-c to exit):" ;
        cin >> filename; 
        cin.ignore(INT_MAX,'\n');

        inFile.close();

        inFile.open(filename.c_str());
        cout << "End of loop body\n";
    }
    
    cout << "\nFile Successfully opened:\n";
    cout << setw(7) << "good:" << inFile.good() << endl 
         << setw(7) <<  "bad:" << inFile.bad()  << endl 
         << setw(7) << "fail:" << inFile.fail() << endl 
         << setw(7) <<  "eof:" << inFile.eof()  << endl;

    inFile.close();

    return 0;
}
