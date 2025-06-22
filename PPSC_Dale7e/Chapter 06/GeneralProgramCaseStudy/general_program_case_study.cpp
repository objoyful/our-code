//*****************************************************************
// LoanPayment program
// This program determines the monthly payments on a loan given
// the loan amount, the yearly interest rate, and the number of
// months (payments).
// The process repeats until a negative loan amount is entered.
//*****************************************************************
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  // Input variables
  float loanAmount;
  float yearlyInterest;
  int numberOfYears;

  // Local variables
  float monthlyInterest;
  int numberOfPayments;
  float payment;

  // Prompts
  cout << "Input loan amount, interest rate, and number of years." << endl;
  cout << "An interest rate of less than 0.25 is assumed to be " << endl;
  cout << "a decimal rather than a percent." << endl;
  cout << "A negative loan amount ends the program." << endl;
  // Read values
  cin >> loanAmount;
  while (loanAmount > 0) {
    cin >> yearlyInterest >> numberOfPayments;
    numberOfPayments = numberOfYears * 12;
    // Calculate values
    if (yearlyInterest >= 0.25)  // Assume percent entered
      yearlyInterest = yearlyInterest / 100.0;
    monthlyInterest = yearlyInterest / 12;
    payment = (loanAmount * pow(1 + monthlyInterest, numberOfPayments) *
               monthlyInterest) /
              (pow(1 + monthlyInterest, numberOfPayments) - 1);

    // Output results
    cout << fixed << "Loan amount:         " << setprecision(2) << loanAmount
         << endl
         << "Interest rate:       " << setprecision(4) << yearlyInterest * 100.0
         << "%" << endl
         << "Number of payments:  " << numberOfPayments << endl;
    cout << fixed << "Monthly payments:    " << setprecision(2) << payment
         << endl;
    cout << fixed << "Total Interest:      " << setprecision(2)
         << (payment * numberOfPayments - loanAmount) << endl;
    // Prompts
    cout << "Input loan amount, interest rate, and number of months." << endl;
    cout << "An interest rate of less than 0.25 is assumed to be " << endl;
    cout << "a decimal rather than a percent." << endl;
    cout << "A negative loan amount ends the program." << endl;
    cin >> loanAmount;
  }
  return 0;
}
