#include "Time.h"


Time::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
    normalize();
}


Time::~Time() {}


void Time::normalize() {
    if (seconds >= 60) {
        minutes += seconds / 60;
        seconds %= 60;
    }
    if (minutes >= 60) {
        hours += minutes / 60;
        minutes %= 60;
    }
    if (hours >= 24) {
        hours %= 24;
    }
}

Time Time::operator+(const Time& other) {
    Time result;
    result.seconds = seconds + other.seconds;
    result.minutes = minutes + other.minutes + result.seconds / 60;
    result.hours = hours + other.hours + result.minutes / 60;
    result.normalize();
    return result;
}

Time Time::operator-(const Time& other) {
    Time result;
    result.seconds = seconds - other.seconds;
    result.minutes = minutes - other.minutes;
    result.hours = hours - other.hours;
    if (result.seconds < 0) {
        result.seconds += 60;
        result.minutes--;
    }
    if (result.minutes < 0) {
        result.minutes += 60;
        result.hours--;
    }
    if (result.hours < 0) {
        result.hours += 24;
    }
    return result;
}


Time Time::operator++(int) {
    Time temp = *this;
    seconds++;
    normalize();
    return temp;
}


Time Time::operator--(int) {
    Time temp = *this;
    seconds--;
    if (seconds < 0) {
        seconds = 59;
        minutes--;
    }
    if (minutes < 0) {
        minutes = 59;
        hours--;
    }
    if (hours < 0) {
        hours = 23;
    }
    return temp;
}


bool Time::operator==(const Time& other) const {
    return (hours == other.hours && minutes == other.minutes && seconds == other.seconds);
}


bool Time::operator!=(const Time& other) const {
    return !(*this == other);
}

ostream& operator<<(ostream& os, const Time& t) {
    os << (t.hours < 10 ? "0" : "") << t.hours << ":"
        << (t.minutes < 10 ? "0" : "") << t.minutes << ":"
        << (t.seconds < 10 ? "0" : "") << t.seconds;
    return os;
}