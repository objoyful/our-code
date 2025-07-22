// Arrays program 2b: Arrays_02b.cpp  

#include <iostream>
#include <cassert>
#include <string>
#include <iomanip>
using namespace std;

// This program illustrates out of bounds conditions on arrays
// In this example, the player2 array is initialized using
// negative index values.  No runtime or compile error occurs,
// and the program runs with side effects of overwriting memory
// not intended to be overwritten.

int main() {
    // Named constant for output field widths
    const int FW = 8;
    const int FW2 = 15;

    int j; 	// loop index value
    string line; // used for controlling flow of program
    const int MAX_VALUE = 10; // max dimension size of array

    float player3[MAX_VALUE]; // player3 is an array of 10 floats
    float player2[MAX_VALUE]; // player2 is an array of 10 floats
    float player1[MAX_VALUE]; // player1 is an array of 10 (MAX_VALUE)
    // elements, and each is a float


    // Initialize the arrays, using a negative index value for the
    // player2 array.  Initialize player2 last to see what the 
    // effect is on the other arrays.
    // initial values player1, index value, player 2, 2*index value
    // and player3, index value*3

    cout << left;
    cout << "Initial array assignments: \n";
    for (int k = 0; k < MAX_VALUE; k++) {
        cout << "   Player1[" << k << "]: " << setw(FW) << k;
        player1[k] = float(k);

        cout << "Player3[" << k << "]: " << setw(FW) << k * 3;
        player3[k] = float(k * 3);

        cout << "Player2[-" << k << "]: " << setw(FW) << -k * 2 << endl;
        player2[-k] = float(-k * 2);				// note the negative index value
    }

    cout << "\nPress enter to see the results stored\n";
    cout << "in the arrays.  What do you expect to see?\n";
    getline(cin, line);

    // Now look at the output of the arrays
    // This shows the result of using a negative index value
    // with arrays.  

    cout << "Player3 is still correctly initialized.  Player2\n";
    cout << "was never properly initialized, and it over wrote\n";
    cout << "part of player1.  The results of using a negative\n";
    cout << "index is not as predictable as going out of range\n";
    cout << "on the positive end of the indexing - ex Ch12_02.cpp\n\n";

    cout << left;
    cout << setw(FW) << "Index" << setw(FW2) << "Player1"
         << setw(FW2) << "Player2" << setw(FW2) << "Player3" << endl;

    for (j = 0; j < MAX_VALUE; j++) {
        cout << setw(FW) << j << setw(FW2) << player1[j]
             << setw(FW2) << player2[j] << setw(FW2) << player3[j] << endl;
    }

    cout << "\n\nWay out of bounds array indexing:\n";
    cout << "Player1[100]: " << player1[100] << endl;
    cout << "Player2[200]: " << player2[200] << endl;
    cout << "Player3[300]: " << player3[300] << endl;


    return 0;
}
