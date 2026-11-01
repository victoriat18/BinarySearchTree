
#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include "btree.h"

template <typename T>
class BinarySearchTree : public BinaryTree<T>
{
public:
    void Insert(const T& x);
    bool Search(const T& x) const;
    bool Remove(const T& x);

private:
    void _Insert(Node<T>*&, const T&);
    bool _Search(Node<T>*, const T&) const;
    void _Remove(Node<T>*&, const T&);
    bool _Leaf(Node<T>* node) const;
};


// Insert a value into the tree
template <typename T>
void BinarySearchTree<T>::Insert(const T& x)
{
    _Insert(this->root, x);
}


// Recursive insert function
template <typename T>
void BinarySearchTree<T>::_Insert(Node<T>*& node, const T& x)
{
    if (node == nullptr)
    {
        node = new Node<T>(x);
    }
    else if (x < node->data)
    {
        _Insert(node->left, x);
    }
    else if (x > node->data)
    {
        _Insert(node->right, x);
    }
}


// Search for a leaf
template <typename T>
bool BinarySearchTree<T>::Search(const T& x) const
{
    return _Search(this->root, x);
}


// Recursive search function
template <typename T>
bool BinarySearchTree<T>::_Search(Node<T>* node, const T& x) const
{
    if (node == nullptr)
    {
        return false;
    }

    if (x == node->data)
    {
        return _Leaf(node);
    }
    else if (x < node->data)
    {
        return _Search(node->left, x);
    }
    else
    {
        return _Search(node->right, x);
    }
}


// Remove a leaf
template <typename T>
bool BinarySearchTree<T>::Remove(const T& x)
{
    if (Search(x))
    {
        _Remove(this->root, x);
        return true;
    }

    return false;
}


// Recursive remove function
template <typename T>
void BinarySearchTree<T>::_Remove(Node<T>*& node, const T& x)
{
    if (node == nullptr)
    {
        return;
    }

    if (x < node->data)
    {
        _Remove(node->left, x);
    }
    else if (x > node->data)
    {
        _Remove(node->right, x);
    }
    else if (_Leaf(node))
    {
        delete node;
        node = nullptr;
    }
}


// Check whether a node is a leaf
template <typename T>
bool BinarySearchTree<T>::_Leaf(Node<T>* node) const
{
    return node != nullptr &&
           node->left == nullptr &&
           node->right == nullptr;
}

#endif // BINARYSEARCHTREE_H_
