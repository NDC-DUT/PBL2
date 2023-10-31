#include "UPDATEITEM.h"
void updateITEM()
{
    tc_cursor_on();
    tc_echo_on();

    std::string _sku;
    size_t _keyget;
    _itemCoor *_returnItem(nullptr);

    while (true)
    {
        clrscr();
        takeSKU(_sku, false);
        _returnItem = ITEM_DB_MANAGER::find_item_with_sku(_sku);
        if (_returnItem == 0)
        {
            printf("%s%s\n", BHRED, "Sản phẩm không tồn tại!");
            printf("%sTiếp tục?[y/n]", BHBLU);
            _keyget = tc_getch();
            if (_keyget == 'y' || _keyget == 'Y')
                continue;
            else
            {
                tc_echo_off();
                tc_cursor_off();
                clrscr();
                return;
            }
        }
        else
        {
            clrscr();
            tc_echo_off();
            tc_cursor_off();
            break;
        }
    }

    int yMax, xMax;
    maxXY(xMax, yMax);
    int startY(yMax - 5 >> 1), startX(xMax - 24 >> 1);
    unsigned short _highLight = 0;

    manArrow();
    tc_print_frame(startY, startX, NChangeChoice, 24, BHMAG);
    itemPrinter(_returnItem, true);
    while (true)
    {
        printChoice(startY, startX, _highLight);
        _keyget = tc_getch();
        switch (_keyget)
        {
        case TC_KEY_ARROW_UP:
            if (_highLight != 0)
                --_highLight;
            break;
        case TC_KEY_ARROW_DOWN:
            if (_highLight != NChangeChoice - 1)
                ++_highLight;
            break;
        case TC_KEY_ESCAPE:
            clrscr();
            return;
        case TC_KEY_ENTER:
            (*_funPtrArr[_highLight])(_returnItem);
            if (_highLight == NChangeChoice - 1)
            {
                clrscr();
                delete _returnItem;
                return;
            }
            manArrow();
            tc_print_frame(startY, startX, NChangeChoice, 24, BHMAG);
            itemPrinter(_returnItem, true);
            break;
        default:
            break;
        }
    }
}
void printChoice(int &startY, int &startX, unsigned short &_highLight)
{
    printf("%s", BHYEL);
    for (int &&i{0}; i < _mulChoice.size(); ++i)
    {
        gotoyx(startY + 1 + (i << 1), startX + 1);
        if (i != _highLight)
            printf("%s", _mulChoice[i].c_str());
        else
            printf("%s%s%s", BHGRN, _mulChoice[i].c_str(), BHYEL);
    }
}
void changeCategory(_itemCoor *_returnItem)
{
    int r, c;
    bool _success = getCategory(r, c);
    if (!_success)
        return;

    clrscr();

    VECTOR<ITEM> &old_cont = ITEM_DB_MANAGER::item_cont_of_category(_returnItem->upper_cat, _returnItem->lower_cat);
    VECTOR<ITEM> &new_cont = ITEM_DB_MANAGER::item_cont_of_category(r, c);

    ITEM _Itemp = std::move(old_cont[_returnItem->_idx]);
    old_cont.remove(_returnItem->_idx);

    char EDIT_MESSAGE[20];
    sprintf(EDIT_MESSAGE, "%d %d %s %d %d", _returnItem->upper_cat, _returnItem->lower_cat, _Itemp.sku().c_str(), r, c);
    EDIT_HISTORY::ADD_HISTORY("UPCAT", EDIT_MESSAGE);

    int i(0);
    for (; i < new_cont.size(); ++i)
        if (_Itemp < new_cont[i])
            break;
    new_cont.insert(i, std::move(_Itemp));
    _returnItem->upper_cat = r;
    _returnItem->lower_cat = c;
    _returnItem->_idx = i;
}
void changeName(_itemCoor *_returnItem)
{
    clrscr();
    std::string new_name;
    std::string new_priname;
    std::string new_origin_priname;

    tc_cursor_on();
    tc_echo_on();
    takeName(new_name);
    new_origin_priname = new_priname = new_name;
    RemoveVietnameseTone(new_priname);
    lowercaseStr(new_priname);
    lowercaseStr(new_origin_priname);
    LowercaseVietNameseCharacter(new_origin_priname);

    ITEM &_Itemp = ITEM_DB_MANAGER::item_in_container(_returnItem->upper_cat, _returnItem->lower_cat, _returnItem->_idx);
    new_priname = _Itemp.sku() + std::string(" ") + new_priname;
    new_origin_priname = _Itemp.sku() + std::string(" ") + new_origin_priname;

    /*UPNAME r c sku oldname;newname*/
    EDIT_HISTORY::ADD_HISTORY("UPNAME", std::to_string(_returnItem->upper_cat) + std::string(" ") +
                                            std::to_string(_returnItem->lower_cat) + std::string(" ") +
                                            _Itemp.sku() + std::string(" ") +
                                            _Itemp.name() + std::string(";") + new_name);

    _Itemp.name(std::move(new_name));
    _Itemp.priname(std::move(new_priname));
    _Itemp.origin_priname(std::move(new_origin_priname));
    tc_cursor_off();
    tc_echo_off();
    clrscr();
}
void addType(_itemCoor *_returnItem)
{
    clrscr();
    tc_echo_on();
    tc_cursor_on();

    std::string _unit;
    size_t _cost;
    size_t _price;
    size_t _promoprice;
    size_t _quantity;
    ITEM &_Itemp = ITEM_DB_MANAGER::item_in_container(_returnItem->upper_cat, _returnItem->lower_cat, _returnItem->_idx);
    printf("%s▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ %sNhập loại %ld %s▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n", BHYEL, BHMAG, _Itemp.ntype() + 1, BHYEL);

    printf("%sTên loại : %s", BHCYN, BHGRN);
    while (true)
    {
        std::getline(std::cin, _unit);

        if (!_Itemp.checkValidNewType(_unit))
        {
            std::cerr << WHTHB << BHRED << _unit << " Đã tồn tại!" << CRESET << '\n';
            printf("%sNhập lại : %s", BHCYN, BHGRN);
            continue;
        }
        break;
    }
    _cost = getULL("Giá nhập");
    _price = getULL("Giá bán");

    printf("%sKhuyến mãi?[y/n] : %s", BCYN, BGRN);
    char ch = std::tolower(tc_getch());
    putchar_unlocked('\n');
    if (ch == 'y')
        _promoprice = getULL("Giá khuyến mãi");
    else
        _promoprice = _price;

    _quantity = getULL("Số lượng trong kho");

    char EDIT_MESSAGE[100];
    sprintf(EDIT_MESSAGE, "%d %d %s %s;%ld %ld %ld %ld", _returnItem->upper_cat, _returnItem->lower_cat, _Itemp.sku().c_str(), _unit.c_str(), _cost, _price, _promoprice, _quantity);
    EDIT_HISTORY::ADD_HISTORY("ADDTYPE", EDIT_MESSAGE);

    _Itemp.addITEMPROP(ITEMPROP(std::move(_unit), _cost, _price, _promoprice, _quantity));

    tc_echo_off();
    tc_cursor_off();
    clrscr();
}
void rmType(_itemCoor *_returnItem)
{
    clrscr();
    short _thType = chooseType(_returnItem);
    ITEM &_Itemp = ITEM_DB_MANAGER::item_in_container(_returnItem->upper_cat, _returnItem->lower_cat, _returnItem->_idx);
    const ITEMPROP &_thItemProp = _Itemp.classify()[_thType];


    if (_thType != -1)
    {char EDIT_MESSAGE[100];
    sprintf(EDIT_MESSAGE, "%d %d %s %s;%ld %ld %ld %ld", _returnItem->upper_cat, _returnItem->lower_cat, _Itemp.sku().c_str(), _thItemProp.unit().c_str(), _thItemProp.cost(), _thItemProp.price(), _thItemProp.promoprice(), _thItemProp.quantity());
    EDIT_HISTORY::ADD_HISTORY("DELTYPE", EDIT_MESSAGE);
        _Itemp.rmITEMPROP(_thType);}
    clrscr();
}
void upCost(_itemCoor *_returnItem)
{
    short _thType = chooseType(_returnItem);
    if (_thType == -1)
        return;

    ITEM &_it = ITEM_DB_MANAGER::item_in_container(_returnItem->upper_cat, _returnItem->lower_cat, _returnItem->_idx);
    const ITEMPROP &_itprop = _it.classify()[_thType];

    short unsigned _priceType = 0;
    auto _typePrice = [&_it, &_priceType, &_thType]()
    {
        gotoyx(3, 1);
        switch (_priceType)
        {
        case 0:
            delline();
            delline();
            delline();
            printf("%sGiá nhập       : %s%ld\n", BHMAG, BHBLU, _it.classify()[_thType].cost());
            printf("%sGiá bán        : %s%ld\n", BHGRN, BHYEL, _it.classify()[_thType].price());
            printf("%sGiá khuyến mãi : %s%ld\n", BHGRN, BHYEL, _it.classify()[_thType].promoprice());
            break;
        case 1:
            delline();
            delline();
            delline();
            printf("%sGiá nhập       : %s%ld\n", BHGRN, BHYEL, _it.classify()[_thType].cost());
            printf("%sGiá bán        : %s%ld\n", BHMAG, BHBLU, _it.classify()[_thType].price());
            printf("%sGiá khuyến mãi : %s%ld\n", BHGRN, BHYEL, _it.classify()[_thType].promoprice());
            break;
        case 2:
            delline();
            delline();
            delline();
            printf("%sGiá nhập       : %s%ld\n", BHGRN, BHYEL, _it.classify()[_thType].cost());
            printf("%sGiá bán        : %s%ld\n", BHGRN, BHYEL, _it.classify()[_thType].price());
            printf("%sGiá khuyến mãi : %s%ld\n", BHMAG, BHBLU, _it.classify()[_thType].promoprice());
            break;
        }
    };
    bool _exit = false;
    manArrow();
    size_t _keyget;
    size_t _ncost;
    size_t _ocost;
    while (!_exit)
    {
        _typePrice();
        _keyget = tc_getch();
        switch (_keyget)
        {
        case TC_KEY_ARROW_UP:
            if (_priceType != 0)
                --_priceType;
            break;

        case TC_KEY_ARROW_DOWN:
            if (_priceType != 2)
                ++_priceType;
            break;

        case TC_KEY_ESCAPE:
            _exit = true;
            break;

        case TC_KEY_ENTER:
            clrscr();
            tc_echo_on();
            tc_cursor_on();
            switch (_priceType)
            {
            case 0:
            {
                _ncost = getULL("Giá nhập mới");
                _ocost = _itprop.cost();
                _it.cost(_thType, _ncost);
                break;
            }
            case 1:
            {
                _ncost = getULL("Giá bán mới");
                _ocost = _itprop.price();
                _it.price(_thType, _ncost);
                break;
            }
            case 2:
            {
                _ncost = getULL("Giá khuyến mãi mới");
                _ocost = _itprop.promoprice();
                _it.promoprice(_thType, _ncost);
                break;
            }
            }
            char EDIT_MESSAGE[100];
            sprintf(EDIT_MESSAGE, "%d %d %s %s;%d %ld %ld", _returnItem->upper_cat, _returnItem->lower_cat, _it.sku().c_str(), _itprop.unit().c_str(), _priceType, _ocost, _ncost);
            EDIT_HISTORY::ADD_HISTORY("UPCOST", EDIT_MESSAGE);

            clrscr();
            tc_echo_off();
            tc_cursor_off();
            manArrow();
            break;
        default:
            break;
        }
    }

    clrscr();
}
void upQuan(_itemCoor *_returnItem)
{
    short _thType = chooseType(_returnItem);
    if (_thType == -1)
        return;

    clrscr();
    tc_echo_on();
    tc_cursor_on();

    size_t _quantity = getULL("Số lượng nhập thêm");
    ITEM &_Itemp = ITEM_DB_MANAGER::item_in_container(_returnItem->upper_cat, _returnItem->lower_cat, _returnItem->_idx);
    const ITEMPROP &_itprop = _Itemp.classify()[_thType];
    _Itemp.addQUANTITY(_thType, _quantity);

    char EDIT_MESSAGE[100];
    sprintf(EDIT_MESSAGE, "%d %d %s %s;%ld", _returnItem->upper_cat, _returnItem->lower_cat, _Itemp.sku().c_str(), _itprop.unit().c_str(), _quantity);
    EDIT_HISTORY::ADD_HISTORY("UPQUAN", EDIT_MESSAGE);

    clrscr();
    tc_echo_off();
    tc_cursor_off();
}
void rmItem(_itemCoor *_returnItem)
{
    ITEM &_Itemp = ITEM_DB_MANAGER::item_in_container(_returnItem->upper_cat, _returnItem->lower_cat, _returnItem->_idx);
    std::string EDIT_MESSAGE = std::to_string(_returnItem->upper_cat) + std::string(" ") +
                               std::to_string(_returnItem->lower_cat) + std::string(" ") +
                               _Itemp.sku() + std::string(" ") +
                               _Itemp.name() + std::string(";") +
                               std::to_string(_Itemp.ntype()) + std::string(" ");
    for (const ITEMPROP &_ip : _Itemp.classify())
    {
        EDIT_MESSAGE += _ip.unit() + std::string(";") +
                        std::to_string(_ip.cost()) + std::string(" ") +
                        std::to_string(_ip.price()) + std::string(" ") +
                        std::to_string(_ip.promoprice()) + std::string(" ") +
                        std::to_string(_ip.quantity()) + std::string(" ");
    }
    EDIT_HISTORY::ADD_HISTORY("DELITEM", EDIT_MESSAGE);

    ITEM_DB_MANAGER::item_cont_of_category(_returnItem->upper_cat, _returnItem->lower_cat).remove(_returnItem->_idx);
}
short chooseType(_itemCoor *_returnItem)
{
    clrscr();
    ITEM &_it = ITEM_DB_MANAGER::item_in_container(_returnItem->upper_cat, _returnItem->lower_cat, _returnItem->_idx);
    short unsigned _highLight = 0;
    auto _typeChoose = [&_it, &_highLight]()
    {
        gotoyx(2, 1);
        printf("%s", BHYEL);
        for (int &&i{0}; i < _it.classify().size(); ++i)
            if (i != _highLight)
                printf("%s\n", _it.classify()[i].unit().c_str());
            else
                printf("%s%s%s\n", BHBLU, _it.classify()[i].unit().c_str(), BHYEL);
    };
    gotoyx(1, 1);
    printf("%sChọn loại\n\n", BHRED);
    manArrow();

    size_t _keypad;
    while (true)
    {
        _typeChoose();
        _keypad = tc_getch();
        switch (_keypad)
        {
        case TC_KEY_ARROW_UP:
            if (_highLight != 0)
                --_highLight;
            break;
        case TC_KEY_ARROW_DOWN:
            if (_highLight != _it.classify().size() - 1)
                ++_highLight;
            break;
        case TC_KEY_ESCAPE:
            clrscr();
            return -1;
        case TC_KEY_ENTER:
            clrscr();
            return _highLight;
        default:
            break;
        }
    }
    return -1;
}