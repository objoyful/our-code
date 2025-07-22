// Chpater 10 program 2: Ch_10_02.cpp
#include <iostream>
#include <string>
#include <cctype> // required for chharacter functions - indirectly included via iostream in g++ 

using namespace std;

// This program looks at char variables and how they correspond
// to integers.
int main() {
    int count; 	// loop control variable
    char letter; // holds character corresponding to count
    string line; // used for program flow control

    // print out the corresponding character for an integer value
    // The machine has the ascii character set, so only integers
    // 0 to 127 have significance.  However, there are other 
    // characters available for values 128 to 255.  Note that since
    // char variables are only one byte, the highest integer value
    // that can be assigned to them is 255.  A value of 256 results
    // in a wrapping back to 0, 257 to 1, etc. 
    for (count = -10; count < 300; count++) {
        letter = count;  // use implicit coercion to assign an integer value
        
        // to the char variable letter
        cout << "Count: " << count;
        
        //cout << " integer(0-256): " << count%256 << " is: " << letter << endl;
        cout << " integer(0-256): " << count << " is: " << letter << endl;
        
        // put a pause in the printing of the values after every 20 values.  
        // Note testing for a vlue of 19 instead of 0 since count starts at 0
        // if I tested for equal to 0, I would get a pause after one value and then every 
        // twenty.  by testing on 19, the first pause occurs after 20 values every time
        if (count % 20 == 19) {
            cout << "press enter to continue:";
            getline(cin, line);
        }
    }

    // Note the book says that toupper, tolower functions
    // require the cctype header file.  Evidently that is not
    // the case with this compiler.  The following uses functions
    // in the cctype header file without including that file.  
    // However, this code is not as protable because of the omission.
    // the header file should be included.  
    //
    // iostream indirectly includes ccytpe header file through the header file iostream
    //
    // best to always include cctype when using any of its functions

    cout << endl;
    cout << "enter a character(z to terminate): ";
    cin.get(letter);
    cin.ignore(100,'\n');
    
    do {
        cout << "is digit: " << isdigit(letter) << endl;
        cout << "is lower: " << islower(letter) << endl;
        cout << "is upper: " << isupper(letter) << endl;
        cout << "is alpha: " << isalpha(letter) << endl;
        cout << "is space: " << isspace(letter) << endl;
        cout << "is blank: " << isblank(letter) << endl;
        cout << "is punct: " << ispunct(letter) << endl << endl;
        cout << "is cntrl: " << iscntrl(letter) << endl << endl;
        cout << "enter a character(z to terminate): ";

        cin.get(letter);
        cin.ignore(100,'\n');
    }while (letter != 'z');

    return 0;
}