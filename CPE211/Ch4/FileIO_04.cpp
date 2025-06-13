//
// *****   Program Ch_04_04.cpp   *****
#include <iostream>
#include <string>
#include <fstream>  // required for using files

using namespace std;

int main()
{
   
   cout << "program starting\n";
   string OneLineAtATime="NullString";

   ifstream InFile;  // InFile variable will contain the name of
			         // the file from which information is read
			
   ofstream OutFile; // OutFile variable will contain the name of the
		         	// the file to which information is written

   // In this example use literal strings for the file names.

   // Associate the actual file Input.txt with the input file stream
   // variable InFile
   InFile.open("Input.txt",ios::in); 
   cout << "Opening file Input.txt for reading\n";

   // Associate the file Output.txt with the output file stream 
   // variable OutFile
   OutFile.open("Output.txt");
   //OutFile.open("Output.txt",ios_base::app);
   cout << "Opening file Output.txt for writing\n";

   // Read one line from the input file associated with the file
   // stream variable InFile
   cout << "reading the first line\n";
   getline(InFile,OneLineAtATime,'\n');

   // output the line read to the output file associated with the file
   // stream variable OutFile
   OutFile << OneLineAtATime << endl;

   // obtain the second line in the file
   cout << "reading the second line\n";
   getline(InFile,OneLineAtATime,'\n');
   OutFile << OneLineAtATime << endl;

   cout << "program complete\n";

   // Close all open files for completeness.  This is more required for
   // the output file than the input file in this particular example.
   InFile.close();
   OutFile.close();

   return 0;
}
