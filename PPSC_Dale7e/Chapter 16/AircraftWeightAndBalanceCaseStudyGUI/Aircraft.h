#ifndef AIRCRAFT_H
#define AIRCRAFT_H

//*********************************************
// SPECIFICATION  FILE for class Aircraft
//*********************************************

#include "GList.h"
#include "People.h"
class RowOverflow  // More than 2 assigned to a row
{};
class TooHeavy  // Plane is too heavy to take off
{};
class CofGWrong  // Center of gravity not within bounds
{};

class Aircraft {
 public:
  Aircraft();
  // Knowledge responsibilities
  float GetTotalWeight();
  // Returns total weight
  float GetCenterOfGravity();
  // Calculates and returns center of gravity

  // Action responsibilities
  void SetClosetAndFuel(float closetWgt, float fuel);
  // Post: Closet weight and fuel weight have been added to the total
  //       weight;
  //       Closet moment and fuel moment have been added to total moment
  void InsertPassenger(Name initName, float pWeight, float bWeight, int rowNo);
  // Post: Name and role inserted into list;
  //       Passenger and baggage weight have been added to total weight;
  //       Passenger and baggage moment have been added to total moment
  void InsertCrew(Name initName, float cWeight);
  // Post: Name and role inserted into list;
  //       Crew weight added to total weight;
  //       Crew moment added to total moment
  void WriteNamesOnBoard(ofstream& outFile);
  // Post: Names and role of all on board written to outFile

 private:
  float weight;        // Running weight
  float moment;        // Running moments
  GList<People> list;  // List of people on board
                       //  (People specialization of GList template)
};

#endif
