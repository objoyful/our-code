//**********************************************************************************
// Format Names Program
// This program gathers a social security number and a first, middle, and last name
// from an input file and formats the names to an output file in the following ways:
// First, middle, last, Social Security Number
// Last, first, middle, Social Security Number
// Last, first, middle initial, Social Security Number
// First, middle initial, last
//**********************************************************************************

#include <fstream>  // For filestream
#include <iostream> // For input/output stream
#include <string>   // For strings

using namespace std;

int main() {
    // Open files
    ifstream inData;
    ofstream outData;

    inData.open("name.in");
    outData.open("names.out");

    // Declare variables
    string firstName, middleName, lastName;
    string ssNumber;
    char middleInitial;

    // Read data
    inData >> ssNumber >> firstName >> middleName >> lastName;
    
    // Get middle initial
    middleInitial = middleName.at(0);

    // Output names to output file

    outData << firstName << ' ' << middleName << ' ' << lastName << ' ' << ssNumber << endl;
    outData << lastName << ", " << firstName << ' ' << middleName << ' ' << ssNumber << endl;
    outData << lastName << ", " << firstName << ' ' << middleInitial << ". " << ssNumber << endl;
    outData << firstName << ' ' << middleInitial << ". " << lastName << endl;

    // Close files
    inData.close();
    outData.close();

    return 0;
}