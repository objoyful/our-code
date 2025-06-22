#include "dialog.h"

using namespace std;

int main() {
  //****** GUI ADDITIONS BEGIN *************************************
  YesNoDialog choice("Continue with calculating BMI?");
  bool response = choice.display();
  //****** GUI ADDITIONS END ***************************************

  string message;  // Message to display to the user in the GUI

  if (response) {
    const int BMI_CONSTANT = 703;  // Constant in nonmetric formula
    float weight;                  // Weight in pounds
    float height;                  // Height in inches
    float bodyMassIndex;           // Appropriate BMI

    // Create the GUI widgets to display to the user.
    FloatDialog weightDialog("Enter your weight in pounds.", 30, 30, 600);
    FloatDialog heightDialog("Enter your height in inches.", 48, 32, 108);

    // Display the GUI widgets to get user input for weight and height
    weight = weightDialog.display();
    height = heightDialog.display();

    // Calculate body mass index
    bodyMassIndex = weight * BMI_CONSTANT / (height * height);

    // Create message to user.
    message = "Your body mass index is " + to_string(bodyMassIndex) + ".\n" +
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
