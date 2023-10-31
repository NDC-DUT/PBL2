// #include "AVLNode.h"
template <class T>
AVLNode<T>::AVLNode()
    : NLeftChild{nullptr}, NRightChild{nullptr}, NValue{T()}, NHeight{1}
{
}

template <class T>
AVLNode<T>::AVLNode(const T &Key)
    : NLeftChild{nullptr}, NRightChild{nullptr}, NValue{Key}, NHeight{1}
{
}

template <class T>
AVLNode<T>::AVLNode(T &&Key)
    : NLeftChild{nullptr}, NRightChild{nullptr}, NValue{std::move(Key)}, NHeight{1}
{
}

template <class T>
size_t NodeHeight(const std::shared_ptr<AVLNode<T>> &Nptr)
{
    size_t LeftHeight, RightHeight;
    LeftHeight = ((Nptr != nullptr) && (Nptr->NLeftChild != nullptr)) ? Nptr->NLeftChild->NHeight : 0;
    RightHeight = ((Nptr != nullptr) && (Nptr->NRightChild != nullptr)) ? Nptr->NRightChild->NHeight : 0;
    return (LeftHeight > RightHeight) ? (LeftHeight + 1) : (RightHeight + 1);
}

template <class T>
size_t BalanceFactor(const std::shared_ptr<AVLNode<T>> &Nptr)
{
    size_t LeftHeight, RightHeight;
    LeftHeight = ((Nptr != nullptr) && (Nptr->NLeftChild != nullptr)) ? (Nptr->NLeftChild->NHeight) : 0;
    RightHeight = ((Nptr != nullptr) && (Nptr->NRightChild != nullptr)) ? (Nptr->NRightChild->NHeight) : 0;
    return LeftHeight - RightHeight;
}