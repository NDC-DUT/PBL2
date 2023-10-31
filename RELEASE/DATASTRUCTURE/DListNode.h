#pragma once
template <class var_t>
class DListNode
{
public:
    var_t _value;
    DListNode *_pAfter;
    DListNode *_pBefore;

public:
    ~DListNode();
    DListNode(var_t _value, DListNode *_pBefore, DListNode* _pAfter);
};
#include "DListNode.cc"