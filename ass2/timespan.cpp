#include <iostream>
#include <iomanip>
#include "timespan.h"

TimeSpan::TimeSpan() {
    Hours = 0;
    Minutes = 0;
    Seconds = 0;
}

TimeSpan::TimeSpan(double currHours) {
    Hours = currHours;
    Minutes = 0;
    Seconds = 0;

    Positive = Hours >= 0;

    // Takes absolute value.
    Hours = abs(Hours);
}

TimeSpan::TimeSpan(double currHours, double currMin) {
    Minutes = currMin + (currHours * 60);
    Positive = Minutes >= 0;

    // Takes absolute value.
    Minutes = abs(Minutes);

    // Convert minutes to hours.
    Hours = Minutes / 60;

    // Reduces the minutes if it is above 60.
    Minutes %= 60;

    Seconds = 0;
}

TimeSpan::TimeSpan(double currHours, double currMin, double currSec) {
    Seconds = (currHours * 3600) + (currMin * 60) + currSec;
    Positive = Seconds >= 0;

    // Takes absolute value.
    Seconds = abs(Seconds);

    // Converts seconds to minutes.
    Minutes = Seconds / 60;

    // Reduces the seconds if it is above 60.
    // If second is '60' it will be 0.
    Seconds %= 60;

    // Converts minutes to hours.
    Hours = Minutes / 60;

    // Reduces the minutes if it is above 60.
    // If minute is '60' it will be 0.
    Minutes %= 60;
}

bool TimeSpan::isPositive() {
    return Positive;
}

int TimeSpan::getInSeconds() const {
    return (Hours * 3600 + Minutes * 60 + Seconds);
}

int TimeSpan::getSeconds() {
    return Seconds;
}

int TimeSpan::getMinutes() {
    return Minutes;
}

int TimeSpan::getHours() {
    return Hours;
}

bool TimeSpan::operator==(const TimeSpan& time) const {
    return getInSeconds() == time.getInSeconds();
}

bool TimeSpan::operator!=(const TimeSpan& time) const {
    return !(*this == time);
}

bool TimeSpan::operator>(const TimeSpan &time) const {
    return getInSeconds() > time.getInSeconds();
}

bool TimeSpan::operator<(const TimeSpan &time) const {
    return getInSeconds() < time.getInSeconds();
}

bool TimeSpan::operator>=(const TimeSpan &time) const {
    return (*this >= time);
}

bool TimeSpan::operator<=(const TimeSpan &time) const {
    return (*this <= time);
}

TimeSpan TimeSpan::operator+(const TimeSpan &time) const {
    int sec;
    sec = getInSeconds() + time.getInSeconds();

    TimeSpan res(0, 0, sec);

    return res;
}

TimeSpan TimeSpan::operator-(const TimeSpan &time) const {
    int sec;
    sec = getInSeconds() - time.getInSeconds();

    TimeSpan res(0, 0, sec);

    return res;
}

TimeSpan TimeSpan::operator*(int num) {
    return TimeSpan(0, 0, getInSeconds() * num);
}

TimeSpan TimeSpan::operator+=(const TimeSpan& time) {
    int sec;
    sec = getInSeconds() + time.getInSeconds();
    TimeSpan res(0, 0, sec);

    Hours = res.Hours;
    Minutes = res.Minutes;
    Seconds = res.Seconds;

    return *this;
}

TimeSpan TimeSpan::operator-=(const TimeSpan& time) {
    int sec;
    sec = getInSeconds() - time.getInSeconds();
    TimeSpan res(0, 0, sec);

    Hours = res.Hours;
    Minutes = res.Minutes;
    Seconds = res.Seconds;

    return *this;
}

ostream &operator<<(ostream &out, const TimeSpan &timeSpan) {
    out << (timeSpan.Positive ? "" : "-");
    out << timeSpan.Hours << ":" << setw(2) << setfill('0') << timeSpan.Minutes << ":" << setw(2) << setfill('0') << timeSpan.Seconds;

    return out;
}