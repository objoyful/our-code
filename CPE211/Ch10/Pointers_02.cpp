// Pointers to a structure example
// Pointers program 2: Pointers_02.cpp

#include <iostream>
using namespace std;

struct Nest {
    int num;
    int num2;
};

struct Name {
    string name;
    int id;
    Nest myNum;
};

int main() {

    //int* intptr =  0x7fff84456f40;
    Name person;        // structure variable
    Name *namePtr;    // pointer variable for structures of type Name
    namePtr = nullptr;  // valid in c++11

    namePtr = &person;      // assign memory address of person
                            // to the Name pointer 
    person.name = "Ron";
    person.id = 123;
    person.myNum.num = 256;

    // output structure values using the pointer
    // First use the -> selection operator - note 
    // no dereferencing of the pointer is necessary

    cout << "Name: " << namePtr -> name << endl;
    cout << " Num: " << namePtr -> myNum.num << endl;

    // output structure value by dereferencing the
    // pointer variable and using the . member selector
    cout << "Id:   " << (*namePtr).id << endl;
    cout << "***************************\n";

    // assign a new value to the members

    (*namePtr).name = "Sam";
    namePtr -> id = 456;

    // compile error for the following
    //*namePtr.name = "Ron";

    cout << "Name: " << namePtr -> name << endl;
    cout << "Id:   " << (*namePtr).id << endl;

    cout << "******************************\n";
    cout << "Increment the pointer to the structure\n";
    cout << "size of Name is: " <<  sizeof(Name) << endl;
    cout << "size of Nest is: " << sizeof(Nest) << endl;
    cout << "size of string is: " << sizeof(string) << endl;
    cout << "size of int is: " << sizeof(int) << endl;
    cout << "Pointer memory contained: " << namePtr << endl;
    namePtr++;
    cout << "Pointer memory now contains: " << namePtr << endl;

    return 0;
}
