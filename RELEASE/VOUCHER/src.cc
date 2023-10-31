#include "GENERATE.h"

int main()
{
    INIT_VOUCHER_TREE();
    createVoucher();
    UPDATE_VOUCHER_DB();
    return 0;
}