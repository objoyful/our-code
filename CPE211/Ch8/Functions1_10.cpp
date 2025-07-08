// Example of recursive function call for factorial
//
// Recursion is a powerful programming technique that must
// be done with caution.  It is easy to setup incorrectly.
// The logic of how it is performed needs to be carefully 
// considered and the logical flow determined.

#include <iostream>

using namespace std;

void Fact(unsigned long& fact, int num);

int main() {
    unsigned long fact = 1;
    int num;
    cout << "find the factorial of what number: ";
    cin >> num;

    Fact(fact, num);

    cout << "Factorial of " << num << " is: " << fact << endl;
    return 0;
}
void Fact(unsigned long& fact, int num) {
    // use a static variable so that the number of calls to the function can be made
    // order is important for count++ being in its location
    // use a local variable - callNumber - to show that each function call 
    // has its own memory allocated to it

    static int count = 0;
    count ++;
    int callNumber = count;

    cout << "call number: " << count << "  Value sent in: " << num << endl;

    // if number passed in is 1, then we are done and there is no need to 
    // perform the multiplication

    if (num == 1) {
        cout << "1 Reached, exiting recursive calls from call number: " << callNumber << "\n";
        return;
    }

    // change factorial by the current value being used, then decrease the number
    // by one and call the function again recursively

    fact = fact * num;
    
    // make recursive call to multiply in the next number
    Fact(fact, num - 1);

    // Once the number value to use in the function is 1, all the functions start
    // returning control back to their caller.  With recursion this results in a 
    // series of returns that eventually ends the recursion.

    cout << "Returning from call number: " << callNumber << "\n";
}
