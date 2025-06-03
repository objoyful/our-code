//
// Chpater 03 program 3: Ch_03_03.cpp
// Type coercion - implicit and explicit, mixed data type statements
#include <iostream>

using namespace std;

int main()
{
    int num1 = 50;		// variable used in coercion equations
    int num;			// variable to hold coerced values
    float flt1 = 3.14159;		// variable used in coercion equations
    float flt;			// variable to hold coerced values

    // If you want to coerce a number from one data type
    // to another, show it by using type casting.  do not let
    // the computer do it automatically by using implicit type coercion

    // implicit type coercion - conversion is done automatically
    cout << "Implicit type coercion of integer to float and float to an int.i\n";
    num = flt1;
    flt = num1;
    cout << "int num contains the value for 3.14159: " << num << endl;
    cout << "float flt contains the value for 50: " << flt << endl;
    cout << "***********************************\n\n";

    // explicit type coercion - type casting
    // here num1 is converted to a float before the multiplication,
    // then the overall result is converted to an integer.
    cout << "Explicit type coercion of int to a float and a float to an int\n";
    num = int(flt1*float(num1));
    cout << "type cast value for num: " << num << endl;
    cout << "calculated float value: " << flt1*num1 << endl;
    cout << "***********************************\n\n";

    // in this statement, flt1 is converted to an integer to 
    // perform integer division, and then the result is made a float
    cout << "integer division result converted to a float\n";
    flt = float(num1/int(flt1));
    cout << "calculated integer value: " << num1/int(flt1) << endl;
    cout << "type cast value for flt: " << flt << endl;
    cout << "***********************************\n\n";

    // mixed data type statements
    // illustration of floating point arithmetic with implicit coercion from int to float
    cout << "Mixed expressions output\n";
    cout << "Value of 3.0/2 + 0.75 = " << 3.0/2 + 0.75 << endl;

    // Illustration of integer division followed by implicit coercion to a float
    flt1 = 100/40*1.0;
    cout << "Value of 100/40*1.0 = " << flt1 << endl;

    flt1 = 1.0*100/40;
    cout << "Value of 1.0*100/40 = " << flt1 << endl;

    flt1 = float(num1/13);  // integer division typecast to float
    cout << "float(num1/13) = " << flt1 << endl;

    flt1 = float(num1)/13;  // integer division typecast to float
    cout << "float(num1)/13 = " << flt1 << endl;

    return 0;
}
