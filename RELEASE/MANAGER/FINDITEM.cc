void trimToOneSpace(std::string &str)
{
    str.push_back(' ');
    for (size_t &&i(0); i < str.length() - 1; ++i)
    {
        while (i < str.length() - 1 && isspace(str[i]) && isspace(str[i + 1]))
            str.erase(str.begin() + i);
    }
    str.pop_back();
    if (isspace(str[0]))
        str.erase(str.begin());
}
void findITEM()
{
    clrscr();
    gotoyx(1, 1);
    tc_cursor_on();
    tc_echo_on();
    int XMAX, YMAX;
    maxXY(XMAX, YMAX);
    int startY = 1;
    int startX = (XMAX - 22) >> 1;
    gotoyx(startY, startX);
    printf("%s┌────────────────────┐", BHGRN);
    gotoyx(startY + 1, startX);
    printf("%s│    %s%sTìm sản phẩm%s    %s│", BHGRN, BLUHB, BHRED, CRESET, BHGRN);
    gotoyx(startY + 2, startX);
    printf("%s└────────────────────┘", BHGRN);
    startY = (YMAX >> 1) - 1;
    startX = (XMAX - 50) >> 1;
    gotoyx(startY, startX);
    printf("%s", BHCYN);
    printf("┌────┬───────────────────────────────────────────┐");
    gotoyx(startY + 1, startX);
    printf("│ 🔍 │                                           │");
    gotoyx(startY + 2, startX);
    printf("└────┴───────────────────────────────────────────┘");
    gotoyx(startY + 1, startX + 7);
    printf("%s", BHGRN);
    std::string user_inp_str;
    std::getline(std::cin, user_inp_str);
    std::string no_pro_cess_user_inp_str(user_inp_str);
    trimToOneSpace(user_inp_str);

    clrscr();
    tc_cursor_off();
    tc_echo_off();

    const VECTOR<_itemCoor> &FIND_RESULT = ITEM_DB_MANAGER::find_similar_item(user_inp_str);

    startY = 1;
    startX = (XMAX - 50) >> 1;
    size_t nResult = FIND_RESULT.size();
    if (nResult)
    {
        size_t curPosItem = 0;
        size_t _keypad;
        bool _exit = false;
        while (!_exit)
        {
            gotoyx(startY, startX);
            printf("%s", BHCYN);
            printf("┌────┬───────────────────────────────────────────┐");
            gotoyx(startY + 1, startX);
            printf("│ 🔍 │                                           │");
            gotoyx(startY + 2, startX);
            printf("└────┴───────────────────────────────────────────┘");
            gotoyx(startY + 1, startX + 7);
            printf("%s%s", GRN, no_pro_cess_user_inp_str.c_str());
            manArrow();
            gotoyx(4, 1);
            itemPrinter(&FIND_RESULT[curPosItem]);
            gotoyx(YMAX - 3, 5);
            printf("%s%s TRANG %s%ld/%s%ld %s", WHTHB, BHRED, BHGRN, curPosItem + 1, BHBLU, nResult, CRESET);
            _keypad = tc_getch();
            switch (_keypad)
            {
            case TC_KEY_ARROW_UP:
                if (curPosItem != 0)
                    --curPosItem;
                break;
            case TC_KEY_ARROW_DOWN:
                if (curPosItem != FIND_RESULT.size() - 1)
                    ++curPosItem;
                break;
            case TC_KEY_ESCAPE:
                _exit = true;
                break;
            case TC_KEY_ENTER:
                break;
            default:
                break;
            }
            clrscr();
        }
    }
    else
    {
        gotoyx(startY, startX);
        printf("%s", BHCYN);
        printf("┌────┬───────────────────────────────────────────┐");
        gotoyx(startY + 1, startX);
        printf("│ 🔍 │                                           │");
        gotoyx(startY + 2, startX);
        printf("└────┴───────────────────────────────────────────┘");
        gotoyx(startY + 1, startX + 7);
        printf("%s%s", GRN, no_pro_cess_user_inp_str.c_str());
        gotoyx(5, startX + 11);
        printf("%s%sKhông tìm thấy sản phẩm nào%s", WHTHB, BHRED, CRESET);
        tc_getch();
    }

    clrscr();
}