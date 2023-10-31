#pragma once

#include "TC.h"

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <termios.h>
#include <sys/ioctl.h>

#define cprintf printf
#define cscanf scanf
#define cgets gets

#define CLEAR "\x1b[2J"
#define SET11 "\x1b[1;1f"
#define CURSOR_UP "\x1b[1A"
#define ERASE_LINE "\x1b[2K"
#define BLINK_SLOW "\x1b[5m"
#define BLINK_RAPID "\x1b[6m"

static struct termios oldterm, newterm;

void initTermios(int echo)
{
    tcgetattr(0, &oldterm);
    newterm = oldterm;
    newterm.c_lflag &= ~ICANON;
    newterm.c_lflag &= echo ? ECHO : ~ECHO;
    tcsetattr(0, TCSANOW, &newterm);
}

void resetTermios(void)
{
    tcsetattr(0, TCSANOW, &oldterm);
}

int getch_(int echo)
{
    int ch;
    initTermios(echo);
    ch = getchar();
    resetTermios();
    return ch;
}

int getch(void)
{
    return getch_(0);
}

int getche(void)
{
    return getch_(1);
}

// #define gotoxy(X, Y) printf("\x1b[%d;%df", Y, X)
// #define gotoyx(Y, X) printf("\x1b[%d;%df", Y, X)

#define clrscr() printf("%s%s", CLEAR, SET11);

void delline()
{
    printf("%s%s", ERASE_LINE, CURSOR_UP);
}

void clreol()
{
    printf("%s", CLEAR);
}

int putch(const char c)
{
    printf("%c", c);
    return (int)c;
}

int cputs(const char *str)
{
    printf("%s", str);
    return 0;
}

int wherexy(int &x, int &y)
{
    printf("\033[6n");
    if (getch() != '\x1B')
        return 0;
    if (getch() != '\x5B')
        return 0;
    int in;
    int ly = 0;
    while ((in = getch()) != ';')
        ly = ly * 10 + in - '0';
    int lx = 0;
    while ((in = getch()) != 'R')
        lx = lx * 10 + in - '0';
    x = lx;
    y = ly;
    return 1;
}
int wherex()
{
    int x = 0, y = 0;
    wherexy(x, y);
    return x;
}

int wherey()
{
    int x = 0, y = 0;
    wherexy(x, y);
    return y;
}

int kbhit()
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}

void maxXY(int &X, int &Y)
{
    struct winsize size;
    ioctl(1, TIOCGWINSZ, &size);
    X = size.ws_col;
    Y = size.ws_row;
}

void EraseRow(int R)
{
    gotoyx(R, 1);
    puts(ERASE_LINE);
}
