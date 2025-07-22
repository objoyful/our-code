// Chpater 10 program 4: Ch_10_04.cpp

#include <iostream>
#include <string>
using namespace std;
// This program shows examples of the enumeration type statement

// Declare the enumeration type as a global so that all functions
// have access to the new DataType 

// by setting JAN = 1, all other enumerators follow in numerical
// order increasing by 1.  Therefore DEC has a value of 12.
// Makes it easier when declaring the months.
// enum hello {HI,,BYE};

enum Month {JAN = 10, FEB = 20, MAR, APR, MAY, JUNE, JULY, AUG, SEP, OCT, NOV, DEC};
enum Change {PENNY = 1, NICKEL = 5, DIME = 10, QUARTER = 25};

// placing this enumeration type here results in multiply defined
// identifiers for the enumerators PENNY, NICKEL, DIME, QUARTER
// enum Change2 {PENNY = 1, NICKEL = 5, DIME = 10, QUARTER = 25};

int main() {
    // can we have name hiding with identifiers declared here
    // only variables of Change2 can use these enumerators
    // variables of data type Change cannot use any of the enumerators
    // enum Change2 {PENNY = 1, NICKEL = 5, DIME = 10, QUARTER = 25};
    // enum Change2 {ENNY = 1, ICKEL = 5, IME = 10, UARTER = 25};
    
    Month day;  // day is a variable of DataType Month;
    Change coin; // coin is a variable of DataType Change
    int value;	// used for implicit coercion of Enum values

    // how are enumerated data types and enumerators stored in memory
    cout << "size of Month: " << sizeof(Month) << endl;
    cout << "size of JAN: " << sizeof(JAN) << endl;
    //cout << "address of JAN" << &JAN << endl;

    day = FEB;
    if (day == 20)
        cout << "yes";

    cout << "\nAssignment of an enumerator to an enumerated varible\n";
    
    day = FEB;
    cout << "day contains the value for FEB: " << day << endl;
    
    coin = DIME;
    cout << "coin contains the value for DIME: " << coin << endl;

    //day = DIME;  // compile error
    //cout << "day contains the value for DIME: " << day << endl;


	cout << "Output JAN and DEC to see what incrementation occurs\n";
	cout << "with the first enumerator set to a value\n";
	cout << "JAN = " << JAN << " DEC = " << DEC << endl;
    
    day = Month(MAR + JAN);
    cout << "day = Month(MAR+JAN) results in day = " << day << endl;

    // Show implicit coercion from the enum DataType to an int
    cout << "\nIllustrating implicit coercion of the enum DataType\n";
	
    cout << "Assign the enumerator shown to the integer variable value\n";
    value = JUNE;
    cout << "value contains the number for JUNE: " << value << endl;
    
    value = QUARTER;
    cout << "value contains the number for QUARTER: " << value << endl;

    // use explicit type coercion to increment enumeration variables
    // can also uses it for assigning integer values to an enumeration
    // variable

    // Assignment using type casting 
    day = Month(10);
    coin = Change(26); // Assign an invalid value to coin 
	
    cout << "\nTypecasting the literal value to the indicated enumeration variable\n";
    cout << "day should have a value of 10: " << day << endl; 
    cout << "coin has an invalid value of : " << coin << endl;

    return 0;
}