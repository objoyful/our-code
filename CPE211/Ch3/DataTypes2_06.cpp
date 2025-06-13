//
// Chpater 03 program 6: Ch_03_06.cpp
#include <iostream>
#include <iomanip> // for using setw and setprecision
#include <climits> // for max integer values
#include <string> // so that the string class can be used
using namespace std;
int main()
{
    string str1 = "This is a programming class";  
    string str2 = "12345"; // str2 contains the substring,

    // output what is contained in string1, with a position indicator
    cout << endl;
    cout << "Substrings will be found in the following string:\n";
    cout << "      0123456789012345678901234567890\n";
    cout << "str1: " << str1 << endl << endl;

    // Look at various substring values
    // the substrings are output between the arrow indicators
    // of ==>  and  <==

    // Length of 0 attempt - null string
    str2 = str1.substr(4,0);
    cout << "str1.substr(4,0) should return null string\n";
    cout << "str2 contains the null ==>" << str2 << "<== string\n";

    // two valid attempts - one with literals, one using find function
    str2 = str1.substr(6,5);
    cout << "\nstr1 substring (6,5) is ==>" << str2 << "<==" << endl;

    cout << endl << "substring of str1 starting with 'pro'\n" << "and containing 8 characters\n";
    str2 = str1.substr(str1.find("pro"),8);
    cout << "str1 substring (str1.find(\"pro\"),8) is ==>" << str2 <<"<==" <<  endl;

    // substring going past end of string
    cout << "\nExtracting beyond the end of the string is okay\n";
    str2 = str1.substr(20,20);
    cout << "str1 substring(20,20) is ==>" << str2 << "<==" << endl;

    // substring starting at position 1
    str2 = str1.substr(1,5);
    cout << "\nstr1 substring(1,5) is ==>" << str2 << "<==" << endl << endl;

    cout.flush(); // make sure the above is printed

    //cout << "Substring with a negative starting position: " << endl;
    // this results in a runtime error with out of range substring error
    // str2 = str1.substr(-40,3);
    //cout << "str2:"  << str2 << "<==\n";

    // here length is -3, -3 will be converted to a large
    // positive number due to the way unsigned integers are
    // stored in the computer.  therefore , the rest of the
    // string from the starting position will be pulled out
    // as the substring
    str2 = str1.substr(4,-3);
    cout << "Substring starting at position 4 with length -3\n";
    cout << "str2:"  << str2 << "<==\n\n";

    cout << "-3 assinged to unsigned integer data types becomes\n";
    cout << "a large positive number\n";
    cout << "Unsigned integer max: " << UINT_MAX << endl;
    cout << "Unsigned long max: " << ULONG_MAX << endl;
    cout << "-3 assigned to unsigned int: " << unsigned(-3) << endl;
	 cout << "-4294967280 assigned to unsigned int: " << unsigned(-4294967280) << endl;
    cout << "-3 assigned to unsigned long: " << (unsigned long)(-3) << endl << endl;

    cout << "\nThe following causes an abort due to starting position\n";
    cout << "Attempting str1 substring (40,3):\n";
    cout << "Press enter to continue: ";
    string line;
    getline (cin,line,'\n');
    cout << endl;
    str2 = str1.substr(40,3);
    cout << str2;
    // starting beyond the end of the string

    return 0;
}
