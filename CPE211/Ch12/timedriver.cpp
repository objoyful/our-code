//********************************************************************************
// timedriver.cpp program
// The purpose of the driver is to unit test the time class
//
//
//********************************************************************************
#include <iostream>

#include "time_sec.h"

using namespace std;

int main() {
    Time time1;  // create object time1 with default constructor
    Time time2(10,11,12); // create object time2 with parameters
    Time time3(4,45);
    Time time4(9);

    cout << "time1 is default time, time2 is 10:11:12,\n";
    cout << "time3 is 04:45:00, time 4 is 09:00:00\n\n";

    cout << "Time 1:\n";
    time1.Write();

    cout << "\nTime 2:\n";
    time2.Write();

    cout << "\nTime 3:\n";
    time3.Write();

    cout << "\nTime 4:\n";
    time4.Write();

    // can we set one class variable equal to another - aggregate assignment?
    cout << "Set time1 = time4:\n";
    time1 = time4;
    cout << "\nTime 1:\n";
    time1.Write();
    
    cout << boolalpha;
    cout << "time1 less than time4?: " 
         << time1.LessThan(time4) << endl;

    cout << "time1 equal to time4?: " 
         << time1.Equal(time4) << endl;

    cout << "Set time1 to 5:59:59:\n";
    time1.Set(5,59,59);

    cout << "Increment time1 and time2 one time:\n";
    time2.Increment();
    time1.Increment();

    cout << "\nTime 1:\n";
    time1.Write();

    cout << "\nTime 2:\n";
    time2.Write();

    cout << boolalpha << "time1 eqaul to time 2?: " 
         << time1.Equal(time2) << endl;
    cout << "time2 less than time1?: " 
         << time2.LessThan(time1) << endl;
    cout << "time1 less than time4?: " 
         << time1.LessThan(time4) << endl;
    
    cout << "\nChecking extra increments\nTime 1 is:\n";
    time1.Write();

    time1.Increment(279);
    cout << "Increment by 279 seconds:\n";
    time1.Write();

    time1.Increment(10, 1745);
    cout << "Increment by 10 seconds and 1745 minutes\n";
    time1.Write();

    cout << "Increment by 30 hours:\n";
    time1.Increment(0, 0, 30);
    // time1.Increment(30.0);  // here 30.0 is considered a double by the compuer
    time1.Write();

    float inc = 10.5;
    cout << "Increment by 10.5 hours:\n";
    time1.Increment(inc);
    time1.Write();

    cout << "\ncurrent values of the class objects:\n";
    cout << "Time1: ";time1.Write();
    cout << "Time2: ";time2.Write();
    cout << "Time3: ";time3.Write();
    cout << "Time4: ";time4.Write();


    return 0;
}  // End timedriver