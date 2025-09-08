#ifndef TIME_H
#define TIME_H

class Time {
    private:
        int hrs;
        int mins;
        int secs;

    public:
        // Constructors
        Time();
        Time(int initHrs, int initMins, int initSecs);

        // Transformers
        void Set(int hours, int minutes, int seconds);
        void Increment();

        // Observers
        virtual void Write() const;
        bool Equal(Time otherTime) const;
        bool LessThan(Time otherTime) const;
        int GetHours() const;
        int GetMinutes() const;
        int GetSeconds() const;
};

#endif