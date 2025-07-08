// Functions1_09b.cpp

// This program shows an example of using the
// assert function

#include <iostream>
#include <fstream> // for file I/0 
#include <cassert> // for using the assert functions
#include <iomanip> // for setprecision

using namespace std;

int main() {     
   int number;
   // istead of floats, use double  with setprecision set to 0
   // much larger factorials can be found using long double
   // versus float.  

   long double factorial;
   cout << "A long double has a length of " 
        << sizeof(factorial) << " bytes\n";;

   // this line will force the number to be printed with 0
   // decimal places and without the exponentiation.  

   cout << fixed <<  setprecision(0);

   // The above line causes incorrect digits to be displayed 
   // on Blackhawk the error occurs at 25 and 26 
   // 25: 15511210043330985984000000
   // 26: 403291461126605635592388608
   // notice that the zeroes on the end have disappeared.
   
   while(true) {	// create an infinite loop broken by the assert
        cout << "\n\n===========================================\n";
        cout << "Enter a positive integer less than 100.\n";
        cout << "An incorrect value will cause the program\n";
        cout << "to terminate.\nNumber: ";
        cin >> number;
        cout << number << endl;

        assert(number >= 0 && number < 100);
        factorial = 1; // initialize the factorial value
        cout << "\ngood job! You entered a valid number\n";

        // place the cout statement below before the loop that 
        // calculates the factorial since the value of the number
        // entered is being reduced

        cout << "The factorial of " << number << " is: ";


        // this loop calculates the factorial by multiplying out
        // each integer value from 1 to the number entered
        // This loop descends in value, and only final value is printed

        for (int j = number; j > 0; j --) {
            factorial *= j;
        }

        cout << factorial <<  endl;

        cout << "===========================================\n";
        factorial = 1;
        
        cout << "      " << string::npos << endl;
        cout << "\n\n               1         2         3" 
             << "         4         5\n";
        cout << "      12345678901234567890123456789" 
             << "012345678901234567890\n";

        // this loop calculates the factorial by multiplying out
        // each integer value from 1 to the number entered
        // This loop ascends in value and all values are printed

        for (int j = 1; j <= number; j ++) {
            factorial *= j;
            cout << setw(4) << j << ": " << factorial << endl;
        }


        cout << "      123456789012345678901234567890123456789"
             << "01234567890\n";
        cout << "               1         2         3" 
             << "         4         5\n";
        cout << "===========================================\n";
   }
   return 0;
}
