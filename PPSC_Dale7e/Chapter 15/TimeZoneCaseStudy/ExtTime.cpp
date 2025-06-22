//*************************************************************
// IMPLEMENTATION FILE  for ExtTime, a derived
// class from TimeOfDay with a time zone
//*************************************************************
#include "ExtTime.h"

#include <iostream>

#include "RelationType.h"
using namespace std;

ExtTime::ExtTime(int newHours, int newMinutes, int newSeconds, ZoneType newZone)
    : TimeOfDay(newHours, newMinutes, newSeconds) {
  zone = newZone;
}

//************************************************************

ExtTime::ExtTime() { zone = PST; }

//************************************************************

ZoneType ExtTime::GetZone() const { return zone; }

//************************************************************

RelationType ExtTime::ComparedTo(ExtTime otherTime) const {
  // A copy of the instance is converted to the same
  // zone as otherTime; TimeOfDay's ComparedTo is
  // then used to compare the copy and the parameter

  int difference = int(otherTime.zone) - int(zone);
  int newHours = (GetHours() + difference) % 24;
  TimeOfDay copy(newHours, GetMinutes(), GetSeconds());
  return copy.ComparedTo(otherTime);
}
