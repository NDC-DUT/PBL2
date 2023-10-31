// #include "DList.h"

template <class var_t>
DList<var_t>::DList()
    : _pHead(nullptr), _pTail(nullptr), _ListsSz(0)
{
}

template <class var_t>
DList<var_t>::~DList()
{
    for (DListNode<var_t> *_pTmp = this->_pHead, *_qTmp; _pTmp != nullptr;)
    {
        _qTmp = _pTmp;
        _pTmp = _pTmp->_pAfter;
        delete _qTmp;
    }
    this->_pHead = this->_pTail = nullptr;
    this->_ListsSz = 0;
}
template <class var_t>
void DList<var_t>::push_back(var_t _value)
{
    if (this->_pTail != nullptr)
    {
        this->_pTail->_pAfter = new DListNode<var_t>(_value, this->_pTail, nullptr);
        this->_pTail = this->_pTail->_pAfter;
    }
    else
        this->_pHead = this->_pTail = new DListNode<var_t>(_value, nullptr, nullptr);
    ++this->_ListsSz;
}
template <class var_t>
void DList<var_t>::pop_back()
{
    if (this->_pTail != nullptr)
    {
        this->_pTail = this->_pTail->_pBefore;
        if (this->_pTail != nullptr)
            delete this->_pTail->_pAfter;
    
        else
        {
            delete this->_pHead;
            this->_pHead = nullptr;
        }
        --this->_ListsSz;
    }
}
template <class var_t>
void DList<var_t>::push_front(var_t _value)
{
    if (this->_pHead != nullptr)
    {
        this->_pHead->_pBefore = new DListNode<var_t>(_value, nullptr, this->_pHead);
        this->_pHead = this->_pHead->_pBefore;
    }
    else
        this->_pHead = this->_pTail = new DListNode<var_t>(_value, nullptr, nullptr);
    ++this->_ListsSz;
}
template <class var_t>
void DList<var_t>::pop_front()
{
    if (this->_pHead != nullptr)
    {
        this->_pHead = this->_pHead->_pAfter;
        if (this->_pHead != nullptr)
            delete this->_pHead->_pBefore;

        else
        {
            delete this->_pTail;
            this->_pTail = nullptr;
        }
        --this->_ListsSz;
    }
}
template <class var_t>
size_t DList<var_t>::size()
{
    return this->_ListsSz;
}
template <class var_t>
DListNode<var_t> *DList<var_t>::head() const
{
    return this->_pHead;
}