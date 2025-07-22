//******************************************************************
// Lecture Example Chapter 12 #2
// Ron Bowman
// 
//
// Sample of Chapter  12 material 
// Using two dimensional arrays with named constants and a typedef statement. 

//******************************************************************
#include <iostream>  // for standard input and output
#include <iomanip>  // for setw()

using namespace std; //include all basic C++ declarations

const int ROWS = 3;
const int COLS = 3;

// IntArray is a new data type that represents a two-dimensional array of integers 
typedef int IntArray[ROWS][COLS]; 

void InitializeArray(IntArray);
void PrintArray(const IntArray);

int main()
{
    IntArray numbers;  // numbers is a two-dimensional array of integers
    int numValues;
    // Initialize the array based on the criteria specified
    // argument must be of data type IntArray 
    InitializeArray(numbers);
    
    // Print out the elements(components) of the 2-dimensional array numbers
    PrintArray(numbers);
    
    
    return 0;
}
void InitializeArray(IntArray nums)
{
     // this function initializes the elements of the two-dimensional array nums
     // initializatioin is to be (row_index + col_index)*2
     // by using the typedef data type IntArray and the defined constants ROWS and
     // COLS, modifications to the program for changes in size of the array are 
     // handled very easily.
     
     int row;           // loop counter for the rows of the array
     int col;           // loop counter for the columns of the array
     
     for (row = 0; row < ROWS; row++)
         for (col=0; col < COLS; col++)
             nums[row][col] = (row+col)*2;
}
void PrintArray(const IntArray nums)
{
     // output the 2-dimensional array specified by the data type IntArray
     
     int row;           // loop counter for the rows of the array
     int col;           // loop counter for the columns of the array
     
     for (row = 0; row < ROWS; row++)
     {
         for (col=0; col < COLS; col++)
         {
             cout << setw(5) << nums[row][col];
         }
         cout << endl;
     }
}
