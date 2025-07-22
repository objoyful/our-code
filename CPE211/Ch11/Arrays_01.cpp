// Chpater 12 program 1: Ch_12_01.cpp 

#include <iostream>
using namespace std;
// This program introduces arrays - how to declare them,
// how to access elements and valid uses of array elements

int main() {
    // declare points to be an array of 10 elements
    // and each element is an integer
    int num1;
    int points[10]; 
    int num2;

    // declare points with negative index - compile error
    //int points[-10]; 

    const int MAX_VALUE = 10; // constant integer value for array size
    //
    // player1 is an array of 10 (MAX_VALUE)
    // elements, and each is a float
    float player1[MAX_VALUE]; 

    float player2[MAX_VALUE * 2]; // player2 is an array of 20 floats

    int booltry[true * 4];
    int chartry['a'];
    cout << "booltry: " << sizeof(booltry) << "  chartry: " << sizeof(chartry) << endl;

    int j = 5; // used for a loop index
    int k; // loop index
    float value = 0.0;

    // initialize the arrays.  since points and player1 are both 10
    // element arrays, could initialize in the same loop. 
    // However, the size of the arrays are declared differently.  One is
    // declared using a constant (MAX_VALUE) the other is declared
    // using a literal value of 10 

    // initialize points - value is the index value
    for (k = 0; k < 10; k++)
        points[k] = k;

    // initialize player1 - value is the index value
    for (k = 0; k < MAX_VALUE; k++)
        player1[k] = float(k);

    // initialize player2 - value is twice the index value
    for (k = 0; k < MAX_VALUE * 2; k++)
        player2[k] = float(k * 2);

    // make some out of range array assignments
    // shows that out of range index values are not checked
    points[100] = 15;
    points[-1] = -1;
    points[-2] = -2;
    points[-3] = -3;
    points[10] = 1000;  // 11th element of a 10 element array
    points[11] = 1100;  // 12th element of a 10 element array
    points[12] = 1200;  // 13th element of a 10 element array

    player1[-10] = 34.5;
    player1[-1] = -11;
    player2[22] = 33;
    player2[-5] = -35;

    for (int i = 10; i < 1000000; i++)
        player1[-i] = i * 5;

    player1[(j * 4 + 5) % MAX_VALUE] = 55.0;
    cout << "points index 200: " << points[200] << endl;

    // output all three arrays from one loop
    cout << "play2\tplay1\tpoints\n";
    for (j = 0; j < MAX_VALUE * 2; j++) {
        cout << player2[j] << "\t";
        if (j < MAX_VALUE) // output player 1 valid values
            cout << player1[j] << "\t";
        if (j < 10) // output valid points values - could use MAX_VALUE here also
            cout << points[j];
        cout << endl;
    }
    cout << "Num1: " << num1 << "  num2: " << num2 << endl;
    return 0;
}
