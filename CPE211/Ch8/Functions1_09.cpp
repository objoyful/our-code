// Functions1_09.cpp

// This program shows an example of using the
// assert function

#include <iostream>
#include <fstream> // for file I/0 
#include <cassert> // for using the assert functions

using namespace std;

int main() {
   int number;  // value entered to determine factorial

   // finding a factorial of 35 or higher using a float
   // variable results in the overflow value of .nf
   float factorial;  // contains result of the factorial of number
   
   while(true) {  // loop until ctrl-c breaks or assert breaks
        // read in a value that the factorial will be determined

        cout << "\n\n===========================================\n";
        cout << "Enter a positive integer less than 35.\n";
        cout << "An incorrect value will cause the program\n";
        cout << "to terminate.\nNumber: ";
        cin >> number;			// read in the value
        cout << number << endl;  // echo print the value back out

        // ensure that the number entered is in a valid range
        // if it is out of range, the assert function will print out
        // a message and terminate the program

        assert(number >= 0 && number < 35);

        // If this statement is executed, a correct value was entered

        cout << "\ngood job! You entered a valid number\n";

        factorial = 1; // initialize the factorial value

        // place the cout statement below before the loop that 
        // calculates the factorial since the value of the number
        // entered is being reduced

        cout << "The factorial of " << number << " is: ";
        for (int j = number; j > 0; j --)
            factorial *= j;
        
        cout << factorial << endl;
        cout << "===========================================\n";
   }

   return 0;
}
