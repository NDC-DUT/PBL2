#include <iostream>
#include <fstream>
#include "ITEMMANAGE.h"
void ProcessITEMDB(const std::string &src, const std::string &dest)
{
    std::ifstream srcDB;
    srcDB.open(src, std::ios::in);
    std::ofstream destDB;
    destDB.open(dest, std::ios::out | std::ios::app);

    std::string _sku;
    std::string _name;
    unsigned int nUnit;
    VECTOR<ITEMPROP> _classify;
    std::string Unit;
    size_t Cost;
    size_t Price;
    size_t PromoPrice;
    size_t Quantity;
    unsigned short _nreview;
    float _medscore;

    while (srcDB >> _sku)
    {
        srcDB.ignore(1);
        std::getline(srcDB, _name);
        destDB << _sku << " " << _name << '\n';
        RemoveVietnameseTone(_name);
        lowercaseStr(_name);
        destDB << _name << '\n';
        srcDB >> nUnit;
        destDB << nUnit << '\n';
        for (int &&i{0}; i < nUnit; ++i)
        {
            srcDB >> Unit >> Cost >> Price >> PromoPrice >> Quantity;
            destDB << Unit << ' '
                   << Cost << ' '
                   << Price << ' '
                   << PromoPrice << ' '
                   << Quantity << '\n';
            _classify.push_back(ITEMPROP(std::move(Unit), Cost, Price, PromoPrice, Quantity));
        }
        srcDB >> _nreview >> _medscore;
        destDB << 0 << ' ' << 0 << '\n'
               << '\n';
    }

    srcDB.close();
    destDB.close();
    std::ofstream truncSRCdb;
    truncSRCdb.open(src, std::ios::trunc);
    truncSRCdb.close();
}

int main()
{
    ProcessITEMDB("unprocess.txt", "process.txt");
    return 0;
}