// Pointer Program 1: Pointers_01.cpp
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int x,y,z;
    int *intPtr;
    int *intPtr2;

    int a,b,c;
    float num = 50.5;
    int number = 50;
    
    // is this okay? increment a float?
    num++;
    cout << "num++ = " << num << endl;

    cout << "Initial numbers, pointer unassigned:\n";
    cout << "Number: " << number << endl;
    cout << "intPtr: " << intPtr << endl;
    cout << "*intPtr: " << *intPtr << endl;  // may or may not cause a runtime error
    cout << "&Number: " << &number << endl << endl;
    cout << "&intPtr: " << &intPtr << endl;
    cout << "size of int ptr:  " << sizeof(intPtr) << endl << endl;

    //cout << "Floating point number to integer pointer\n";
    //intPtr = &num;  // compile error
    //cout << "intPtr: " << intPtr << endl;
    //cout << "*intPtr: " << *intPtr << endl;


    //try to assign a regular integer to an integer pointer
    //intPtr = number;  // compile error

    intPtr = &number;
    cout << "increment and derefence "  << *intPtr <<  " ptr value: " << intPtr << endl;
    *intPtr++;
    cout << "increment and derefence "  << *intPtr << " ptr value: " << intPtr <<  endl;
    // delete intPtr; // runtime error of segmentation fault 

    intPtr = &number;
    cout << "intPtr has address of number\n";
    cout << "intPtr: " << intPtr << endl;
    cout << "*intPtr: " << *intPtr << endl;
    *intPtr = 60;
    cout << "number: " << number << endl << endl;

    int num2 = 0;
    cout << "Increment pointer by 1\n";
    intPtr++;
    cout << "intPtr: " << intPtr << endl;
    *intPtr = 5;
    num2 = *intPtr--;
    cout << "num2 = " << num2 << endl << endl;

	//cout << "*(intPtr)--: " << *(intPtr)++ << endl;
    *intPtr--;
    cout << "num2 = " << num2 << endl;
	cout << "number = " << number << endl;
    cout << "intPtr: " << intPtr << endl;
    //cout << "*intPtr--: " << *(intPtr)++ << endl;
    
    return 0;
}

