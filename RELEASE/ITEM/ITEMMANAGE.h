#pragma once

#include "ITEM.h"
#include "../ALGORITHM/SKIPSEARCH.h"
#include "../CONIO/CONIO.h"
#include "../CONIO/GETNOEXP.h"
#include "../DATASTRUCTURE/PAIR.h"

#include <limits>
#include <vector>
#include <iostream>
#include <stddef.h>
#include <fstream>
#include <queue>
struct _findItemArgs
{
    short unsigned upper_cat, lower_cat;
    std::string _sku;
    _findItemArgs(short unsigned upper_cat, short unsigned lower_cat, std::string _sku)
        : upper_cat{upper_cat}, lower_cat{lower_cat}, _sku{std::move(_sku)}
    {
    }
};
struct db_update_arg /*init and update function argument*/
{
    int upper_cat, lower_cat;
    std::string fPath;
    db_update_arg(int upper_cat = 0, int lower_cat = 0, std::string fPath = "")
        : upper_cat{upper_cat}, lower_cat{lower_cat}, fPath{std::move(fPath)}
    {
    }
};
struct _itemCoor
{
    short unsigned upper_cat;
    short unsigned lower_cat;
    size_t _idx;
    _itemCoor(short unsigned upper_cat = 0, short unsigned lower_cat = 0, size_t _idx = 0)
        : upper_cat{upper_cat}, lower_cat{lower_cat}, _idx{_idx}
    {
    }
};

class ITEM_DB_MANAGER
{
private:
    ITEM_DB_MANAGER() = default;
    static VECTOR<VECTOR<VECTOR<ITEM>>> ITEM_CONTAINER;
    static VECTOR<PAIR<std::string, VECTOR<std::string>>> CATEGORY;
    static VECTOR<db_update_arg> db_update_argv;
    static VECTOR<_itemCoor> item_finder_cont;
    static void *init_item_container_routine(void *args);
    static void *update_item_stream_routine(void *args);
    static void *sort_item_container_routine(void *args);
    static void *find_item_with_sku_routine(void *args);
    static void *find_similar_item_routine(void *args);
    static void *fint_similar_item_routine_vietnamese_version(void *args);
    static pthread_mutex_t item_finder_cont_mutex;

public:
    static std::string &
    th_category(int th);
    static VECTOR<std::string> &th_sub_category(int th);
    static size_t th_sub_category_size(int th);
    static VECTOR<ITEM> &item_cont_of_category(int upper_cat, int lower_cat);
    static size_t item_cont_of_category_size(int upper_cat, int lower_cat);
    static void init_item_container();
    static void update_item_stream();
    static void sort_item_container();
    static _itemCoor *find_item_with_sku(const std::string &_sku);
    static ITEM &item_in_container(int upper_cat, int lower_cat, int index);
    static const VECTOR<_itemCoor> &find_similar_item(std::string &);
};

/*function declaration*/
bool getCategory(int &r, int &c);
void printCategory(int &r, int &startY);
void printSubCat(const VECTOR<std::string> &subcat, int &c, int &startY);
void rmSubCat(const VECTOR<std::string> &subcat, int &startY);
void manArrow();

bool checkValidSKU(const std::string &_sku);
bool checkValidUnit(short unsigned &nUnit);

void takeSKU(std::string &_sku, bool _chk = true);
void takeName(std::string &_name);
void takenUnit(short unsigned &nUnit);
void takeType(VECTOR<ITEMPROP> &_classify, short unsigned &nUnit);

void itemPrinter(const _itemCoor *_it_Attr, bool = false);
/*function definition*/
#include "ITEMMANAGE.cc"