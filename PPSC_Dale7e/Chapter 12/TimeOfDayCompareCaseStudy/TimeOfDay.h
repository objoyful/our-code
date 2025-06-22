//******************************************************************
// SPECIFICATION FILE (TimeOfDay.h)
// This file gives the specification of a TimeOfDay abstract data
// type as revised to show object-oriented features and a
// comparison function
//******************************************************************
#include "RelationType.h"
class TimeOfDay {
 public:
  // Constructors
  TimeOfDay();
  // Post: hours, minutes, and seconds have been set to 0
  TimeOfDay(int initHours, int initMinutes, int initSeconds);
  // Pre: 0 <= hours <= 23, 0 <= minutes <= 59, 0 <= seconds <= 59
  // Post: Time is set according to the incoming parameters

  // Knowledge responsibilities
  TimeOfDay Increment() const;
  // Post: Returns a time that is the instance plus one,
  //       23:59:59 wrapping around to 0:0:0
  int GetHours() const;
  // Returns hours
  int GetMinutes() const;
  // Returns minutes
  int GetSeconds() const;
  // Returns seconds
  RelationType ComparedTo(TimeOfDay otherDay);
  // Post: Returns BEFORE if instance comes before otherDay;
  //       Returns SAME if instance and otherDay are the same;
  //       Returns AFTER if instance comes after otherDay
 private:
  int hours;
  int minutes;
  int seconds;
};
