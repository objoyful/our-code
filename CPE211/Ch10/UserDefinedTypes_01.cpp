//  Chpater 10 program 1: Ch_10_01.cpp

#include <iostream>
#include <string>
using namespace std;

// This program contains various additional C++ operations
int main() {
    int num1, num2; // hold values for testing with conditional operator

    int num;		// all variables used with size of function
    float average;  // to illustrate memory requirements
    string line;
    char letter;
    int my_array[10]; // This is a one dimensional array

    // possible declaration? - no, unsigned is for integers only
    //unsigned float x;
    //
    //What is unsigned?
    unsigned y;
    cout << "unsigned size: " << sizeof(y) << endl;


    /*
    int float;  // declare a variable named float?
    float = 80;
    cout << "float = " << float << endl;
    //  */

    //    int if;

    // /*
    
    char main;   // declare a variable named main?
    main = 'b';
    cout << "main = " << main << endl << endl;

    // */

    cout << "using j = 5...\n";
    int j = 5;
    j = (j++) * 5;
    cout << "j = (j++)*5: " << j << endl;

    j = 5;
    j = (++j) * 5;
    cout << "j = (++j)*5: " << j << endl;

    j = 5;
    j = j++ * 5;
    cout << "j = j++*5: " << j << endl;

    // use the integer value returning operator - sizeof(  ) to
    // determine the number of bytes allocated to variables.
    // This operator can also be used with structures and arrays

    cout << "\n\nIllustration of the sizeof operator\n";
    cout << "Integer: " << sizeof(num) << endl;
    cout << "Integer: " << sizeof(int) << endl;

    cout << "float: " << sizeof(average) << endl;
    cout << "float: " << sizeof(float) << endl;

    cout << "string: " << sizeof(line) << endl;
    cout << "string: " << sizeof(string) << endl;

    cout << "char: " << sizeof(letter) << endl;
    cout << "char: " << sizeof(char) << endl;

    cout << "int array: " << sizeof(my_array) << endl;
    cout << "---------------------------------------------------\n\n";

    // // cast operation on variables.  Explicit coercion of
    // // variables showing that the type conversion is intentional

    // cout << "\nIllustration of Functional and Prefix coercion\n";
    // int num1, num2; // hold values for testing with conditional operator

    // int num;		// all variables used with size of function
    // float average;  // to illustrate memory requirements
    // string line;
    // char letter;
    // int my_array[10]; // This is a one dimensional array

    // // possible declaration? - no, unsigned is for integers only
    // //unsigned float x;
    // //
    // //What is unsigned?
    // unsigned y;
    // cout << "unsigned size: " << sizeof(y) << endl;


    // /*
    // int float;  // declare a variable named float?
    // float = 80;
    // cout << "float = " << float << endl;
    // //  */

    // //    int if;

    // // /*
    // char main;   // declare a variable named main?
    // main = 'b';
    // cout << "main = " << main << endl << endl;

    // // */

    // cout << "using j = 5...\n";
    // int j = 5;
    // j = (j++) * 5;
    // cout << "j = (j++)*5: " << j << endl;

    // j = 5;
    // j = (++j) * 5;
    // cout << "j = (++j)*5: " << j << endl;

    // j = 5;
    // j = j++ * 5;
    // cout << "j = j++*5: " << j << endl;

    // // use the integer value returning operator - sizeof(  ) to
    // // determine the number of bytes allocated to variables.
    // // This operator can also be used with structures and arrays

    // cout << "\n\nIllustration of the sizeof operator\n";
    // cout << "Integer: " << sizeof(num) << endl;
    // cout << "Integer: " << sizeof(int) << endl;

    // cout << "float: " << sizeof(average) << endl;
    // cout << "float: " << sizeof(float) << endl;

    // cout << "string: " << sizeof(line) << endl;
    // cout << "string: " << sizeof(string) << endl;

    // cout << "char: " << sizeof(letter) << endl;
    // cout << "char: " << sizeof(char) << endl;

    // cout << "int array: " << sizeof(my_array) << endl;
    // cout << "---------------------------------------------------\n\n";

    // cast operation on variables.  Explicit coercion of
    // variables showing that the type conversion is intentional

    cout << "\nIllustration of Functional and Prefix coercion\n";
    cout << "by type casting average = 75.5 to an int\n\n";
    average = 75.5;

    // convert a float to an integer using FUNCTIONAL NOTATION
    num = int(average);
    cout << "Using functional notation num = int(average): \n";
    cout << "num: " << num << "  average: " << average << endl << endl;

    // convert a float to an integer using PREFIX NOTATION
    num = (int)average;
    cout << "Using prefix notation: num=(int)average: \n";
    cout << "num: " << num << "  average: " << average << endl;
    cout << "---------------------------------------------------\n";

    return 0;
}
