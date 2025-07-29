// Pointer program 7: Pointers_07.cpp

#include<iostream>
#include<iomanip>
#include<cstddef>

using namespace std;

int main() {
    string line;
    int *intPtr;
    intPtr = NULL;
    intPtr = 0;
    intPtr = nullptr;
    cout << "NULL for null ptr: " << NULL << endl;
    // compile error for below
    // cout << "nullptr for null ptr: " << nullptr << endl;
    //    /*
    //    this works for the old ABI (application binary interface)
    //    to use this, use the flag -D_GLIBCXX_USE_CXX11_ABI=0
    //    this ABI also gives strings as 8 bytes, the new one makes them 32 bytes.
    
    int index;
    int myArray[20];
    
    //     */
    
    /*
    // this is the order for the new ABI that blackhawk runs by default
    int index;
    int myArray[20];
    */
    
    intPtr = new int;
    cout << "Dynamic address assigned to intPtr: " << intPtr << endl;
    cout << "Memory Address assigned to intPtr: " << &intPtr << endl;
    delete intPtr;

    cout << "\ninitialize myArray to 0 through 95\n";

    for (index = 0; index < 20; index++) {
        myArray[index] = index * 5;
    }

    // have intPtr point to the myArray declared
    // same as intPtr = &myArray[0];

    intPtr = myArray;
    // what about the following
    // intPtr = &myArray;  // is this possible??
    

    cout << "Memory address of variable index: " << &index << endl;
    cout << "Memory address of myArray[]: " << &myArray[0] << endl << endl;

    cout << "Memory location stored in intPtr: " << intPtr 
         << "  Value at that memory location: " << *intPtr 
         << endl<< endl;
    cout << "intPtr[2] = " << intPtr[2] << endl;

    cout << "pause - hit enter to continue: ";
    getline(cin, line, '\n');

    for (index = 0; index < 20; index++) {
        cout << "Memory location stored in intPtr: " << intPtr 
             << "  Value: " << setw(2) << *(intPtr) 
             << "  intPtr incremented" << endl;

        // increment pointer memory location by 1 integer 
        // worth of bytes (which is 4)

        intPtr++;  
    }

    cout << "\nMemory address stored in intPtr: " << intPtr << endl;
    cout << "out of bounds memory value at that location: " << *intPtr << endl;

    // if lucky the following will increment intPtr to the memory
    // address of index and change index

    cout << "\nTry to overwrite index by incrementing the pointer\n";
    cout << "to the myArray.  intPtr is incremented by 1 then 3000 assigned\n";
    cout << "current memory location stored in intPtr: " << intPtr << endl;
    cout << "Index value is: " << index << endl;

    intPtr++;

    cout << "New memory location stored in intPtr: " << intPtr << endl;
    cout << "Memory location assigned to index:    " << &index << endl;

    *intPtr = 3000;
    cout << "Index value is now: " << index << endl;
    cout << "access myArray[21] and set it to 1000\n";
    myArray[21] = 1000;
    cout << "Index is now: " << index << endl;

    return 0;
}
