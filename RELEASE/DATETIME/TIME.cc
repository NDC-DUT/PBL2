
TIME::TIME(const unsigned short int &_hour, const unsigned short int &_minute, const unsigned short int &_second)
    : _hour{_hour}, _minute{_minute}, _second{_second}
{
    if (this->VALID() == 0)
    {
        TIME();
        throw INVALIDTIME();
    }
}

TIME::TIME(unsigned short int &&_hour, unsigned short int &&_minute, unsigned short int &&_second)
    : _hour{_hour}, _minute{_minute}, _second{_second}
{
    if (this->VALID() == 0)
    {
        TIME();
        throw INVALIDTIME();
    }
}

TIME::TIME(const std::string &str)
{
    if (str.length() == 6)
    {
        for (int &&i{0}; i < 6; i++)
        {
            if (str[i] > '9' || str[i] < '0')
            {
                TIME();
                throw INVALIDTIME();
            }
        }
        _hour = (str[0] - '0') * 10 + (str[1] - '0');
        _minute = (str[2] - '0') * 10 + (str[3] - '0');
        _second = (str[4] - '0') * 10 + (str[5] - '0');
        if (this->VALID() == 0)
        {
            TIME();
            throw INVALIDTIME();
        }
    }
    else
    {
        TIME();
        throw INVALIDTIME();
    }
}

TIME::TIME(std::string &&str)
{
    if (str.length() == 6)
    {
        for (int &&i{0}; i < 6; i++)
        {
            if (str[i] > '9' || str[i] < '0')
            {
                TIME();
                throw INVALIDTIME();
            }
        }
        _hour = (str[0] - '0') * 10 + (str[1] - '0');
        _minute = (str[2] - '0') * 10 + (str[3] - '0');
        _second = (str[4] - '0') * 10 + (str[5] - '0');
        if (this->VALID() == 0)
        {
            TIME();
            throw INVALIDTIME();
        }
    }
    else
    {
        TIME();
        throw INVALIDTIME();
    }
}

bool TIME::VALID()
{
    if (_hour > 24 || _hour < 0)
        return false;
    if (_minute > 60 || _minute < 0)
        return false;
    if (_second > 60 || _second < 0)
        return false;
    return true;
}

unsigned short int TIME::second() const { return _second; }

unsigned short int TIME::minute() const { return _minute; }

unsigned short int TIME::hour() const { return _hour; }

std::string TIME::hms() const
{
    std::string ans{"000000"};
    ans[0] = _hour / 10 + '0';
    ans[1] = _hour % 10 + '0';
    ans[2] = _minute / 10 + '0';
    ans[3] = _minute % 10 + '0';
    ans[4] = _second / 10 + '0';
    ans[5] = _second % 10 + '0';
    return ans;
}

bool TIME::operator>(const TIME &rhs)
{
    if (this->_hour > rhs._hour)
        return true;
    if (this->_hour < rhs._hour)
        return false;
    if (this->_minute > rhs._minute)
        return true;
    if (this->_minute < rhs._minute)
        return false;
    if (this->_second > rhs._second)
        return true;
    return false;
}

bool TIME::operator>(const TIME &&rhs)
{
    if (this->_hour > rhs._hour)
        return true;
    if (this->_hour < rhs._hour)
        return false;
    if (this->_minute > rhs._minute)
        return true;
    if (this->_minute < rhs._minute)
        return false;
    if (this->_second > rhs._second)
        return true;
    return false;
}

bool TIME::operator<(const TIME &rhs)
{
    if (this->_hour < rhs._hour)
        return true;
    if (this->_hour > rhs._hour)
        return false;
    if (this->_minute < rhs._minute)
        return true;
    if (this->_minute > rhs._minute)
        return false;
    if (this->_second < rhs._second)
        return true;
    return false;
}

bool TIME::operator<(const TIME &&rhs)
{
    if (this->_hour < rhs._hour)
        return true;
    if (this->_hour > rhs._hour)
        return false;
    if (this->_minute < rhs._minute)
        return true;
    if (this->_minute > rhs._minute)
        return false;
    if (this->_second < rhs._second)
        return true;
    return false;
}

bool TIME::operator==(const TIME &rhs)
{
    return this->_hour == rhs._hour && this->_minute == rhs._minute && this->_second == rhs._second;
}

bool TIME::operator==(const TIME &&rhs)
{
    return this->_hour == rhs._hour && this->_minute == rhs._minute && this->_second == rhs._second;
}
#include <iomanip>
std::ostream &operator<<(std::ostream &os, const TIME &t)
{
    return os << std::setfill('0') << std::setw(2) << t.hour() << std::setw(2) << t.minute() << std::setw(2) << t.second();
}