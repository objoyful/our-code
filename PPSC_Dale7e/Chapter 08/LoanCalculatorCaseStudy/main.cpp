//*****************************************************************
// Loan Calculator program
// This program determines the monthly payments on a loan given
// the loan amount, yearly interest rate, number of years,
// and total interest paid over the period of the loan.
// The process repeats until a negative loan amount is entered
//*****************************************************************
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

// Function prototypes
void GetLoanAmt(float& loanAmount);
void GetRest(float& monthlyInterest, int& numberOfYears);
void GetInterest(float& monthlyInterest);
void DeterminePayment(float loanAmount, float monthlyInterest,
                      int numberOfPayments, float& payment);
void OutputResults(float loanAmount, float yearlyInterest, int numberOfPayments,
                   float payment, float totalInterest);

int main() {
  // Variable declarations
  float loanAmount;
  int numberOfYears;
  float monthlyInterest;
  int numberOfPayments;
  float payment;
  float totalInterest;

  // Calculate payments
  GetLoanAmt(loanAmount);
  while (loanAmount > 0) {
    GetRest(monthlyInterest, numberOfYears);
    numberOfPayments = numberOfYears * 12;

    DeterminePayment(loanAmount, monthlyInterest, numberOfPayments, payment);
    totalInterest = payment * numberOfPayments - loanAmount;
    OutputResults(loanAmount, monthlyInterest, numberOfPayments, payment,
                  totalInterest);
    GetLoanAmt(loanAmount);
  }

  return 0;
}

//****************************************************************

void GetLoanAmt(float& loanAmount) {
  cout << "Input loan amount.  "
       << "A negative loan amount ends the processing." << endl;
  cin >> loanAmount;
}

//****************************************************************

void GetRest(float& monthlyInterest, int& numberOfYears) {
  GetInterest(monthlyInterest);
  cout << "Enter the number of years of the loan." << endl;
  cin >> numberOfYears;
}

//****************************************************************

void GetInterest(float& monthlyInterest) {
  float yearlyInterest;  // Local variable
  cout << "Input interest rate.  "
       << "An interest rate of less than 0.25 is assumed "
       << " to be a decimal rather than a percent." << endl;
  cin >> yearlyInterest;
  if (yearlyInterest >= 0.25)  // Assume percent entered
    yearlyInterest = yearlyInterest / 100.0;
  monthlyInterest = yearlyInterest / 12;
}

//****************************************************************

void DeterminePayment(float loanAmount, float monthlyInterest,
                      int numberOfPayments, float& payment) {
  using namespace std;
  payment = (loanAmount * pow(1 + monthlyInterest, numberOfPayments) *
             monthlyInterest) /
            (pow(1 + monthlyInterest, numberOfPayments) - 1);
}

//****************************************************************

void OutputResults(float loanAmount, float yearlyInterest, int numberOfPayments,
                   float payment, float totalInterest) {
  cout << fixed << "Loan amount:         " << setprecision(2) << loanAmount
       << endl
       << "Interest rate:       " << setprecision(4) << yearlyInterest * 100.0
       << "%" << endl
       << "Number of payments:  " << numberOfPayments << endl;
  cout << fixed << "Monthly payments:    " << setprecision(2) << payment
       << endl;
  cout << fixed << "Total Interest:      " << setprecision(2)
       << (payment * numberOfPayments - loanAmount) << endl;
}
