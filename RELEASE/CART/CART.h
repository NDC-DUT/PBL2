#pragma once

#include "../ITEM/ITEM.h"
#include "../DATASTRUCTURE/PAIR.h"
#include "../DATASTRUCTURE/VECTOR.h"

class CART
{
private:
    VECTOR<PAIR<ITEM, unsigned short>> CARTCont;
    unsigned long long totPrice;

public:
    CART();
    CART(VECTOR<PAIR<ITEM, unsigned short>> &&CARTCont);
    ~CART() = default;

public:
    void AddToCART(const ITEM &, const short unsigned &);
    void RemoveFromCART(const ITEM &);
    unsigned long long GetPrice();
};

CART::CART(/* args */)
    : totPrice{0}
{
}

CART::CART(VECTOR<PAIR<ITEM, unsigned short>> &&CARTCont)
    : CARTCont{std::move(CARTCont)}
{
    for (int &&i{0}; i < CARTCont.size(); ++i)
        totPrice = totPrice + CARTCont[i].first().GetPrice() * CARTCont[i].second();
}

void CART::AddToCART(const ITEM &ITEM, const short unsigned &thType)
{
    int FindITEMIndex = -1;
    for (int &&i{0}; i < CARTCont.size(); ++i)
    {
        if (CARTCont[i].first() == ITEM)
        {
            FindITEMIndex = i;
            break;
        }
    }
    if (FindITEMIndex != -1)
        CARTCont[FindITEMIndex].second() += 1;
    else
    {
        PAIR<ITEM, unsigned short> &&Temp{ITEM, static_cast<unsigned short>(1)};
        CARTCont.push_back(Temp);
        FindITEMIndex = CARTCont.size() - 1;
    }
    totPrice = totPrice + ITEM.GetPrice(thType);
}

void CART::RemoveFromCART(const ITEM &ITEM)
{
    int FindITEMIndex = -1;
    for (int &&i{0}; i < CARTCont.size(); ++i)
    {
        if (CARTCont[i].first() == ITEM)
        {
            FindITEMIndex = i;
            break;
        }
    }
    CARTCont.remove(FindITEMIndex);
    totPrice = totPrice - ITEM.GetPrice();
}

unsigned long long CART::GetPrice()
{
    return totPrice;
}