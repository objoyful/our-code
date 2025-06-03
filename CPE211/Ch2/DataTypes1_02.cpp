// Data Types1 program 2 : DataTypes1_02.cpp

// This is a program illustrating the concept of namespaces. 
// illustrates qualified name method, a using declaration (use
// one identifier from a namesapce) and
// a using directive (use the entire namespace)

#include <iostream>
#include <string>  // required for string operations

// using namespace std line should be here, but is left offf for the example

int main ()
{
	// without the line using namespace std;, 
	// Data types are no longer defined, so must use the 
	// qualified name method

	// Note: when line is output, the output will be the word
	// Hello and the new line character will terminate the line
	
	std::string line = "Hello\n"; 

	// cout is no longer defined as well, so use the 
	// qualified name method here also

	std::cout << "Output using a qualified name: " ;
	std::cout << line ;

	if (true)
	{
		// The following is a using declaration - it declares
		// one identifer in a namespace to be available
		// for the rest of the scope where the using declaration is made
		// allows cout to be used, but only within the if block

		using std::cout;  

		cout << "Output with a using declaration: " ;
		cout << line; 
		cout << "We can still use cout\n";
	}

	// cout << "test"; this line will not work
	// since cout is not defined for main, but in the if statement only

	// A using directive makes all identifiers within a namespace
	// available for use until the scope of the using directive ends
	// after the following line is executed, all declarations
	// in the std namespace are available.

	using namespace std;

	cout << "Output with a using directive: " ;
	cout << line;
	string name = "Ron";  // can now declare string variables normally

	return 0;
}
