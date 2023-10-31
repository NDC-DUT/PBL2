
void addITEM()
{
    clrscr();
    int r, c;
    bool success = getCategory(r, c);
    clrscr();
    if (!success)
        return;

    tc_cursor_on();
    tc_echo_on();

    std::string _sku;
    std::string _name;
    std::string _priname;
    std::string _origin_priname;
    short unsigned _nunit;
    VECTOR<ITEMPROP> _classify;

    takeSKU(_sku);
    takeName(_name);

    _priname = _name;
    RemoveVietnameseTone(_priname);
    lowercaseStr(_priname);
    _priname = _sku + std::string(" ") + _priname;

    _origin_priname = _name;
    LowercaseVietNameseCharacter(_origin_priname);
    lowercaseStr(_origin_priname);
    _origin_priname = _sku + std::string(" ") + _origin_priname;

    takenUnit(_nunit);
    takeType(_classify, _nunit);
    
    char EDIT_MESSAGE[20];
    sprintf(EDIT_MESSAGE, "%d %d %s",r,c,_sku.c_str());
    EDIT_HISTORY::ADD_HISTORY("ADDITEM", EDIT_MESSAGE);

    ITEM _Itemp(std::move(_sku), std::move(_name), std::move(_priname), std::move(_origin_priname), std::move(_classify), 0, 0.0);

    VECTOR<ITEM> &ref_cont = ITEM_DB_MANAGER::item_cont_of_category(r, c);

    int i(0);
    for (; i < ref_cont.size(); ++i)
        if (_Itemp < ref_cont[i])
            break;
    ref_cont.insert(i, std::move(_Itemp));

    clrscr();
    tc_echo_off();
    tc_cursor_off();
}