#pragma once
#include <string>
#include <time.h>

#include "INVALIDTIME.h"

class TIME
{
private:
    unsigned short int _hour;
    unsigned short int _minute;
    unsigned short int _second;

public:
    TIME();
    TIME(const unsigned short int &, const unsigned short int &, const unsigned short int &);
    TIME(unsigned short int &&, unsigned short int &&, unsigned short int &&);
    TIME(const std::string &);
    TIME(std::string &&);
    ~TIME() = default;

public:
    unsigned short int hour() const;
    unsigned short int minute() const;
    unsigned short int second() const;
    std::string hms() const;

public:
    bool VALID();
    bool operator>(const TIME &);
    bool operator>(const TIME &&);
    bool operator<(const TIME &);
    bool operator<(const TIME &&);
    bool operator==(const TIME &);
    bool operator==(const TIME &&);
};

TIME::TIME()
{
    time_t TIMETYPE(time(nullptr));
    struct tm *TM = localtime(&TIMETYPE);
    _hour = TM->tm_hour;
    _minute = TM->tm_min;
    _second = TM->tm_sec;
}

#include "TIME.cc"