#pragma once
#include "../Datetime/link.h"
#include "../CART/CART.h"
class PurchaseHistory
{
private:
    const char *username;
    DATE tradingdate;
    CART oldCART;

public:
    PurchaseHistory() = default;
    ~PurchaseHistory() = default;

public:
};