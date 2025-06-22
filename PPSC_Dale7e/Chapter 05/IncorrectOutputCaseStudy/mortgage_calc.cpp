//*****************************************************************
// Mortgage Payment Calculator program
// This program determines the monthly payments on a loan given
// the loan amount, the yearly interest rate, and the number of
// years.
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

  // Read values
  cin >> loanAmount >> yearlyInterest >> numberOfYears;

  // Calculate values
  if (yearlyInterest >= 0.25)  // Assume percent entered
    yearlyInterest = yearlyInterest / 100.0;
  monthlyInterest = yearlyInterest / 12;
  numberOfPayments = numberOfYears * 12;
  payment = (loanAmount * pow(1 + monthlyInterest, numberOfPayments) *
             monthlyInterest) /
            (pow(1 + monthlyInterest, numberOfPayments) - 1);

  // Output results
  cout << fixed << "Loan amount:         " << setprecision(2) << loanAmount
       << endl
       << "Interest rate:   " << setprecision(4) << yearlyInterest * 100.0
       << "%" << endl
       << "Number of years: " << numberOfYears << endl;
  cout << fixed << "Monthly payment: " << setprecision(2) << payment << endl;
  return 0;
}
