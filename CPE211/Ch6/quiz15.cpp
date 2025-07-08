#include <iostream>

using namespace std;

int main() {
    int a = 0;
    int sum = 0;
    
    while (a < 5) {
        sum = sum + a;
        a++;
    }
    
    cout << sum << endl;
}