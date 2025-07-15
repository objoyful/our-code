// Structures Program: Structures_01.cpp

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Declare (no memory is allocated) 
// a structure for a Customer record
struct CustomerRecord {
    string 		customerName;
    int 		customerId;
    int 		accountId;
    string		lastPayDate;
    float		balance = 0;
    //const float allowance = 5;
};

struct CustomerRecord_dup {
    string 		customerName;
    int 		customerId;
    int 		accountId;
    string		lastPayDate;
    float		balance;
};

// The above structure has 5 members.  
// No memory is allocated until a variable declaration -
// which is usually a definition [memory is allocated] is made.

// structures can be passed as an argument to functions by 
// value or by reference
// structures can also be used as the return value 
// for a value returning function

// function to add information to the structure paramter 
// function prototype

CustomerRecord my_function(CustomerRecord &);  

int main() {
    // declare a variable with the same name as a structure member name.
    // is this possible???
    string customerName;

    // define customer1 and customer2 to be of 
    // DataType CustomerRecord

    // first structure var used for showing assignments
    CustomerRecord   customer1;

    // 2nd structure declared used to show 
    // allowed aggregate ssignment of structs
    CustomerRecord   customer2;  


    CustomerRecord_dup   customer3;  
    // Even though the structures CustomerRecord and CustomerRecordDup
    // have identical members, customer2 and customer3 
    // are of different data types so the following does not compile
    // customer3 = customer2;
    // cout << customer2 << endl;  // this is not allowed - compile error
   
    // my_function returns a structure of type CustomerRecord
    // This function assigns values to customer1 and creates 
    // a modified version in customer2
    customer2 = my_function(customer1);  // function call

    // output some of the structure members from both structure variables
    // output first structure values followed by second structure.  
    // this output shows the results from the assignments 
    // made in the function call

    cout << fixed << setprecision(2);
    cout << "\nFirst structure values: \n";
    cout << setw(9) << "name: " << customer1.customerName << endl;
    cout << setw(9) << "cust id: " << customer1.customerId << endl;
    cout << setw(9) << "acct id: " << customer1.accountId << endl;
    cout << setw(9) << "date: " << customer1.lastPayDate << endl ;
    cout << setw(9) << "balance: " << customer1.balance << endl << endl;

    cout << "\nSecond structure values: \n";
    cout << setw(9) << "name: " << customer2.customerName << endl;
    cout << setw(9) << "cust id: " << customer2.customerId << endl;
    cout << setw(9) << "acct id: " << customer2.accountId << endl;
    cout << setw(9) << "date: " << customer2.lastPayDate << endl;
    cout << setw(9) << "balance: " << customer2.balance << endl << endl;

    return 0;
}

CustomerRecord my_function(CustomerRecord & cust1) { // function definition
    CustomerRecord cust2;  // returned structure used to hold modified cust1

    // Assign some values to the structure parameter cust1
    cust1.customerName = "Ron";
    cust1.customerId = 777;
    cust1.accountId = 123456;
    cust1.lastPayDate = "January 1, 1999";
    cust1.balance = 542.45;

    // One structure variable can be assigned to 
    // another structure variable 

    cust2 = cust1;

    // make some modifications to some members of structure cust2
    cust2.customerId += 1000;
    cust2.customerName += " Bowman";
    cust2.balance -= 42.45;
    cust2.accountId -= 100000;
    cust2.lastPayDate += "-Old Date";

    return cust2;
}