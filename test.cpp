#include <iostream>
#include <string>

using namespace std;

int main() {
    string first_name = "Ron", last_name = "Bowman";
    string name;
    const char SPACE = ' ';
    
    name = first_name + " Bowman"; // Valid
    // name = "Ron" + " Bowman"; // not valid
    name = first_name + SPACE + "Bowman"; // Valid
    cout << name << endl; // Output: Ron Bowman
}