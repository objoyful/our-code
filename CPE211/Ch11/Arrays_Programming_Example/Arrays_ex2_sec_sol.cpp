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

const int ROWS = ;  // Maximum number of rows in the array
const int COLS = ;  // Maximum number of columns in the array

// IntArray is a new data type that represents a two-dimensional array of integers 
typedef; 

void InitializeArray(#); // set array values to a known default
void PrintArray(#);  // print out the array values

int main()
{
    numbers;  // numbers is a two-dimensional array of integers
        
    // Initialize the array based on the criteria specified
    // argument must be of data type IntArray 
    InitializeArray(#);
    
    // Print out the elements(components) of the 2-dimensional array numbers
    PrintArray(#);
    
    return 0;
}
void InitializeArray(#)
{
     // this function initializes the elements of the two-dimensional array nums
     // initializatioin is to be (row_index + col_index)*2
     // by using the typedef data type IntArray and the defined constants ROWS and
     // COLS, modifications to the program for changes in size of the array are 
     // handled very easily.
     
     int row;           // loop counter for the rows of the array
     int col;           // loop counter for the columns of the array
     
     for (row = 0; row ; row++)
         for (col=0; col ; col++)
             # = (row+col)*2;
}
void PrintArray(#)
{
     // output the 2-dimensional array specified by the data type IntArray
     
     int row;           // loop counter for the rows of the array
     int col;           // loop counter for the columns of the array
     
     for (row = 0; row ; row++)
     {
         for (col=0; col ; col++)
         {
             cout << setw(5) << ##[row][col];
         }
         cout << endl;
     }
}
