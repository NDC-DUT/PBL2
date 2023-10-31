#include "MANAGE.h"

AVLTree<VOUCHER> VOUCHER_MANAGER_CLASS::VOUCHER_DS;

void VOUCHER_MANAGER_CLASS::INIT_VOUCHER_DS(std::string DB_PATH)
{
    std::ifstream _v_stream;
    _v_stream.open(DB_PATH);
    if (!_v_stream.is_open())
        return;
        
    std::string ID;
    size_t LowerBound;
    short unsigned PercentDiscount;
    size_t MoneyDiscount;
    std::string tmp;
    VOUCHER VTMP;
    DATE _curdate = DATE();
    while (_v_stream >> ID >> LowerBound >> PercentDiscount >> MoneyDiscount >> tmp)
    {
        VTMP = VOUCHER(ID, LowerBound, PercentDiscount, MoneyDiscount, tmp);
        if (VTMP.expiry() >= _curdate)
            VOUCHER_MANAGER_CLASS::VOUCHER_DS.Insert(VTMP);
    }

    _v_stream.close();
}

void VOUCHER_MANAGER_CLASS::UPDATE_VOUCHER_DB(std::string DB_PATH)
{
    std::ofstream _v_stream;
    _v_stream.open(DB_PATH, std::ios::trunc);

    VOUCHER_MANAGER_CLASS::VOUCHER_DS.RNL(_v_stream);

    _v_stream.close();
}

void VOUCHER_MANAGER_CLASS::INSERT_NEW_VOUCHER(VOUCHER &&mv_voucher, bool *SUCCESS)
{
    VOUCHER_MANAGER_CLASS::VOUCHER_DS.Insert(std::move(mv_voucher), SUCCESS);
}