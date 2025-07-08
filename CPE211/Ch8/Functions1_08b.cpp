// Functions1_08b.cpp
//
#include <iostream>
using namespace std;

// Simple program showing that variables declared in a function
// are local to that function and not the main program.  Also
// Shows that variables declared in main are not accessible in
// a function.
// this version of the program results in a compile error due
// to the problem in the function trying to use a variable 
// declared in main.  This program will not compile

void Area (float); // Function prototype <======
int main() {
	float radius;   // radius of the circle 
	// variable used to show limited scope
	// there is an identical identifie area in the Area function
	float area = -15.0;  

	// prompt for and read in the radius of a circle
	cout << "Enter a radius: ";
	cin >> radius;

	// block statement that has local variable number
	// declared inside it.  number cannot be 
	// accessed outside the block
	{
		int number;
		number = 99;
		cout << "Number: " << number << endl;
	}

    // number cannot be used here.  this is a compile error
	// cout << "Number2: " << number << endl;

	// output some program execution information, and then
	// make a function call to find the area of the circle
	//
	cout << "--before function call, area in main = " << area << endl;
	Area(radius); // function call   <=========
	cout << "--after function call, area in main = " << area << endl;

	return 0;
} // End of Main

void Area (float rad) {   // function definition <===========
	cout << "----Entering function\n";
	float area;   // variable to show limited scope
	area = 3.14159 * rad * rad;  // calculate the area of a circle

	// Note that the parameter rad is assigned the value of the 
	// function call argument which is radius.
	cout <<"----Circle of Radius " << rad << " has area of ";
	cout << area << endl;

	// the line below gives the following compile error
	//  line 48: Error: radius is not defined.
	//cout << "Radius from main is: " << radius << endl;
	cout << "----Exiting  function\n";
}
