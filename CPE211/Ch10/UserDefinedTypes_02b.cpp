// Chpater 10 program 2b: Ch_10_02b.cpp
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// This program looks at char variables and how they correspond
// to integers.
int main() {
	char letter;  // holds the character being evaluated
	string line;  // string being analyzed one character at a time

	// Various evaluations of the the toupper and tolower functions
	// in the header file cctype.  Note thatt on the suns that header
	// file is not required, but it should be used to allow for portability
	// of the code.

	// toupper and tolower return an integer value regardless
	// of the char argument (literal versus variable)

	cout << "\nOutput of toupper and tolower values of a literal directly from cout\n";
	cout << "This shows that the return from these functions is an integer\n";
	cout << "lowercase a to upper: " << toupper('a') << endl;
	cout << "uppercase B to lower: " << tolower('B') << endl;

	cout << "\nSame as above but using a char variable instead of literal\n";
	
	letter ='a';
	cout << "lowercase a to upper: " << toupper(letter) << endl;
	
	letter ='B';
	cout << "uppercase B to lower: " << tolower(letter) << endl;

	// toupper and tolower return an integer which can be assigned
	// to a char variable.  Output of the char variable will be
	// as a character not an integer
	cout << "\nAssign the change to a char variable then print out that variable\n";
	
	letter = toupper('a'); 
	cout << "lowercase a to upper: " << letter << endl;
	
	letter = tolower('B'); 
	cout << "uppercase B to lower: " << letter << endl;

	cout << "\nShowing that toupper and tolower are value returning functions\n";
	cout << "and that they do not change the value of the variable\n";
	cout << "used as an argument in the function call.\n";
	
	// toupper and tolower do not change the value of the argument
	letter ='a';
	toupper(letter);  // value returned is lost
	cout << "lowercase a stored in letter, and letter after using 'toupper(letter);' : " << letter << endl;
	
	letter = 'B';
	tolower(letter); 
	cout << "uppercase B stored in letter, and letter after using 'tolower(letter);' : " << letter << endl;
    
	// put in a pause here
	cout << "\nPress enter to continue\n";
	getline (cin, line);

	// Now look at string variables and how they are made up of
	// characters - thereby showing they are not simple data types
	cout << "\n\nString variable example\n";
	line = "This is a string";
	cout << "String variable output: " << line << endl;
	cout << "can access each character individually:\n";
	
	for (int j = 0; j < line.length(); j++) {
		cout << "character in position: " << j << " \t" << line[j] << endl;
	}

	return 0;
}