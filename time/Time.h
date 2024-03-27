#ifndef TIME_H
#define TIME_H

#include <string>
#include <ctime>

class Time {
public:
    Time();

    unsigned int getDay();
    unsigned int getMonth();
    unsigned int getYear();
    unsigned int getHour();
    unsigned int getMinute();
    
    std::string GetDateAsString() const;

    bool operator>(const Time &other);

private:
    unsigned int day;
    unsigned int month;
    unsigned int year;

    unsigned int hour;
    unsigned int minute;
};

#endif // TIME_H