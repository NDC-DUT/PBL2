// #include "DListNode.h"
template <class var_t>
DListNode<var_t>::~DListNode()
{
    if (this->_pBefore)
        this->_pBefore->_pAfter = this->_pAfter;
    if (this->_pAfter)
        this->_pAfter->_pBefore = this->_pBefore;
    this->_pBefore = this->_pAfter = nullptr;
}
template <class var_t>
DListNode<var_t>::DListNode(var_t _value, DListNode *_pBefore, DListNode *_pAfter)
    : _value(_value), _pBefore(_pBefore), _pAfter(_pAfter)
{
}