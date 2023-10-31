#pragma once

#include <stdio.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
#include <stdint.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>

#define tc_clear_screen() puts("\x1B[2J")
#define tc_cursor_off() puts("\e[?25l")
#define tc_cursor_on() puts("\e[?25h")
#define gotoxy(X, Y) printf("\033[%d;%dH", Y, X)
#define gotoyx(Y, X) printf("\033[%d;%dH", Y, X)

void tc_get_cols_rows(int &cols, int &rows);

#define tc_enter_alt_screen() puts("\033[?1049h\033[H")
#define tc_exit_alt_screen() puts("\033[?1049l")

void tc_echo_off();
void tc_echo_on();

void tc_get_cols_rows(int &cols, int &rows)
{
    struct winsize size;
    ioctl(1, TIOCGWINSZ, &size);
    cols = size.ws_col;
    rows = size.ws_row;
}

void tc_echo_off()
{
    struct termios term;
    tcgetattr(1, &term);
    term.c_lflag &= ~ECHO;
    tcsetattr(1, TCSANOW, &term);
}

void tc_echo_on()
{
    struct termios term;
    tcgetattr(1, &term);
    term.c_lflag |= ECHO;
    tcsetattr(1, TCSANOW, &term);
}

void tc_canon_on()
{
    struct termios term;
    tcgetattr(1, &term);
    term.c_lflag |= ICANON;
    tcsetattr(1, TCSANOW, &term);
}

void tc_canon_off()
{
    struct termios term;
    tcgetattr(1, &term);
    term.c_lflag &= ~ICANON;
    tcsetattr(1, TCSANOW, &term);
}

#define TC_KEY_ESCAPE 0x1b
#define TC_KEY_F1 0x1b4f50
#define TC_KEY_F1_TTY 0x1b5b5b41
#define TC_KEY_F2 0x1b4f51
#define TC_KEY_F2_TTY 0x1b5b5b42
#define TC_KEY_F3 0x1b4f52
#define TC_KEY_F3_TTY 0x1b5b5b43
#define TC_KEY_F4 0x1b4f53
#define TC_KEY_F4_TTY 0x1b5b5b44
#define TC_KEY_F5 0x1b5b31357e
#define TC_KEY_F5_TTY 0x1b5b5b45
#define TC_KEY_F6 0x1b5b31377e
#define TC_KEY_F7 0x1b5b31387e
#define TC_KEY_F8 0x1b5b31397e
#define TC_KEY_F9 0x1b5b32307e
#define TC_KEY_F10 0x1b5b32317e
#define TC_KEY_F11 0x1b5b32337e
#define TC_KEY_F12 0x1b5b32347e

#define TC_KEY_ARROW_UP 0x1b5b41
#define TC_KEY_ARROW_DOWN 0x1b5b42
#define TC_KEY_ARROW_LEFT 0x1b5b44
#define TC_KEY_ARROW_RIGHT 0x1b5b43

#define TC_KEY_TAB 0x9
#define TC_KEY_RETURN 0xa
#define TC_KEY_ENTER 0xa

#define TC_KEY_INSERT 0x1b5b327e
#define TC_KEY_HOME 0x1b5b48
#define TC_KEY_PAGE_UP 0x1b5b357e
#define TC_KEY_DELETE 0x1b5b337e
#define TC_KEY_END 0x1b5b46
#define TC_KEY_PAGE_DOWN 0x1b5b367e

#define TC_KEY_EURO 0xffffffffffe181ac
#define TC_KEY_GBP 0xffffffffffffc1a3

#define RAW_INPUT_SIZE 120

typedef struct _raw_input raw_input;
typedef struct _tc_inp ti;

void *t_process_keycode(void *t);
void *t_process_thread(void *t);

struct _raw_input
{

    struct timespec tp;
    char c;
};

struct _tc_inp
{
    raw_input ri[RAW_INPUT_SIZE];
};

uint64_t tc_getch()
{
    ti *t = (ti *)malloc(sizeof(ti));
    memset(t, 0, sizeof(ti));

    tc_canon_off();

    pthread_t thid, thid2;
    pthread_create(&thid, NULL, t_process_thread, (void *)t);
    pthread_create(&thid2, NULL, t_process_keycode, (void *)t);

    int *keycode;
    pthread_join(thid2, (void **)&keycode);
    pthread_cancel(thid);

    uint64_t res = *keycode;
    delete keycode;
    tc_canon_on();
    return res;
}

void *t_process_keycode(void *arg)
{
    ti *t = (ti *)arg;
    int i = 0;
    uint64_t key = 0;
    uint64_t time;
    uint64_t next_time;

    while (!((t->ri[i]).tp.tv_nsec))
        usleep(10000);

    usleep(100);

    key = (t->ri[i]).c;
    time = ((t->ri[i]).tp.tv_sec) * 1000000000;
    time += ((t->ri[i]).tp.tv_nsec);
    (t->ri[i]).tp.tv_nsec = 0;

    i++;
    if (i >= RAW_INPUT_SIZE)
        i = 0;

    if ((t->ri[i]).tp.tv_nsec)
    {
        next_time = ((t->ri[i]).tp.tv_sec) * 1000000000;
        next_time += ((t->ri[i]).tp.tv_nsec);
        while (next_time - time < 100000)
        { // 100,000 nanoseconds
            key <<= 8;
            key += (t->ri[i]).c;
            time = next_time;
            (t->ri[i]).tp.tv_nsec = 0;
            i++;
            if (i >= RAW_INPUT_SIZE)
                i = 0;

            next_time = ((t->ri[i]).tp.tv_sec) * 1000000000;
            next_time += ((t->ri[i]).tp.tv_nsec);
        }
    }
    uint64_t *res = new uint64_t(key);

    return (void *)res;
}

void *t_process_thread(void *arg)
{
    ti *t = (ti *)arg;
    int ri_index = 0;
    int n = 1;

    while (n)
    {
        n = fread(&((t->ri[ri_index]).c), 1, 1, stdin);
        clock_gettime(CLOCK_MONOTONIC, &((t->ri[ri_index]).tp));
        ++ri_index;
        if (ri_index >= RAW_INPUT_SIZE)
            ri_index = 0;
    }

    return nullptr;
}

// void tc_print_fill(short unsigned fWidth, const char *crt)
// {
//     for (int &&i{0}; i < fWidth; i++)
//         printf("%s", crt);
// }
#define tc_print_fill(fWidth, crt)    \
    for (int &&i{0}; i < fWidth; ++i) \
    printf("%s", crt)

void tc_print_frame(short unsigned startY, short unsigned startX, short unsigned fSlot, short unsigned fWidth, const char *color)
{
    puts(color);
    gotoyx(startY, startX);
    printf("%s", "┌");
    tc_print_fill(fWidth, "─");
    printf("%s", "┐");
    gotoyx(startY + 1, startX);
    printf("%s", "│");
    tc_print_fill(fWidth, " ");
    printf("%s", "│");
    int i;
    for (i = 0; i < fSlot - 1; ++i)
    {
        gotoyx(startY + 2 + (i << 1), startX);
        printf("%s", "├");
        tc_print_fill(fWidth, "─");
        printf("%s", "┤");
        gotoyx(startY + 3 + (i << 1), startX);
        printf("%s", "│");
        tc_print_fill(fWidth, " ");
        printf("%s", "│");
    }
    gotoyx(startY + 2 + (i << 1), startX);
    printf("%s", "└");
    tc_print_fill(fWidth, "─");
    printf("%s", "┘");
}
#define textcolor(X) puts(X)
