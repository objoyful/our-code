// Functions2_01.cpp

// This is a program illustrating the concept of name 
// hiding of global variables.  Note that name hiding
// also occurs on a local level.

#include <iostream>
using namespace std;

// function declarations/prototypes are made globally  
void MyFunction(int num1, int num2 ); // function prototype 

// Variables and constants declared here are global
int number = 100; // global variable used to show precedence
const double PI = 3.14159; // global constant example

int main() {
    int temp;  // holds a copy of number before a for loop
    // Variables defined here are local to the function main
    // and any blocks defined in main.  Variables defined in 
    // main are not available to functions called from main
    int number = 200; // local variable to main, and takes precedence
    // over the global variable number
    if (true) {
        int number = 300; // Variable local to this if block only
    }

    // as already mentioned, variable declarations in a for
    // statement are local in scope to the for loop only
    for (int number = 0; number < 5 ; number ++) { // not allowed in visual C++
        // number is a local variable to the for loop only
        // and it takes precedence over the variable number 
        // declared in main and the global declaration

        temp = number; // temp holds value of number of the for loop
        if (true) {
            // number here is local to the if statement and it takes
            // precedence over the previously declared variables of
            // the same name.
            int number = 400 + 100 * temp;
        }
    }
    // int number = 500;
    return 0;
}
void MyFunction(int num1, int num2) { // function definition

    // Can also have what is called name precedence or name hiding
    // can declare a local variable or constant here with the same name as
    // one declared as a global.  The one defined here "hides" the
    // global value and only the local value is used

    // local variable declaration that hides the global
    // declaration of number;
    int number = 2000; 
}
