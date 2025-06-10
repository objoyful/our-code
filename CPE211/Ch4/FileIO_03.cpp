//
// ***** Program Ch4_3.cpp ***********
// example of using the ignore function.
// the ignore function is really only useful
// when reading from files. The extraction operator >> 
// ignores any leading white spaces - including the
// new line character.


#include <iostream>
#include <string>
#include <climits> // for INT_MAX

using namespace std;
int main()
{
    string str1, str2; // hold the strings read from the input
    char ch1; // dummy character holder

    // The ignore function is used to remove extraneous information
    // from the input stream. 
    // use the leading A to allow entry of the entire line
    // into the input stream before it is used.

    cout << "A string value is read from the input stream, followed\n";
    cout << "by an ignore of 9 characters followed by a string value\n";
    cout << "being read\n";

    cout << "Type in: \"AThis is an entire line\" ";
    cin >> ch1;

    cout << "*******************************\n\n";

    // place the line on the screen for comparison to what is read
    cout << "This is an entire line\n"; 
    cout << "----------------------\n";

    // read in a string value from the input. The reading marker is moved to
    // the space between This and is. 
    cin >> str1;
    cout << str1;

    // skip 9 characteres in the input stream or to the end of line
    // whichever comes first. In our case, we will skip 9 characters
    // This should put the reading marker on the 't' in 'entire'
    cin.ignore(9,'\n');

    // read in another string value and output it. This should be the word
    // tire from entire
    cin >> str1;
    cout << str1 << endl;

    // ignore rest of line. Move cursor to the next line or endo of file.
    cout << "INT_MAX = " << INT_MAX << endl;
    cin.ignore(INT_MAX,'\n');
    //cin.ignore(9,'\n');
    cout << "Enter a word: ";
    cin >> str1;
    cout << "String read is: " << str1 << endl;

    return 0;
}
