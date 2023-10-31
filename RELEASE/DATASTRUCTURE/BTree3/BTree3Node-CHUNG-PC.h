#pragma once

template<class DATA_T>
class BTree3Node
{
public:
    DATA_T leftValue;
    DATA_T rightValue;
    bool isFull;
public:
    BTree3Node* midChild;
    BTree3Node* leftChild;
    BTree3Node* rightChild;
    BTree3Node()
        : isFull{false}, midChild{nullptr}, leftChild{nullptr}, rightChild{nullptr}
    {}
    BTree3Node(const DATA_T& leftValue)
        : leftValue{leftValue}, isFull{false}, midChild{nullptr}, leftChild{nullptr}, rightChild{nullptr}
    {}
    BTree3Node(const DATA_T& leftValue, BTree3Node* leftChild, BTree3Node* midChild)
        : leftValue{leftValue}, isFull{false}, leftChild{leftChild}, midChild{midChild}, rightChild{nullptr}
    {
    }
    ~BTree3Node() = default;
};