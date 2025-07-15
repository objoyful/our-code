// Structures Example Program 4: Structures_04.cpp

#include <iostream>
#include <iomanip>

using namespace std;

// example showing the difference between a union and a 
// structure.  Unions reuse the same memory for each of
// their members.  Structures allocate memory for each member

// Unions cannot have string variables as members

union Union2 { // union declaration
    double average;
    char middleInitial;
    int id;
};

// create a hierarchical union - also used to show
// that memory requirement of a union depends on the
// size of its largest member

union Union { // union declaration
    float average;
    char middleInitial;
    int id;
    Union2 union2var;
};

// declare a structure with identical members
struct Structure {
    float average;
    int id;
    char middleInitial;
    long double value;
    //string name;  // not possible to use when structure declared in union
};

// what is possible to have in a Union
// strings are not allowed, structures are as long as they
// do not contain a string.  character arrays are possible
// as well

union Union3 {
    int id;
    Structure possible;
    char name[65];    // for this declaration size of Union3 is 80 bytes
    //char name[60];  // for this declaration size of Union3 is 64 bytes
    //string notPossible;  // no strings allowed in a union
};

int main() {
    Structure structVar;
    Union unionVar1, unionVar2;

    // structures must allocate memory for all members
    // unions only need the amount of memory necessary
    // to hold the largest member.

    // Check the memory allocation for the 
    // union and structure
    cout << "\nMemory allocation for various data types.  value shown\n";
    cout << "is the number of bytes of memory allocated\n";
    cout << "-------------------------------------------------------\n";
    cout << "Size for Union : " << sizeof(Union) << endl;
    cout << "Size for Union2 : " << sizeof(Union2) << endl;
    cout << "Size for Union3 : " << sizeof(Union3) << endl;
    cout << "Size for Struct: " << sizeof(Structure) << endl;
    cout << "Size of a float: " << sizeof(float) << endl;
    cout << "Size of a doubl: " << sizeof(double) << endl;
    cout << "Size of a longd: " << sizeof(long double) << endl;
    cout << "Size of a char : " << sizeof(char) << endl;
    cout << "Size of a int  : " << sizeof(int) << endl;
    cout << "Size of a uint : " << sizeof(unsigned int) << endl;
    cout << "Size of a long : " << sizeof(long) << endl;
    cout << "Size of a stri : " << sizeof(string) << endl;
    cout << endl;

    // assign some values to a struct variable and a 
    // union variable then output the values.  
    // Only the last value assigned to the
    // union will be correct 100% of the time 
    // (there are possibilities where other members 
    // may appear to be correct)

    cout << "assigning the following values to members"
         << " of the structure\n";
    cout << "and the union variables.\n";
    cout << setw(25) << "id value:   45\n";
    cout << setw(25) << "Middle Initial:    A\n";
    cout << setw(25) << "average: 65.5\n\n";
    cout << "-------------------------------------------------------\n\n";

    structVar.id = 45;
    structVar.middleInitial = 'A';
    structVar.average = 65.5;

    // for the union, make 2 assignments, and then 
    // copy the first union variable to the second one, 
    // and then make the last assignment to 
    // the first union variable
    // This will show that the last assignment 
    // to the union variable is the one that is valid.

    unionVar1.id = 45;
    unionVar1.middleInitial = 'A';
    unionVar2 = unionVar1;
    unionVar1.average = 65.5;

    // output the various values for the 
    //structure and union variables
    cout << setw(16) <<  "For structure:\n"; 
    cout << setw(16) << "id: " << structVar.id << endl;
    cout << setw(16) << "Middle Initial: " 
         << structVar.middleInitial << endl;
    cout << setw(16) << "Average: " 
         << structVar.average << endl << endl;

    cout << setw(16) << "For Union:\n";
    cout << setw(16) << "id: " << unionVar1.id << endl;
    cout << setw(16) << "Middle Initial: " 
         << unionVar1.middleInitial << endl;
    cout << setw(16) << "Average: " 
         << unionVar1.average << endl << endl;

    cout << setw(16) << "For Union2:\n";
    cout << setw(16) << "id: " << unionVar2.id << endl;
    cout << setw(16) << "Middle Initial: " 
         << unionVar2.middleInitial << endl;
    cout << setw(16) << "Average: " 
         << unionVar2.average << endl << endl;

    return 0;
}