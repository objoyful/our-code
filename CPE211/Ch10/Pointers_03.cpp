// Pointers example 3: Pointers_03.cpp
// Pointers to a structure example
// Using new to create memory and
// delete to delete it

#include <iostream>
using namespace std;

struct Name {
    string name;
    int id;
};

int main() {

    Name person;        // structure variable

    // nullptr is for c+11 and higher
    Name *namePtr = nullptr;    // pointer variable for structures of type Name
    // what happens if we dereference the unll pointer?
    // get a segmentation fault
    //cout << "Null Pointer dereferenced: " << (*namePtr).name << endl;

    person.name = "Ron";
    person.id = 123;

    // use new to create a variable of data type Name

    namePtr = new Name;
    namePtr -> name = "Sam";
    namePtr -> id = 456;

    // output values of namePtr and person

    cout << "Name-ptr: " << namePtr -> name << endl;
    cout << "Id-ptr:   " << (*namePtr).id  << endl;
    cout << "***************************\n\n";
    cout << "Regular structure output\n";
    cout << "Name: " << person.name << endl;
    cout << "Id:   " << person.id << endl;
    cout << "***************************\n";

    // assign the namePtr values to person

    person = *namePtr;
    cout << "\nRegular structure after assigned pointer values\n";
    cout << "Name: " << person.name << endl;
    cout << "Id:   " << person.id << endl;

    cout << "***************************\n\n";
    cout << "Memory deallocated only\n";
    cout << "cannot access memory that has been deallocated\n";

    // delete memory allocated to namePtr
    // this does not delete the pointer variable

    cout << "before delete, namePtr memory contained is: " 
         << namePtr << endl;

    delete namePtr;

    cout << "after delete, namePtr memory contained is: " 
         << namePtr << endl;

    // try to output namePtr values
    // causes a segmentation fault

    //string s = namePtr->name;
    //cout << "s length = " << s.size() << endl;
      //cout << "Name-ptr: " << namePtr->name << endl;
    cout << "Id-ptr:   " << (*namePtr).id << endl;

    cout << "***************************\n\n";
    cout << "Memory deallocated, null assigned\n";

    // when delete memory assigned to a pointer
    // it is best to assign NULL to the pointer
    // so that a test can be performed

    namePtr = NULL;  // or use = nullptr
    //if (namePtr != NULL)
    if (namePtr != nullptr) {
        cout << "Name-ptr: " << namePtr->name << endl;
        cout << "Id-ptr:   " << (*namePtr).id << endl;
    }
    
    cout << "after delete and NULL, namePtr memory contained is: " 
         << namePtr << endl;

    return 0;
}
