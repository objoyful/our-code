// Functions2_02.cpp
// This is a program illustrating the concept of name 
// hiding of global variables.  Note that name hiding
// also occurs on a local level.

#include <iostream>
using namespace std;

// function declarations/prototypes are made globally  
void MyFunction(void); // function prototype 
void Fnc(int param);  // prototype

// Variables and constants declared here are global
int number = 100; // global variable for showing precedence

int main() {
    // Variables defined here are local to the function main
    // and any blocks defined in main.  Variables defined in 
    // main are not available to functions called from main
    // funciton prototype limits scope to main
    void Fnc(int param);  // prototype
    Fnc(10);


    /*
    // funciton definitions not allowed in other functions
    void Fnc22(int param) {
        cout << "hello " << param << "\n";
    }
    Fnc22(50);
    */

    cout << "Main: Global value of number: " << number << endl;

    int number = 200; // local variable to main, and takes precedence
    // over the global variable number
    cout << "Main: local value of number: " << number << endl << endl;
    if (true) {
        int number = 300; // Variable local to this if block only
        cout << "Main: local value of number in if: " 
             << number << endl << endl;
    }

    // as already mentioned, variable declarations in a for
    // statement are local in scope to the for loop only
    for (int number = 1; number < 5 ; number ++) { // does not work in visuall C++
        // number is a local variable to the for loop only
        // and it takes precedence over the variable number 
        // declared in main and the global declaration

        cout << "Main: local value of number in for loop before if: " 
             << number << endl;
        if (true) {
            // local declaration here takes precedence over
            // local declaration of number in the for statement above.

            int number = 400; 
            cout << "Main: local value of number in if statement in for loop: " 
                 << number << endl << endl;
        }
    }
    // int number = 700; // local variable to main, and takes precedence
    MyFunction();
    return 0;
}
void MyFunction(void) { // function definition
    // Can also have what is called name precedence or name hiding
    // can declare a local variable or constant here with the same name as
    // one declared as a global.  The one defined here "hides" the
    // global value and only the local value is used

    cout << "MyFunction: Global value of number: " << number << endl;

    // local variable declaration that hides the global
    // declaration of number;
    int number = 2000;  
    cout << "MyFunction: local value of number: " << number << endl;
    Fnc(12);
}

void Fnc(int param) {
    cout << "hello " << param << "\n";
}
