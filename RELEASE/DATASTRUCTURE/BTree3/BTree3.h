#pragma once
// #include <iostream>
// using std::cout;
#include "BTree3Node.h"
template <class DATA_T>
class BTree3
{
private:
    static size_t NumberOfElements;

private:
    BTree3Node<DATA_T> *btRoot;

private:
    BTree3Node<DATA_T> *T_Insert(BTree3Node<DATA_T> *BPtr, const DATA_T &Key);
    BTree3Node<DATA_T> *T_Insert(BTree3Node<DATA_T> *BPtr, const DATA_T &&Key);
    BTree3Node<DATA_T> *T_Find(BTree3Node<DATA_T> *BPtr, const DATA_T &Key);
    BTree3Node<DATA_T> *T_Find(BTree3Node<DATA_T> *BPtr, const DATA_T &&Key);

public:
    BTree3() : btRoot{nullptr} {};
    ~BTree3();

public:
    void Insert(const DATA_T &Key);
    void Insert(const DATA_T &&Key);
    // void Delete(const DATA_T &Key);
    BTree3Node<DATA_T> *Find(const DATA_T &Key);
    static size_t GetElementCount();
    BTree3Node<DATA_T> *GetRoot();
};

template <class DATA_T>
size_t BTree3<DATA_T>::NumberOfElements{0};

template <class DATA_T>
size_t BTree3<DATA_T>::GetElementCount()
{
    return BTree3<DATA_T>::NumberOfElements;
}

template <class DATA_T>
BTree3Node<DATA_T> *BTree3<DATA_T>::GetRoot()
{
    return this->btRoot;
}

template <class DATA_T>
void DeallocateBTree(BTree3Node<DATA_T> *nPTR)
{
    if (nPTR != nullptr)
    {
        if (nPTR->leftChild == nullptr)
            delete nPTR;
        else
        {
            DeallocateBTree(nPTR->leftChild);
            DeallocateBTree(nPTR->midChild);
            if (nPTR->isFull == true)
                DeallocateBTree(nPTR->rightChild);
            delete nPTR;
        }
    }
}

template <class DATA_T>
BTree3<DATA_T>::~BTree3()
{
    DeallocateBTree(btRoot);
}

template <class DATA_T>
BTree3Node<DATA_T> *BTree3<DATA_T>::T_Insert(BTree3Node<DATA_T> *nPTR, const DATA_T &Key)
{
    if (nPTR == nullptr) // nPTR is null btRoot
    {
        nPTR = new BTree3Node<DATA_T>(Key);
        BTree3<DATA_T>::NumberOfElements += 1;
        return nPTR;
    }
    // Case 1 : Leaf
    if (nPTR->leftChild == nullptr)
    {
        // 1-Val Leaf
        if (nPTR->isFull == 0)
        {
            if (Key > nPTR->leftValue)
                nPTR->rightValue = Key;

            else
            {
                nPTR->rightValue = nPTR->leftValue;
                nPTR->leftValue = Key;
            }
            nPTR->isFull = 1;
            BTree3<DATA_T>::NumberOfElements += 1;
            return nPTR;
        }
        // 2-Val Leaf
        BTree3Node<DATA_T> *OutNode1;
        BTree3Node<DATA_T> *OutNode2;
        if (Key < nPTR->leftValue)
        {
            OutNode2 = new BTree3Node<DATA_T>(nPTR->rightValue);
            OutNode1 = new BTree3Node<DATA_T>(nPTR->leftValue, nPTR, OutNode2);
            nPTR->leftValue = Key;
        }

        else if (Key > nPTR->rightValue)
        {
            OutNode2 = new BTree3Node<DATA_T>(Key);
            OutNode1 = new BTree3Node<DATA_T>(nPTR->rightValue, nPTR, OutNode2);
        }
        else
        {
            OutNode2 = new BTree3Node<DATA_T>(nPTR->rightValue);
            OutNode1 = new BTree3Node<DATA_T>(Key, nPTR, OutNode2);
        }
        BTree3<DATA_T>::NumberOfElements += 1;
        nPTR->isFull = 0;
        return OutNode1;
    }
    // case 2 : AVLNode
    // case 2.1 : 2-node
    if (nPTR->isFull == false)
    {
        if (Key < nPTR->leftValue)
        {
            nPTR->leftChild = T_Insert(nPTR->leftChild, Key);
            // join
            if (nPTR->leftChild->isFull == false)
            {
                BTree3Node<DATA_T> *PL = nPTR->leftChild;
                nPTR->rightValue = nPTR->leftValue;
                nPTR->leftValue = PL->leftValue;
                nPTR->isFull = 1;
                nPTR->rightChild = nPTR->midChild;
                nPTR->midChild = PL->midChild;
                nPTR->leftChild = PL->leftChild;
                delete PL;
            }
            return nPTR;
        }
        // Key > nPTR->leftValue
        else
        {
            nPTR->midChild = T_Insert(nPTR->midChild, Key);
            if (nPTR->midChild->isFull == false)
            {
                BTree3Node<DATA_T> *PM = nPTR->midChild;
                nPTR->rightValue = PM->leftValue;
                nPTR->isFull = 1;
                nPTR->midChild = PM->leftChild;
                nPTR->rightChild = PM->midChild;
                delete PM;
            }
        }
        return nPTR;
    }
    // case 2.2 : 3-node
    BTree3Node<DATA_T> *PCheck{nullptr};
    BTree3Node<DATA_T> *SubNode{nullptr};
    if (Key < nPTR->leftValue)
    {
        nPTR->leftChild = T_Insert(nPTR->leftChild, Key);
        PCheck = nPTR->leftChild;
        if (PCheck->isFull == false)
        {
            SubNode = new BTree3Node<DATA_T>(nPTR->leftValue, PCheck, nPTR);
            nPTR->leftValue = nPTR->rightValue;
            nPTR->isFull = false;
            nPTR->leftChild = nPTR->midChild;
            nPTR->midChild = nPTR->rightChild;
            nPTR->rightChild = nullptr;
            return SubNode;
        }
    }
    // Key > nPTR->leftValue
    else if (Key > nPTR->rightValue)
    {
        nPTR->rightChild = T_Insert(nPTR->rightChild, Key);
        PCheck = nPTR->rightChild;
        if (PCheck->isFull == false)
        {
            SubNode = new BTree3Node<DATA_T>(nPTR->rightValue, nPTR, PCheck);
            nPTR->isFull = false;
            nPTR->rightChild = nullptr;
            return SubNode;
        }
    }
    else
    {
        nPTR->midChild = T_Insert(nPTR->midChild, Key);
        PCheck = nPTR->midChild;
        if (PCheck->isFull == false)
        {
            SubNode = new BTree3Node<DATA_T>(PCheck->leftValue, nPTR, PCheck);
            nPTR->midChild = PCheck->leftChild;
            PCheck->leftValue = nPTR->rightValue;
            PCheck->leftChild = PCheck->midChild;
            PCheck->midChild = nPTR->rightChild;
            nPTR->isFull = false;
            nPTR->rightChild = nullptr;
            return SubNode;
        }
    }
    return nPTR;
}

template <class DATA_T>
BTree3Node<DATA_T> *BTree3<DATA_T>::T_Insert(BTree3Node<DATA_T> *nPTR, const DATA_T &&Key)
{
    if (nPTR == nullptr) // nPTR is null btRoot
    {
        nPTR = new BTree3Node<DATA_T>(std::move(Key));
        BTree3<DATA_T>::NumberOfElements += 1;
        return nPTR;
    }
    // Case 1 : Leaf
    if (nPTR->leftChild == nullptr)
    {
        // 1-Val Leaf
        if (nPTR->isFull == 0)
        {
            if (Key > nPTR->leftValue)
                nPTR->rightValue = std::move(Key);
            else
            {
                nPTR->rightValue = nPTR->leftValue;
                nPTR->leftValue = std::move(Key);
            }
            BTree3<DATA_T>::NumberOfElements += 1;
            nPTR->isFull = 1;
            return nPTR;
        }
        // 2-Val Leaf
        BTree3Node<DATA_T> *OutNode1;
        BTree3Node<DATA_T> *OutNode2;
        if (Key < nPTR->leftValue)
        {
            OutNode2 = new BTree3Node<DATA_T>(nPTR->rightValue);
            OutNode1 = new BTree3Node<DATA_T>(nPTR->leftValue, nPTR, OutNode2);
            nPTR->leftValue = std::move(Key);
        }
        else if (Key > nPTR->rightValue)
        {
            OutNode2 = new BTree3Node<DATA_T>(std::move(Key));
            OutNode1 = new BTree3Node<DATA_T>(nPTR->rightValue, nPTR, OutNode2);
        }
        else
        {
            OutNode2 = new BTree3Node<DATA_T>(nPTR->rightValue);
            OutNode1 = new BTree3Node<DATA_T>(std::move(Key), nPTR, OutNode2);
        }
        BTree3<DATA_T>::NumberOfElements += 1;
        nPTR->isFull = 0;
        return OutNode1;
    }
    // case 2 : AVLNode
    // case 2.1 : 2-node
    if (nPTR->isFull == false)
    {
        if (Key < nPTR->leftValue)
        {
            nPTR->leftChild = T_Insert(nPTR->leftChild, std::move(Key));
            // join
            if (nPTR->leftChild->isFull == false)
            {
                BTree3Node<DATA_T> *PL = nPTR->leftChild;
                nPTR->rightValue = nPTR->leftValue;
                nPTR->leftValue = PL->leftValue;
                nPTR->isFull = 1;
                nPTR->rightChild = nPTR->midChild;
                nPTR->midChild = PL->midChild;
                nPTR->leftChild = PL->leftChild;
                delete PL;
            }
            return nPTR;
        }
        // Key > nPTR->leftValue
        else
        {
            nPTR->midChild = T_Insert(nPTR->midChild, std::move(Key));
            if (nPTR->midChild->isFull == false)
            {
                BTree3Node<DATA_T> *PM = nPTR->midChild;
                nPTR->rightValue = PM->leftValue;
                nPTR->isFull = 1;
                nPTR->midChild = PM->leftChild;
                nPTR->rightChild = PM->midChild;
                delete PM;
            }
        }
        return nPTR;
    }
    // case 2.2 : 3-node
    BTree3Node<DATA_T> *PCheck{nullptr};
    BTree3Node<DATA_T> *SubNode{nullptr};
    if (Key < nPTR->leftValue)
    {
        nPTR->leftChild = T_Insert(nPTR->leftChild, std::move(Key));
        PCheck = nPTR->leftChild;
        if (PCheck->isFull == false)
        {
            SubNode = new BTree3Node<DATA_T>(nPTR->leftValue, PCheck, nPTR);
            nPTR->leftValue = nPTR->rightValue;
            nPTR->isFull = false;
            nPTR->leftChild = nPTR->midChild;
            nPTR->midChild = nPTR->rightChild;
            nPTR->rightChild = nullptr;
            return SubNode;
        }
    }
    // Key > nPTR->leftValue
    else if (Key > nPTR->rightValue)
    {
        nPTR->rightChild = T_Insert(nPTR->rightChild, std::move(Key));
        PCheck = nPTR->rightChild;
        if (PCheck->isFull == false)
        {
            SubNode = new BTree3Node<DATA_T>(nPTR->rightValue, nPTR, PCheck);
            nPTR->isFull = false;
            nPTR->rightChild = nullptr;
            return SubNode;
        }
    }
    else
    {
        nPTR->midChild = T_Insert(nPTR->midChild, std::move(Key));
        PCheck = nPTR->midChild;
        if (PCheck->isFull == false)
        {
            SubNode = new BTree3Node<DATA_T>(PCheck->leftValue, nPTR, PCheck);
            nPTR->midChild = PCheck->leftChild;
            PCheck->leftValue = nPTR->rightValue;
            PCheck->leftChild = PCheck->midChild;
            PCheck->midChild = nPTR->rightChild;
            nPTR->isFull = false;
            nPTR->rightChild = nullptr;
            return SubNode;
        }
    }
    return nPTR;
}

template <class DATA_T>
void BTree3<DATA_T>::Insert(const DATA_T &Key)
{
    btRoot = T_Insert(btRoot, Key);
}

template <class DATA_T>
void BTree3<DATA_T>::Insert(const DATA_T &&Key)
{
    btRoot = T_Insert(btRoot, std::move(Key));
}
template <class DATA_T>
BTree3Node<DATA_T> *BTree3<DATA_T>::T_Find(BTree3Node<DATA_T> *nPTR, const DATA_T &Key)
{
    while (nPTR != nullptr)
    {
        if (Key < nPTR->leftValue)
            nPTR = nPTR->leftChild;
        else if (Key > nPTR->leftValue)
        {
            if (nPTR->isFull == true)
            {
                if (Key < nPTR->rightValue)
                    nPTR = nPTR->midChild;
                else if (Key > nPTR->rightValue)
                    nPTR = nPTR->rightChild;
                else
                    break;
            }
            else
                nPTR = nPTR->midChild;
        }
        else
            break;
    }
    return nPTR;
}

template <class DATA_T>
BTree3Node<DATA_T> *BTree3<DATA_T>::Find(const DATA_T &Key)
{
    return T_Find(btRoot, Key);
}

// template <class DATA_T>
// BTree3Node<DATA_T> *BTree3<DATA_T>::Find(const DATA_T &&Key)
// {
//     return T_Find(btRoot, std::move(Key));
// }
// template <class DATA_T>
// void BTree3<DATA_T>::Delete(const DATA_T &Key)
// {
// }