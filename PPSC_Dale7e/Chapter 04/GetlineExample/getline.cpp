//**********************************************
// This program demonstrates the use of cin and
// getline combined.
//**********************************************
#include <iostream>
#include <string>
using namespace std;

int main() {
  int partNumber;
  int quantity;
  float unitPrice;
  float totalPrice;
  string title;
  getline(cin, title);
  cin >> partNumber;
  cin >> quantity;
  cin >> unitPrice;
  totalPrice = quantity * unitPrice;
  cout << title << endl;
  cout << partNumber << " " << quantity << " " << unitPrice << " ";
  cout << totalPrice << endl;
  return 0;
}
