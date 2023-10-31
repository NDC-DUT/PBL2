#pragma once

#include "ITEMPROP.h"
#include "../DATASTRUCTURE/VECTOR.h"

class ITEM
{
    friend std::istream &operator>>(std::istream &, ITEM &);
    friend std::ostream &operator<<(std::ostream &, const ITEM &);

protected:
    std::string _sku;
    std::string _name;
    std::string _priname;
    std::string _origin_priname;
    VECTOR<ITEMPROP> _classify;
    short unsigned _nreview;
    float _medscore;

public:
    ITEM(const ITEM &RHS);
    ITEM(ITEM &&RHS);
    ITEM(const std::string &_sku,
         const std::string &_name,
         const std::string &_priname,
         const std::string &_origin_priname,
         const VECTOR<ITEMPROP> &_classify,
         const short unsigned &_nreview,
         const float &_medscore);
    ITEM(std::string &&_sku = "NULL",
         std::string &&_name = "NULL",
         std::string &&_priname = "NULL",
         std::string &&_origin_priname = "NULL",
         VECTOR<ITEMPROP> &&_classify = VECTOR<ITEMPROP>(),
         short unsigned &&_nreview = 0,
         float &&_medscore = 0.0);

    ~ITEM() = default;

    bool operator<(const ITEM &RHS) const;
    bool operator==(const ITEM &RHS) const;
    bool operator>(const ITEM &RHS) const;
    ITEM &operator=(const ITEM &RHS);
    ITEM &operator=(ITEM &&RHS);

public:
    std::string sku() const;
    std::string name() const;
    void name(std::string &&);
    std::string priname() const;
    void priname(std::string &&);
    std::string origin_priname() const;
    void origin_priname(std::string &&);
    size_t ntype() const;
    void addITEMPROP(ITEMPROP &&ip);
    void rmITEMPROP(const unsigned short &idx);
    void addQUANTITY(const short unsigned &thType, const size_t &_quantity);
    const VECTOR<ITEMPROP> &classify() const;
    void cost(const short unsigned &thType, const size_t &_ncost);
    void price(const short unsigned &thType, const size_t &_nprice);
    void promoprice(const short unsigned &thType, const size_t &_npromoprice);
    bool checkValidNewType(const std::string &_newType) const;
};

#include "ITEM.cc"