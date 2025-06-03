// Data Types 1, program 3
// This is a program illustrating the concept of namespaces. 
// illustrates qualified name method, a using declaration (use
// one identifier from a namesapce) and
// a using directive (use the entire namespace)
//
#include <iostream>
#include <string>  // required for string operations

// create a namespace with a simple variable
namespace Ron
{
	int var1=20;
    int cout = 100;
    namespace Ron2
    {
        int cout = -100;
    }
}

// using namespace std line should be here, but is left off for the example
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
    std::cout << std::endl;

	int var1 = 10;
    Ron::var1 = Ron::var1*2;
	std::cout << "var1 in main: " << var1 
              << "  var1 in Ron: " << Ron::var1 << std::endl;

    std::cout << "cout in Ron: " << Ron::cout << std::endl;
    std::cout << "cout in Ron2: " << Ron::Ron2::cout << std::endl;
    std::cout << std::endl;

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
        cout << std::endl;
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
	int number = 0;  // can now declare variables normally

	return 0;
}
