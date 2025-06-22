#include "dialog.h"

using namespace std;

int main() {
  string message;                // Message to display to the user in the GUI
  const int BMI_CONSTANT = 703;  // Constant in nonmetric formula
  float weight;                  // Weight in pounds
  float height;                  // Height in inches
  float bodyMassIndex;           // Appropriate BMI
  bool dataAreOK;                // True if data are nonnegative

  // Create the GUI widgets to display to the user.
  FloatDialog weightDialog("Enter your weight in pounds.");
  FloatDialog heightDialog("Enter your height in inches.");

  // Display the GUI widgets to get user input for weight and height
  weight = weightDialog.display();
  height = heightDialog.display();

  // Test data
  if (weight < 0 || height < 0)
      dataAreOK = false;
  else
      dataAreOK = true;

  if (dataAreOK) {
      // Calculate body mass index
      bodyMassIndex = weight * BMI_CONSTANT / (height * height);

      // Create message to user.
      message =
              "Your body mass index is " + to_string(bodyMassIndex) + ".\n" +
              "Interpretation and instructions.\n";

      if (bodyMassIndex < 20)
          message += "Underweight: Have a milk shake.\n";
      else if (bodyMassIndex <= 25)
          message += "Normal: Have a glass of milk.\n";
      else if (bodyMassIndex <= 30)
          message += "Overweight: Have a glass of iced tea.\n";
      else
          message += "Obese: See your doctor.\n";
      
  } else {
      message += "Invalid data; weight and height must be positive.\n";
  }

  OutputDialog bmiOutput("BMI Output");
  bmiOutput.SetOutput(message);
  bmiOutput.display();
}
