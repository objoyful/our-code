//******************************************************************
// Profile Program
// This program inputs a name, weight, height, blood pressure
// readings, and cholesterol values.  Appropriate health messages
// are written for each of the input values on file healthProfile.
//******************************************************************

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// Function prototypes

string Name();
// This function inputs a name and returns it in first,
// middle initial, and last order

void EvaluateCholesterol(ofstream& healthProfile, string name);
// This function inputs HDL (good cholesterol) and LDL (bad
// cholesterol) and outputs a health message based on their
// values on file healthProfile.
// Pre: Input file has been successfully opened

void EvaluateBMI(ofstream& healthProfile, string name);
// This function inputs weight in pounds and height in inches and
// calculates the body mass index (BMI), then outputs a health message
// based on the BMI. Input is in English weights.
// Pre: Input file has been successfully opened

void EvaluateBloodPressure(ofstream& healthProfile, string name);
// This function gets blood pressure readings (systolic/diastolic)
// and outputs a health message based on their values
// on file healthProfile.
// Pre: Input file has been successfully opened

int main() {
  // Declare and open the output file
  ofstream healthProfile;
  healthProfile.open("Profile");
  string name;
  name = Name();

  // Write patient's name on output file
  healthProfile << "Patient's name " << name << endl;

  // Evaluate the patient's statistics
  EvaluateCholesterol(healthProfile, name);
  EvaluateBMI(healthProfile, name);
  EvaluateBloodPressure(healthProfile, name);
  healthProfile << endl;

  healthProfile.close();
  return 0;
}

//******************************************************************

string Name()
// This function inputs a name and returns it in first,
// middle initial, and last order
{
  // Declare the patient's name
  string firstName;
  string lastName;
  char middleInitial;

  // Prompt for and enter the patient's name
  cout << "Enter the patient's first name: ";
  cin >> firstName;
  cout << "Enter the patient's last name: ";
  cin >> lastName;
  cout << "Enter the patient's middle initial: ";
  cin >> middleInitial;
  return firstName + ' ' + middleInitial + ". " + lastName;
}

//******************************************************************

void EvaluateCholesterol(ofstream& healthProfile, string name)
// This function inputs HDL (good cholesterol) and LDL (bad
// cholesterol) and outputs a health message based on their
// values on file healthProfile.
{
  int HDL;
  int LDL;

  // Prompt for and enter HDL and LDL
  cout << "Enter HDL for " << name << ": ";
  cin >> HDL;
  cout << "Enter LDL for " << name << ": ";
  cin >> LDL;
  float ratio = static_cast<float>(HDL) /
                static_cast<float>(LDL);  // Calculate HDL to LDL ratio

  healthProfile << "Cholesterol Profile " << endl
                << "   HDL: " << HDL << "  LDL: " << LDL << endl
                << "   Ratio: " << fixed << setprecision(4) << ratio << endl;

  // Output message based on HDL value
  if (HDL < 40)
    healthProfile << "   HDL is too low" << endl;
  else if (HDL < 60)
    healthProfile << "   HDL is okay" << endl;
  else
    healthProfile << "   HDL is excellent" << endl;
  // Output message based on LDL value
  if (LDL < 100)
    healthProfile << "   LDL is optimal" << endl;
  else if (LDL < 130)
    healthProfile << "   LDL is near optimal" << endl;
  else if (LDL < 160)
    healthProfile << "   LDL is borderline high" << endl;
  else if (LDL < 190)
    healthProfile << "   LDL is high" << endl;
  else
    healthProfile << "   LDL is very high" << endl;

  if (ratio > 0.3)
    healthProfile << "   Ratio of HDL to LDL is good" << endl;
  else
    healthProfile << "   Ratio of HDL to LDL is not good" << endl;
}

//******************************************************************

void EvaluateBMI(ofstream& healthProfile, string name)
// This function inputs weight in pounds and height in inches and
// calculates the body mass index. Input in English weights.
{
  const int BMI_CONSTANT = 703;  // Constant in English formula
  int pounds;
  int inches;

  // Enter the patient's weight and height
  cout << "Enter the weight in pounds for " << name << ": ";
  cin >> pounds;
  cout << "Enter the height in inches for " << name << ": ";
  cin >> inches;
  int bodyMassIndex = pounds * BMI_CONSTANT / (inches * inches);

  healthProfile << "Body Mass Index Profile" << endl
                << "   Weight: " << pounds << "  Height: " << inches << endl;
  // Output bodyMassIndex
  healthProfile << "   Body mass index is " << bodyMassIndex << endl;
  healthProfile << "   Interpretation of BMI " << endl;

  // Output interpretation of BMI
  if (bodyMassIndex < 20)
    healthProfile << "   Underweight" << endl;
  else if (bodyMassIndex <= 25)
    healthProfile << "   Normal" << endl;
  else if (bodyMassIndex <= 30)
    healthProfile << "   Overweight" << endl;
  else
    healthProfile << "   Obese" << endl;
}

//******************************************************************

void EvaluateBloodPressure(ofstream& healthProfile, string name)
// This function gets blood pressure readings (systolic/diastolic)
// and outputs a health message based on their values
// on file healthProfile.
{
  // Declare the blood pressure readings
  int systolic;
  int diastolic;

  // Enter the patient's blood pressure readings
  cout << "Enter the systolic blood pressure reading for " << name << ": ";
  cin >> systolic;
  cout << "Enter the diastolic blood pressure reading for " << name << ": ";
  cin >> diastolic;

  // Output interpretation of systolic reading
  healthProfile << "Blood Pressure Profile " << endl
                << "   Systolic: " << systolic << "   Diastolic: " << diastolic
                << endl;
  if (systolic < 120)
    healthProfile << "   Systolic reading is optimal" << endl;
  else if (systolic < 130)
    healthProfile << "   Systolic reading is normal" << endl;
  else if (systolic < 140)
    healthProfile << "   Systolic reading is high normal" << endl;
  else if (systolic < 160)
    healthProfile << "   Systolic indicates hypertension Stage 1" << endl;
  else if (systolic < 180)
    healthProfile << "   Systolic indicates hypertension Stage 2" << endl;
  else
    healthProfile << "   Systolic indicates hypertension Stage 3" << endl;

  // Output interpretation of diastolic reading
  if (diastolic < 80)
    healthProfile << "   Diastolic reading is optimal" << endl;
  else if (diastolic < 85)
    healthProfile << "   Diastolic reading is normal" << endl;
  else if (diastolic < 90)
    healthProfile << "   Diastolic reading is high normal" << endl;
  else if (diastolic < 100)
    healthProfile << "   Diastolic indicates hypertension Stage 1" << endl;
  else if (diastolic < 110)
    healthProfile << "   Diastolic indicates hypertension Stage 2" << endl;
  else
    healthProfile << "   Diastolic indicates hypertension Stage 3" << endl;
}
