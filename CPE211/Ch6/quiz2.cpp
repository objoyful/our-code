#include <iostream>

using namespace std;

int main() {
    int num;

    cout << "Enter an integer: ";
    cin >> num;
    cout << num << endl;
    cout << endl;

    while (num != 0) {
        cout << "Enter another integer: ";
        cin >> num;
        cout << num << endl;
        cout << endl;
    }

    return 0;
}