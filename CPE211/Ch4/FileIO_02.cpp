//
// Chpater 04 program 2: Ch_04_02.cpp
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

   // what happens if we use single quotes indicating a character
   // but we put in more than 1 character?
   ch1 = '1234567';
   cout << "ch1: " << ch1 << endl << endl;

   // character arithmetic.  characters are stored 
   // as integers.  character 1 has integer value 49 and
   // character 2 has integer value 50
   ch1 = '1';
   ch2 = '2';
   cout << "ch1 * ch2 = " << ch1*ch2 << endl << endl;

   cout << "Type in: \"a b c d\"  ";
   
   // try to use the get function with a string variable
   // as an argumente - compile error
   //cin.get(str1); // try to read in the 'a'


   // note input statements never have endl in them - ony cout statements
   cin.get(ch1); // read in the 'a'
   cout << ch1 << endl;

   cin.get(ch1); // read in the space - get does not skip characters
   cout << ch1 << endl;

   cin.get(ch1); // read in 'b'
   cout << ch1 << endl;

   cin.get(ch1); // read in the space - get does not skip characters
   cout << ch1 << endl;

   cin.get(ch1); // read in 'c'
   cout << ch1 << endl;

   cin.get(ch1); // read in the space - get does not skip characters
   cout << ch1 << endl;

   cin.get(ch1); // read in 'd'
   cout << ch1 << endl;
   cout << "*******************************\n";

   cout << "read one more character from the input line\n";
   cout << "ch1 is initialized to A\n";
   ch1 = 'A';

   // is this the end of the input stream?
   // what happens with the following
   // when the get function is used, the end of line character remains
   // on the input stream, and it is read with the following cin.get 

   cin.get(ch1);

   // because ch1 contains the newline character, when it
   // is output, it acts like the line termination
   cout << "Reading the \\n character from the input line:\n" << endl;
   cout << "Character read is: " <<ch1 << endl;

   cout << "*******************************\n\n";
   return 0;
}
