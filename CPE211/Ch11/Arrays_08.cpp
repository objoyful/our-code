// Arrays Program 8: Arrays_08.cpp    

#include <iostream>
#include <iomanip> // for setw
using namespace std;

// Examples of two dimensional arrays

const int ROWS = 8;  // number of rows in an array
const int COLS = 5;  // number of columns in an array

// define IntArray to be a DataType that is a two-dimensional
// array of integers with ROWS rows and COLS columns

typedef int IntArray[ROWS][COLS];

int main() {

    int row, col, index; // loop counter variables

    // declare grid and grid2 to be a variable of the DataType IntArray
    // Therefore grid and grid2 are two dimensional arrays of integer elements
    // and the size of the arrays is ROWSxCOLS

    IntArray grid;  // grid and grid2 are test arrays for showing the
    IntArray grid2; // use of the typedef statement

    // Here are two methods to initialize a two dimensional (or
    // multi-dimensional with some additional work) arrays

    // Method 1: straightforward nested loops - use on grid

    for (row = 0; row < ROWS; row++)
        for (col = 0; col < COLS; col++)
            grid[row][col] = row + col;

    // Method 2: use a single loop and some math.  This method
    // is more in line with how multi-dimensional arrays are
    // stored in memory
    // here index goes from 0 to 24.  The first row uses index
    // values 0 to 4, the second row index values 5 to 9, etc

    for (index = 0; index < ROWS * COLS; index++) {
        // find the row number based on how many columns there are
        // using integer math.  When index is between 0 and 4, row
        // will be 0.  when index is between 5 and 9, row will be 1, etc
        row = index / COLS; 

        // for a particular row, determine the column position
        // for index between 0 and 4, col = index - 0.  for index between
        // 5 and 9, col = index - 5, etc.
        col = index - row * COLS;

        grid2[row][col] = row * col;
    }

    cout << "grid2[20] = " << grid2[20] << endl;
    cout << "grid2[20][3] = " << grid2[20][3] << endl;

    // output the arrays to see the results

    cout << "The arrays grid and grid2 are output.\n";
    cout << "Grid is initialized to values of row position + column position\n";
    cout << "Grid2 is initialized to values of row position * column position\n";
    cout << "\n\n\tGRID\t\t\tGRID2\n";

    for (row = 0; row < ROWS; row++) {
        // print out a row from grid
        for (col = 0; col < COLS; col++)
            cout << setw(4) << left << grid[row][col];

        // Place 6 spaces between the two grids
        cout << setw(6) << " ";

        // print out a row from grid2
        for (col = 0; col < COLS; col++)
            cout << setw(4) << grid2[row][col];

        // terminate the current row
        cout << endl;
    }

    // can we use a single loop and access the array elements
    // as a one dimensional array?

    return 0;
}