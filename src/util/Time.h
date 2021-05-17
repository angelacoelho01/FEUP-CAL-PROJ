#ifndef SRC_UTIL_TIME_H
#define SRC_UTIL_TIME_H

#include <string>
#include <ctime>

class Time {
public:
    Time();
    Time(int hour, int minute);

    unsigned getHour() const;
    unsigned getMinute() const;
    std::string getTime() const;

    void addHours(int hours);
    void addMinutes(int minutes);

    bool operator==(const Time& time) const;
    bool operator<(const Time& time) const;
    Time operator+(const Time& time);

    friend std::ostream& operator<<(std::ostream& os, const Time& time);

private:
    bool isValid() const;

    tm _time;
};


#endif //SRC_UTIL_TIME_H
