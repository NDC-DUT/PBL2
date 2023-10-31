#pragma once
#include "EDITHISTORY.h"
#include "../ITEM/ITEMMANAGE.h"

VECTOR<std::string> _mulChoice{
    "    Chuyển danh mục     ",
    "    Sửa tên sản phẩm    ",
    "   Thêm loại sản phẩm   ",
    "   Xóa loại sản phẩm    ",
    "    Sửa giá sản phẩm    ",
    "   Nhập thêm sản phẩm   ",
    "      Xóa sản phẩm      "};
void printChoice(int &startY, int &startX, unsigned short &_highLight);

void changeCategory(_itemCoor *_returnItem);
void changeName(_itemCoor *_returnItem);
void addType(_itemCoor *_returnItem);
void rmType(_itemCoor *_returnItem);
void upCost(_itemCoor *_returnItem);
void upQuan(_itemCoor *_returnItem);
void rmItem(_itemCoor *_returnItem);
short chooseType(_itemCoor *_returnItem);

#define NChangeChoice 7
void (*_funPtrArr[NChangeChoice])(_itemCoor *_returnItem){
    changeCategory,
    changeName,
    addType,
    rmType,
    upCost,
    upQuan,
    rmItem};

void updateITEM();
#include "UPDATEITEM.cc"
