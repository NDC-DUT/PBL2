#include "MENU.h"
void HOMEPAGE()
{
    clrscr();

    int xMax, yMax;
    int highlight{0};
    maxXY(xMax, yMax);
    int startY = (yMax - mMenu.size()) >> 1;
    int startX = (xMax - 22) >> 1;

    tc_print_frame(startY, startX, mMenu.size(), 22, BHBLU);
    manArrow();

    uint64_t ch;
    while (true)
    {
        printMenu(highlight, startY, startX);
        ch = tc_getch();
        switch (ch)
        {
        case TC_KEY_ARROW_UP:
            if (highlight != 0)
                --highlight;
            break;

        case TC_KEY_ARROW_DOWN:
            if (highlight != mMenu.size() - 1)
                ++highlight;
            break;

        case TC_KEY_RETURN:
            switch (highlight)
            {
            case 0:
                findITEM();
                break;
            case 1:
                addITEM();
                break;
            case 2:
                updateITEM();
                break;
            case 3:
                createVoucher();
                break;
            case 4:
                viewHistory();
                break;
            }
            tc_print_frame(startY, startX, mMenu.size(), 22, BHBLU);
            manArrow();
            break;
        case TC_KEY_ESCAPE:
            clrscr();
            return;
        }
    }
}

void printMenu(int &highlight, int &startY, int &startX)
{
    textcolor(BHYEL);
    for (int &&i{0}; i < mMenu.size(); ++i)
    {
        gotoyx(startY + (i << 1) + 1, startX + 1);
        if (i != highlight)
            printf("%s%s", BHMAG, mMenu[i].c_str());
        else
            printf("%s%s%s%s", GRNHB, BHCYN, mMenu[i].c_str(), CRESET);
    }
}
