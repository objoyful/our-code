#include <iostream>
#include "exttime.h"

using namespace std;

void Print(const Time & someTime) {
    cout << endl << "****************" << endl;
    someTime.Write();
    cout << endl << "****************" << endl;
}

int main() {
    Time tm1(20, 18, 25);
    cout << "tm1's time zone" << endl;
    tm1.Write();
    cout << endl;

    ExtTime extm1;
    ExtTime extm2(8, 35, 0, PST);
    
    cout << endl << "extm1:";
    extm1.Write();

    cout << endl << "extm2:";
    extm2.Write();
    cout << endl;

    Print(extm1);
    Print(extm2);
}