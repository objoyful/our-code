// Ch_05_6.cpp
// Example showing the mistake of using a single = in
// an if statement instead of a ==
#include <iostream>
#include <iomanip>
using namespace std;

// Common mistake, if-then-else examples

int main() {
    int num1, num2, num3, temp;

    while (true)  // create an infinite loop
    {
        cout << endl;
        cout << "Enter three integers (ctrl-c to exit): ";
        cin >> num1 >> num2 >> num3;

        cout << endl << endl << "entered values are: num1: " << num1;
        cout << "    num2: " << num2 << "    num3: " << num3 << endl;
        cout << "==============================================\n\n";

        temp = num1; // maintain a copy of original num1

        // This first section shows what happens when a 
        // single = is used instead of a == as part of 
        // the logical expression of an if statement.  
        // Sample data to use for testing: 10 3 7; 3 4 5 

        cout << "Example of single = using num1 = num2 + num3\n\n";
        cout << "before if, num1 is: " << num1 << endl;

        if (num1 = num2 + num3)
            cout << "First number equals the sum of the other two\n";
        else 
            cout << "First number doesn't equal the sum of the other 2\n";

        cout << "after if num1 is: " << num1 << endl;
        cout << "==============================================\n\n";


        // ***************************************************
        // ***************************************************
        //
        // A better way to write a test for equality if one
        // side is to be an expression.  put the expression 
        // on the left side of the test.  That way if a single
        // equal sign is used, you receive a compile error
        //
        // if (num2 + num3 = num1)   results in a compile error
        // if (num2 + num3 == num1)  test for equality of the 
        //                           two operands (num2 + num3)
        //                           and num1

        // ***************************************************
        // ***************************************************
        // corrected version using == instead of =

        num1 = temp;
        cout << "correct version of previous example\n\n";
        cout << "before if, num1 is: " << num1 << endl;

        if (num1 == num2 + num3)
            cout << "First number equals the sum of the other two\n";
        else 
            cout << "First number doesn't equal the sum of the other 2\n";

        cout << "after if num1 is: " << num1 << endl ;
        cout << "==============================================\n\n";
        cout << endl;
    }

    return 0;
}
