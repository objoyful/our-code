// DataTypes 1, program 1: DataTypes1_01.cpp
//
#include <iostream>
#include <string>

#include <cctype> // required for chharacter functions 

using namespace std;

// This program looks at char variables and how they correspond
// to integers.
//
int main()
{
    const float PI = 3.14159;
	int count; 	// loop control variable
	char letter; // holds character corresponding to count
    //char null ='';  // null character allowed
	string line; // used for program flow control
    // can you assign a character variable to a string
    letter='j';
    line = letter;
    cout << "Assigned character variable to a string variable: " << line << endl;

	// print out the corresponding character for an integer value
	// The machine has the ascii character set, so only integers
	// 0 to 127 have significance.  However, there are other 
	// characters available for values 128 to 255.  Note that since
	// char variables are only one byte, the highest integer value
	// that can be assigned to them is 255.  A value of 256 results
	// in a wrapping back to 0, 257 to 1, etc. 
	
	for (count = 0 ; count < 260; count++)
	{  
		letter = count;  // use implicit coercion to assign an integer value
						// to the char variable letter
		cout << "Count: " << count;
		cout << " integer(0-256): " << count%256 << " is: " << letter << endl;

		// put a pause in the printing of the values after every 20 values.  
		// Note testing for a vlue of 19 instead of 0 since count starts at 0
		// if I tested for equal to 0, I would get a pause after one value and then every 
		// twenty.  by testing on 19, the first pause occurs after 20 values every time

		if (count%20  == 19)
		{
			cout << "press enter to continue:";
			getline(cin,line);
		}
	}


	return 0;
}
