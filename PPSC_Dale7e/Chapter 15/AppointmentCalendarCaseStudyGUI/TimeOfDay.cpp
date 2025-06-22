//******************************************************************
// IMPLEMENTATION FILE (TimeOfDay.cpp)
// This file implements the TimeOfDay member functions as revised.
//******************************************************************
#include "TimeOfDay.h"
#include <iostream>
 
using namespace std;
 
TimeOfDay::TimeOfDay()
{
  hours = 0;
  minutes = 0;
  seconds = 0;
}
 
//******************************************************************
 
TimeOfDay::TimeOfDay(int initHours, int initMinutes,
                     int initSeconds)
{
  hours = initHours;
  minutes = initMinutes;
  seconds = initSeconds;
}
 
//******************************************************************
 
TimeOfDay TimeOfDay::Increment() const
{
  // Create a duplicate of instance and increment duplicate
  TimeOfDay result(hours, minutes, seconds);
  result.seconds = result.seconds++;  // Increment seconds
  if (result.seconds > 59)            // Adjust if seconds carry
  {
    result.seconds = 0;
    result.minutes = result.minutes++;
    if (result.minutes > 59)          // Adjust if minutes carry
    {
      result.minutes = 0;
      result.hours = result.hours++;
     if (result.hours > 23)          // Adjust if hours carry
        result.hours = 0;
    }
  }
  return result;
}
 
//******************************************************************
 
int TimeOfDay::GetHours() const
{ return hours; }
 
//*****************************************************************
 
int TimeOfDay::GetMinutes() const
{ return minutes; }
 
//*****************************************************************
 
int TimeOfDay::GetSeconds() const
{ return seconds; }
 
//******************************************************************
 
RelationType TimeOfDay::ComparedTo(TimeOfDay otherTime) const
{
  if (hours < otherTime.hours)
    return BEFORE;
  else if (hours > otherTime.hours)
    return AFTER;
  else if (minutes < otherTime.minutes)
    return BEFORE;
  else if (minutes > otherTime.minutes)
    return AFTER;
  else if (seconds < otherTime.seconds)
    return BEFORE;
  else if (seconds > otherTime.seconds)
    return AFTER;
  else
    return SAME;
}
