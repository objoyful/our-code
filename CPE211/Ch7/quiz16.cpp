#include <iostream>

using namespace std;

int main() {
    int num = 0;
    while (num < 5) {
        switch(num) {
            case 1:
                cout << "1";
                break;
            case 2:
                cout << "2";
            case 3:
                cout << "3";
            default:
                cout << "4";
        }
        num  ++;
    }
}