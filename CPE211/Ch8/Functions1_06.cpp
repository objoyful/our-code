// Functions1_06.cpp

// Example showing the use of reference parameters in a 
// void function.  Once again, comments are shown in the
// function definition.  This time the comments indicate
// the transference characteristic of the parameters.  Here
// both parameters are reference, and the data transference
// is out only.  that means the corresponding arguments have 
// no value assigned to them when the function is called.  The function
// then provides values to the parameters and these values are then
// available to the caller of the function

#include <iostream>
#include <fstream> // for file I/0 
#include <string>
#include <cstdlib>  // for exit function

using namespace std;

// Function prototype
// This function will prompt for and read in the name of a file
// to open.  The file is also opened in the function.
//  Testing of the status of the input file is performed in main
// since both values are obtained in the function and then returned
// back to the caller, the flow of direction is out only not in/out.

void OpenFile(ifstream&  /* out */, string& /* out */ );

// input and output file streams need to be passed in by reference
// If the & is left off of the file stream data type, a
// compile error will occur when a function call is attempted.
// just having the prototype and the function definition will 
// compile without any warnings or errors.  Once a function
// call is attepted, the error will occur during compile
void OpenFile2(ifstream  /* out */, string /* out */ );

int main()
{
    // this program will try to open 3 separate input
    // file streams.

	ifstream InFile1;
	ifstream InFile2;
	ifstream InFile3; 
	string name;

    // without this open statement, the program compiles
    // when this open is attempted, the compiler gives an error
    //OpenFile2(InFile1,name);

    // reset file streams to a good status
    InFile1.clear();
    InFile2.clear();
    InFile3.clear();
    if (InFile1.good() && InFile2.good()&& InFile3.good())
    {
        cout << "All three streams are valid\n";
    }

    // see a list of files to use with the open function
	cout << endl << "List of available files:\n";
	cout <<         "------------------------\n";
	system ("ls");
	cout <<         "------------------------\n\n";

	// function call to obtain the name of an input file,
	// and open the file.

	// since InFile1 and name were both passed in to reference 
	// parameters, the values obtained for these variables in
	// the function are available here in main using the arguments.

	// if InFile1 is coerced to false, then it was not able to be opened,
	// so an error has occurred.  output that information and terminate

	OpenFile (InFile1, name);
	if (!InFile1) 
	{ 
		cout << "error.  could not open file: " << name << endl;
		cout << "Terminating the program\n";
		exit(1); // exit main with an error code of 1
	} 

	cout << "File: "<< name << " is a valid file\n";

    // try to open the second file

	OpenFile (InFile2, name);
	if (InFile2.fail()) 
	{ 
		cout << "error.  could not open file: " << name << endl;
		cout << "Terminating the program\n";
		exit(1); // exit main with an error code of 1
	}  
	cout << "File: "<< name << " is a valid file\n";

    // try to open the third file

    OpenFile (InFile3, name); 

	if (!InFile3.good()) 
	{ 
		cout << "error.  could not open file: " << name << endl;
		cout << "Terminating the program\n";
		exit(1); // exit main with an error code of 1
	}  
	cout << "File: "<< name << " is a valid file\n";
    //once the following is uncommented, a compile error occurs
    // OpenFile2 (InFile3, name); 
	return 0;
}

void OpenFile(ifstream& InFile, string& name) // function definition
{
	// This function obtains the name of the input file and opens it.
	// testing of the open status is left for the caller of the function
	cout << "Enter the name of the file to open:";
	cin >> name;
	InFile.open(name.c_str());
	if (!InFile) 
	{ 
		cout << "error.  could not open file: " << name << endl;
		cout << "Terminating the program in main\n\n";
	}  
}
void OpenFile2(ifstream InFile, string name) // function definition
{
	// This function obtains the name of the input file and opens it.
	// testing of the open status is left for the caller of the function
	cout << "Enter the name of the file to open:";
	cin >> name;
	InFile.open(name.c_str());
	if (!InFile) 
	{ 
		cout << "error.  could not open file: " << name << endl;
		cout << "Terminating the program in main\n\n";
	}  
}
