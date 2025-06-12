// Ch_05_3.cpp
// Examples of logical operators and boolean values
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
int main() {
    // this example shows that non-zero integer values evaluate as true
    // when used in logical expressions.  Integer values assigned to 
    // integer variables are used in relational expressions to determine
    // the boolean response.

    bool b_verify;        // holds result of relational expression
    int num1, num2;        // numbers used in the relational expressions

    cout << endl << endl;  // put in 2 blank lines
    cout << left;  // left justification for setw

    // output manipulator to print out boolean vars as true or false
    cout << boolalpha; 

    while (true) { // note this creates an infinite loop
        cout << "Integer values not equal to 0 evaluate as true\n";
        
        cout << "enter 2 integers(ctrl-c to exit): ";
        cin >> num1 >> num2;

        cout << endl ;  // put in a blank line
        cout << "num1 = " << num1 << "       num2 = " << num2 << endl;
        
        cout << "b_verify is a boolean variable\n";
        cout << string(47, '*') << endl;

        b_verify = num1;
        cout << setw(42) << "Assign num1 to b_verify :" 
             << b_verify << endl;

        b_verify = num2;
        cout << setw(42) << "Assign num2 to b_verify :" 
             << b_verify << endl;

        // Logical operator AND results
        b_verify = num1 && num2;
        cout << setw(42) << "b_verify holds result of num1 && num2:" 
             << b_verify << endl;
        
        b_verify = num1 and num2;
        cout << setw(42) << "b_verify holds result of num1 and num2:" 
             << b_verify << endl;

        // Logical operator OR results
        b_verify = num1 || num2;
        cout << setw(42) << "b_verify holds result of num1 || num2:" 
             << b_verify << endl;
        
        b_verify = num1 or num2;
        cout << setw(42) << "b_verify holds result of num1 or num2:" 
             << b_verify << endl;

        // Logical operator NOT results
        b_verify = !num2;
        cout << setw(42) << "Assign !num2 to b_verify:" 
             << b_verify << endl;

        // Logical operators NOT and AND combined
        b_verify = !(num2 && num1);
        cout << setw(42) << "Assign !(num2 && num1) to b_verify:" 
             << b_verify << endl;
        
        b_verify = not(num2 && num1);
        cout << setw(42) << "Assign not(num2 && num1) to b_verify:" 
             << b_verify << endl;

        float avg = -99;
        
        b_verify = num1 > 0 || (num2 != 0 && (avg = num1 / num2)) || num2;
        cout << setw(42) << "Assign xx to b_verify:" 
             << b_verify << "  avg: " << avg << endl;

        cout << string(47,'*') << endl;

        cout << endl << endl;  // put in 2 blank lines
    }  // keep looping until ctrl-c is entered
    return 0;
}
