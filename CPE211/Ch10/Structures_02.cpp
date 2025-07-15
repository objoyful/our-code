// Structures Program 2: Structures_02.cpp

#include <iostream>
#include <string>
using namespace std;

int main() {
    // structures can be declared in main 
    // for local scope to main only

    // Here structures Student and Student2 are identical.

    // The structure declaration for Student also declares 
    // the variables Fred and temp which the structure 
    // declaration for Student2 does not.  
    // Variables of the structure DataType Student2 are
    // declared with their own statement

    // ignoring the addition of the number "2" on the end of the
    // names, the two structure declarations provide the same end
    // result. 

    struct Student {
        string name;
        int age;
        string class_year;
        float gpa;
    } Fred, temp;

    // below is the preferred method for declaring a structure
    // and defining/declaring variables of the structure DataType
    struct Student2 {
        string name;
        int age;
        string class_year;
        float gpa;
    };
    Student2 Fred2, temp2;  // declare Fred2 and temp2 as Student2 variables

    return 0;
}