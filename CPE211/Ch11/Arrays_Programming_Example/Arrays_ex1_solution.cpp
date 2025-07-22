//******************************************************************
// Lecture Example Chapter 12 #1
// Ron Bowman
// 
//
// Sample of Chapter  12 material 
// Using one-dimensional arrays to hold characters entered on one line
// Maximum number of characters is 256.
// Characters entered are to be output in reverse order.  Use functions
// to read and output the characters. 

//******************************************************************
#include <iostream>  // for standard input and output

using namespace std; //include all basic C++ declarations

const int MAX = 256;

void ReadData(char [], int&);  // function to obtain characters entered
void PrintData(const char[], int); // output the characters in reverse order

int main()
{
    char characters[MAX];    // holds the characters read in from the input
    int numValues;           // Hold the number of chars read from input
    
    // Read in the characters from the input
    ReadData(characters, numValues);
    
    // Print the characters in reverse order
    PrintData(characters, numValues);
    
    return 0;
}
void ReadData(char chars[], int& index)
{
     // this function reads in the chars on a single line until the new line
     // character is encountered.  The chars are stored in a one-dimensional
     // array.  Assume that less than 256 characters are provided

     char ch;               // character read from the input stream
     index = 0;              // number of characters read
     
     cout << "Enter in up to 256 characters: ";
     cin.get(ch);         // use the get function to get all characters
     while(ch != '\n')    // if character read is the newline character, end loop
     {
         chars[index] = ch;  // assign character read tot he array
         index++;            // increment the array index counter
         cin.get(ch);        // try to read another character from the input stream
     }
     if (index > MAX)
     {
         cout << "Error!!! More than 256 characters were entered on the line\n";
         cout << "Program is designed for 256 characters only!!\n";
     }
}
void PrintData(const char chars[], int number)
{
     int index;      // loop control variable
     for (index = number-1; index >= 0; index--)
     {
         cout << chars[index];   // output characters entered in reverse order
     }
     cout << endl;
}
