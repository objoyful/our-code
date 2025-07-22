#include <iostream>
#include <iomanip> // for setw
using namespace std;

// Examples of two dimensional arrays with functions 
// This example is an expansion of Ch_12_08.cpp 

// Shows the difference between using an array declared 
// by normal variable declaration methods versus one declared
// using a typedef statement

// Declare the constants and the typedef of the array as globals
// so that the functions have access to them
const int ROWS = 5;  // number of rows in the array
const int COLS = 5;  // nbumber of columns in the array

// define IntArray to be a DataType that is a two-dimensional
// array of integers with ROWS rows and COLS columns
typedef int IntArray[ROWS][COLS];

// functions used in this program illustrate the convenience of using the
// typedef statement versus not using it.  These show the differences in
// the two valid methods for using arrays with functions
void ArrayInit1(IntArray); // prototype using a typedef
void ArrayInit2(int[][COLS]); // prototype without a typedef
void PrintArrays(IntArray, int[][COLS]); // prototype with a typedef and without a typedef

int main() {
    // The following two declarations show the differences between using a typedef
	// statement and the standard declaration for a two-dimensional array 
	// declare grid to be a variable of the DataType IntArray - a 2 dim int array
	IntArray grid;
	int arr[25];

	// declare grid2 to be a two-dimensional integer array
	int grid2[ROWS][COLS];

	cout << "\n\nFor the following outputs, \ngrid is defined using: IntArray grid;\n";
	cout << "grid2 is defined using: int grid2[ROWS][COLS]\n";
	cout << "*****************************************************************************\n\n";

	// call the initialization functions for the arrays;
	ArrayInit1(grid); // initialize a typedef array using a typedef parameter
	ArrayInit2(grid2);// initialize using a standard declaration with a standard parameter
	ArrayInit1(arr);
	for (int i = 0; i < 25; i++)
	  cout << arr[i] << " " << endl;

	// output the arrays to see the results
	cout << "Array grid is printed out under GRID and it was initialized\n";
	cout << "using the function ArrayInit1.  The array grid2 is printed out\n";
	cout << "under GRID2 and is was initialized using the function ArrayInit2.\n";
	cout << "\n\n\tGRID\t\t\tGRID2\n";

	PrintArrays(grid, grid2);  // grid and grid2 match up with the parameter that matches the
							 // way in which they were declared

	// Note, that it is possible to use the arrays in either
	// function.  Provided both arrays have the same dimensions
	// this will work.  However, if the dimensions are changed, problems
	// may occur - but only if one of the arrays is declared
	// with literal values.  Here I have used defined constants,
	// so changing one of them results in a change to both arrays

	// swap rolls of grid2 and grid.  As long as they are declared of the same size, then
	// no problem is encountered.
	ArrayInit1(grid2);
	ArrayInit2(grid);

	// output the arrays to see the results
	cout << "Array grid2 is printed out under GRID2 and it was initialized\n";
	cout << "using the function ArrayInit1.  The array grid is printed out\n";
	cout << "under GRID and is was initialized using the function ArrayInit2.\n";
	cout << "\n\n\tGRID2\t\t\tGRID\n";

	PrintArrays(grid2, grid);

	return 0;
}

void ArrayInit1(IntArray arr) {
	int row, col; // loop index values
	for (row = 0; row < ROWS; row++)
		for (col = 0; col < COLS; col++)
			arr[row][col] = row + col;
}

void ArrayInit2(int arr[][COLS]) {
	int loop, row, col; // loop index values
	for (loop = 0; loop < ROWS * COLS; loop++) {
		// find the row number based on how many columns there are
		// use integer math.  When loop is between 0 and 4, row
		// will be 0.  when loop is between 5 and 9, row will be 1, etc
		row = loop / COLS;

		// for a particular row, determine the column position
		// for loop between 0 and 4, col = loop - 0.  for loop between
		// 5 and 9, col = loop - 5, etc.
		col = loop - row * COLS;

		arr[row][col] = row * col;
	}
}

void PrintArrays (IntArray grid, int grid2[][COLS]) {
	int row, col; // loop index values
	for (row = 0; row < ROWS; row++) {
		// print out a row from grid
		for (col = 0; col < COLS; col++)
			cout << setw(4) << left << grid[row][col];

		// print out 6 spaces betwwen the two grids
		cout << setw(6) << left << " ";

		// print out a row from grid2
		for (col = 0; col < COLS; col++)
			cout << setw(4) << left << grid2[row][col];

		// terminate the current row
		cout << endl;
	}
	cout << endl;
}