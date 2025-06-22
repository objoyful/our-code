#include <iostream>

using namespace std;

int main() {
  const int BMI_CONSTANT = 703;  // Constant in nonmetric formula
  float weight;                  // Weight in pounds
  float height;                  // Height in inches
  float bodyMassIndex;           // Appropriate BMI
  bool dataAreOK;                // True if data are nonnegative

  // Prompt for and input weight and height
  cout << "Enter your weight in pounds. " << endl;
  cin >> weight;
  cout << "Enter your height in inches. " << endl;
  cin >> height;

  // Test data
  if (weight < 0 || height < 0)
    dataAreOK = false;
  else
    dataAreOK = true;

  if (dataAreOK) {
    // Calculate body mass index
    bodyMassIndex = weight * BMI_CONSTANT / (height * height);

    // Display message indicating status
    cout << "Your body mass index is " << bodyMassIndex << ". " << endl;
    cout << "Interpretation and instructions. " << endl;
    if (bodyMassIndex < 20)
      cout << "Underweight: Have a milk shake." << endl;
    else if (bodyMassIndex <= 25)
      cout << "Normal: Have a glass of milk." << endl;
    else if (bodyMassIndex <= 30)
      cout << "Overweight: Have a glass of iced tea." << endl;
    else
      cout << "Obese: See your doctor." << endl;
  } else
    cout << "Invalid data; weight and height must be positive." << endl;
}
