#pragma once
#include "AVLNode.h"
#include <string>
template <class T>
void NODELNR(std::ostream &os, const std::shared_ptr<AVLNode<T>> &node, std::string delim = "\n");
template <class T>
void NODERNL(std::ostream &os, const std::shared_ptr<AVLNode<T>> &node, std::string delim = "\n");
template <class T>
void NODELNR(std::ofstream &ofs, const std::shared_ptr<AVLNode<T>> &node, std::string delim = "\n");
template <class T>
void NODERNL(std::ofstream &ofs, const std::shared_ptr<AVLNode<T>> &node, std::string delim = "\n");

template <class T>
class AVLTree
{
    static size_t NumberOfElements;

protected:
    std::shared_ptr<AVLNode<T>> TRoot;

private:
    std::shared_ptr<AVLNode<T>> LLRotation(std::shared_ptr<AVLNode<T>> Nptr);
    std::shared_ptr<AVLNode<T>> LRRotation(std::shared_ptr<AVLNode<T>> Nptr);
    std::shared_ptr<AVLNode<T>> RRRotation(std::shared_ptr<AVLNode<T>> Nptr);
    std::shared_ptr<AVLNode<T>> RLRotation(std::shared_ptr<AVLNode<T>> Nptr);

private:
    std::shared_ptr<AVLNode<T>> RInsert(std::shared_ptr<AVLNode<T>> Nptr, const T &Key, bool *SUCCESS = nullptr);
    std::shared_ptr<AVLNode<T>> RDelete(std::shared_ptr<AVLNode<T>> Nptr, const T &Key, bool *SUCCESS = nullptr);
    std::shared_ptr<AVLNode<T>> RFindByKey(std::shared_ptr<AVLNode<T>> Nptr, const T &Key);

public:
    void Insert(const T &Key, bool *SUCCESS = nullptr);
    void Delete(const T &Key, bool *SUCCESS = nullptr);
    std::shared_ptr<AVLNode<T>> FindByKey(const T &Key);

public:
    AVLTree() = default;
    ~AVLTree() = default;

public:
    static size_t Size()
    {
        return AVLTree::NumberOfElements;
    }
    std::shared_ptr<AVLNode<T>> getRoot()
    {
        return TRoot;
    }
    void LNR(std::ostream &os, std::string delim = "\n");
    void RNL(std::ostream &os, std::string delim = "\n");
    void LNR(std::ofstream &ofs, std::string delim = "\n");
    void RNL(std::ofstream &ofs, std::string delim = "\n");
};

#include "AVLTree.cc"