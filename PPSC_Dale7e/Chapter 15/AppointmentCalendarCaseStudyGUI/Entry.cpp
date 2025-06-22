//*****************************************************************
// IMPLEMENTATION FILE (Entry.cpp)
// This file contains the specification of the Entry ADT,
// which has two contained classes, Name and Time
//*****************************************************************

#include "Entry.h"

#include <iostream>
#include <string>

using namespace std;

Entry::Entry() {}

//*************************************************************

Entry::Entry(string firstName, string middleName, string lastName,
             int initHours, int initMinutes, int initSeconds)

    : name(firstName, middleName, lastName),
      time(initHours, initMinutes, initSeconds) {}

//*************************************************************

TimeOfDay Entry::GetTime() const { return time; }

//************************************************************

Name Entry::GetName() const { return name; }
