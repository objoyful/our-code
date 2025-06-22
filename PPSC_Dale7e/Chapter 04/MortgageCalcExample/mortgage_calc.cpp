//***********************************************************
// Mortgage Payment Calculator program
// This program determines the monthly payments on a mortgage
// given the loan amount, the yearly interest rate, and the
// number of years.
//***********************************************************
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;
int main() {
  // Input variables
  float loanAmount;
  float yearlyInterest;
  int numberOfYears;
  ofstream outData;
  ifstream inData;

  // Local variables
  float monthlyInterest;
  int numberOfPayments;
  float payment;

  // Open files
  inData.open("loan.in");
  outData.open("loan.out");

  // Read values
  inData >> loanAmount >> yearlyInterest >> numberOfYears;

  // Calculate values
  monthlyInterest = yearlyInterest / 12;

  numberOfPayments = numberOfYears * 12;
  payment = (loanAmount * pow(1 + monthlyInterest, numberOfPayments) *
             monthlyInterest) /
            (pow(1 + monthlyInterest, numberOfPayments) - 1);

  // Output results
  outData << fixed << "Loan amount:     " << setprecision(2) << loanAmount
          << endl
          << "Interest rate:   " << setprecision(4) << yearlyInterest << endl
          << "Number of years: " << numberOfYears << endl;
  outData << fixed << "Monthly payment: " << setprecision(2) << payment << endl;

  // Close files
  inData.close();
  outData.close();
  return 0;
}
