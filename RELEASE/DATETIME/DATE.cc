
DATE::DATE()
{
    TM = localtime(&TIMETYPE);
    _day = TM->tm_mday;
    _month = TM->tm_mon + 1;
    _year = TM->tm_year + 1900;
}

DATE::DATE(const DATE &D)
    : _day{D._day}, _month{D._month}, _year{D._year} {}

DATE::DATE(const unsigned short &_day, const unsigned short &_month, const unsigned short &_year)
    : _year{_year}, _month{_month}, _day{_day}
{
    if (!valid(_day, _month, _year))
    {
        DATE();
        throw INVALIDDATE();
    }
}
DATE::DATE(const char *str)
    : DATE(std::string(str))
{
}
#include <iostream>
using namespace std;
DATE::DATE(const std::string &str)
{
    if (str.length() == 8)
    {
        for (int &&i{0}; i < 8; i++)
        {
            if (str[i] > '9' || str[i] < '0')
            {
                try
                {
                    try_cast_str(str);
                    return;
                }
                catch (...)
                {
                    DATE();
                    throw;
                }
            }
        }
        _day = (str[0] - '0') * 10 + (str[1] - '0');
        _month = (str[2] - '0') * 10 + (str[3] - '0');
        _year = (str[4] - '0') * 1000 + (str[5] - '0') * 100 + (str[6] - '0') * 10 + (str[7] - '0');
        if (!valid(this->_day, this->_month, this->_year))
        {
            DATE();
            throw INVALIDDATE();
        }
    }
    else
    {
        try
        {
            try_cast_str(str);
        }
        catch (...)
        {
            DATE();
            throw;
        }
    }
}

void DATE::try_cast_str(const std::string &str)
{
    unsigned dd, mm, yy;
    std::string dmypart[3];
    int idx = 0;
    int p = 0;
    while (p < str.length())
    {
        for (; p < str.length(); ++p)
        {
            if (std::isspace(str[p]))
                continue;
            if (std::isdigit(str[p]))
                dmypart[idx] += str[p];

            else
            {
                while (p < str.length() && !std::isdigit(str[p]))
                    ++p;
                ++idx;
                break;
            }
        }
        if (idx == 3)
            break;
    }
    dd = std::stoi(dmypart[0]);
    mm = std::stoi(dmypart[1]);
    yy = std::stoi(dmypart[2]);

    if (valid(dd, mm, yy))
    {
        this->_day = dd;
        this->_month = mm;
        this->_year = yy;
    }
    else
        throw INVALIDDATE();
}
bool DATE::leap()
{
    return _year % 400 == 0 || _year % 4 == 0 && _year % 100 != 0;
}

unsigned short DATE::day() const
{
    return _day;
}

unsigned short DATE::month() const
{
    return _month;
}

unsigned short DATE::year() const
{
    return _year;
}

const std::string &DATE::dmy() const
{
    static std::string ans{"00000000"};
    ans = std::to_string(_day) + std::to_string(_month) + std::to_string(_year);
    return ans;
}

bool DATE::operator>(const DATE &rhs) const
{
    if (this->_year > rhs._year)
        return true;
    if (this->_year < rhs._year)
        return false;
    if (this->_month > rhs._month)
        return true;
    if (this->_month < rhs._month)
        return false;
    if (this->_day > rhs._day)
        return true;
    return false;
}
bool DATE::operator>=(const DATE &rhs) const
{
    return operator>(rhs) || operator==(rhs);
}

bool DATE::operator<(const DATE &rhs) const
{
    if (this->_year < rhs._year)
        return true;
    if (this->_year > rhs._year)
        return false;
    if (this->_month < rhs._month)
        return true;
    if (this->_month > rhs._month)
        return false;
    if (this->_day < rhs._day)
        return true;
    return false;
}
bool DATE::operator<=(const DATE &rhs) const
{
    return operator<(rhs) || operator==(rhs);
}
bool DATE::operator==(const DATE &rhs) const
{
    return this->_year == rhs._year && this->_month == rhs._month && this->_day == rhs._day;
}

DATE &DATE::operator=(const DATE &rhs)
{
    this->_day = rhs._day;
    this->_month = rhs._month;
    this->_year = rhs._year;
    return *this;
}

DATE DATE::current()
{
    return DATE();
}

bool leap(const unsigned &_year)
{
    return _year % 400 == 0 || _year % 4 == 0 && _year % 100 != 0;
}

bool valid(const unsigned &_day, const unsigned &_month, const unsigned &_year)
{
    if (_month > 12 || _month == 0 || _day == 0)
        return false;
    if (leap(_year))
        return _day <= Leap[_month];
    return _day <= NotLeap[_month];
}
#include <random>

DATE randdate(DATE lowerdate, DATE upperdate)
{
    if (lowerdate > upperdate)
        return lowerdate;

    std::random_device rd;
    std::mt19937 rng(rd());

    int _year, _month, _day;
    _year = lowerdate.year() + rng() % (upperdate.year() - lowerdate.year() + 1);
    _month = rng() % 12 + 1;
    _day = rng() % 31 + 1;
    while (!valid(_day, _month, _year))
        _day = rng() % 31 + 1;
    return DATE(_day, _month, _year);
}
#include <iomanip>
ostream &operator<<(ostream &os, const DATE &d)
{
    return os << std::setfill('0') << std::setw(2) << d.day() << std::setw(2) << d.month() << std::setw(4) << d.year();
}