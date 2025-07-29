// Pointers program 6: Pointers_06.cpp

#include<iostream>

using namespace std;

int main() {
    int alpha;
    int& intRef = alpha;    // reference variable must be assigned
    // when declared.

    int beta = 20;
    alpha = 30;

    cout << "\nalpha assigned to reference intRef\n";
    cout << "look at memory address for alpha and intRef\n";
    cout << " Memory address of alpha: " << &alpha << endl;
    cout << "Memory address of intRef: " << &intRef << endl <<  endl;
    
     // outputs the value of alpha
    cout << "Value of variable pointed to by intRef: " << intRef << endl;
    cout << "Value of the variable alpha: " << alpha << endl;
    cout << "************************\n\n";

    intRef = beta;  // assigns value of beta to intRef
    // which in effect assigns beta to alpha
    // intReg is still referencing alpha

    cout << "intRef assigned value of beta: " << intRef << endl;
    cout << "Alpha is now: " << alpha << endl << endl;

    intRef = 40;            // assigns 40 to alpha
    cout << "Value of alpha after assigning 40 to intRef: " << alpha << endl;
    return 0;
}