// Chpater 05 program 4: Ch_05_04.cpp
// Floating point arithmetic example
// This program shows the inaccuracies of floating
// point arithmetic by using an example of adding 1/3 three
// times to get 1 - in various ways

#include<iostream>
#include<iomanip>
#include <cmath> // for the fabs function
using namespace std;

int main() {
    //double real1=0.0,real2=0.0; 
    float real1 = 0.0, real2 = 0.0; // double or long double would be more appropriate
    bool verify; 	// comparison result of two floats
    cout << boolalpha;

    // show where the precision of 1/3 ends.
    real1 = 1.0 / 3.0;
    cout << "real1 is 1.0 / 3.0:\t\t\t";
    cout <<setprecision(32) << fixed << real1 << endl;

    // calculate a value by adding 1/3 three times
    real2 = real1 + real1 + real1;
    cout << "result of real1 + real1 + real1:\t";
    cout << real2 << endl;

    // show that adding 1/3 three times does not necessarily equal
    // 1/3 multiplied by 3. 
    // rounding errors with floating point numbers

    cout << "result of real2 - 3.0 * real1:\t\t";
    cout << real2 - 3.0 * real1 << endl;

    cout << "result of real2 - real1 - real1 - real1:";
    cout << real2 - real1 - real1 - real1 << endl;

    cout << "result of real2 - 3.0 * real1:\t\t";
    cout << real2 - 3.0 * real1<< endl;

    // look at comparing two floats versus using the floating point
    // absolute value function for comparison

    verify = real2 == 3.0 * real1;
    cout << "\nDoes real2 = 3.0 * real1?: " 
         << verify << endl;
    cout << endl;

    cout << "Using fabs for assigning\n";
    verify = (fabs(real2 - 3.0 * real1) < 0.0000001);
    
    cout << "\nDoes real2 = 3.0 * real1?: " 
        << verify << endl;
    cout << endl;

    return 0;
}
