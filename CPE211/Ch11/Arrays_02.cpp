// Arryas program 2: Arrays_02.cpp

#include <iostream>
#include <cassert>
#include <string>
using namespace std;

// This program illustrates out of bounds conditions on arrays
// and how the cassert library can be used to check for out of
// bound conditions.

int main() {
    int j; 	// loop index value
    string line; // used for controlling flow of program
    const int MAX_VALUE = 10; // constant integer value for max array size

    float player2[MAX_VALUE * 2]; // player2 is an array of 20 floats
    float player1[MAX_VALUE]; // player1 is an array of 10 (MAX_VALUE)
    // elements, and each is a float


    // initialize the arrays using the same loop, and go up to 
    // MAX_VALUE*2.  This will cause problems since player1 will
    // write to memory not allocated to it. 

    cout << "Initial array assignments: \n";

    for (int k = 0; k < MAX_VALUE * 2; k++) {
        if (k == 10) // indication when player 1 assignments become invalid
            cout << "---- End of Valid player1 assignments ----\n";

        cout << "player2[" << k << "]: " << k * 2;
        player2[k] = float(k * 2);

        cout << "   \tplayer1[" << k << "]: " << k * 3 << endl;
        player1[k] = float(k * 3);
    }



    cout << "\nPress enter to see the results stored\n";
    cout << "in the arrays.  What do you expect to see?\n";
    getline(cin,line);

    // Now look at the output of the arrays
    // output player 1 and player2 arrays with a break where valid
    // player1 assignments end.  This example illustrates what
    // happens when array boundaries are exceeded.

    cout << "index \tplayer2  \tplayer1\n";
    for (j = 0; j < MAX_VALUE*2 ; j++) {
        if (j == 10)
            cout << "---- End of Valid player1 assignments ----\n";
        cout << j << "\t";
        cout << player2[j] << "\t\t";
        cout << player1[j] <<  endl;
    }

    cout << "\n\nNow use the assert condition in the loop\n";
    cout << "to test for out of bounds conditions\n";
    cout << "Press enter to continue\n";
    getline(cin,line);

    cout << "index \tplayer2  \tplayer1\n";
    for (j = 0; j < 20 ; j++) {
    
        assert(j >= 0 && j < MAX_VALUE); // test to make sure that valid indexes are used
        if (j == 10)
            cout << "---- End of Valid player1 assignments ----\n";
        cout << j << "\t";
        cout << player2[j] << "\t\t";
        cout << player1[j] <<  endl;
    }

    return 0;
}
