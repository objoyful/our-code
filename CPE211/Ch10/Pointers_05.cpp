// Pointer program 5: Pointers_05.cpp

// pointer comparison example
#include<iostream>
#include <cstdlib>

using namespace std;

int main() {
    int *intPtr1;
    int *intPtr2;

    int number = 50;
    int num = 40;

    intPtr1 = &number;
    intPtr2 = &num;

    cout << "\nnumber = " << number << "   num = " << num << endl;
    cout << "intPtr1 = &number,  intPtr2 = &num\n";
    cout << "*****************************************\n\n";

    cout << "Pointer 1 information:\n";
    cout << "intPtr1: " << intPtr1 << endl;
    cout << "*intPtr1: " << *intPtr1 << endl << endl;

    cout << "Pointer 2 information:\n";
    cout << "intPtr2: " << intPtr2 << endl;
    cout << "*intPtr2: " << *intPtr2 << endl << endl << endl;

    cout << "Initial assignment test\n";
    cout << "**********************************************\n";
    
    if (intPtr1 == intPtr2)
        cout << "--> pointers contain the same memory address\n";
    else
        cout << "--> pointers do not contain the same memory address\n";

    if (*intPtr1 == *intPtr2)
        cout << "==> values referenced by the pointers are the same\n";
    else
        cout << "==> values referenced by the pointers are different\n";
    
    cout << endl << endl;

    cout << "assign num to number and retest the pointers\n";
    cout << "**********************************************\n";
    
    number = num;
    if (intPtr1 == intPtr2)
        cout << "--> pointers contain the same memory address\n";
    else
        cout << "--> pointers do not contain the same memory address\n";

    if (*intPtr1 == *intPtr2)
        cout << "==> values referenced by the pointers are the same\n";
    else
        cout << "==> values referenced by the pointers are different\n";
    
    cout << endl << endl;

    cout << "assign address of number to intPtr2 and retest\n";
    cout << "**********************************************\n";
    
    intPtr2 = &number;
    if (intPtr1 == intPtr2)
        cout << "--> pointers contain the same memory address\n";
    else
        cout << "--> pointers do not contain the same memory address\n";

    if (*intPtr1 == *intPtr2)
        cout << "==> values referenced by the pointers are the same\n";
    else
        cout << "==> values referenced by the pointers are different\n";
    
    cout << endl;

    return 0;
}