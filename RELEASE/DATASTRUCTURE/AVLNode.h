#pragma once
#include <memory>
template <class T>
class AVLNode
{

public:
    std::shared_ptr<AVLNode<T>> NLeftChild;
    std::shared_ptr<AVLNode<T>> NRightChild;
    T NValue;
    size_t NHeight;

public:
    AVLNode();
    AVLNode(const T &Key);
    AVLNode(T &&Key);
    ~AVLNode() = default;
};
template <class T>
size_t NodeHeight(const std::shared_ptr<AVLNode<T>> &Nptr);
template <class T>
size_t BalanceFactor(const std::shared_ptr<AVLNode<T>> &Nptr);

#include "AVLNode.cc"