// Data Types 1
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// This program looks at char variables and how they correspond
// to integers.
int main()
{
    // valid identifier? main does work
     //float return;
     string pause;
     float main;
     main = 10.5;
    //return = 10.5;
    //cout << return << endl;
    cout << "main = " << main << endl;
    //
    // does the following work for concatenation:
    // order does matter - c++ 11 
    string name, first = "Ron ";
    const char SPACE = ' ';
    name = first + SPACE + " Bowman";
    cout << name << endl << endl;
    name = SPACE + " Bowman" + first;
    cout << name << endl << endl;
    cout << "========================\n";
    getline(cin,pause,'\n');

	char letter;  // holds the character being evaluated
	string line;  // string being analyzed one character at a time

    letter = 'A';
    line = letter;
    cout << "line: " << line << endl;

    // characters can hold a single character only
    // this assignment gives a warning and the last letter
    // G is assigned to the variable letter
    letter = 'ABCDE';
    //letter = 'ABCDEFGHI';
    cout << "Letter: " << letter << endl;
    cout << '\n\n\n';
    cout << "next line\n";
    getline(cin,pause,'\n');

	// Various evaluations of the the toupper and tolower functions
	// in the header file cctype.  

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
	cout << "\nAssign the case change to a char variable\n"
	     << "then print out that variable\n";
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
	cout << "\nOutput of variable letter(which contains a)\n"
	     << "after using 'toupper(letter);' : " << letter << endl << endl;
	letter = 'B';
	tolower(letter); 
	cout << "Output of variable letter(which contains B)\n"
	     << "after using  'tolower(letter);' : " << letter << endl;
    

    cout << endl;
    cout << "Look at results of character functions in CCTYPE\n";
    cout << "Header File\n";
    cout << "enter a character(z to terminate): ";
    cin >> letter;
    do
    {
        cout << "is digit: " << isdigit(letter) << endl;
        cout << "is lower: " << islower(letter) << endl;
        cout << "is upper: " << isupper(letter) << endl;
        cout << "is alpha: " << isalpha(letter) << endl;
        cout << "is punct: " << ispunct(letter) << endl << endl;
        cout << "enter a character(z to terminate): ";
        cin >> letter;
    }while (letter != 'z');


	// put in a pause here
	cout << "\nPress enter to continue\n";
	getline (cin, line);

	// Now look at string variables and how they are made up of
	// characters - thereby showing they are not simple data types
	cout << "\n\nString variable example\n";
	line = "This is a string";
	cout << "String variable output: " << line << endl;
	cout << "can access each character individually:\n";
	for (int j = 0; j < line.length(); j++)
	{
		cout << "character in position: " << j << " \t" << line[j] << endl;
	}

	return 0;
}