//
// Chpater 03 program 4: Ch_03_04.cpp 
#include <iostream>
#include <iomanip>  // needed for setw and setprecision

//using namespace std;
// have to use name qualification and using delcarations

using std::cout;
using std::setw;
using std::endl;

int main()
{
    // example showing the default formatting with setw
    // default justification is to the right
    float a = 4.25;

    cout << std::setfill('*');  // set extra space fill character to *

    cout << "Look at various setw outputs for the value 4.25\n\n";
    cout << "123456789012345678901234567890\n";

    cout << "--------------------\n";
    cout << setw(2) << a << "\t\tsetw(2)" << endl; // 4.25
    cout << setw(4) << a <<"\t\tsetw(4)" <<  endl; // 4.25
    cout << setw(6) << a << "\t\tsetw(6)" << endl; // **4.25 

    cout << a << "\t\tno setw" << endl;  // no setw here, to show that setw applies once

    cout << setw(5) << a << "\t\tsetw(5)" << endl; // *4.25
    cout << std::setfill(' ');
    cout << setw(10) << a << "\tsetw(10)" << endl; // $$$$$$4.25

    // back to back setw with nothing output for first setw
    // first setw is ignored
    cout << setw(10) << setw(30) << "Hello" << endl;
    cout << "123456789012345678901234567890\n";  // ruler to show how many spaces were used
    cout << "================================\n\n";
    return 0;
}
