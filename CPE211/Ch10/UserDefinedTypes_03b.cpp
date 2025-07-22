// Chpater 10 program 4b: Ch_10_04b.cpp

#include <iostream>
#include <string>
#include <cctype>  // for tolower function
using namespace std;
// This program shows examples of the enumeration type statement

// Declare the enumeration type as a global so that all functions
// have access to the new DataType 

//enum Month {JAN=1,FEB,MAR,APR,MAY,JUNE,JULY,AUG,SEP,OCT,NOV,DEC};
enum Month {JAN = 10, FEB = 5, MAR, APR, MAY, JUNE, JULY, AUG, SEP, OCT, NOV, DEC};
enum Change {PENNY = 1, NICKEL = 5, DIME = 10, QUARTER = 25};

int main() {
    Month day;  // day is a variable of DataType Month;
    Change coin; // coin is a variable of DataType Change
    string line; // used for flow control and for enumeration input testing

    cout << "\nShow the use of enumeration types in a for loop\n";
    cout << "day is the enumerated variable and the loop runs\n";
    cout << "from JAN to DEC.  implicit coercion takes place on day for output\n\n";

    // for loop showing incrementation
    // output implicitly coerces enumeration variable day to an integer
    for (day = JAN; day <= DEC; day = Month(day + 1))
        cout << "In loop, day = " << day << endl;
    cout << JAN << " " << FEB << " " << MAR << " " << JULY << " " << AUG << endl;

    cout << "\n\nNext show an example of outputting a phrase for\n";
    cout << "an enumerated data type.  Use a switch statement to\n";
    cout << "determine the phrase to output\n";
    cout << "Press enter to continue:";
    
    getline (cin,line,'\n');
    
    cout << endl << "coin is the enumerated variable used in the for loop\n";
    cout << "and going from PENNTY to QUARTER\n";
    // This for loop illustrates the point that an enumeration 
    // variable can contain a value that is not an enumeration type
    for (coin = PENNY; coin <= QUARTER; coin = Change(coin + 1)) {
        switch (coin) {
            case PENNY:
                cout << "coin = " << coin << " and ";
                cout << "The coin is a penny\n";
                break;
            case NICKEL:
                cout << "coin = " << coin << " and ";
                cout << "The coin is a nickel\n";
                break;
            case DIME:
                cout << "coin = " << coin << " and ";
                cout << "The coin is a dime\n";
                break;
            case QUARTER:
                cout << "coin = " << coin << " and ";
                cout << "The coin is a quarter\n";
                break;
            default:
                cout << "coin = " << coin << " and ";
                cout << "NOT a coin\n";
        }
    }

    cout << "\n\nNext show an example of inputting an enum type\n";
    cout << "Press enter to continue:";
    getline (cin,line,'\n');
    //cin.clear();

    do {
        line ="";
        cout << "\nEnter one of the following words:\n";
        cout << "((P)enny, (N)ickel, (D)ime, (Q)uarter, (E)xit): ";
        cin >> line; // read in the word entered
        cin.ignore(200,'\n');  // remove the new-line from input stream
        //getline (cin, line, '\n');

        // use a switch statement to test on the first letter entered
        // output a message saying what was entered, and then assign
        // the appropriate enum type to the variable coin
        switch (line[0]) {
            case 'P':
            case 'p':
                cout << "You entered Penny\n";
                coin = PENNY;
                break;
            case 'N':
            case 'n':
                cout << "You entered Nickel\n";
                coin = NICKEL;
                break;
            case 'D':
            //case 'd':
            case 100:
                cout << "You entered Dime\n";
                coin = DIME;
                break;
            case 'Q':
            case 'q':
                cout << "You entered Quarter\n";
                coin = QUARTER;
                break;
            case 'e':
            case 'E':
                cout << "Exiting switch statement loop\n";
                break;
            default:
                cout << "You did not enter a valid choice\n";
        }
    //}while(line[0] != 'e' && line[0] != 'E'); // or could use while (tolower(line[0]) != e);
    } while (tolower(line[0]) != 'e');

    return 0;
}