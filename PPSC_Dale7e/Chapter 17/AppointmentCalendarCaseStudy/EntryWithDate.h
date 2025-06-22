//*******************************************
// SPECIFICATION File for class EntryWithDate
//*******************************************
#include "Date.h"
#include "Entry.h"
class EntryWithDate : public Entry {
 public:
  // Constructors
  EntryWithDate();
  EntryWithDate(Date initDate, TimeOfDay initTime, Name initName);
  // Knowledge responsibility
  Date GetDate() const;
  bool operator<(const EntryWithDate& otherEntry) const;
  // Post: Returns true if instance comes before otherEntry
  bool operator>(const EntryWithDate& otherEntry) const;
  // Post: Returns true if instance comes after otherEntry
  bool operator==(const EntryWithDate& otherEntry) const;
  // Post: Returns true if instance is the same date as otherEntry
  bool operator<=(const EntryWithDate& otherEntry) const;
  // Post: Returns true if instance is <= otherEntry
  bool operator>=(const EntryWithDate& otherEntry) const;
  // Post: Returns true if instance is >= otherEntry
  bool operator!=(const EntryWithDate& otherEntry) const;
  // Post: Returns true if instance is != otherEntry
 private:
  Date date;
};
