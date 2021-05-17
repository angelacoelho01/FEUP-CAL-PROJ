#include "Time.h"

#include <iomanip>
#include <iostream>

#include "../model/exception/TimeException.h"

Time::Time() : _time{0, 0, 0, 1, 1} {
    time_t t = std::time(nullptr);
    localtime_r(&t, &_time);
}

Time::Time(int hour, int minute) : _time() {
    _time.tm_hour = hour;
    _time.tm_min = minute;
    _time.tm_year = 2021 - 1900;
    _time.tm_mon = 1;
    _time.tm_mday = 1;
    _time.tm_isdst = -1;
    if(!isValid()) throw InvalidTime(getTime());
}

unsigned Time::getHour() const {
    return (unsigned) _time.tm_hour;
}

unsigned Time::getMinute() const {
    return (unsigned) _time.tm_min;
}

std::string  Time::getTime() const {
    std::ostringstream os;
    os << std::right << std::setfill('0') << std::setw(2) << getHour()
        << ':' << std::setw(2) << getMinute();
    return os.str();
}

void Time::addHours(int hours) {
    _time.tm_hour += hours;
    std::time_t time = mktime(&_time);
    localtime_r(&time,&_time);
}

void Time::addMinutes(int minutes) {
    _time.tm_min += minutes;
    std::time_t time = mktime(&_time);
    localtime_r(&time,&_time);
}

bool Time::operator==(const Time &time) const {
    return getTime() == time.getTime();
}

bool Time::operator<(const Time &time) const {
    return getTime() < time.getTime();
}

Time Time::operator+(const Time &time) {
    this->addMinutes((int) time.getMinute());
    this->addHours((int) time.getHour());
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Time& time) {
    os << time.getTime();
    return os;
}

bool Time::isValid() const {
    if(getHour() >= 24 || getMinute() >= 60) return false;
    return true;
}