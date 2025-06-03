//
// Chpater 03 program 4b: Ch_03_04b.cpp
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double value = 45.65;
    double x = 3.14159;
    double y = 12345678.98;
    double z = 5;
    string line;  // used to pause program as it runs

    // now look at the effects of showpoint (show the decimal
    // point in whole floating point numbers) and set precision.
    // Also show the effects of the left and right manipulators

    cout << "Variables used and their values: \n";
    cout << "\tvalue = 45.65" << endl;
    cout << "\tx = 3.14159" << endl;
    cout << "\ty = 12345678.98" << endl;
    cout << "\tz = 5" << endl;
    cout << "--------------------------------------\n";
    cout << "--------------------------------------\n";

    cout << "output with no modifications\n";
    cout << "value:" << value << endl;
    cout << "x:" << x << "Next" << endl;
    cout << "y:" << y << "Next" << endl;
    cout << "z:" << z << endl;
    cout << showpoint << "z2:" << z << noshowpoint << endl;
    cout << "===================================================\n\n";

    cout << "Press Enter to continue: ";
    getline(cin,line,'\n');
    cout << endl;


    cout << "Floats with showpoint and setprecsion of 5\n";
    cout << "12345678901234567890\n";
    cout << "--------------------------------------\n";
    cout << showpoint << setprecision(5);

    cout << "value in setw(3):" << setw(3) << value << endl;
    cout << "x in setw(10) and left  justified:" << setw(10) << left << x << "Next" << endl;
    cout << "y in setw(15) and right justified:" << setw(15) << right << y << "Next" << endl;
    cout << "z without using setw:" << z << endl;
    cout << "===================================================\n\n";

    cout << "Press Enter to continue: ";
    getline(cin,line,'\n');
    cout << endl;

    // now use the fixed manipulator which will remove the use 
    // of exponential form for printing floating point numbers
    cout << "Now add in the fixed manipulator\n";
    cout << "12345678901234567890\n";
    cout << "--------------------------------------\n";
    cout << fixed;
    //cout << fixed << noshowpoint;
    cout << "value in setw(3):" << setw(3) << value << endl;
    cout << "x in setw(10) and left  justified:" << setw(10) << left << x << "Next" << endl;
    cout << "y in setw(15) and right justified:" << setw(15) << right << y << "Next" << endl;
    cout << "z without using setw:" << z << endl;
    cout << "===================================================\n\n";

    cout << "Press Enter to continue: ";
    getline(cin,line,'\n');
    cout << endl;

    // now go back to scientific to see the effects of set-precision
    cout << "Now go back to scientific mode\n";
    cout << "12345678901234567890\n";
    cout << "--------------------------------------\n";
    cout << scientific;
    cout << "value in setw(3):" << setw(3) << value << endl;
    cout << "x in setw(10) and left  justified:" << setw(10) << left << x << "Next" << endl;
    cout << "y in setw(15) and right justified:" << setw(15) << right << y << "Next" << endl;
    cout << "z without using setw:" << z << endl;
    cout << "===================================================\n\n";


    return 0;
}
