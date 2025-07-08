// Functions1_08.cpp
#include <iostream>
using namespace std;

// Simple program showing that variables declared in a function
// are local to that function and not the main program.  Also
// Shows that variables declared in main are not accessible in
// a function.

void Area (float); // Function prototype <======
int count = 0;  // global variable for clarification of scope

int main () {

    float radius;   // radius of the circle 

    // variable used to show limited scope
    // there is an identical identifie area in the Area function

    float area = -15.0;  

    cout << "\nIn main: count = " << count << endl;
    // prompt for and read in the radius of a circle

    cout << "Enter a radius: ";
    cin >> radius;

    // output some program execution information, and then
    // make a function call to find the area of the circle

    cout << "\n--before function call, area in main = " 
         << area << endl << endl;

    Area(radius); // function call   <=========

    cout << "--after function call, area in main = " 
         << area << endl;

    cout << "In main: count = " << count << endl << endl;

    return 0;
} // End of Main

void Area (float rad) {  // function definition <===========
    // output current value of count and then increment it

    cout << "-----Entering function ... count = " << count ++ << "\n";
    float area;   // variable to show limited scope

    area = 3.14159 * rad * rad;  // calculate the area of a circle

    // Note that the parameter rad is assigned the value of the 
    // function call argument which is radius.
    cout << "-----In middle of Function: count = " << count << endl;

    cout <<"-----Circle of Radius " << rad << " has area of ";
    cout << area << endl;



    // the line below gives the following compile error
    //  line 46: Error: radius is not defined.
    // So, I have commented it out
     //cout << "Radius from main is: " << radius << endl;

    //  Increment count showing global variable effect
    count ++;

    cout << "-----Exiting  function\n\n";
}
