#include "Time.h"

Time::Time() {
    time_t tt = time(nullptr);
    day = localtime(&tt)->tm_mday;
    month = localtime(&tt)->tm_mon + 1;
    year = localtime(&tt)->tm_year + 1900;
    hour = localtime(&tt)->tm_hour;
    minute = localtime(&tt)->tm_min;
}

unsigned int Time::getDay() {
    return day;
}

unsigned int Time::getMonth() {
    return month;
}

unsigned int Time::getYear() {
    return year;
}

unsigned int Time::getHour() {
    return hour;
}

unsigned int Time::getMinute() {
    return minute;
}

std::string Time::GetDateAsString() const{
    return (
        ((day < 10) ? ("0" + std::to_string(day)) : (std::to_string(day))) + "." +
        ((month < 10) ? ("0" + std::to_string(month)) : (std::to_string(month))) + "." +
        std::to_string(year) + " " +
        ((hour < 10) ? ("0" + std::to_string(hour)) : (std::to_string(hour))) + ":" +
        ((minute < 10) ? ("0" + std::to_string(minute)) : (std::to_string(minute)))
    );
}

bool Time::operator>(const Time &other) {
    if (year < other.year) {
        return true;
    } else {
        if (month < other.month) {
            return true;
        } else {
            return day < other.day;
        }
    }
}