// #include "AVLTree.h"

template <class T>
void NODELNR(std::ostream &os, const std::shared_ptr<AVLNode<T>> &node, std::string delim)
{
    if (node != nullptr)
    {
        NODELNR(os, node->NLeftChild,delim);
        os << node->NValue << delim;
        NODELNR(os, node->NRightChild,delim);
    }
}
template <class T>
void NODERNL(std::ostream &os, const std::shared_ptr<AVLNode<T>> &node, std::string delim)
{
    if (node != nullptr)
    {
        NODERNL(os, node->NRightChild, delim);
        os << node->NValue << delim;
        NODERNL(os, node->NLeftChild, delim);
    }
}
template <class T>
void NODELNR(std::ofstream &ofs, const std::shared_ptr<AVLNode<T>> &node, std::string delim)
{
    if (node != nullptr)
    {
        NODELNR(ofs, node->NLeftChild, delim);
        ofs << node->NValue << delim;
        NODELNR(ofs, node->NRightChild, delim);
    }
}
template <class T>
void NODERNL(std::ofstream &ofs, const std::shared_ptr<AVLNode<T>> &node, std::string delim)
{
    if (node != nullptr)
    {
        NODERNL(ofs, node->NRightChild,delim);
        ofs << node->NValue << delim;
        NODERNL(ofs, node->NLeftChild,delim);
    }
}
template <class T>
size_t AVLTree<T>::NumberOfElements{0};

template <class T>
std::shared_ptr<AVLNode<T>> AVLTree<T>::LLRotation(std::shared_ptr<AVLNode<T>> Nptr)
{
    std::shared_ptr<AVLNode<T>> PL = Nptr->NLeftChild;
    std::shared_ptr<AVLNode<T>> PLR = PL->NRightChild;
    PL->NRightChild = Nptr;
    Nptr->NLeftChild = PLR;
    Nptr->NHeight = NodeHeight(Nptr);
    PL->NHeight = NodeHeight(PL);
    if (TRoot == Nptr)
        TRoot = PL;
    return PL;
}

template <class T>
std::shared_ptr<AVLNode<T>> AVLTree<T>::LRRotation(std::shared_ptr<AVLNode<T>> Nptr)
{
    std::shared_ptr<AVLNode<T>> PL = Nptr->NLeftChild;
    std::shared_ptr<AVLNode<T>> PLR = PL->NRightChild;
    PL->NRightChild = PLR->NLeftChild;
    Nptr->NLeftChild = PLR->NRightChild;
    PLR->NLeftChild = PL;
    PLR->NRightChild = Nptr;
    PL->NHeight = NodeHeight(PL);
    Nptr->NHeight = NodeHeight(Nptr);
    PLR->NHeight = NodeHeight(PLR);
    if (TRoot == Nptr)
        TRoot = PLR;
    return PLR;
}

template <class T>
std::shared_ptr<AVLNode<T>> AVLTree<T>::RRRotation(std::shared_ptr<AVLNode<T>> Nptr)
{
    std::shared_ptr<AVLNode<T>> PR = Nptr->NRightChild;
    std::shared_ptr<AVLNode<T>> PRL = PR->NLeftChild;
    PR->NLeftChild = Nptr;
    Nptr->NRightChild = PRL;
    Nptr->NHeight = NodeHeight(Nptr);
    PR->NHeight = NodeHeight(PR);
    if (TRoot == Nptr)
        TRoot = PR;
    return PR;
}

template <class T>
std::shared_ptr<AVLNode<T>> AVLTree<T>::RLRotation(std::shared_ptr<AVLNode<T>> Nptr)
{
    std::shared_ptr<AVLNode<T>> PR = Nptr->NRightChild;
    std::shared_ptr<AVLNode<T>> PRL = PR->NLeftChild;
    PR->NLeftChild = PRL->NRightChild;
    Nptr->NRightChild = PRL->NLeftChild;
    PRL->NRightChild = PR;
    PRL->NLeftChild = Nptr;
    PR->NHeight = NodeHeight(PR);
    Nptr->NHeight = NodeHeight(Nptr);
    PRL->NHeight = NodeHeight(PRL);
    if (TRoot == Nptr)
        TRoot = PRL;
    return PRL;
}

template <class T>
std::shared_ptr<AVLNode<T>> AVLTree<T>::RInsert(std::shared_ptr<AVLNode<T>> Nptr, const T &Key, bool *SUCCESS)
{
    if (Nptr == nullptr)
    {
        AVLTree::NumberOfElements += 1;
        if (SUCCESS != nullptr)
            *SUCCESS = true;

        return std::make_shared<AVLNode<T>>(Key);
    }
    if (Key < Nptr->NValue)
        Nptr->NLeftChild = RInsert(Nptr->NLeftChild, Key, SUCCESS);
    else if (Key > Nptr->NValue)
        Nptr->NRightChild = RInsert(Nptr->NRightChild, Key, SUCCESS);
    else
    {
        if (SUCCESS != nullptr)
            *SUCCESS = false;

        return Nptr;
    }

    Nptr->NHeight = NodeHeight(Nptr);

    size_t Balance_Root = BalanceFactor(Nptr);
    size_t Balance_Lchild = BalanceFactor(Nptr->NLeftChild);
    size_t Balance_Rchild = BalanceFactor(Nptr->NRightChild);
    if (Balance_Root == 2 && Balance_Lchild == 1)
        return LLRotation(Nptr);
    else if (Balance_Root == 2 && Balance_Lchild == -1)
        return LRRotation(Nptr);
    else if (Balance_Root == -2 && Balance_Rchild == -1)
        return RRRotation(Nptr);
    else if (Balance_Root == -2 && Balance_Rchild == 1)
        return RLRotation(Nptr);

    return Nptr;
}

template <class T>
void AVLTree<T>::Insert(const T &Key, bool *SUCCESS)
{
    TRoot = RInsert(TRoot, Key, SUCCESS);
}

template <class T>
std::shared_ptr<AVLNode<T>> AVLTree<T>::RFindByKey(std::shared_ptr<AVLNode<T>> Nptr, const T &Key)
{
    while (Nptr != nullptr)
    {
        if (Nptr->NValue == Key)
            return Nptr;
        else if (Key < Nptr->NValue)
            Nptr = Nptr->NLeftChild;
        else
            Nptr = Nptr->NRightChild;
    }
    return nullptr;
}

template <class T>
std::shared_ptr<AVLNode<T>> AVLTree<T>::FindByKey(const T &Key)
{
    return RFindByKey(TRoot, Key);
}

template <class T>
std::shared_ptr<AVLNode<T>> AVLTree<T>::RDelete(std::shared_ptr<AVLNode<T>> Nptr, const T &Key, bool *SUCCESS)
{
    if (Nptr != nullptr)
    {
        if (Key < Nptr->NValue)
            Nptr->NLeftChild = RDelete(Nptr->NLeftChild, Key, SUCCESS);
        else if (Key != Nptr->NValue)
            Nptr->NRightChild = RDelete(Nptr->NRightChild, Key, SUCCESS);
        else
        {
            AVLTree::NumberOfElements -= 1;
            if (Nptr->NLeftChild == nullptr)
                Nptr = Nptr->NRightChild;
            else if (Nptr->NRightChild == nullptr)
                Nptr = Nptr->NLeftChild;
            else
            {
                std::shared_ptr<AVLNode<T>> PL = Nptr->NLeftChild;

                if (PL->NRightChild == nullptr)
                {
                    PL->NRightChild = Nptr->NRightChild;
                    Nptr = PL;
                }
                else
                {
                    std::shared_ptr<AVLNode<T>> PLR = PL->NRightChild;
                    while (PLR->NRightChild != nullptr)
                        PLR = PLR->NRightChild;
                    Nptr->NValue = PLR->NValue;
                    Nptr->NLeftChild = RDelete(Nptr->NLeftChild, PLR->NValue, SUCCESS);
                }
            }
            if (SUCCESS != nullptr)
                *SUCCESS = true;
        }
        if (Nptr != nullptr)
        {
            Nptr->NHeight = NodeHeight(Nptr);
            size_t Balance_Root = BalanceFactor(Nptr);
            size_t Balance_Lchild = BalanceFactor(Nptr->NLeftChild);
            size_t Balance_Rchild = BalanceFactor(Nptr->NRightChild);
            if (Balance_Root == 2 && Balance_Lchild == 1)
                return LLRotation(Nptr);
            else if (Balance_Root == 2 && Balance_Lchild == -1)
                return LRRotation(Nptr);
            else if (Balance_Root == 2 && Balance_Lchild == 0)
                return LLRotation(Nptr);
            else if (Balance_Root == -2 && Balance_Rchild == -1)
                return RRRotation(Nptr);
            else if (Balance_Root == -2 && Balance_Rchild == 1)
                return RLRotation(Nptr);
            else if (Balance_Root == -2 && Balance_Lchild == 0)
                return RRRotation(Nptr);
        }
    }

    else
        if (SUCCESS != nullptr)
            *SUCCESS = false;

    return Nptr;
}

template <class T>
void AVLTree<T>::Delete(const T &Key, bool *SUCCESS)
{
    TRoot = RDelete(TRoot, Key, SUCCESS);
}
template <class T>
void AVLTree<T>::LNR(std::ostream &os, std::string delim)
{
    NODELNR(os, TRoot, delim);
}
template <class T>
void AVLTree<T>::RNL(std::ostream &os, std::string delim)
{
    NODERNL(os, TRoot, delim);
}
template <class T>
void AVLTree<T>::LNR(std::ofstream &ofs, std::string delim)
{
    NODELNR(ofs, TRoot, delim);
}
template <class T>
void AVLTree<T>::RNL(std::ofstream &ofs, std::string delim)
{
    NODERNL(ofs, TRoot, delim);
}