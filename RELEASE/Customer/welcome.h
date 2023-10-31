#pragma once

VECTOR<const char *> watermark

    {
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
        "           wwwww       wwwwww"

    };

VECTOR<const char *> TEXT_COLOR

    {
        "\x1B[1;30m",
        "\x1B[1;31m",
        "\x1B[1;32m",
        "\x1B[1;33m",
        "\x1B[1;34m",
        "\x1B[1;35m"

    };

void PRINT_LOGO(int &colorChange)
{
    static int startX = XMAX / 2 - 65;
    static int startY = YMAX / 2 - 7;
    for (int &&i{0}; i < 14; ++i)
    {
        tc_move_cursor(startY + i, startX);
        printf("%s", TEXT_COLOR[--colorChange]);
        printf("%s", watermark[i]);
        if (colorChange == 0)
            colorChange = 6;
    }
}

void WELCOME()
{
    tc_enter_alt_screen();
    tc_clear_screen();
    tc_echo_off();
    tc_cursor_off();
    tc_canon_off();
    tc_get_cols_rows(&XMAX, &YMAX);
    tc_move_cursor(YMAX - 2, 3);
    std::cout << TC_YEL;
    std::cout << "Press any key to continue...";

    int colorChange = 1;
    bool NEXTPAGE = 0;
    pthread_t tid1;
    pthread_create(&tid1, nullptr, GET_SIGNAL, &NEXTPAGE);
    while (!NEXTPAGE)
    {
        PRINT_LOGO(colorChange);
        sleep(1);
    }
    tc_echo_on();
    tc_cursor_on();
    tc_canon_on();
}
