// Functions2_04.cpp 

// This is a program illustrating the concept of 
// static variables
#include <iostream>
using namespace std;

void Function1(); // static variable in this Function
void Function2(); // regular variables for comparison

int main() {
    // Note that the i defined in the for loop has 
    // scope only in that loop, and since it is in main, 
    // the variable is not available to the Function.
    // The i defined in the Function has scope 
    // in the Function block only. 

    // execute the loop 6 times.  each time through the loop
    // call Function1 and Function2.

    cout << "In Function 1: i is static and initialized to 0\n";
    cout << "In Function 1: j is static but not initialized at declaration\n";
    cout << "In Function 2: i is not static and initialized to 0\n";
    cout << "In Function 2: j is not static and never initialized\n";

    cout << "Looping in main from i = 10 to i =15\n";
    for (int i = 10 ; i <= 15 ; i ++) {
        cout << "In Main i = " << i << "\n";
        Function1(); 
        Function2(); 
    }

    return 0;
}

void Function1() {
    // to be used properly, static variables 
    // need to be initialized in their 
    // definition/declaration.  
    // This occurs on first call only

    static int i = 0 ; // variable for testing static property
    static int j;  // show the effect of no initialization

    // initialize the variable j.  
    // This occurs on every Function call.
    j = 0; 

    // by declaring i as a static variable, 
    // i retains its value from Function call to
    // Function call and initialization only occurs once
    cout << "\tFuntion1:  i = " << i << ",  ";
    i ++;
    cout << "j = " << j << endl;

    j ++;
}

void Function2() {
    // several variables declared to see what the values
    // are if they are never initialized
    int x;
    int y;
    float yy;
    int kk, yyy, zz;

    // j is an uninitialized variable in the Function.
    int j;

    // i is not declared as a static, 
    // so it is assigned the value of 0 each 
    // time the Function is called.
    int i = 0; 

    cout << "\tFuntion2:  i = " << i << ",  ";
    cout << "j = " << j << "  j is unitialized\n" << endl;  // j is not initiailized
    cout << "Un-initialized Vars:  " << y << "  " << x << " " << yy << " " 
         << kk << " " << yyy << " " << zz << endl << endl;

    // increment i, but this increment is lost 
    // when the Function ends
    i++; 
    j++;
}
