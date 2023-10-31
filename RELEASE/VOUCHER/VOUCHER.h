#pragma once
#include <stddef.h>
#include "../DATETIME/DATE.h"
#include <ostream>
class VOUCHER
{
    friend std::ostream &operator<<(std::ostream &, const VOUCHER &);

private:
    std::string _vid;
    size_t _vlowerBound;
    unsigned short _vpercent;
    size_t _vdiscount;
    DATE _vexpiry;

public:
    VOUCHER();
    VOUCHER(const std::string &, const size_t &, const unsigned short &, const size_t &, const DATE &);
    bool operator<(const VOUCHER &rhs) const;
    bool operator==(const VOUCHER &rhs) const;
    bool operator>(const VOUCHER &rhs) const;
    VOUCHER &operator=(const VOUCHER &rhs);
    size_t PriceAfterUseVoucher(const size_t &Initial_Price);

    ~VOUCHER() = default; //????

public:
    const DATE &expiry() const;
};

#include <cstring>

std::ostream &operator<<(std::ostream &os, const VOUCHER &V)
{
    std::string tmp = V._vexpiry.dmy();
    return os << V._vid << ' '
              << V._vlowerBound << ' '
              << V._vpercent << ' '
              << V._vdiscount << ' '
              << tmp << '\n';
}

VOUCHER::VOUCHER()
    : _vlowerBound{0}, _vpercent{0}, _vdiscount{0}, _vexpiry{DATE()}, _vid{"NULL"}
{
}

VOUCHER::VOUCHER(const std::string &_vid, const size_t &_vlowerBound, const unsigned short &_vpercent,
                 const size_t &_vdiscount, const DATE &_vexpiry)
    : _vlowerBound{_vlowerBound}, _vpercent{_vpercent},
      _vdiscount{_vdiscount}, _vexpiry{_vexpiry}, _vid(_vid)
{
}

bool VOUCHER::operator<(const VOUCHER &rhs) const
{
    return this->_vid < rhs._vid;
}

bool VOUCHER::operator==(const VOUCHER &rhs) const
{
    return this->_vid == rhs._vid;
}

bool VOUCHER::operator>(const VOUCHER &rhs) const
{
    return this->_vid > rhs._vid;
}

VOUCHER &VOUCHER::operator=(const VOUCHER &rhs)
{
    this->_vid = rhs._vid;
    this->_vlowerBound = rhs._vlowerBound;
    this->_vpercent = rhs._vpercent;
    this->_vdiscount = rhs._vdiscount;
    this->_vexpiry = rhs._vexpiry;
    return *this;
}
size_t VOUCHER::PriceAfterUseVoucher(const size_t &Initial_Price)
{
    // if (CheckValidVoucher() == false) {
    //     throw InvalidVoucher();
    // }
    return 0;
}

const DATE &VOUCHER::expiry() const
{
    return this->_vexpiry;
}