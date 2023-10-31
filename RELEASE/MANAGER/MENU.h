#pragma once
#include <iostream>
#include "ADDITEM.h"
#include "UPDATEITEM.h"
#include "FINDITEM.h"
#include "../CONIO/CONIO.h"
#include "../VOUCHER/CREATE.h"

VECTOR<std::string> mMenu{
    "     Tìm sản phẩm     ", // 0
    "     Thêm sản phẩm    ", // 1
    "     Sửa sản phẩm     ", // 2
    "      Tạo voucher     ", // 3
    "   Lịch sử chỉnh sửa  "};

void printMenu(int &highlight, int &startY, int &startX);
void HOMEPAGE();
#include "MENU.cc"