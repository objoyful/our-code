#include <iostream>
#include <string>

using namespace std;

int main() {
    struct Date {
        string month;
        int day;
        int year;
    };
    
    Date birthday;

    birthday.month = "December";
    birthday.year = 2000;

    return 0;
}