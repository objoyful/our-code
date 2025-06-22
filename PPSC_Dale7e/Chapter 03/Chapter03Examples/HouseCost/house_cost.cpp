// This program computes the cost per square foot of
// living space for a house, given the dimensions of
// the house, the number of stories, the size of the
// nonliving space, and the total cost less land
//******************************************************************
#include <iomanip>  // For setw() and setprecision()
#include <iostream>

using namespace std;

const float WIDTH = 30.0;              // Width of the house
const float LENGTH = 40.0;             // Length of the house
const float STORIES = 2.5;             // Number of full stories
const float NON_LIVING_SPACE = 825.0;  // Garage, closets, etc.
const float PRICE = 150000.0;          // Selling price less land

int main() {
  float grossFootage;   // Total square footage
  float livingFootage;  // Living area
  float costPerFoot;    // Cost/foot of living area

  cout << fixed << showpoint;  // Set up floating-pt. output format

  grossFootage = LENGTH * WIDTH * STORIES;
  livingFootage = grossFootage - NON_LIVING_SPACE;
  costPerFoot = PRICE / livingFootage;

  cout << "Cost per square foot is " << setw(6) << setprecision(2)
       << costPerFoot << endl;
  return 0;
}
