// Brittney Oeur
// Assginment #2: TimeSpan

#include <iostream>
#ifndef TIMESPAN
#define TIMESPAN

using namespace std;

class TimeSpan {
    public:
        int getSeconds();
        int getInSeconds() const;
        int getMinutes();
        int getHours();


        TimeSpan();
        TimeSpan(double currHours);
        TimeSpan(double currHours, double currMin);
        TimeSpan(double currHours, double currMin, double currSec);
        
        bool operator==(const TimeSpan &time) const;
        bool operator!=(const TimeSpan &time) const;
        bool operator>(const TimeSpan &time) const;
        bool operator<(const TimeSpan &time) const;
        bool operator>=(const TimeSpan &time) const;
        bool operator<=(const TimeSpan &time) const;
        bool isPositive();
        
        TimeSpan operator+(const TimeSpan &time) const;
        TimeSpan operator-(const TimeSpan &time) const;
        TimeSpan operator*(int num);
        TimeSpan operator+=(const TimeSpan &time);
        TimeSpan operator-=(const TimeSpan &time);

        friend ostream &operator<<(ostream &out, const TimeSpan &timeSpan);

    private:
        int Hours;
        int Minutes;
        int Seconds;
        bool Positive;

};

#endif