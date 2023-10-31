#include "MENU.h"
#include "GREET.h"
#include <iostream>

int main()
{
    WELCOME();
    tc_echo_off();
    tc_cursor_off();
    try
    {
        EDIT_HISTORY::INIT_HISTORY();
        ITEM_DB_MANAGER::init_item_container();
        VOUCHER_MANAGER_CLASS::INIT_VOUCHER_DS();
    }
    catch (...)
    {
    }
    HOMEPAGE();

    VOUCHER_MANAGER_CLASS::UPDATE_VOUCHER_DB();
    EDIT_HISTORY::UPDATE_HISTORY();

    // ITEM_DB_MANAGER::update_item_stream();

    THANKYOU();

    clrscr();
    tc_echo_on();
    tc_cursor_on();
    gotoyx(1, 1);

    return 0;
}
