#include <iostream>
#include "exttime.h"

using namespace std;

ExtTime::ExtTime() {
    zone = CST;
}

ExtTime::ExtTime(int initHrs, int initMins, int initSecs, ZoneType initZone)
    : Time(initHrs, initMins, initSecs) {
    zone = initZone;
}

void ExtTime::Set(int hrs, int mins, int secs, ZoneType timeZone) {
    Time::Set(hrs, mins, secs);
    zone = timeZone;
}

ZoneType ExtTime::Zone() const {
    return zone;
}

void ExtTime::Write() const {
    static string zoneString[8] = {"EST", "CST", "MST", "PST", "EDT", "CDT", "MDT", "PDT"};

    Time::Write();
    cout << ' ' << zoneString[zone];
}