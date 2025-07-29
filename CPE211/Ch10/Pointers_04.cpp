// Pointers Program 4: Pointers_04.cpp
// pointer comparison example
#include<iostream>
#include <cstdlib>

using namespace std;

int main() {
    int *intPtr1;
    int *intPtr2;

    // nullptr valid for c++11
    intPtr1 = nullptr;

    int number = 50; 
    int num = 40;

    intPtr1 = &number;
    intPtr2 = &num;



    // do not deallocate memory that is not allocated using the new
    // function.
    // What happens if we delete memory for a variable not assigned by
    // new.  An error occurs and the program is aborted

    // deallocate intPtr1 which is trying to delete memory location of
    // number 

    //   comment out illegal block of code
    /*
        cout << "number before delete is: " << number << endl;
        delete intPtr1;  // this is not allowed - results in abort of program
        cout << "Value after delete is: " << number << endl;
    */



    // what about using new for memory allocation to a pointer and then
    // changing the pointer to something else
    // // results in the same error as before

    intPtr1 = new int;
    cout << "address of number(regular variable): " << &number << endl;
    cout << "address assigned to intPtr1(declared with new): " << intPtr1 << endl;
    cout << endl;

    *intPtr1 = 555;
    intPtr2 = intPtr1; // assign memory address in Ptr1 to Ptr2
    intPtr1 = &number;

    cout << "New used to assign memory to intPtr1, then \n";
    cout << "intPtr2 = intPtr1 is executed after assigning 555 to intPtr1\n";
    cout << "intPtr1 given address of number\n";
    cout << "value of intPtr1: " << *intPtr1 << endl;
    cout << "value of intPtr2: " << *intPtr2 << endl;
    cout << "value of number: " << number << endl << endl;

    //delete intPtr1;  // gives an error and program aborted

    delete intPtr2;

    cout << "Memory deallocated from intPtr2\n";

    cout << "value of intPtr1: " << *intPtr1 << endl;
    cout << "value of intPtr2: " << *intPtr2 << endl;
    cout << "value of number: " << number << endl;

    return 0;
}