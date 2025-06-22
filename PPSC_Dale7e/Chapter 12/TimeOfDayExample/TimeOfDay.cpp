//******************************************************************
// IMPLEMENTATION FILE (TimeOfDay.cpp)
// This file implements the TimeOfDay member functions
//******************************************************************
#include "TimeOfDay.h"

#include <iostream>

using namespace std;

TimeOfDay::TimeOfDay() {
  hours = 0;
  minutes = 0;
  seconds = 0;
}

//******************************************************************

TimeOfDay::TimeOfDay(int initHours, int initMinutes, int initSeconds) {
  hours = initHours;
  minutes = initMinutes;
  seconds = initSeconds;
}

//******************************************************************

TimeOfDay TimeOfDay::Increment() const {
  // Create a duplicate of instance and increment duplicate
  TimeOfDay result(hours, minutes, seconds);
  result.seconds++;         // Increment seconds
  if (result.seconds > 59)  // Adjust if seconds carry
  {
    result.seconds = 0;
    result.minutes++;
    if (result.minutes > 59)  // Adjust if minutes carry
    {
      result.minutes = 0;
      result.hours++;
      if (result.hours > 23)  // Adjust if hours carry
        result.hours = 0;
    }
  }
  return result;
}

//******************************************************************

void TimeOfDay::Write() const {
  // Insert extra 0 if there is only one digit in a place
  if (hours < 10) cout << '0';
  cout << hours << ':';
  if (minutes < 10) cout << '0';
  cout << minutes << ':';
  if (seconds < 10) cout << '0';
  cout << seconds;
}

//******************************************************************

bool TimeOfDay::Equal(TimeOfDay otherTime) const {
  return (hours == otherTime.hours && minutes == otherTime.minutes &&
          seconds == otherTime.seconds);
}

//******************************************************************

bool TimeOfDay::LessThan(TimeOfDay otherTime) const {
  return (hours < otherTime.hours ||
          hours == otherTime.hours && minutes < otherTime.minutes ||
          hours == otherTime.hours && minutes == otherTime.minutes &&
              seconds < otherTime.seconds);
}
