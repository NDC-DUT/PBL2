#pragma once
template <class DATA_T1, class DATA_T2>
class PAIR
{
public:
    DATA_T1 first;
    DATA_T2 second;

public:
    PAIR(const PAIR &);
    PAIR(PAIR &&);
    PAIR(const DATA_T1 &, const DATA_T2 &);
    PAIR(DATA_T1 && = DATA_T1(), DATA_T2 && = DATA_T2());

public:
    ~PAIR() = default;

public:
    PAIR operator=(const PAIR &);
    PAIR operator=(PAIR &&);
    bool operator<(const PAIR &);
};
#include "PAIR.cc"