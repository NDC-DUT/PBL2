#pragma once
#define clearbuffer() std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n')
#include <iostream>
#include <limits>
#include "COLOUR.h"

long long getLL(std::string &&_message = "", void (*ckLL)(const long long &) = nullptr)
{
    long long LLres;
    std::string _user_inp;
    while (true)
    {
        if (_message != "")
            std::cout << BCYN << _message << " : " << BGRN;
        std::cin >> _user_inp;
        clearbuffer();
        try
        {
            LLres = stoll(_user_inp);
            if (ckLL != nullptr)
                ckLL(LLres);
        }
        catch (...)
        {
            std::cerr << WHTB << BRED << "invalid_argument" << CRESET << '\n';
            continue;
        }
        break;
    }
    return LLres;
}
size_t getULL(std::string &&_message = "", void (*ckULL)(const size_t &) = nullptr)
{
    size_t ULLres;
    std::string _user_inp;
    while (true)
    {
        if (_message != "")
            std::cout << BCYN << _message << " : " << BGRN;
        std::cin >> _user_inp;
        clearbuffer();
        try
        {
            for (const char &ch : _user_inp)
                if (ch == '-')
                    throw 0;
            ULLres = stoull(_user_inp);
            if (ckULL != nullptr)
                ckULL(ULLres);
        }
        catch (...)
        {
            std::cerr << WHTB << BRED << "invalid_argument" << CRESET << '\n';
            continue;
        }
        break;
    }
    return ULLres;
}
int getI(std::string &&_message = "", void (*ckI)(const int &) = nullptr)
{
    int Ires;
    std::string _user_inp;
    while (true)
    {
        if (_message != "")
            std::cout << BCYN << _message << " : " << BGRN;
        std::cin >> _user_inp;
        clearbuffer();
        try
        {
            Ires = stoi(_user_inp);
            if (ckI != nullptr)
                ckI(Ires);
        }
        catch (...)
        {
            std::cerr << WHTB << BRED << "invalid_argument" << CRESET << '\n';
            continue;
        }
        break;
    }
    return Ires;
}
unsigned long getUL(std::string &&_message = "", void (*ckUL)(const int &) = nullptr)
{
    int ULres;
    std::string _user_inp;
    while (true)
    {
        if (_message != "")
            std::cout << BCYN << _message << " : " << BGRN;
        std::cin >> _user_inp;
        clearbuffer();
        try
        {
            ULres = stoul(_user_inp);
            if (ckUL != nullptr)
                ckUL(ULres);
        }
        catch (...)
        {
            std::cerr << WHTB << BRED << "invalid_argument" << CRESET << '\n';
            continue;
        }
        break;
    }
    return ULres;
}
double getD(std::string &&_message = "", void (*ckD)(const double &) = nullptr)
{
    double Dres;
    std::string _user_inp;
    while (true)
    {
        if (_message != "")
            std::cout << BCYN << _message << " : " << BGRN;
        std::cin >> _user_inp;
        clearbuffer();
        try
        {
            Dres = stod(_user_inp);
            if (ckD != nullptr)
                ckD(Dres);
        }
        catch (...)
        {
            std::cerr << WHTB << BRED << "invalid_argument" << CRESET << '\n';
            continue;
        }
        break;
    }
    return Dres;
}
