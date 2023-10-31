#pragma once
#include "essentiallib.h"

std::string ACCOUNT = "";
std::string PASSWORD;

void getACCOUNT();
void getPASSWORD();

VECTOR<const char *> LOGINBOX

    {
        "               \x1B[1;33mĐĂNG NHẬP\x1B[0m               ",
        "",
        "\x1B[1;35m┌─────────┬───────────────────────────┐",
        "\x1B[1;35m│\x1B[1;36mtài khoản\x1B[1;35m│                           │",
        "\x1B[1;35m├─────────┼───────────────────────────┤",
        "\x1B[1;35m│\x1B[1;36mmật khẩu\x1B[1;35m │                           │",
        "\x1B[1;35m└─────────┴───────────────────────────┘"

    };
unsigned short boxH;
unsigned short boxW;
unsigned short startULy;
unsigned short startULx;

void BOX()
{
    for (int &&i{0}; i < boxH; i++)
    {
        tc_move_cursor(startULy + i, startULx);
        printf("%s", LOGINBOX[i]);
    }
}

void LOGIN()
{
    tc_clear_screen();
    tc_get_cols_rows(&XMAX, &YMAX);
    boxH = 7;
    boxW = 39;
    startULy = (YMAX - boxH) / 2;
    startULx = (XMAX - boxW) / 2;
    BOX();
    getACCOUNT();
}

void getACCOUNT()
{
    // tc_canon_on();
    // tc_move_cursor(startULy + 3, startULx + 11);
    int c;
    std::cin >> c;
}
void getPASSWORD()
{
}