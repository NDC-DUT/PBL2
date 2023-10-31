#pragma once
#include "DListNode.h"
#include <iostream>
template<class var_t>
class DList
{
private:
    DListNode<var_t> *_pHead;
    DListNode<var_t> *_pTail;
    size_t _ListsSz;

public:
    DList();
    ~DList();
    void push_back(var_t _value);
    void pop_back();
    void push_front(var_t _value);
    void pop_front();
    size_t size();
    DListNode<var_t> *head() const;
};

#include "DList.cc"