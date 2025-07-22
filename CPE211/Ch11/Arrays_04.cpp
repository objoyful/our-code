// Chpater 12 program 4: Ch_12_04.cpp 

#include <iostream>
#include <string>
#include <climits>
using namespace std;

// Use of arrays with functions.  Arrays are always passed
// by reference in a function.  Therefore, C++ does not require
// the use of the & with the parameter in the function prototype
// and the function definition. Also, since arrays are passed by
// reference, the modifications to an array in the function are
// available to the caller of the function.  To avoid this
// problem, the key word const must be used as shown below

// function prototypes.  Note that a number is not required in
// the brackets in the prototype (This only applies to 
// one-dimensional arrays.  Two-dimensional arrays are slightly
// different.

const int MAX_SIZE = 10; // constant integer value

void InitArray(int[], int); // first parameter is a one dimensional array

// write out an array.  array is passed in as a constant - unchangeable 
void PrintArray(const int[], int);

void SortHighLow(int[], int); // sort the array passed in, return result via same array

// first array of SortLowHigh cannot be modified in the function
void SortLowHigh(const int[], int[], int); //sort an array and pass it out via a different array

int main() {
    string line; // used for program flow control

    int points[MAX_SIZE]; // declare points to be an array of 10
    // elements and each element is an integer

    int points2[MAX_SIZE]; // second 10 element array for use with SortLowHigh

    // initialize points using the InitArray function
    cout << "Initializing array points\n";
    InitArray(points, MAX_SIZE);

    // output the array after initialization to see the initial values
    // and their order
    cout << "\nWriting out array points:\n";
    PrintArray(points, MAX_SIZE);

    cout << "press return to continue: ";
    getline(cin, line);

    // use SortHighLow to sort points from highest to lowest and store those
    // results in the points array - reference parameter
    cout << "\nsorting points from highest to lowest\n";
    SortHighLow(points, MAX_SIZE);
    PrintArray(points, MAX_SIZE);

    cout << "press return to continue: ";
    getline(cin, line);

    // sort points from lowest to highest using SortLowHigh.  In this case,
    // points is passed in as a constant, so points2 holds the sorted array values
    cout << "\nsorting points from lowest to highest \n";
    SortLowHigh(points, points2, MAX_SIZE);

    // Write out the values contained in the arrays points and points2.
    // points should be unchanged from the previous output, and points2 
    // contains the sorting of points
    cout << "points2 array\n";
    PrintArray(points2, MAX_SIZE);

    cout << "points array\n";
    PrintArray(points, MAX_SIZE);

    // Example of a common mistake.  calling a function with an 
    // array element specified

//    PrintArray(points[MAX_SIZE], MAX_SIZE);
    // The above line gives a compile error

    return 0;
}

void InitArray(int array[], int elements) {
    // This function will initialize the array elements
    // to the index value squared
    for (int k = 0; k < elements; k++)
        array[k] = k * k;
}

void PrintArray(const int array[], int elements) {
    // This function will output the elements of the array
    // showing the index and the value of the corresponding elememt

    for (int k = 0; k < elements; k++)
        cout << k << ": " << array[k] << endl;

    // try to modify a constant array element value
    
      //array[4] = 30;
}

void SortHighLow(int array1[], int elements) {
    // This function sorts the array sent in, and returns the
    // sorted array to the caller by using the array as a reference
    // parameter
    // This function will put the array entries into the form of
    // Highest to lowest
    int temp;  // holds a value that needs to be swapped for sorting 

    // below is standard search and swap for sorting a list of values
    for (int k = 0; k < elements - 1; k++) {
        for (int j = k + 1; j < elements; j++) {
            if (array1[k] < array1[j]) {
                temp = array1[k];
                array1[k] = array1[j];
                array1[j] = temp;
            }
        }
    }
}
void SortLowHigh(const int array1[], int array2[], int elements) {
    // This function sorts the elements of array1, putting them in
    // the order from lowest to highest.  The sorted values are
    // returned using array2.
    // Any attempt to modify array1 in the function results in
    // a compile error.  Therefore the first thing that needs to
    // be done is assign all values of array1 to array2.
    int temp;
    int j, k; // loop indexes
    //
    // show that you cannot change a value in array1
    // array1[4] = 32;

    // since array assignment is not an allowable aggregate operation
    // elements must be assigned individually
    for (k = 0; k < elements; k++)
        array2[k] = array1[k];


    for (k = 0; k < elements - 1; k++) {
        for (j = k + 1; j < elements; j++) {
            if (array2[k] > array2[j]) {
                temp = array2[k];
                array2[k] = array2[j];
                array2[j] = temp;
            }
        }
    }
}