// #include "VECTOR.h"
// #include <iostream>
// using namespace std;

template <class DATA_T>
void VECTOR<DATA_T>::expand()
{
    AlloSize += 100;
    DATA_T *oldContainner{Container};
    Container = new DATA_T[AlloSize];
    for (int &&i{0}; i < CurSize; ++i)
        Container[i] = std::move(oldContainner[i]);

    if (oldContainner != nullptr)
        delete[] oldContainner;
}

template <class DATA_T>
VECTOR<DATA_T>::VECTOR()
    : Container{nullptr}, CurSize{0}, AlloSize{0}
{
}

template <class DATA_T>
VECTOR<DATA_T>::VECTOR(size_t nSize)
    : CurSize{nSize}, AlloSize{nSize}, Container{nullptr}
{
    if (nSize != 0)
        Container = new DATA_T[AlloSize];
}

template <class DATA_T>
VECTOR<DATA_T>::VECTOR(size_t nSize, DATA_T initVal)
    : CurSize{nSize}, AlloSize{nSize}, Container{nullptr}
{
    if (nSize != 0)
    {
        Container = new DATA_T[AlloSize];
        for (int &&i{0}; i < nSize; ++i)
            Container[i] = initVal;
    }
}

template <class DATA_T>
VECTOR<DATA_T>::VECTOR(std::initializer_list<DATA_T> &&init_list)
    : Container{new DATA_T[init_list.size()]}, CurSize{init_list.size()}, AlloSize{init_list.size()}
{

    std::copy(init_list.begin(), init_list.end(), Container);
}

template <class DATA_T>
VECTOR<DATA_T>::VECTOR(const VECTOR<DATA_T> &rvec)
    : AlloSize{rvec.AlloSize}, CurSize{rvec.CurSize}, Container{nullptr}
{
    if (this->AlloSize != 0)
    {
        Container = new DATA_T[this->AlloSize];
        for (int &&i{0}; i < this->CurSize; ++i)
            Container[i] = rvec.Container[i];
    }
}

template <class DATA_T>
VECTOR<DATA_T>::VECTOR(VECTOR<DATA_T> &&rvec)
    : AlloSize{rvec.AlloSize}, CurSize{rvec.CurSize}, Container{rvec.Container}
{
    rvec.Container = nullptr;
    rvec.CurSize = 0;
    rvec.AlloSize = 0;
}

template <class DATA_T>
VECTOR<DATA_T>::~VECTOR()
{
    if (Container != nullptr)
    {
        delete[] Container;
        Container = nullptr;
        CurSize = 0;
        AlloSize = 0;
    }
}

template <class DATA_T>
void VECTOR<DATA_T>::push_back(const DATA_T &KEY)
{
    if (CurSize == AlloSize)
        expand();
    Container[CurSize++] = KEY;
}

template <class DATA_T>
void VECTOR<DATA_T>::push_back(DATA_T &&KEY)
{
    if (CurSize == AlloSize)
        expand();
    Container[CurSize++] = std::move(KEY);
}

template <class DATA_T>
void VECTOR<DATA_T>::pop_back()
{
    --CurSize;
}

template <class DATA_T>
void VECTOR<DATA_T>::push_front(const DATA_T &KEY)
{
    insert(0, KEY);
}

template <class DATA_T>
void VECTOR<DATA_T>::push_front(DATA_T &&KEY)
{
    insert(0, std::move(KEY));
}

template <class DATA_T>
void VECTOR<DATA_T>::pop_front()
{
    remove(0);
}

template <class DATA_T>
void VECTOR<DATA_T>::insert(const size_t &idx, const DATA_T &KEY)
{
    if (idx < 0 || idx > CurSize)
        return;
    if (CurSize == AlloSize)
        expand();
    for (size_t i{CurSize}; i > idx; --i)
        Container[i] = std::move(Container[i - 1]);
    Container[idx] = KEY;
    ++CurSize;
}

template <class DATA_T>
void VECTOR<DATA_T>::insert(const size_t &idx, DATA_T &&KEY)
{
    if (idx < 0 || idx > CurSize)
        return;
    if (CurSize == AlloSize)
        expand();
    for (size_t i{CurSize}; i > idx; --i)
        Container[i] = std::move(Container[i - 1]);
    Container[idx] = std::move(KEY);
    ++CurSize;
}

template <class DATA_T>
DATA_T &VECTOR<DATA_T>::operator[](const size_t &INDEX)
{
    static DATA_T tempres;
    if (INDEX < 0 || INDEX >= CurSize)
        return tempres;
    return Container[INDEX];
}

template <class DATA_T>
DATA_T &VECTOR<DATA_T>::operator[](size_t &&INDEX)
{
    static DATA_T tempres;
    if (INDEX < 0 || INDEX >= CurSize)
        return tempres;
    return Container[INDEX];
}

template <class DATA_T>
const DATA_T &VECTOR<DATA_T>::operator[](const size_t &INDEX) const
{
    static DATA_T tempres;
    if (INDEX < 0 || INDEX >= CurSize)
        return tempres;
    return Container[INDEX];
}

template <class DATA_T>
const DATA_T &VECTOR<DATA_T>::operator[](size_t &&INDEX) const
{
    static DATA_T tempres;
    if (INDEX < 0 || INDEX >= CurSize)
        return tempres;
    return Container[INDEX];
}

template <class DATA_T>
const size_t &VECTOR<DATA_T>::size() const
{
    return CurSize;
}

template <class DATA_T>
void VECTOR<DATA_T>::remove(const size_t &INDEX)
{
    for (size_t i{INDEX}; i < CurSize - 1; ++i)
        Container[i] = std::move(Container[i + 1]);
    --CurSize;
}
template <class DATA_T>

void VECTOR<DATA_T>::remove(size_t &&INDEX)
{
    for (size_t i{INDEX}; i < CurSize - 1; ++i)
        Container[i] = std::move(Container[i + 1]);
    --CurSize;
}

template <class DATA_T>
void *VECTOR<DATA_T>::find(const DATA_T &KEY)
{
    for (size_t &&i{0}; i < CurSize; ++i)
        if (Container[i] == KEY)
            return Container + i;
    return nullptr;
}

template <class DATA_T>
void *VECTOR<DATA_T>::find(DATA_T &&KEY)
{
    for (size_t &&i{0}; i < CurSize; ++i)
        if (Container[i] == KEY)
            return Container + i;
    return nullptr;
}

template <class DATA_T>
DATA_T *VECTOR<DATA_T>::begin() const
{
    return Container;
}

template <class DATA_T>
DATA_T *VECTOR<DATA_T>::end() const
{
    return Container + CurSize;
}

template <class DATA_T>
VECTOR<DATA_T> &VECTOR<DATA_T>::operator=(const VECTOR &rvec)
{
    this->~VECTOR();
    CurSize = rvec.CurSize;
    AlloSize = rvec.AlloSize;
    Container = new DATA_T[this->AlloSize];
    std::copy(rvec.begin(), rvec.end(), Container);
    return *this;
}

template <class DATA_T>
VECTOR<DATA_T> &VECTOR<DATA_T>::operator=(VECTOR &&rvec)
{
    this->~VECTOR();
    CurSize = rvec.CurSize;
    AlloSize = rvec.AlloSize;
    Container = rvec.Container;
    rvec.CurSize = 0;
    rvec.AlloSize = 0;
    rvec.Container = nullptr;
    return *this;
}