// Arrays Program 5: Arrays_05.cpp    

#include <iostream>
#include <iomanip>
using namespace std;

// This program illustrates the concept of using a typedef
// statement to make array declarations.
// by using a typedef statement, there is less risk of going
// out of bounds when accessing array elements, it is easier
// to make changes as needed.

// use a defined constant to control the array size

const int ARRAY_SIZE = 10; 

// Define IntArray to be a DataType that is an array of integers
// and has a size of ARRAY_SIZE 

typedef int IntArray[ARRAY_SIZE]; 

int main() {
    int k; //loop index

    // declare an identifier  position to be of type IntArray.  
    // This is the same as using int position[10]

    IntArray position; // position is a 0ne-d array of ARRAY_SIZE integers
    IntArray position2;// position2 is a 0ne-d array of ARRAY_SIZE integers

    // initialize the arrays.  position is assigned the index value
    // position2 is assigned ARRAY_SIZE - index value

    for (k = 0; k < ARRAY_SIZE; k++) {
        position[k] = k;
        position2[k] = ARRAY_SIZE - k;
    }

    // output the values of the arrays.  If they were not valid arrays
    // then values assigned to position2 would overwrite those values
    // assigned to position

    cout << left << setw(8) << "index" << setw(20) << "Position" << "Position2\n";
    cout << setw(8) << "-----" << setw(20) << "--------" << "---------\n";

    for (k = 0; k < ARRAY_SIZE; k++)
        cout << setw(8) << k << setw(20) << position[k] << position2[k] << endl;
    
    cout << endl;
    return 0;
}
