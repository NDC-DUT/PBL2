VECTOR<VECTOR<VECTOR<ITEM>>> ITEM_DB_MANAGER::ITEM_CONTAINER{
    // 0.Thịt - Hải Sản Tươi
    {
        {}, // 0.Thịt
        {}  // 1.Hải Sản
    },
    // 1.Trứng - Đậu Hũ
    {
        {}, // 0.Trứng
        {}  // 1.Đậu Hũ
    },
    // 2.Rau - Củ
    {
        {}, // 0.Rau Lá
        {}  // 1.Củ, Quả
    },
    // 3.Trái Cây Tươi
    {
        {} // 0.
    },
    // 4.Thực Phẩm Chế Biến
    {
        {}, // 0.Bánh Mì
        {}, // 1.Xúc Xích - Thịt Nguội
        {}, // 2.Bánh Bao
        {}, // 3.Kim Chi
        {}  // 4.Thực Phẩm Chế Biến Khác
    },
    // 5.Thực Phẩm Đông Lạnh
    {
        {}, // 0.Hải Sản Đông Lạnh
        {}, // 1.Thịt Đông Lạnh
        {}, // 2.Chả Giò
        {}, // 3.Cá - Bò Viên
        {}  // 4.Thực Phẩm Đông Lạnh Khác
    },
    // 6.Mì - Thực Phẩm Ăn Liền
    {
        {}, // 0.Mì
        {}, // 1.Miến - Hủ Tíu - Bánh Canh
        {}, // 2.Cháo
        {}  // 3.Phở - Bún
    },
    // 7.Thực Phẩm Khô
    {
        {}, // 0.Gạo - Nông Sản Khô
        {}, // 1.Ngũ Cốc - Yến Mạch
        {}, // 2.Thực Phẩm Đóng Hộp
        {}, // 3.Rong Biển - Tảo Biển
        {}, // 4.Bột Các Loại
        {}  // 5.Thực Phẩm Chay
    },
    // 8.Gia Vị
    {
        {}, // 0.Dầu Ăn
        {}, // 1.Nước Mắm - Nước Chấm
        {}, // 2.Đường
        {}, // 3.Nước Tương
        {}, // 4.Hạt Nêm
        {}, // 5.Tương Các Loại
        {}  // 6.Gia Vị Khác
    },
    // 9.Bánh Kẹo
    {
        {}, // 0.Bánh Xốp - Bánh Quy
        {}, // 1.Kẹo - Chocolate
        {}, // 2.Bánh Snack
        {}  // 3.Hạt - Trái Cây Sấy Khô
    },
    // 10.sữa-sản phẩm từ sữa
    {
        {}, // 0.Sữa Tươi
        {}, // 1.Sữa Hạt - Sữa Đậu
        {}, // 2.Sữa Bột
        {}, // 3.Bơ Sữa - Phô Mai
        {}, // 4.Sữa Đặc
        {}  // 5. Sữa Chua-Váng Sữa
    },
    // 11.đồ uống-giải khát
    {
        {}, // 0.Cà Phê
        {}, // 1.Nước Suối
        {}, // 2.Nước Ngọt
        {}  // 3.Trà - Các Loại Khác
    },
    // 12.nước uống có cồn
    {
        {} // 0.Bia
    },
    // 13.hóa phẩm-tẩy rửa
    {
        {}, // 0.Bình Xịt Côn Trùng
        {}, // 1.Nước Giặt
        {}, // 2.Nước Lau Sàn-Lau Kính
        {}, // 3.Nước Rửa Chén
        {}, // 4.Nước Tẩy Rửa
        {}  // 5.Nước Xả
    },
    // 14.chăm sóc cá nhân
    {
        {}, // 0.Chăm Sóc Tóc
        {}, // 1.Chăm Sóc Da
        {}, // 2.Chăm Sóc Răng Miệng
        {}, // 3.Chăm Sóc Phụ Nữ
        {}, // 4.Chăm Sóc Cá Nhân Khác
        {}, // 5.Mỹ Phẩm
        {}  // 6.Khăn Giấy - Khăn Ướt
    },
    // 15.chăm sóc bé
    {
        {}, // 0.Sữa Bột - Sữa Dinh Dưỡng
        {}, // 1.Tả - Bỉm
        {}, // 2.Sữa Tắm - Gội Cho Bé
        {}  // 3.Chăm Sóc Cá Nhân Cho Bé
    },
    // 16.đồ gia dụng
    {
        {}, // 0.Đồ Dùng Phòng Ngủ
        {}, // 1.Đồ Dùng Trong Nhà
        {}, // 2.Dụng Cụ Sửa Chửa
        {}, // 3.Đồ Dùng Nhà Bếp
        {}, // 4.Thiết Bị Dùng Điện Trong Nhà
        {}  // 5.Vệ Sinh Nhà Cửa
    },
    // 17.điện gia dụng
    {
        {} // 0.
    },
    // 18.văn phòng phẩm-đò chơi
    {
        {} // 0.
    }      //
};
VECTOR<PAIR<std::string, VECTOR<std::string>>> ITEM_DB_MANAGER::CATEGORY{
    {"Thịt - Hải Sản Tươi         🥩", {"             Thịt              ", "            Hải Sản            "}},
    {"Trứng  - Đậu Hũ             🥚", {"             Trứng             ", "            Đậu Hũ             "}},
    {"Rau - Củ                    🥦", {"            Rau Lá             ", "            Củ, Quả            "}},
    {"Trái Cây Tươi               🍑", {}},
    {"Thực Phẩm Chế Biến          🥐", {"            Bánh mì            ", "     Xúc xích - Thịt nguội     ", "           Bánh bao            ", "            Kim chi            ", "    Thực phẩm chế biến khác    "}},
    {"Thực Phẩm Đông Lạnh         🍗", {"       Hải Sản Đông Lạnh       ", "        Thịt Đông Lạnh         ", "            Chả Giò            ", "         Cá - Bò Viên          ", "   Thực Phẩm Đông Lạnh Khác    "}},
    {"Mì - Thực Phẩm Ăn Liền      🍜", {"              Mì               ", "   Miến - Hủ Tíu - Bánh Canh   ", "             Cháo              ", "           Phở - Bún           "}},
    {"Thực Phẩm Khô               🍙", {"      Gạo - Nông Sản Khô       ", "      Ngũ Cốc - Yến Mạch       ", "      Thực Phẩm Đóng Hộp       ", "     Rong Biển - Tảo Biển      ", "         Bột Các Loại          ", "        Thực Phẩm Chay         "}},
    {"Gia Vị                      🧂", {"            Dầu ăn             ", "     Nước Mắm - Nước Chấm      ", "             Đường             ", "          Nước Tương           ", "            Hạt Nêm            ", "        Tương Các Loại         ", "          Gia Vị Khác          "}},
    {"Bánh Kẹo                    🍰", {"      Bánh Xốp - Bánh Quy      ", "        Kẹo - Chocolate        ", "          Bánh Snack           ", "    Hạt - Trái Cây Sấy Khô     "}},
    {"Sữa - Sản Phẩm Từ Sữa       🥛", {"           Sữa Tươi            ", "       Sữa Hạt - Sữa Đậu       ", "            Sữa Bột            ", "       Bơ Sữa - Phô Mai        ", "            Sữa Đặc            ", "      Sữa Chua - Váng Sữa      "}},
    {"Đồ Uống - Giải Khát         ☕", {"            Cà Phê             ", "           Nước Suối           ", "           Nước Ngọt           ", "      Trà - Các Loại Khác      "}},
    {"Nước Uống Có Cồn            🍺", {"              Bia              "}},
    {"Hóa Phẩm - Tẩy Rửa          🧻", {"      Bình Xịt Côn Trùng       ", "           Nước Giặt           ", "    Nước Lau Sàn - Lau Kính    ", "         Nước Rửa Chén         ", "         Nước Tẩy Rửa          ", "            Nước Xả            "}},
    {"Chăm Sóc Cá Nhân            🧏", {"         Chăm Sóc Tóc          ", "          Chăm Sóc Da          ", "      Chăm Sóc Răng Miệng      ", "        Chăm Sóc Phụ Nữ        ", "     Chăm Sóc Cá Nhân Khác     ", "            Mỹ Phẩm            ", "     Khăn Giấy - Khăn Ướt      "}},
    {"Chăm Sóc Bé                 👶", {"   Sữa Bột - Sữa Dinh Dưỡng    ", "           Tã - Bỉm            ", "     Sữa Tắm - Gội Cho Bé      ", "    Chăm Sóc Cá Nhân Cho Bé    "}},
    {"Đồ Gia Dụng                 🛁", {"       Đồ Dùng Phòng Ngủ       ", "       Đồ Dùng Trong Nhà       ", "       Dụng Cụ Sửa Chữa        ", "        Đồ Dùng Nhà Bếp        ", " Thiết Bị Dùng Điện Trong Nhà  ", "        Vệ Sinh Nhà Cửa        "}},
    {"Điện Gia Dụng               🔌", {}},
    {"Văn Phòng Phẩm - Đồ Chơi    🧸", {}} //
};
#define CATEGORY_SZ 19
VECTOR<db_update_arg> ITEM_DB_MANAGER::db_update_argv{
    db_update_arg(0, 0, "../ITEM/0/0.txt"),
    db_update_arg(0, 1, "../ITEM/0/1.txt"),
    db_update_arg(1, 0, "../ITEM/1/0.txt"),
    db_update_arg(1, 1, "../ITEM/1/1.txt"),
    db_update_arg(2, 0, "../ITEM/2/0.txt"),
    db_update_arg(2, 1, "../ITEM/2/1.txt"),
    db_update_arg(3, 0, "../ITEM/3/0.txt"),
    db_update_arg(4, 0, "../ITEM/4/0.txt"),
    db_update_arg(4, 1, "../ITEM/4/1.txt"),
    db_update_arg(4, 2, "../ITEM/4/2.txt"),
    db_update_arg(4, 3, "../ITEM/4/3.txt"),
    db_update_arg(4, 4, "../ITEM/4/4.txt"),
    db_update_arg(5, 0, "../ITEM/5/0.txt"),
    db_update_arg(5, 1, "../ITEM/5/1.txt"),
    db_update_arg(5, 2, "../ITEM/5/2.txt"),
    db_update_arg(5, 3, "../ITEM/5/3.txt"),
    db_update_arg(5, 4, "../ITEM/5/4.txt"),
    db_update_arg(6, 0, "../ITEM/6/0.txt"),
    db_update_arg(6, 1, "../ITEM/6/1.txt"),
    db_update_arg(6, 2, "../ITEM/6/2.txt"),
    db_update_arg(6, 3, "../ITEM/6/3.txt"),
    db_update_arg(7, 0, "../ITEM/7/0.txt"),
    db_update_arg(7, 1, "../ITEM/7/1.txt"),
    db_update_arg(7, 2, "../ITEM/7/2.txt"),
    db_update_arg(7, 3, "../ITEM/7/3.txt"),
    db_update_arg(7, 4, "../ITEM/7/4.txt"),
    db_update_arg(7, 5, "../ITEM/7/5.txt"),
    db_update_arg(8, 0, "../ITEM/8/0.txt"),
    db_update_arg(8, 1, "../ITEM/8/1.txt"),
    db_update_arg(8, 2, "../ITEM/8/2.txt"),
    db_update_arg(8, 3, "../ITEM/8/3.txt"),
    db_update_arg(8, 4, "../ITEM/8/4.txt"),
    db_update_arg(8, 5, "../ITEM/8/5.txt"),
    db_update_arg(8, 6, "../ITEM/8/6.txt"),
    db_update_arg(9, 0, "../ITEM/9/0.txt"),
    db_update_arg(9, 1, "../ITEM/9/1.txt"),
    db_update_arg(9, 2, "../ITEM/9/2.txt"),
    db_update_arg(9, 3, "../ITEM/9/3.txt"),
    db_update_arg(10, 0, "../ITEM/10/0.txt"),
    db_update_arg(10, 1, "../ITEM/10/1.txt"),
    db_update_arg(10, 2, "../ITEM/10/2.txt"),
    db_update_arg(10, 3, "../ITEM/10/3.txt"),
    db_update_arg(10, 4, "../ITEM/10/4.txt"),
    db_update_arg(10, 5, "../ITEM/10/5.txt"),
    db_update_arg(11, 0, "../ITEM/11/0.txt"),
    db_update_arg(11, 1, "../ITEM/11/1.txt"),
    db_update_arg(11, 2, "../ITEM/11/2.txt"),
    db_update_arg(11, 3, "../ITEM/11/3.txt"),
    db_update_arg(12, 0, "../ITEM/12/0.txt"),
    db_update_arg(13, 0, "../ITEM/13/0.txt"),
    db_update_arg(13, 1, "../ITEM/13/1.txt"),
    db_update_arg(13, 2, "../ITEM/13/2.txt"),
    db_update_arg(13, 3, "../ITEM/13/3.txt"),
    db_update_arg(13, 4, "../ITEM/13/4.txt"),
    db_update_arg(13, 5, "../ITEM/13/5.txt"),
    db_update_arg(14, 0, "../ITEM/14/0.txt"),
    db_update_arg(14, 1, "../ITEM/14/1.txt"),
    db_update_arg(14, 2, "../ITEM/14/2.txt"),
    db_update_arg(14, 3, "../ITEM/14/3.txt"),
    db_update_arg(14, 4, "../ITEM/14/4.txt"),
    db_update_arg(14, 5, "../ITEM/14/5.txt"),
    db_update_arg(14, 6, "../ITEM/14/6.txt"),
    db_update_arg(15, 0, "../ITEM/15/0.txt"),
    db_update_arg(15, 1, "../ITEM/15/1.txt"),
    db_update_arg(15, 2, "../ITEM/15/2.txt"),
    db_update_arg(15, 3, "../ITEM/15/3.txt"),
    db_update_arg(16, 0, "../ITEM/16/0.txt"),
    db_update_arg(16, 1, "../ITEM/16/1.txt"),
    db_update_arg(16, 2, "../ITEM/16/2.txt"),
    db_update_arg(16, 3, "../ITEM/16/3.txt"),
    db_update_arg(16, 4, "../ITEM/16/4.txt"),
    db_update_arg(16, 5, "../ITEM/16/5.txt"),
    db_update_arg(17, 0, "../ITEM/17/0.txt"),
    db_update_arg(18, 0, "../ITEM/18/0.txt") //
};
#define _N_UPDATE_THREADS 74
std::string &ITEM_DB_MANAGER::th_category(int th)
{
    return ITEM_DB_MANAGER::CATEGORY[th].first;
}
VECTOR<std::string> &ITEM_DB_MANAGER::th_sub_category(int th)
{
    return ITEM_DB_MANAGER::CATEGORY[th].second;
}
VECTOR<ITEM> &ITEM_DB_MANAGER::item_cont_of_category(int upper_cat, int lower_cat)
{
    return ITEM_DB_MANAGER::ITEM_CONTAINER[upper_cat][lower_cat];
}
size_t ITEM_DB_MANAGER::th_sub_category_size(int th)
{
    return ITEM_DB_MANAGER::CATEGORY[th].second.size();
}
size_t ITEM_DB_MANAGER::item_cont_of_category_size(int upper_cat, int lower_cat)
{
    return ITEM_DB_MANAGER::ITEM_CONTAINER[upper_cat][lower_cat].size();
}
void *ITEM_DB_MANAGER::init_item_container_routine(void *args)
{
    db_update_arg *iArgs = (db_update_arg *)args;
    const int &upper_cat = iArgs->upper_cat;
    const int &lower_cat = iArgs->lower_cat;

    std::ifstream dbITEM;
    dbITEM.open(iArgs->fPath);

    ITEM _itemp;
    while (dbITEM >> _itemp)
        ITEM_DB_MANAGER::ITEM_CONTAINER[upper_cat][lower_cat].push_back(std::move(_itemp));

    dbITEM.close();

    return nullptr;
}
void *ITEM_DB_MANAGER::update_item_stream_routine(void *args)
{
    db_update_arg *iArgs = (db_update_arg *)args;

    std::ofstream UpdateDB;
    UpdateDB.open(iArgs->fPath, std::ios::trunc);
    for (const ITEM &_it : ITEM_DB_MANAGER::ITEM_CONTAINER[iArgs->upper_cat][iArgs->lower_cat])
        UpdateDB << _it;

    UpdateDB.close();
    return nullptr;
}
void *ITEM_DB_MANAGER::sort_item_container_routine(void *args)
{
    db_update_arg *iArgs = (db_update_arg *)args;
    std::sort(ITEM_DB_MANAGER::ITEM_CONTAINER[iArgs->upper_cat][iArgs->lower_cat].begin(), ITEM_DB_MANAGER::ITEM_CONTAINER[iArgs->upper_cat][iArgs->lower_cat].end());
    return nullptr;
}
void *ITEM_DB_MANAGER::find_item_with_sku_routine(void *args)
{
    _findItemArgs *_fa = (_findItemArgs *)args;
    VECTOR<ITEM> &LRVec = ITEM_DB_MANAGER::ITEM_CONTAINER[_fa->upper_cat][_fa->lower_cat];
    long long lo{0}, hi{static_cast<long long>(LRVec.size() - 1)};
    long long mi;
    _itemCoor *_res{nullptr};
    while (lo <= hi)
    {
        mi = lo + hi >> 1;
        if (LRVec[mi].sku() == _fa->_sku)
        {
            _res = new _itemCoor(_fa->upper_cat, _fa->lower_cat, mi);
            break;
        }
        else if (LRVec[mi].sku() > _fa->_sku)
            hi = mi - 1;
        else
            lo = mi + 1;
    }
    delete _fa;
    return _res;
}
void ITEM_DB_MANAGER::init_item_container()
{
    pthread_t iThread[_N_UPDATE_THREADS];
    for (int &&i{0}; i < _N_UPDATE_THREADS; ++i)
        pthread_create(&iThread[i], nullptr, ITEM_DB_MANAGER::init_item_container_routine, &db_update_argv[i]);

    for (int &&i{0}; i < _N_UPDATE_THREADS; ++i)
        pthread_join(iThread[i], nullptr);
}
void ITEM_DB_MANAGER::update_item_stream()
{
    pthread_t iThread[_N_UPDATE_THREADS];
    for (int &&i{0}; i < _N_UPDATE_THREADS; ++i)
        pthread_create(&iThread[i], nullptr, ITEM_DB_MANAGER::update_item_stream_routine, &db_update_argv[i]);

    for (int &&i{0}; i < _N_UPDATE_THREADS; ++i)
        pthread_join(iThread[i], nullptr);
}
void ITEM_DB_MANAGER::sort_item_container()
{
    pthread_t iThread[_N_UPDATE_THREADS];
    for (int &&i{0}; i < _N_UPDATE_THREADS; ++i)
        pthread_create(&iThread[i], nullptr, ITEM_DB_MANAGER::sort_item_container_routine, &db_update_argv[i]);

    for (int &&i{0}; i < _N_UPDATE_THREADS; ++i)
        pthread_join(iThread[i], nullptr);
}
_itemCoor *ITEM_DB_MANAGER::find_item_with_sku(const std::string &_sku)
{
    pthread_t _findThread[_N_UPDATE_THREADS];
    for (short unsigned &&i{0}, &&k{0}; i < ITEM_DB_MANAGER::ITEM_CONTAINER.size(); ++i)
        for (short unsigned &&j{0}; j < ITEM_DB_MANAGER::ITEM_CONTAINER[i].size(); ++j)
            pthread_create(&_findThread[k++], nullptr, ITEM_DB_MANAGER::find_item_with_sku_routine, new _findItemArgs(i, j, _sku));

    bool _exist = false;
    _itemCoor *_ckptr{nullptr};
    _itemCoor *_iptres{nullptr};

    for (short unsigned &&i{0}; i < _N_UPDATE_THREADS; ++i)
    {
        pthread_join(_findThread[i], (void **)&_ckptr);
        if (_ckptr != nullptr)
            _iptres = _ckptr;
    }
    if (_iptres != 0)
        return _iptres;

    return nullptr;
}
ITEM &ITEM_DB_MANAGER::item_in_container(int upper_cat, int lower_cat, int index)
{
    return ITEM_DB_MANAGER::ITEM_CONTAINER[upper_cat][lower_cat][index];
}
bool getCategory(int &upper_cat, int &lower_cat)
{
    clrscr();
    int xMax, yMax;
    int startX, startY;
    maxXY(xMax, yMax);

    tc_print_frame(1, (xMax - 13) >> 1, 1, 15, BHYEL);
    gotoyx(2, ((xMax - 13) >> 1) + 2);
    printf("%sCHỌN DANH MỤC", BHRED);
    manArrow();

    startY = yMax - 39;
    tc_print_frame(startY, 1, 19, 31, BHCYN);
    upper_cat = 0;
    lower_cat = -1;
    uint64_t kp;
    bool exit = true;
    bool activeR = true;

    while (true)
    {
        if (activeR)
            printCategory(upper_cat, startY);
        if (ITEM_DB_MANAGER::th_sub_category_size(upper_cat) != 0)
        {
            tc_print_frame(startY, 34, ITEM_DB_MANAGER::th_sub_category_size(upper_cat), 31, BHCYN);
            printSubCat(ITEM_DB_MANAGER::th_sub_category(upper_cat), lower_cat, startY);
        }
        kp = tc_getch();
        switch (kp)
        {
        case TC_KEY_ARROW_UP:
            if (activeR && upper_cat != 0)
            {
                rmSubCat(ITEM_DB_MANAGER::th_sub_category(upper_cat), startY);
                --upper_cat;
            }
            else if (!activeR && lower_cat != 0)
                --lower_cat;
            break;

        case TC_KEY_ARROW_DOWN:
            if (activeR && upper_cat != CATEGORY_SZ - 1)
            {
                rmSubCat(ITEM_DB_MANAGER::th_sub_category(upper_cat), startY);
                ++upper_cat;
            }
            else if (!activeR && lower_cat != ITEM_DB_MANAGER::th_sub_category_size(upper_cat) - 1)
                ++lower_cat;
            break;

        case TC_KEY_ARROW_RIGHT:
            if (activeR)
            {
                activeR = false;
                lower_cat = 0;
            }
            break;
        case TC_KEY_ARROW_LEFT:
            if (!activeR)
            {
                activeR = true;
                lower_cat = -1;
            }
            break;
        case TC_KEY_RETURN:
            if (ITEM_DB_MANAGER::th_sub_category_size(upper_cat) == 0)
            {
                lower_cat = 0;
                return true;
            }
            if (!activeR)
                return true;
            break;
        case TC_KEY_ESCAPE:
            return false;
        default:
            break;
        }
    }
    return false;
}
void printCategory(int &upper_cat, int &startY)
{
    printf("%s", BHYEL);
    for (int &&i{0}; i < CATEGORY_SZ; ++i)
    {
        gotoyx(startY + 1 + (i << 1), 3);
        if (i != upper_cat)
            printf("%s%s", BHCYN, ITEM_DB_MANAGER::th_category(i).c_str());
        else
            printf("%s%s%s%s", BLUHB, BHMAG, ITEM_DB_MANAGER::th_category(i).c_str(), CRESET);
    }
}
void printSubCat(const VECTOR<std::string> &subcat, int &lower_cat, int &startY)
{
    textcolor(BHGRN);
    for (int &&i{0}; i < subcat.size(); i++)
    {
        gotoyx(startY + (i << 1) + 1, 35);
        if (i != lower_cat)
            printf("%s%s", BHGRN, subcat[i].c_str());
        else
            printf("%s%s%s%s", YELHB, BHBLU, subcat[i].c_str(), CRESET);
    }
}
void rmSubCat(const VECTOR<std::string> &subcat, int &startY)
{
    for (int &&i{0}; i <= (subcat.size() << 1); i++)
    {
        gotoyx(startY + i, 34);
        tc_print_fill(33, " ");
    }
}
void manArrow()
{
    int xMax, yMax;
    maxXY(xMax, yMax);
    gotoyx(yMax - 3, xMax - 17);
    printf("%s🠅🠇🠄🠆 %s : %sDi chuyển", "\x1B[1;32m", "\x1B[0;34m", "\x1B[0;33m");
    gotoyx(yMax - 2, xMax - 17);
    printf("%sENTER %s: %sChọn", "\x1B[1;32m", "\x1B[0;34m", "\x1B[0;33m");
    gotoyx(yMax - 1, xMax - 17);
    printf("%sESC   %s: %sQuay lại", "\x1B[1;32m", "\x1B[0;34m", "\x1B[0;33m");
}

bool checkValidSKU(const std::string &_sku)
{
    if (_sku.length() != 8)
        return false;
    for (const char &ch : _sku)
        if (isdigit(ch) == false)
            return false;
    return true;
}
bool checkValidUnit(short unsigned &nUnit)
{
    return !(nUnit < '1' || nUnit > '5');
}

void takeSKU(std::string &_sku, bool _chk)
{
    _itemCoor *item_finder_ptr(nullptr);
    while (true)
    {
        while (true)
        {
            printf("%sSKU : %s", BHCYN, BHGRN);
            std::cin >> _sku;
            clearbuffer();
            if (!checkValidSKU(_sku))
            {
                printf("%sSKU không hợp lệ !\n", BHRED);
                continue;
            }
            break;
        }
        if (_chk)
        {
            item_finder_ptr = ITEM_DB_MANAGER::find_item_with_sku(_sku);
            if (item_finder_ptr != nullptr)
            {
                printf("%s%sSKU đã tồn tại!%s\n", WHTHB, BHRED, CRESET);
                putchar_unlocked('\n');
                itemPrinter(item_finder_ptr);
                item_finder_ptr = nullptr;
                printf("%s%sNhập lại%s\n", MAGHB, BHWHT, CRESET);
                delete item_finder_ptr;
                continue;
            }
        }
        break;
    }
}
void takeName(std::string &_name)
{
    printf("%sTên sản phẩm : %s", BHCYN, BHGRN);
    std::getline(std::cin, _name);
}
void takenUnit(short unsigned &nUnit)
{
    while (true)
    {
        printf("%sSố loại [1-5] : %s", BHCYN, BHGRN);
        nUnit = tc_getch();
        if (!checkValidUnit(nUnit))
        {
            printf("\n%sSố lượng không hợp lệ!\n", BHRED);
            continue;
        }
        break;
    }
    nUnit -= '0';
    putchar_unlocked('\n');
}
void takeType(VECTOR<ITEMPROP> &_classify, short unsigned &nUnit)
{
    std::string _unit;
    size_t _cost;
    size_t _price;
    size_t _promoprice;
    size_t _quantity;
    for (int &&i{0}; i < nUnit; ++i)
    {
        printf("%s▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ %sNhập loại %d %s▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n", BHYEL, BHMAG, i + 1, BHYEL);

        printf("%sTên loại : %s", BCYN, BGRN);
        std::getline(std::cin, _unit);

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

        _classify.push_back(ITEMPROP(std::move(_unit), _cost, _price, _promoprice, _quantity));
    }
}
void itemPrinter(const _itemCoor *_it_Attr, bool _top)
{
    if (_top)
        gotoyx(1, 1);
    printf("%s┌──%s%s %s%s\n", HYEL, GRNHB, BHRED, ITEM_DB_MANAGER::th_category(_it_Attr->upper_cat).c_str(), CRESET);
    if (ITEM_DB_MANAGER::th_sub_category_size(_it_Attr->upper_cat) != 0)
        printf("%s├──%s%s%s%s\n", HYEL, YELHB, BHMAG, ITEM_DB_MANAGER::th_sub_category(_it_Attr->upper_cat)[_it_Attr->lower_cat].c_str(), CRESET);

    else
        printf("%s│\n", HYEL);
    printf("%s│\n", HYEL);

    printf("%s├─%sSKU          : %s%s\n", HYEL, BHCYN, BHGRN, ITEM_DB_MANAGER::item_in_container(_it_Attr->upper_cat, _it_Attr->lower_cat, _it_Attr->_idx).sku().c_str());
    printf("%s├─%sTên sản phẩm : %s%s\n", HYEL, BHCYN, BHGRN, ITEM_DB_MANAGER::item_in_container(_it_Attr->upper_cat, _it_Attr->lower_cat, _it_Attr->_idx).name().c_str());
    printf("%s└─%sSố loại      : %s%ld\n", HYEL, BHCYN, BHGRN, ITEM_DB_MANAGER::item_in_container(_it_Attr->upper_cat, _it_Attr->lower_cat, _it_Attr->_idx).classify().size());
    putchar_unlocked('\n');
    for (int &&i{0}; i < ITEM_DB_MANAGER::item_in_container(_it_Attr->upper_cat, _it_Attr->lower_cat, _it_Attr->_idx).classify().size(); ++i)
    {
        printf("%s        ┌─%sTên loại           : %s%s\n", GRN, BHCYN, BHGRN, ITEM_DB_MANAGER::item_in_container(_it_Attr->upper_cat, _it_Attr->lower_cat, _it_Attr->_idx).classify()[i].unit().c_str());
        printf("%s        ├─%sGiá nhập           : %s%ld\n", GRN, BHCYN, BHGRN, ITEM_DB_MANAGER::item_in_container(_it_Attr->upper_cat, _it_Attr->lower_cat, _it_Attr->_idx).classify()[i].cost());
        printf("%s%sLoại %d%s  %s├─%sGiá bán            : %s%ld\n", GRNHB, BHYEL, i + 1, CRESET, GRN, BHCYN, BHGRN, ITEM_DB_MANAGER::item_in_container(_it_Attr->upper_cat, _it_Attr->lower_cat, _it_Attr->_idx).classify()[i].price());
        printf("%s        ├─%sGiá khuyến mãi     : %s%ld\n", GRN, BHCYN, BHGRN, ITEM_DB_MANAGER::item_in_container(_it_Attr->upper_cat, _it_Attr->lower_cat, _it_Attr->_idx).classify()[i].promoprice());
        printf("%s        └─%sSố lượng trong kho : %s%ld\n", GRN, BHCYN, BHGRN, ITEM_DB_MANAGER::item_in_container(_it_Attr->upper_cat, _it_Attr->lower_cat, _it_Attr->_idx).classify()[i].quantity());
        putchar_unlocked('\n');
    }
}

VECTOR<_itemCoor> ITEM_DB_MANAGER::ITEM_DB_MANAGER::item_finder_cont;
pthread_mutex_t ITEM_DB_MANAGER::item_finder_cont_mutex;

void *ITEM_DB_MANAGER::find_similar_item_routine(void *args)
{
    _findItemArgs *_fa = (_findItemArgs *)args;
    VECTOR<ITEM> &LRVec = ITEM_DB_MANAGER::ITEM_CONTAINER[_fa->upper_cat][_fa->lower_cat];
    for (size_t &&i(0); i < LRVec.size(); ++i)
    {
        if (SKIPSEARCH(_fa->_sku.c_str(), LRVec[i].priname().c_str()))
        {
            pthread_mutex_lock(&ITEM_DB_MANAGER::item_finder_cont_mutex);
            ITEM_DB_MANAGER::item_finder_cont.push_back(_itemCoor(_fa->upper_cat, _fa->lower_cat, i));
            pthread_mutex_unlock(&ITEM_DB_MANAGER::item_finder_cont_mutex);
        }
    }
    delete _fa;
    return nullptr;
}
void *ITEM_DB_MANAGER::fint_similar_item_routine_vietnamese_version(void *args)
{
    _findItemArgs *_fa = (_findItemArgs *)args;
    VECTOR<ITEM> &LRVec = ITEM_DB_MANAGER::ITEM_CONTAINER[_fa->upper_cat][_fa->lower_cat];
    for (size_t &&i(0); i < LRVec.size(); ++i)
    {
        if (SKIPSEARCH(_fa->_sku.c_str(), LRVec[i].origin_priname().c_str()))
        {
            pthread_mutex_lock(&ITEM_DB_MANAGER::item_finder_cont_mutex);
            ITEM_DB_MANAGER::item_finder_cont.push_back(_itemCoor(_fa->upper_cat, _fa->lower_cat, i));
            pthread_mutex_unlock(&ITEM_DB_MANAGER::item_finder_cont_mutex);
        }
    }
    delete _fa;
    return nullptr;
}
const VECTOR<_itemCoor> &ITEM_DB_MANAGER::find_similar_item(std::string &similar_str)
{
    pthread_mutex_init(&ITEM_DB_MANAGER::item_finder_cont_mutex, nullptr);
    item_finder_cont.~VECTOR();
    pthread_t item_finder_td[_N_UPDATE_THREADS];
    if (IsVietNameseString(similar_str))
    {
        LowercaseVietNameseCharacter(similar_str);
        lowercaseStr(similar_str);
        for (short unsigned &&i{0}, &&k{0}; i < ITEM_DB_MANAGER::ITEM_CONTAINER.size(); ++i)
            for (short unsigned &&j{0}; j < ITEM_DB_MANAGER::ITEM_CONTAINER[i].size(); ++j)
                pthread_create(&item_finder_td[k++], nullptr, ITEM_DB_MANAGER::fint_similar_item_routine_vietnamese_version, new _findItemArgs(i, j, similar_str));

        for (short unsigned &&i{0}; i < _N_UPDATE_THREADS; ++i)
            pthread_join(item_finder_td[i], nullptr);
    }
    else
    {
        lowercaseStr(similar_str);

        for (short unsigned &&i{0}, &&k{0}; i < ITEM_DB_MANAGER::ITEM_CONTAINER.size(); ++i)
            for (short unsigned &&j{0}; j < ITEM_DB_MANAGER::ITEM_CONTAINER[i].size(); ++j)
                pthread_create(&item_finder_td[k++], nullptr, ITEM_DB_MANAGER::find_similar_item_routine, new _findItemArgs(i, j, similar_str));

        for (short unsigned &&i{0}; i < _N_UPDATE_THREADS; ++i)
            pthread_join(item_finder_td[i], nullptr);
    }

    pthread_mutex_destroy(&ITEM_DB_MANAGER::item_finder_cont_mutex);
    return ITEM_DB_MANAGER::item_finder_cont;
}