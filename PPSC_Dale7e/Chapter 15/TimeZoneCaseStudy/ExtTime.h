#ifndef EXTTIME_H
#define EXTTIME_H

#include "TimeOfDay.h"

enum ZoneType { PST, MST, CST, EST };

class ExtTime : public TimeOfDay {
 public:
  // Constructors
  ExtTime(int newHours, int newMinutes, int newSeconds, ZoneType newZone);
  ExtTime();  //   setting time to 0:0:0 EST

  // Knowledge responsibilities
  ZoneType GetZone() const;
  // Returns the time zone
  RelationType ComparedTo(ExtTime otherTime) const;
  // Post: Returns
  //       BEFORE if instance is earlier than otherTime;
  //       SAME if they are identical;
  //       AFTER if instance is later than otherTime
 private:
  ZoneType zone;
};

#endif  // EXTTIME_H
