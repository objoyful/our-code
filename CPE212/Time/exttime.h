#include "time.h"

enum ZoneType {EST, CST, MST, PST, EDT, CDT, MDT, PDT};

class ExtTime: public Time {
    private:
        ZoneType zone;
    
    public:
        ExtTime();
        ExtTime(int initHrs, int initMins, int initSecs, ZoneType initZone);

        void Set(int hrs, int mins, int secs, ZoneType zone);
        void Write() const;

        ZoneType Zone() const;

};