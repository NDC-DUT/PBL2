#pragma once
#include <string>
#include <fstream>
#include "../DATETIME/DATE.h"
#include "../DATETIME/TIME.h"
#include "../DATASTRUCTURE/DList.h"

class EDIT_OBJECT
{
private:
    std::string _EDIT_ID;
    std::string _EDIT_TYPE;
    std::string _EDIT_MESSAGE;
    DATE _EDIT_DATE;
    TIME _EDIT_TIME;

public:
    const std::string &EDIT_ID() const;
    const std::string &EDIT_TYPE() const;
    const std::string &EDIT_MESSAGE() const;
    const DATE &EDIT_DATE() const;
    const TIME &EDIT_TIME() const;
    EDIT_OBJECT(std::string &&, std::string &&, std::string &&, std::string &&, std::string &&);
    EDIT_OBJECT(std::string &&, std::string &&, std::string &&, DATE &, TIME &);
};
class EDIT_HISTORY
{
private:
    EDIT_HISTORY()=default;
    static DList<EDIT_OBJECT> HISTORY_DB;
    static size_t _CURRENT_ID;

public:
    static void ADD_HISTORY(std::string EDIT_TYPE, std::string EDIT_MESSAGE, DATE = DATE(), TIME = TIME());
    static void INIT_HISTORY(std::string fpath = "EDITHISTORY.txt");
    static void UPDATE_HISTORY(std::string fpath = "EDITHISTORY.txt");
    static DListNode<EDIT_OBJECT> *head();
};
void viewHistory();
void displayEditObjectContent(const EDIT_OBJECT &);
#include "EDITHISTORY.cc"

/*
 * ADDITEM r c sku                          => add sku to icont[r][c]
 * UPCAT   r(old) c(old) sku r(new) c(new)  => change category
 * UPNAME  r c sku oldname;newname          => change name
 * ADDTYPE r c sku typename;cost price promo quantity
 * DELTYPE r c sku typename;cost price promo quantity
 * UPCOST  r c sku typename;th price oldprice newprice
 * UPQUAN  r c sku typename;numadd
 * DELITEM r c sku itemname;numtype 1st type name;cost price promo quantity 2nd typename; ...;
 */