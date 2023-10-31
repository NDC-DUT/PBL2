// #include "CREATE.h"

void createVoucher()
{
    clrscr();
    tc_cursor_on();
    tc_echo_on();

    size_t _lowerBound, _percent, _discount, _genNum;
    DATE ExpiryDate;
    getVoucherInfo(_lowerBound, _percent, _discount, _genNum, ExpiryDate);

    std::string _vid("0000000000");
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<int> dist(0, 25);
    auto genChar = [&](char &ch) mutable
    {
        switch (dist(engine) % 3)
        {
        case 0:
            ch = dist(rd) + 'a';
            break;
        case 1:
            ch = dist(rd) + 'A';
            break;
        case 2:
            ch = dist(rd) % 10 + '0';
            break;
        default:
            break;
        }
    };
    VOUCHER tmp;
    bool _success;
    for (int &&i{0}; i < _genNum; ++i)
    {
        while (true)
        {
            for (char &ch : _vid)
                genChar(ch);
            VOUCHER_MANAGER_CLASS::INSERT_NEW_VOUCHER(VOUCHER(_vid, _lowerBound, _percent, _discount, ExpiryDate), &_success);
            if (!_success)
                continue;
            break;
        }
    }
    tc_cursor_off();
    tc_echo_off();
    clrscr();
}

void getDATE(DATE &_date)
{
    std::string _inDate;
    while (true)
    {
        try
        {
            std::getline(std::cin, _inDate);
            _date = DATE(_inDate);
            if (_date < DATE())
                throw INVALIDDATE();
        }
        catch (const INVALIDDATE &exp)
        {
            printf("%s%s\n", BHRED, exp.what());
            printf("%sNhập lại : %s", BHMAG, BHGRN);
            continue;
        }
        break;
    }
}
void getVoucherInfo(size_t &_lowerBound, size_t &_percent, size_t &_discount, size_t &_genNum, DATE &ExpiryDate)
{
    _lowerBound = getULL("Giá trị tối thiểu");
    _percent = getULL("% giảm giá");

    if (_percent == 0)
        _discount = getULL("Số tiền giảm giá");

    else
        _discount = 0;
    printf("%sNgày hết hạn : %s", BHCYN, BHGRN);
    getDATE(ExpiryDate);
    _genNum = getULL("Số lượng voucher cần tạo");
}