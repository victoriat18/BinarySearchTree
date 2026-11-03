//HEADER!
//***************************************************************************
//
// Name: Victoria Torres
// ZId:  Z2043396 
// CSCI 340 PE1
// Binary Search Tree, inserting values, searching for leaf nodes, removing
// nodes, and displaying the trees using inorder traversal.
// Due Date: November 3rd, 2026
// I certify that this is my own work and, where appropriate, an extension
// Of the starter code provided for the assignment.
//
//***************************************************************************

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include "btree.h"

// BinarySearchTree inherits from Binary Tree
// Smaller values go left and larger values go right
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
// Smaller values go left, larger values go right, duplicate values are ignored
template <typename T>
void BinarySearchTree<T>::_Insert(Node<T>*& node, const T& x)
{
    // if the current position is empty, create a new node
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


// Public search function
// Starts searching for the value from the root of the tree. 
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
    // If the value is found, check whether the node is a leaf.
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
// finds the requested value and deletes it only if it is a leaf
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


// Checks whether a node is a leaf
// A leaf has no left or right child
template <typename T>
bool BinarySearchTree<T>::_Leaf(Node<T>* node) const
{
    return node != nullptr &&
           node->left == nullptr &&
           node->right == nullptr;
}

#endif // BINARYSEARCHTREE_H_
