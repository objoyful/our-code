// Ch_05_5.cpp
// Examples of if-then and if-then-else examples
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int num1, num2, num3;  // three integer values used for testing

    while (true) {// create an infinite loop
        // read three integers for testing purposes
        cout << endl;
        cout << "Enter three integers (ctrl-c to exit): ";
        cin >> num1 >> num2 >> num3;

        // output a header showing the 3 values entered by the user
        cout << endl << endl << "num1 = " << num1 
             << "\tnum2 = " << num2 
             << "\tnum3 = " << num3 << endl;
        cout << "================================================\n";


        // *********************************************************
        // This example shows the if-then-else structure

        cout << "if-then-else testing using num1 > num2 + num3\n\n";
        cout << "Start of if-then-else\n";

        if (num1 > num2 + num3)
            cout << "First number is greater than the sum of the other 2\n";
        else 
            cout << "First number is not greater than the sum of the other 2\n";

        cout << "================================================\n";

        // *********************************************************
        // This example shows the if-then structure 
        // (no else is required) it also shows the 
        // use of block statements with an if statement

        cout << "if-then statement testing num1==num2 then num2==num3\n\n";
        cout << "Start of if-then\n";
        if (num1 == num2) {
            cout << "first and second number are equal\n";
            if (num2 == num3)
                cout << "So are the second and third numbers\n";
        }
        cout << "Outside of if-then statement\n";
        cout << "================================================\n";

        // **************************************************
        // Example of formatting no-effect on execution of the code

        cout << endl;
        cout << "Example showing formatting has no effect\n";
        cout << "There are two cout statements following an if-then\n\n";

        // only the first line following the if statement is executed
        // when num1 > num2.  The next 2 cout statements are always 
        // executed

        cout << "Start of if statement\n";
        if (num1 > num2)
            cout << "1) first number is greater than second number\n";
            cout << "2) The above is the result of testing num1 > num2\n";
            cout << "3) =============================================\n\n";

        if(num1 > num2) {
            cout << "other format\n";
            cout << "of if block\n";
        }

        if(num1 > num2) {
            cout << "other format\n";
            cout << "of if block\n";
        }

    }
    
    return 0;
}
