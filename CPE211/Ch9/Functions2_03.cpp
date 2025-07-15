// Functions2_03.cpp

// This is a program illustrating the concept of namespaces. 
// illustrates qualified name method, a using declaration (use
// one identifier from a namesapce) and
// a using directive (use the entire namespace)

#include <iostream>
#include <string>  

// what happens if name qualify and have the using directive as well
// using namespace std;

int main() {
    // without the line using namespace std;, 
    // strings need to be name qualified
    
    std::string word;  // needs to be name qualified
    
    // standard built in data types do not need to be name qualified
    int num;  
    float avg;
    char ch;
    bool finish;

    // Note: when string variable line is output, the output will be the word
    // Hello and the new line character will terminate the line

    std::string line = "Hello\n"; 

    // cout is no longer defined as well, so use the 
    // qualified name method here also
    std::cout << "Output using a qualified name: " ;
    std::cout << line ;

    if (true) {
        // The following is a using declaration - it declares
        // one identifer in a namespace to be available
        // for the rest of the scope where the using declaration is made
        // allows cout to be used, but only within the if block
        using std::cout;  

        cout << "Output with a using declaration: " ;
        cout << line; 
        cout << "We can still use cout\n";
    }
    // cout << "test"; // this line will not work
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
