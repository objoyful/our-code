// Functions2 program 8 : Functions2_08.cpp

#include <iostream>
#include <fstream> // for filestream use
#include <string> // for use of string variables
#include <cstdlib> // for exit function
using namespace std;

// This program is an example of declaring a function
// inside of main - makes the function local to main
//
// Function declaration for all parts of the program
void TestFunction();

int main() {

    cout << "*****************************\n";
    cout << "Start of program in main\n";
    // attempt of function definition in main
    /*
    void MyLocalDef() {
        cout << "in MyLocalDef\n";
    }
    */

    void MyFunction(); // function prototype - scope of MyFunction is main only
    MyFunction();

    cout << "*****************************\n";

    TestFunction();

    cout << "*****************************\n";
    cout << "End of program in main\n";

    return 0;
}

void TestFunction() {
    // can this function call MyFunction which is declared inside of main?
    // get a compile error because MyFunction is not declared in this scope
    cout << "\nCalling MyFunction from TestFunction?? is this possible??\n";
    // MyFunction();  // no prototype with scope for using MyFunction in TestFunction
}

void MyFunction() {
    cout << "in MyFunction\n";
}