//
// *****   Program Ch_04_05.cpp   *****
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	cout << "program starting\n";   

	string OneLineAtATime = "Null String";
	string infilename, outfilename;

	ifstream InFile;  // file stream variable for input
	ofstream OutFile; // file stream variable for output
    fstream testStream;  // showing how to open a file stream defined as fstream

	// use interactive input to obtain the file names to use
	// This means that string variables will have to be
	// converted to their literal string equivalents 

	cout << "Input Filename: ";
	cin >> infilename;

	// associate the input file name with the input file stream variable
	InFile.open(infilename.c_str()); 
	//InFile.open(infilename);   // valid in c++11

	cout << "Output Filename: ";
	cin >> outfilename;

	// associat the output file name with the output file stream variable
	// OutFile.open(outfilename.c_str()); 
	OutFile.open(outfilename); 

	// obtain the firet line from the input file and write it to the output file.
	cout << "reading the first line\n";
	getline(InFile,OneLineAtATime,'\n');
	OutFile << OneLineAtATime << endl; 

	// Output a line of * to the output file, then 
	OutFile << "*******************************************\n";

	//read the second line and write it to the output file
	cout << "reading the second line\n";
	getline(InFile,OneLineAtATime,'\n');
	OutFile << OneLineAtATime << endl;

	cout << "program complete\n";

	// Close all open files for completeness.  This is more required for
	// the output file than the input file in this particular example.
	
	InFile.close();
	OutFile.close();

    cout << "Opening a output file stream declared with fstream. \n";
    cout << "Append \"Hello\" to the file\n";
    // ios::in for reading, ios::out for writing, ios::app to append
    testStream.open(outfilename,ios::app|ios::out);
    testStream << "Hello\n";
    testStream.close();
	return 0;
}
