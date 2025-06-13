//
// *****   Program Ch04_2.cpp   ***********
// examples of using the get function,
// and the getline function.    The get function does not
// skip leading white spaces,  

#include <iostream>
#include <string>
using namespace std;
int main()
{
   string str1, str2;
   char ch1, ch2;
   cout << "read in a line using the getline function\n";
   
   // Example of the getline function
   cout << "\n\nEnter in a line: ";
   getline(cin,str1,'\n'); // reads all characteres in the input stream

   // until the new-line charcater is read.  In this case, the 
   // remnants of the last line entered

   // with getline, the end of line character is removed, 
   // so the next input statement following the getline 
   // is waiting for an input.

   cout << "Input line is: " << str1 << "<==" << endl;
   cout << "*******************************\n";
   cout << "read one more character from the input line\n";
   cout << "This time a letter must be entered.\n";
   cout << "ch1 is initialized to A\n";
      
   // Is this the end of the line?  
   // or is there still some information
   // in the input stream?
   ch1 ='A';
   cin.get(ch1);
   cout << "Letter contained in char var ch1: " << ch1 << endl;
   cout << "*******************************\n";

   return 0;
}
