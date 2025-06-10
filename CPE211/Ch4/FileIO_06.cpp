//
// *****   Program Ch_04_07.cpp   ***********
// This program illustrates possible errors with
// incorrect data entry
#include <iostream>
#include <string>

using namespace std;

int main()
{
   int int1, int2;
   float flt1;


   // correct data reading and no fail state
   int1 = int2 = -99; flt1 = -99;
   cout << "First correct entry and no fail state\n";
   cout << "Initialized values:  ";
   cout << "int1=" << int1 << ", flt1=" << flt1 << ", int2=" << int2 << endl;

   cout << "using an input stream of 12 1.5 15\n";
   cout << "Read one integer, one float, and one integer: " ;
   cin >> int1 >> flt1 >> int2;

   cout << "int1=" << int1 << ", flt1=" << flt1 << ", int2=" << int2 << endl;
   cout << "*******************************************\n\n";

   // No fail state, error in data entry
   int1 = int2 = -99; flt1 = -99;
   cout << "now incorrect data entry and no fail state\n";
   cout << "Initialized values:  ";
   cout << "int1=" << int1 << ", flt1=" << flt1 << ", int2=" << int2 << endl;

   cout << "using an input stream of 121.5 15\n";
   cout << "Read one integer, one float, and one integer: " ;
   cin >> int1 >> flt1 >> int2;

   cout << "int1=" << int1 << ", flt1=" << flt1 << ", int2=" << int2 << endl;
   cout << "*******************************************\n\n";

   // Input stream put into fail state mode
   int1 = int2 = -99; flt1 = -99;
   cout << "put input stream into fail state mode\n";
   cout << "Initialized values:  ";
   cout << "int1=" << int1 << ", flt1=" << flt1 << ", int2=" << int2 << endl;

   cout << "using an input stream of 12.5 15 16.1\n";
   cout << "Read one integer, one integer, one float: " ;
   cin >> int1 >> int2 >> flt1;

   cout << "int1=" << int1 << ", int2=" << int2 << ", flt1=" << flt1 << endl;
   cout << "*******************************************\n\n";

   cout << "input stream is in the fail state mode, so the read from \n";
   cout << "the input stream below is skipped.\n";
   cout << "enter a number: ";

   cin >> int2;
   cout << "\nnext line after cin, int1 = " << int1 << "  int2 = " 
        << int2 << "   flt1 = " << flt1 << "\n";

   return 0;
}
