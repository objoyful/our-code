//*************************** time.h *******************************
// Homer Simpson, Project XYZ, CPE 212-01
// Purpose: Declaration of class to represent Time ADT
//******************************************************************

// set the guard for the header file
#ifndef TIME_H
#define TIME_H
// extern int globalInt;

static int objectNumber = 0;
class Time {
    private:  // Private members here
        int hrs;                // Valid range 0-23 inclusive
        int mins;               // Valid range 0-59 inclusive
        int secs;
        int objNum;               // Valid range 0-59 inclusive

    protected:    // Protected members here -- none required

    public:   // Public members here
        /******* Constructors *******/

        Time();             // Default constructor sets Time to 0:0:0

        // Parameterized constructor: Constructs Time using incoming parameters
        Time(int, int, int); // 3 parameters    
        Time(int, int); // 2 parameters
        Time(int); // 1 parameter

        /******* Transformers *******/
        void Set(int, int, int);     // Sets Time based on incoming parameters

        void Increment();           // Time has been advanced by one second,
        void Increment(int);           // advance by # seconds
        void Increment(int, int);           // advance by #seconds and #minutes
        void Increment(int, int, int);           // advance by #seconds and #minutes and #hours
        void Increment(float);           // advance by floating point number of hours

        /******* Observers *******/
        void Write() const;         // Time has been output in the form HH:MM:SS

        bool Equal(Time) const;      // Function value == true, if this time equals otherTime;
                                                // value false otherwise

        bool LessThan(Time) const;       // Function value == true, if this time is earlier;
                                                    // value false otherwise
                                                    // Assuming this time and otherTime represent times in the same day
        /******* Iterators - none *******/

        /******* Destructors - none *******/
        ~Time();    // default destructor
};

#endif