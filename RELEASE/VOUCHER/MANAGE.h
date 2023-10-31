#pragma once
#include <fstream>
#include <iostream>

#include "VOUCHER.h"
#include "../DATASTRUCTURE/AVLTree.h"

class VOUCHER_MANAGER_CLASS
{
private:
    VOUCHER_MANAGER_CLASS() = default;
    static AVLTree<VOUCHER> VOUCHER_DS;

public:
    static void INIT_VOUCHER_DS(std::string = "../VOUCHER/VOUCHER.txt");
    static void UPDATE_VOUCHER_DB(std::string = "../VOUCHER/VOUCHER.txt");
    static void INSERT_NEW_VOUCHER(VOUCHER &&, bool * = nullptr);
};

// void CHECK_VALID_VOUCHER(const VOUCHER &V)
// {
//     auto ptr = VOUCHER_DS.FindByKey(V);
//     if (ptr == nullptr)
//         throw "Voucher không hợp lệ!";
// }
#include "MANAGE.cc"