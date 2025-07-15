// Structures Program 3:  Structures_03.cpp

#include <iostream>
#include <string>

using namespace std;

// This program is an example showing a hierarchical structure
// Note that structures must be declared before they are used
// as DataType declarations in subsequent structure declarations


// can we have a structure prototype setup?
//struct Date;
//struct Shirt;

// Date structure declaration must come before the 
// structure declarations for Pant and Shirt since
// Pant and Shirt have members that are a Date structure 
// Declaration for  Shirt must occur before the 
// Declaration for Clothes since a member of clothes is
// a structure of data type Shirt

struct Date {
    //int day;  // 1 - 31
    int day = 9;  // 1 - 31
    int month;  // 1-12 
    int year; // 1900 -
};

struct Shirt {
    int neck_size;
    int sleeve_length;
    int sleeve_type;
    float cost;
    string designer;
    Date  purch_date;  // because Date is a structure, it must
                        // be declared before this structure
}; 

struct Clothes {
    Shirt tops; // tops is a member of Clothes, and it is a structure
    int quantity; // number of tops owned 

};
// can you declare a structure in a structure
struct Struct1 {
    int first;
    // same as declaring Struct2 outside of Struct1
    // and then having Struct2 s2; as a member
    struct Struct2 {
        int second;
    } s2;
};

int main() {
    // check structure in a structure
    Struct1 one;
    // Struct2 two;  // no access to Struct2 so compile error
    Struct1::Struct2 two;  // no access to Struct2 via name qualification? so compile error
    one.first = 1;
    one.s2.second = 2;
    cout << "one.s2.second = " << one.s2.second << endl;

    two.second = 10;
    cout << "two.second: " << two.second << endl;

    // declare/define a variable of the structure type Clothes
    Clothes ron;
    Clothes ron2;

    // show that local variables are uninitialized when declared
    // sometimes they are set to 0 other times they are not
    int num2;  
    int num;
    int num3;
    cout << "\noutput of num which is not assigned a value: " <<  num  
         << "  " << num2 << "  " << num3<< endl;

    // make some assignments to various members of the structure variable
    ron.tops.neck_size = 16;
    ron.tops.sleeve_length = 35;
    ron.tops.purch_date.month = 12;
    ron.tops.purch_date.year = 2003;

    // can make an aggregate assignment of one structure variable 
    // to another structure variable 
    ron2.tops = ron.tops;

    // information can be printed out in a similar manner
    cout << "\nron shirt neck size: " << ron.tops.neck_size << endl;
    cout << "ron shirt purchase year: " << ron.tops.purch_date.year << endl;
    cout << "ron2 sleeve length: " << ron2.tops.sleeve_length << endl;

    // no value has been assigned to ron.tops.purch_date.day
    // this cout statement shows you what happens in that case 
    cout << "\nNo value has been assigned to the day values printed out\n";
    cout << "ron shirt purchase day: " << ron.tops.purch_date.day<< endl;
    cout << "ron2 shirt purchase day2: " << ron2.tops.purch_date.day<< endl;

    return 0;
}