// Arrays Program 3:  Arrays_03.cpp

#include <iostream>
using namespace std;

// examples showing initialization of an array during declaration.
// use of enumeration types with arrays

int main()
{
    int j,k;  // loop counter variables

    // declare an array with 5 elements with values 0,1,2,3,4
    //int points[5] = {1};   // this compiles and runs
    int points[5] = {1,2,3,4};   // this compiles and runs
    //int points2[5] = {1,2,3,4,5,6};  // does not compile
    //int points[5] = {0,1,2,3,4};

    //int myarray[10][10][10][10][10][10];  // works
    //int myarray[10][10][10][10][10][10][10]; // seg fault
    //int myarray[5][5][5][5][5][5][5][5][5][5];   // compiles, but gives seg fault
    //int myarray[5][5][5][5][5][5][5][5];   // compiles and runs
    //int myarray[5][5][5][5][5][5][5][5][5];  // compiles and runs
    //int myarray[100][100][100][100];
    //int myarray[10][10][10][10][10][10][10][10][10][10];  // compiles but gives seg fault

    // 24 dimensional array 2^24 = 16.777 Million, so 67.109 MBytes required
    // This segmentation faults during run time
    //int array1[2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2];
    //int array1[2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2];

    // 20 dimensional array 2^20 = 1.0486 Million, so 4.1943 MBytes required
    // This compiles and runs 
    int array2[2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2];

    // 28 - dimensional array - compiles and runs 
    int array3[1][1][1][1][1][1][1][1][1][1][1][1][1][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2];

    // can omit the size of a one-dimensional array in the declaration when the
    // values are being assigned during declaration

    //int speeds[] = { 45, 55, 65, 70, 75, 80};
    int speeds[] = {25, 35, 45, 55, 65, 70, 75, 80};

    // Usually when arrays are declared in the above fashion, 
    // a constant is defined to be the number of elements in the
    // array.  Then if the number of elements in the array needs
    // to be changed, it is easy to do and the constant associated
    // with the number of elements is updated.  These constants
    // are used in the program when dealing with the arrays.

    const int NUM_PTS = 5;
    const int NUM_SPEEDS = 6;

    // another way to determine the number of elements is to perform the following:
    // using the size of function to divide the size of the array by the size of a 
    // single array entry (int in this case)

    const int NUM_PTS2 = sizeof(points) / sizeof(int);
    const int NUM_SPEEDS2 = sizeof(speeds) / sizeof(int);

    // output the values for the constants declared above.  These values show
    // two different ways of assigning values to constants for use with arrays.
    cout << "\nTwo examples of determining the number of elements in an array\n";
    cout << "---------------------------------------------------------------\n";
    cout << "NUM_PTS = " << NUM_PTS << endl;
    cout << "NUM_PTS2 = " << NUM_PTS2 << endl;
    cout << "NUM_SPEEDS = " << NUM_SPEEDS << endl;
    cout << "NUM_SPEEDS2 = " << NUM_SPEEDS2 << endl;

    // output the arrays declared above to show that initialization did occur
    // first the points array

    cout << "\nArrays were initialized during declaration\n";
    cout << "---------------------------------\n";
    cout << "output of the points array:\n";
    for (j = 0; j < NUM_PTS; j++)
        cout << points[j] << "   ";
    cout << endl << endl;

    // now the speeds array
    cout << "Output for the speeds array:\n";
    for (j = 0; j < NUM_SPEEDS2; j++)
        cout << speeds[j] << "   ";
    cout << endl << endl << endl;

    return 0;
}
