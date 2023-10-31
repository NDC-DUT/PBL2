#pragma once
#include <string>
#include <time.h>

#include "DATE.h"
#include "INVALIDDATE.h"

time_t TIMETYPE = time(nullptr);
struct tm *TM;

unsigned short int Leap[]{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
unsigned short int NotLeap[]{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool valid(const unsigned &_day, const unsigned &_month, const unsigned &_year);
bool leap(const unsigned &_year);

class DATE
{
private:
    unsigned short int _day;
    unsigned short int _month;
    unsigned short int _year;
    void try_cast_str(const std::string &);

public:
    DATE();
    ~DATE() = default;

public:
    DATE(const DATE &);
    DATE(const unsigned short &, const unsigned short &, const unsigned short &);
    DATE(const std::string &);
    DATE(const char *);

public:
    bool leap();

public:
    unsigned short day() const;
    unsigned short month() const;
    unsigned short year() const;
    const std::string &dmy() const;
    DATE current();

public:
    bool operator>(const DATE &) const;
    bool operator>=(const DATE &) const;
    bool operator<(const DATE &) const;
    bool operator<=(const DATE &) const;
    bool operator==(const DATE &) const;
    DATE &operator=(const DATE &);
};

DATE randdate(DATE lowerdate, DATE upperdate);

#include "DATE.cc"