#pragma once
#include <initializer_list>
#include <stddef.h>

template <class DATA_T>
class VECTOR
{
private:
    DATA_T *Container;
    size_t CurSize;
    size_t AlloSize;

private:
    void expand();

public:
    VECTOR();
    VECTOR(size_t);
    VECTOR(size_t, DATA_T);
    VECTOR(const VECTOR<DATA_T> &rvec);
    VECTOR(VECTOR<DATA_T> &&rvec);
    VECTOR(std::initializer_list<DATA_T> &&init_list);
    ~VECTOR();

public:
    void push_back(const DATA_T &KEY);
    void push_back(DATA_T &&KEY);
    void pop_back();
    void push_front(const DATA_T &KEY);
    void push_front(DATA_T &&KEY);
    void pop_front();
    void insert(const size_t &idx, const DATA_T &KEY);
    void insert(const size_t &idx, DATA_T &&KEY);
    DATA_T &operator[](const size_t &INDEX);
    DATA_T &operator[](size_t &&INDEX);
    const DATA_T &operator[](const size_t &INDEX) const;
    const DATA_T &operator[](size_t &&INDEX) const;
    void remove(const size_t &INDEX);
    void remove(size_t &&INDEX);
    void *find(const DATA_T &KEY);
    void *find(DATA_T &&KEY);
    const size_t &size() const;

public:
    VECTOR &operator=(const VECTOR &rvec);
    VECTOR &operator=(VECTOR &&rvec);
    // VECTOR &operator=(std::initializer_list<DATA_T> &&init_list);

public:
    DATA_T *begin() const;
    DATA_T *end() const;
};

#include "VECTOR.cc"