#pragma once
#include "../CONIO/CONIO.h"
#include "../DATASTRUCTURE/VECTOR.h"

int XMAX, YMAX, startX, startY;

VECTOR<const char *> winmart_watermark{
    " wwwwww     wwwww       wwwww       wwww",
    "wwwwwwww    wwwwww     wwwww       wwwww",
    " wwwwwwww   wwwwwww   wwwww       wwwwwwiiii                     mmmmmm           mmmmm                                 tttttt",
    "  wwwwwwww   wwwwwww wwwww       wwwwww iiii                     mmmmmmm         mmmmmm                                 tttttt",
    "  wwwwwwwww   wwwwwwwwwww       wwwwww          nnn   nnnnn      mmmmmmmm       mmmmmmm      aaaaaaa       rrr  rrr   ttttttttttt",
    "   wwwwwwwww   wwwwwwwwww      wwwwww  iiiiii  nnnnnnnnnnnnnn    mmmmmmmmm     mmmmmmmm   aaaaaaaaaaaaa   rrrrrrrrrr  ttttttttttt",
    "    wwwwwwwww   wwwwwwww      wwwwww   iiiiii  nnnnnn   nnnnnn   mmmmmmmmmm   mmmmmmmmm            aaaaa  rrrrrrrrrr    tttttt",
    "     wwwwwwwww   wwwwwww     wwwwww    iiiiii  nnnnn     nnnnn   mmm mmmmmmm mmm  mmmmm    aaaaaaaaaaaaa  rrrrr         tttttt",
    "      wwwwwwwww   wwwwwww   wwwwww     iiiiii  nnnnn     nnnnn   mmm  mmmmmmmmm   mmmmm  aaaaaaaa  aaaaa  rrrrr         tttttt",
    "       wwwwwwwwwwwwwwwwwwwwwwwwww      iiiiii  nnnnn     nnnnn   mmm   mmmmmmm    mmmmm  aaaaaa   aaaaaa  rrrrr         tttttt",
    "        wwwwwwwwwwwwwwwwwwwwwwww       iiiiii  nnnnn     nnnnn   mmm    mmmmm     mmmmm  aaaaaaaaaaaaaaa  rrrrr          ttttttttt",
    "         wwwwwwwww   wwwwwwwwww        iiiiii  nnnnn     nnnnn   mmm              mmmmm     aaaaaaa  aaa  rrrrr            tttttt",
    "          wwwwwww     wwwwwwww",
    "           wwwww       wwwwww" /**/
};

VECTOR<const char *> TEXT_COLOR{
    "\e[1;90m",
    "\e[1;91m",
    "\e[1;92m",
    "\e[1;93m",
    "\e[1;94m",
    "\e[1;95m",
    "\e[1;96m",
    "\e[1;97m" /**/
};

void BLINK_WATERMARK(int &colorChange)
{
    for (int &&i{0}; i < 14; ++i)
    {
        gotoyx(startY + i, startX);
        printf("%s%s", TEXT_COLOR[--colorChange], winmart_watermark[i]);
        if (colorChange == 0)
            colorChange = 8;
    }
}
void *PRINT_WATER_MARK(void *)
{
    int colorChange = 1;
    while (true)
    {
        BLINK_WATERMARK(colorChange);
        usleep(500);
    }
    return nullptr;
}
void WELCOME()
{
    clrscr();
    tc_echo_off();
    tc_cursor_off();

    maxXY(XMAX, YMAX);
    startX = (XMAX >> 1) - 65;
    startY = (YMAX >> 1) - 7;

    pthread_t print_watermark_thread;
    pthread_create(&print_watermark_thread, nullptr, PRINT_WATER_MARK, nullptr);
    tc_getch();
    pthread_cancel(print_watermark_thread);

    tc_echo_on();
    tc_cursor_on();
    clrscr();
}

VECTOR<const char *> thankyou_watermark{
    " ________  __                            __              __      __                         __  __ ",
    "/        |/  |                          /  |            /  \\    /  |                       /  |/  |",
    "$$$$$$$$/ $$ |____    ______   _______  $$ |   __       $$  \\  /$$/______   __    __       $$ |$$ |",
    "   $$ |   $$      \\  /      \\ /       \\ $$ |  /  |       $$  \\/$$//      \\ /  |  /  |      $$ |$$ |",
    "   $$ |   $$$$$$$  | $$$$$$  |$$$$$$$  |$$ |_/$$/         $$  $$//$$$$$$  |$$ |  $$ |      $$ |$$ |",
    "   $$ |   $$ |  $$ | /    $$ |$$ |  $$ |$$   $$<           $$$$/ $$ |  $$ |$$ |  $$ |      $$/ $$/ ",
    "   $$ |   $$ |  $$ |/$$$$$$$ |$$ |  $$ |$$$$$$  \\           $$ | $$ \\__$$ |$$ \\__$$ |       __  __ ",
    "   $$ |   $$ |  $$ |$$    $$ |$$ |  $$ |$$ | $$  |          $$ | $$    $$/ $$    $$/       /  |/  |",
    "   $$/    $$/   $$/  $$$$$$$/ $$/   $$/ $$/   $$/           $$/   $$$$$$/   $$$$$$/        $$/ $$/ " /**/
};

void BLINK_THANKYOU_WATERMARK(int &colorChange)
{
    for (int &&i{0}; i < 9; ++i)
    {
        gotoyx(startY + i, startX);
        printf("%s%s", TEXT_COLOR[--colorChange], thankyou_watermark[i]);
        if (colorChange == 0)
            colorChange = 8;
    }
}
void *PRINT_THANKYOU(void *)
{
    int colorChange = 1;
    while (true)
    {
        BLINK_THANKYOU_WATERMARK(colorChange);
        usleep(500);
    }
    return nullptr;
}
void THANKYOU()
{
    tc_clear_screen();
    tc_echo_off();
    tc_cursor_off();
    maxXY(XMAX, YMAX);
    startX = (XMAX - 104) >> 1;
    startY = (YMAX - 9) >> 1;

    pthread_t print_thankyou_thread;
    pthread_create(&print_thankyou_thread, nullptr, PRINT_THANKYOU, nullptr);
    tc_getch();
    pthread_cancel(print_thankyou_thread);

    tc_echo_on();
    tc_cursor_on();
}