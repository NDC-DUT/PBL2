#pragma once
#include <regex>
#include <string>
#include <iostream>
class ITEMPROP
{
    friend std::istream &operator>>(std::istream &is, ITEMPROP &ip);
    friend std::ostream &operator<<(std::ostream &os, const ITEMPROP &ip);

protected:
    std::string _unit;
    size_t _cost;
    size_t _price;
    size_t _promoPrice;
    size_t _quantity;

public:
    ITEMPROP() = default;
    ITEMPROP(std::string &&_unit,
             size_t &_cost,
             size_t &_price,
             size_t &_promoPrice,
             size_t &_quantity);

public: // setter
    void unit(const std::string &);
    void cost(const size_t &);
    void price(const size_t &);
    void promoprice(const size_t &);
    void quantity(const size_t &);

public: // getter
    const std::string &unit() const;
    const size_t &cost() const;
    const size_t &price() const;
    const size_t &promoprice() const;
    const size_t &quantity() const;

public:
    ~ITEMPROP() = default;

public:
    bool operator<(const ITEMPROP &_ip);
    ITEMPROP &operator=(const ITEMPROP &_ip);
};

void RemoveVietnameseTone(std::string &text);
void lowercaseStr(std::string &text);
bool IsVietNameseString(const std::string &text);
void LowercaseVietNameseCharacter(std::string &text);
#include "ITEMPROP.cc"