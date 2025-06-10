//
// Chpater 04 program 1: Ch_04_01.cpp
// examples of using cin and an explanation of 
// the reading marker
// Remember that cin will skip all leading white spaces
// therefore, all blanks in the line will be ignored
#include <iostream>
#include <string>
using namespace std;
int main()
{
   string str1, str2;
   char ch1, ch2;

   // need the A so that I can type in the line required
   // This allows for printing out the information as outlined
   // without the A, the initial set up information could not be entered
   // read in the char A and do not use it.
   // that leaves this is an entire line in the input buffer
   //
   cout << "Type in: \"AThis is an entire line\"  ";
   cin >> ch1;
   cout << "The program will read a string, 2 chars, 2 strings\n";
   cout << "2 more chars and then another string\n";
   cout << "*******************************\n\n";
   
   // place the line on the screen for comparison to what is read
   cout << "This is an entire line\n"; 
   cout << "----------------------\n";
   
   // input a string, and then output it.  do not use endl so that all
   // outputs are put on the same line
   // This reads in the word "This"
   cin >> str1;
   cout << str1;  

   // input 2 chars and output them;
   // blank space is ignored, and i and s are read
   cin >> ch1 >> ch2;
   cout << ch1 << ch2;

   // input two strings.  blank space is ignored, and an is read
   // blank is ignored and entire is read
   cin >> str1 >> str2;
   cout << str1 << str2;

   // input 2 chars and output them
   // blank is ignored and l and i are read
   cin >> ch1 >> ch2;
   cout << ch1 << ch2;

   // input a string and output it.  ne is read 
   cin >> str1;
   cout << str1 << endl;

   return 0;
}

