// #include "EDITHISTORY.h"

EDIT_OBJECT::EDIT_OBJECT(std::string &&_EDIT_ID,
                         std::string &&_EDIT_TYPE,
                         std::string &&_EDIT_MESSAGE,
                         std::string &&_EDIT_DATE,
                         std::string &&_EDIT_TIME)
    : _EDIT_ID(std::move(_EDIT_ID)),
      _EDIT_TYPE(std::move(_EDIT_TYPE)),
      _EDIT_MESSAGE(std::move(_EDIT_MESSAGE)),
      _EDIT_DATE(std::move(_EDIT_DATE)),
      _EDIT_TIME(std::move(_EDIT_TIME))
{
}
EDIT_OBJECT::EDIT_OBJECT(std::string &&_EDIT_ID,
                         std::string &&_EDIT_TYPE,
                         std::string &&_EDIT_MESSAGE,
                         DATE &_EDIT_DATE,
                         TIME &_EDIT_TIME)
    : _EDIT_ID(std::move(_EDIT_ID)),
      _EDIT_TYPE(std::move(_EDIT_TYPE)),
      _EDIT_MESSAGE(std::move(_EDIT_MESSAGE)),
      _EDIT_DATE(_EDIT_DATE),
      _EDIT_TIME(_EDIT_TIME)
{
}
const std::string &EDIT_OBJECT::EDIT_ID() const
{
    return this->_EDIT_ID;
}
const std::string &EDIT_OBJECT::EDIT_TYPE() const
{
    return this->_EDIT_TYPE;
}
const std::string &EDIT_OBJECT::EDIT_MESSAGE() const
{
    return this->_EDIT_MESSAGE;
}
const DATE &EDIT_OBJECT::EDIT_DATE() const
{
    return this->_EDIT_DATE;
}
const TIME &EDIT_OBJECT::EDIT_TIME() const
{
    return this->_EDIT_TIME;
}
std::ostream &operator<<(std::ostream &os, const EDIT_OBJECT &eobj)
{
    return os << eobj.EDIT_ID() << ' '
              << eobj.EDIT_TYPE() << '\n'
              << eobj.EDIT_MESSAGE() << '\n'
              << eobj.EDIT_DATE() << ' '
              << eobj.EDIT_TIME() << '\n';
}
DList<EDIT_OBJECT> EDIT_HISTORY::HISTORY_DB;
size_t EDIT_HISTORY::_CURRENT_ID(0);
void EDIT_HISTORY::ADD_HISTORY(std::string EDIT_TYPE, std::string EDIT_MESSAGE, DATE EDIT_DATE, TIME EDIT_TIME)
{
    std::string cur_ID = std::to_string(_CURRENT_ID++);
    EDIT_HISTORY::HISTORY_DB.push_front(EDIT_OBJECT(std::string("EH") + std::string(10 - cur_ID.length(), '0') + cur_ID,
                                                    std::move(EDIT_TYPE),
                                                    std::move(EDIT_MESSAGE),
                                                    EDIT_DATE,
                                                    EDIT_TIME));
}
void EDIT_HISTORY::INIT_HISTORY(std::string fpath)
{
    std::ifstream INIT_STREAM;
    INIT_STREAM.open(fpath);
    std::string _EDIT_ID, _EDIT_TYPE, _EDIT_MESSAGE, _EDIT_DATE, _EDIT_TIME;

    INIT_STREAM >> EDIT_HISTORY::_CURRENT_ID;
    while (INIT_STREAM >> _EDIT_ID)
    {
        INIT_STREAM >> _EDIT_TYPE;
        INIT_STREAM.ignore(1);
        std::getline(INIT_STREAM, _EDIT_MESSAGE);
        INIT_STREAM >> _EDIT_DATE >> _EDIT_TIME;
        EDIT_HISTORY::HISTORY_DB.push_back(EDIT_OBJECT(std::move(_EDIT_ID), std::move(_EDIT_TYPE), std::move(_EDIT_MESSAGE), std::move(_EDIT_DATE), std::move(_EDIT_TIME)));
    }
    INIT_STREAM.close();
}
void EDIT_HISTORY::UPDATE_HISTORY(std::string fpath)
{
    std::ofstream UPDATE_STREAM;
    UPDATE_STREAM.open(fpath);
    UPDATE_STREAM << EDIT_HISTORY::_CURRENT_ID << '\n';
    for (DListNode<EDIT_OBJECT> *_ptr = EDIT_HISTORY::HISTORY_DB.head(); _ptr != nullptr; _ptr = _ptr->_pAfter)
        UPDATE_STREAM << _ptr->_value << '\n';

    UPDATE_STREAM.close();
}
DListNode<EDIT_OBJECT> *EDIT_HISTORY::head()
{
    return EDIT_HISTORY::HISTORY_DB.head();
}
#include <sstream>
void displayEditObjectContent(const EDIT_OBJECT &eobj)
{
    std::stringstream StrStream;
    int _UpperCat, _LowerCat;
    std::string _Sku;
    const DATE &refDate = eobj.EDIT_DATE();
    const TIME &refTime = eobj.EDIT_TIME();
    StrStream.str(eobj.EDIT_MESSAGE());

    std::cout << WHTHB << BHCYN << "ID : " << eobj.EDIT_ID() << CRESET << '\t';
    std::cout << GRNHB << BHBLU
              << refDate.day() << '.' << refDate.month() << '.' << refDate.year() << ' '
              << refTime.hour() << ':' << refTime.minute() << ':' << refTime.second() << CRESET << "\n\n";
    std::cout << YELHB << BHRED << "Nội dung chỉnh sửa"
              << CRESET << "\n\n";
    if (eobj.EDIT_TYPE() == "ADDITEM")
    {
        StrStream >> _UpperCat >> _LowerCat >> _Sku;
        std::cout << BHGRN << "Thêm sản phẩm có sku " << BHCYN << _Sku << BHGRN << " vào danh mục\n";

        std::cout << GRNHB << BHRED << ITEM_DB_MANAGER::th_category(_UpperCat) << CRESET << '\n';
        if (ITEM_DB_MANAGER::th_sub_category(_UpperCat).size() != 0)
            std::cout << YELHB << BHMAG << ITEM_DB_MANAGER::th_sub_category(_UpperCat)[_LowerCat] << CRESET << "\n\n";
        return;
    }
    if (eobj.EDIT_TYPE() == "UPCAT")
    {
        int uc_old, lc_old, uc_new, lc_new;
        StrStream >> uc_old >> lc_old >> _Sku >> uc_new >> lc_new;
        std::cout << BHGRN << "Chuyển sản phẩm có sku " << BHCYN << _Sku << BHGRN << " từ danh mục\n";
        std::cout << GRNHB << BHRED << ITEM_DB_MANAGER::th_category(uc_old) << CRESET << '\n';
        if (ITEM_DB_MANAGER::th_sub_category(uc_old).size() != 0)
            std::cout << YELHB << BHMAG << ITEM_DB_MANAGER::th_sub_category(uc_old)[lc_old] << CRESET << "\n\n";
        std::cout << BHGRN << "sang danh mục"
                  << '\n'
                  << '\n';
        std::cout << GRNHB << BHRED << ITEM_DB_MANAGER::th_category(uc_new) << CRESET << '\n';
        if (ITEM_DB_MANAGER::th_sub_category(uc_new).size() != 0)
            std::cout << YELHB << BHMAG << ITEM_DB_MANAGER::th_sub_category(uc_new)[lc_new] << CRESET << "\n\n";
        return;
    }
    if (eobj.EDIT_TYPE() == "UPNAME")
    {
        std::string _OldName, _NewName;
        StrStream >> _UpperCat >> _LowerCat >> _Sku;
        std::getline(StrStream, _OldName, ';');
        std::getline(StrStream, _NewName);
        std::cout << BHGRN << "Thay đổi tên sản phẩm có sku " << BHCYN << _Sku << BHGRN << " của danh mục\n";
        std::cout << GRNHB << BHRED << ITEM_DB_MANAGER::th_category(_UpperCat) << CRESET << '\n';
        if (ITEM_DB_MANAGER::th_sub_category(_UpperCat).size() != 0)
            std::cout << YELHB << BHMAG << ITEM_DB_MANAGER::th_sub_category(_UpperCat)[_LowerCat] << CRESET << "\n\n";
        std::cout << WHTHB << BHGRN << "Tên cũ " << CRESET << BHGRN << ' ' << _OldName << '\n';
        std::cout << WHTHB << BHGRN << "Tên mới" << CRESET << BHGRN << ' ' << _NewName << '\n'
                  << '\n';
        return;
    }
    if (eobj.EDIT_TYPE() == "ADDTYPE")
    {
        std::string _TypeName;
        size_t _Cost, _Price, _ProPrice, _Quantity;
        StrStream >> _UpperCat >> _LowerCat >> _Sku;
        std::getline(StrStream, _TypeName, ';');
        StrStream >> _Cost >> _Price >> _ProPrice >> _Quantity;
        std::cout << BHGRN << "Thêm loại cho sản phẩm có sku " << BHCYN << _Sku << BHGRN << " của danh mục\n";
        std::cout << GRNHB << BHRED << ITEM_DB_MANAGER::th_category(_UpperCat) << CRESET << '\n';
        if (ITEM_DB_MANAGER::th_sub_category(_UpperCat).size() != 0)
            std::cout << YELHB << BHMAG << ITEM_DB_MANAGER::th_sub_category(_UpperCat)[_LowerCat] << CRESET << "\n\n";
        std::cout << WHTHB << BHGRN << "Tên loại      " << CRESET << BHGRN << " " << _TypeName << '\n';
        std::cout << WHTHB << BHGRN << "Giá nhập      " << CRESET << BHGRN << " " << _Cost << '\n';
        std::cout << WHTHB << BHGRN << "Giá bán       " << CRESET << BHGRN << " " << _Price << '\n';
        std::cout << WHTHB << BHGRN << "Giá khuyến mãi" << CRESET << BHGRN << " " << _ProPrice << '\n';
        std::cout << WHTHB << BHGRN << "Số lượng      " << CRESET << BHGRN << " " << _ProPrice << "\n\n";
        return;
    }
    if (eobj.EDIT_TYPE() == "DELTYPE")
    {
        std::string _TypeName;
        size_t _Cost, _Price, _ProPrice, _Quantity;
        StrStream >> _UpperCat >> _LowerCat >> _Sku;
        std::getline(StrStream, _TypeName, ';');
        StrStream >> _Cost >> _Price >> _ProPrice >> _Quantity;
        std::cout << BHGRN << "Xóa loại sản phẩm có sku " << BHCYN << _Sku << BHGRN << " của danh mục\n";
        std::cout << GRNHB << BHRED << ITEM_DB_MANAGER::th_category(_UpperCat) << CRESET << '\n';
        if (ITEM_DB_MANAGER::th_sub_category(_UpperCat).size() != 0)
            std::cout << YELHB << BHMAG << ITEM_DB_MANAGER::th_sub_category(_UpperCat)[_LowerCat] << CRESET << "\n\n";
        std::cout << WHTHB << BHGRN << "Tên loại      " << CRESET << BHGRN << " " << _TypeName << '\n';
        std::cout << WHTHB << BHGRN << "Giá nhập      " << CRESET << BHGRN << " " << _Cost << '\n';
        std::cout << WHTHB << BHGRN << "Giá bán       " << CRESET << BHGRN << " " << _Price << '\n';
        std::cout << WHTHB << BHGRN << "Giá khuyến mãi" << CRESET << BHGRN << " " << _ProPrice << '\n';
        std::cout << WHTHB << BHGRN << "Số lượng      " << CRESET << BHGRN << " " << _ProPrice << "\n\n";
        return;
    }
    if (eobj.EDIT_TYPE() == "UPCOST")
    {
        std::string _TypeName;
        size_t _ThPrice, _OCost, _NCost;
        StrStream >> _UpperCat >> _LowerCat >> _Sku;
        std::getline(StrStream, _TypeName, ';');
        StrStream >> _ThPrice >> _OCost >> _NCost;
        std::cout << BHGRN << "Thay đổi giá sản phẩm có sku " << BHCYN << _Sku << BHGRN << " của danh mục\n";
        std::cout << GRNHB << BHRED << ITEM_DB_MANAGER::th_category(_UpperCat) << CRESET << '\n';
        if (ITEM_DB_MANAGER::th_sub_category(_UpperCat).size() != 0)
            std::cout << YELHB << BHMAG << ITEM_DB_MANAGER::th_sub_category(_UpperCat)[_LowerCat] << CRESET << "\n\n";
        std::cout << BHGRN << "Loại " << _TypeName << '\n';
        std::cout << YELHB << BHRED;
        if (_ThPrice == 0)
            std::cout
                << "Giá nhập";
        else if (_ThPrice == 1)
            std::cout
                << "Giá bán";
        else
            std::cout << "Giá khuyến mãi";
        std::cout << CRESET << ' ' << ' ';
        std::cout << WHTHB << BHCYN << "Giá cũ" << CRESET << BHGRN << " " << _OCost << " ➡  ";
        std::cout << WHTHB << BHCYN << "Giá mới" << CRESET << BHGRN << " " << _NCost << "\n\n";
        return;
    }
    if (eobj.EDIT_TYPE() == "UPQUAN")
    {
        std::string _TypeName;
        size_t _NAdd;
        StrStream >> _UpperCat >> _LowerCat >> _Sku;
        std::getline(StrStream, _TypeName, ';');
        StrStream >> _NAdd;
        std::cout << BHGRN << "Nhập hàng sản phẩm có sku " << BHCYN << _Sku << BHGRN << " của danh mục\n";
        std::cout << GRNHB << BHRED << ITEM_DB_MANAGER::th_category(_UpperCat) << CRESET << '\n';
        if (ITEM_DB_MANAGER::th_sub_category(_UpperCat).size() != 0)
            std::cout << YELHB << BHMAG << ITEM_DB_MANAGER::th_sub_category(_UpperCat)[_LowerCat] << CRESET << "\n\n";
        std::cout << WHTHB << BHGRN << "  Loại  " << CRESET << BHGRN << " " << _TypeName << '\n';
        std::cout << WHTHB << BHGRN << "Số lượng" << CRESET << BHGRN << " " << _NAdd << "\n\n";
        return;
    }
    if (eobj.EDIT_TYPE() == "DELITEM")
    {
        std::string _ItemName;
        std::string _TypeName;
        size_t _Cost, _Price, _ProPrice, _Quantity;
        int _NType;
        StrStream >> _UpperCat >> _LowerCat >> _Sku;
        std::getline(StrStream, _ItemName, ';');
        StrStream >> _NType;
        VECTOR<ITEMPROP> _Classify;
        for (int i(0); i < _NType; ++i)
        {
            std::getline(StrStream, _TypeName, ';');
            StrStream >> _Cost >> _Price >> _ProPrice >> _Quantity;
            _Classify.push_back(ITEMPROP(std::move(_TypeName), _Cost, _Price, _ProPrice, _Quantity));
        }
        std::cout << BHGRN << "Xoá sản phẩm có sku " << BHCYN << _Sku << BHGRN << " của danh mục\n";
        std::cout << GRNHB << BHRED << ITEM_DB_MANAGER::th_category(_UpperCat) << CRESET << '\n';
        if (ITEM_DB_MANAGER::th_sub_category(_UpperCat).size() != 0)
            std::cout << YELHB << BHMAG << ITEM_DB_MANAGER::th_sub_category(_UpperCat)[_LowerCat] << CRESET << "\n\n";
        std::cout << CYNHB << BHYEL << "Tên sản phẩm" << CRESET << " " << _ItemName << '\n';
        for (int &&i{0}; i < _NType; ++i)
        {
            printf("%s        ┌─%sTên loại           : %s%s\n", GRN, BHCYN, BHGRN, _Classify[i].unit().c_str());
            printf("%s        ├─%sGiá nhập           : %s%ld\n", GRN, BHCYN, BHGRN, _Classify[i].cost());
            printf("%s%sLoại %d%s  %s├─%sGiá bán            : %s%ld\n", GRNHB, BHYEL, i + 1, CRESET, GRN, BHCYN, BHGRN, _Classify[i].price());
            printf("%s        ├─%sGiá khuyến mãi     : %s%ld\n", GRN, BHCYN, BHGRN, _Classify[i].promoprice());
            printf("%s        └─%sSố lượng trong kho : %s%ld\n", GRN, BHCYN, BHGRN, _Classify[i].quantity());
            putchar_unlocked('\n');
        }
        return;
    }
}
void viewHistory()
{
    tc_cursor_off();
    tc_echo_off();
    DListNode<EDIT_OBJECT> *_curIterator = EDIT_HISTORY::head();
    if (_curIterator == nullptr)
    {
        int XMAX, YMAX;
        maxXY(XMAX, YMAX);
        gotoyx(YMAX >> 1, XMAX - 30 >> 1);
        clrscr();
        printf("%s%s%sChưa có lịch sử chỉnh sửa nào!%s", WHTHB, BHRED, BLINK_RAPID, CRESET);
        tc_getch();
        return;
    }
    size_t _keygetch;
    bool _exit = false;
    while (!_exit)
    {
        clrscr();
        displayEditObjectContent(_curIterator->_value);
        _keygetch = tc_getch();
        switch (_keygetch)
        {
        case TC_KEY_ARROW_UP:
            if (_curIterator->_pAfter != nullptr)
                _curIterator = _curIterator->_pAfter;
            break;
        case TC_KEY_ARROW_DOWN:
            if (_curIterator->_pBefore != nullptr)
                _curIterator = _curIterator->_pBefore;
            break;
        case TC_KEY_ESCAPE:
            _exit = true;
            break;
        }
    }
    clrscr();
}