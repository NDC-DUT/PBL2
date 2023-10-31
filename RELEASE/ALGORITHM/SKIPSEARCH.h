
#pragma once
#include <cstring>
#include <iostream>
using namespace std;

#define ASize 256

class _cell
{
public:
    unsigned int element;
    _cell *next;

public:
    _cell(unsigned int element = 0, _cell *next = nullptr)
        : element{element}, next{next}
    {
    }
};

typedef _cell *List;

void Allocate(List *X, int *str, const size_t &len)
{
    for (size_t &&i{0}; i < len; ++i)
        X[str[i]] = new _cell(i, X[str[i]]);
}

void DeAllocate(List *X, int *str, const size_t &len)
{
    List p{nullptr};
    for (size_t &&i{0}; i < len; i++)
    {
        while (X[str[i]])
        {
            p = X[str[i]];
            X[str[i]] = p->next;
            delete p;
        }
    }
}
bool ELEMENTCMP(int *X, size_t X_LENGTH, int *Y, size_t Y_LENGTH, size_t X_START_POS, size_t Y_START_POS, size_t CMP_LENGTH)
{
    if (X_START_POS + CMP_LENGTH > X_LENGTH || Y_START_POS + CMP_LENGTH > Y_LENGTH)
        return false;

    for (size_t i(X_START_POS), j(Y_START_POS); i < X_START_POS + CMP_LENGTH; ++i, ++j)
        if (X[i] != Y[j])
            return false;

    return true;
}
bool SKIPSEARCH(const char *pat, const char *txt)
{
    size_t patlen = strlen(pat);
    size_t txtlen = strlen(txt);

    if (patlen > txtlen)
        return false;

    int *pattmp = new int[patlen];
    for (int &&i(0); i < patlen; ++i)
    {
        pattmp[i] = pat[i];
        if (pattmp[i] < 0)
            pattmp[i] += 256;
    }
    int *txttmp = new int[txtlen];
    for (int &&i(0); i < txtlen; ++i)
    {
        txttmp[i] = txt[i];
        if (txttmp[i] < 0)
            txttmp[i] += 256;
    }
    List X[ASize] = {nullptr};
    List p{nullptr};
    Allocate(X, pattmp, patlen);

    for (size_t i = patlen - 1; i < txtlen; i += patlen)
    {
        for (p = X[txttmp[i]]; p != nullptr; p = p->next)
        {
            // if (memcmp(pattmp, txttmp + i - p->element, patlen) == 0 &&
            //     (i - p->element) <= (txtlen - patlen))
            if (ELEMENTCMP(pattmp, patlen, txttmp, txtlen, 0, i - p->element, patlen))
            {
                DeAllocate(X, pattmp, patlen);
                delete[] pattmp;
                delete[] txttmp;
                return true;
            }
        }
    }
    DeAllocate(X, pattmp, patlen);
    delete[] pattmp;
    delete[] txttmp;
    return false;
}
