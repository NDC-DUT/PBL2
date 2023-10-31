
// #include "ALGORITHM/SKIPSEARCH.h"

#include "ITEMMANAGE.h"
#include "../DATETIME/DATE.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;


int main()
{
    ITEM_DB_MANAGER::init_item_container();
    size_t quan;
    size_t randquan;

    std::random_device rd;
    std::mt19937 rng(rd());
    for (ITEM &_it : ITEM_DB_MANAGER::item_cont_of_category(0, 0))
    {
        for (int i = 0; i < _it.classify().size(); ++i)
        {
            quan = _it.classify()[i].quantity();
            while (quan)
            {
                randquan = rng() % quan + 1;
                cout << _it.sku() << ' '
                     << i << ' '
                     << randdate("01072022", "30112022") << ' '
                     << randdate("01122022", "30062023") << ' '
                     << randquan << '\n';
                quan -= randquan;
            }
        }
    }
    return 0;
}
