//
// Chpater 03 program 5: Ch_03_05.cpp
#include <iostream>
#include <iomanip> // for using setw and setprecision
#include <string> // so that the string class can be used
using namespace std;
main()
{

    string str1 = "This is a programming class";	
    string str2 = "Instructor";	
    string str3 = "cl";
    string::size_type length;	// holds length of a string variable
    string::size_type pos;		// holds character position in a string

    // output values for string::npos under various conditions
    cout << endl;
    cout << "Value for string::npos: " << string::npos << endl;

    int number = string::npos;
    cout << "string::npos assigned to an integer variable: " << number << endl;

    unsigned int number2 = string::npos;
    cout << "string::npos assigned to an unsigned integer variable: " << number2 << endl;

    // output how much memory certain data types use
    cout << "size of int: " << sizeof(int) << endl;
    cout << "size of long: " << sizeof(long) << endl;
    cout << "size of long long: " << sizeof(long long) << endl;
    cout << "size of Ulong: " << sizeof(unsigned long) << endl;
    cout << "size of string::size_type: " << sizeof(string::size_type) << endl;
    cout << endl;


    cout << "The following two strings will be manipulated "
        << "in the program\n";
    cout << "      0123456789012345678901234567890\n";
    cout << "str1: " << str1 << endl; 
    cout << "str2: " << str2 << endl << endl;

    // show that length() and size() both perform the same function
    cout << "Determine number of characters in str1 and str2 "
        << "using length and size\n";
    length = str1.length();
    cout << "The length of str1 is: " << length << endl;
    length = str2.size();
    cout << "The size of str2 is: " << length << endl << endl;

    cout << "Use the find function to find various sub strings in str1\n";
    pos = str1.find("gram");
    cout << "\"gram\" first occurs in str1 at position: " << pos << endl;

    pos = str1.find("GRAM");
    cout << "\"GRAM\" is not in str1, so string::npos is returned: " << pos << endl;

    pos = str1.find(str3+"as");
    cout << "\"" << str3 + "as" << "\" is found in str1 at position: " << pos << endl;
    return 0;
}
