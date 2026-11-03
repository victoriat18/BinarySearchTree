
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
#ifndef H_BTREE
#define H_BTREE

#include "node.h"

// Base class for a binary tree
template <typename T>
class BinaryTree
{
public:
    BinaryTree();
    unsigned getSize() const;
    unsigned getHeight() const;
    virtual void Insert(const T&);
    void Inorder(void (*)(const T&));

protected:
    Node<T>* root;

private:
    unsigned _getSize(Node<T>*) const;
    unsigned _getHeight(Node<T>*) const;
    void _Insert(Node<T>*&, const T&);
    void _Inorder(Node<T>*, void (*)(const T&));
};

// Constructor initializes the tree as empty
template <typename T>
BinaryTree<T>::BinaryTree()
{
    root = nullptr;
}

// Returns the total number of nodes in the tree
template <typename T>
unsigned BinaryTree<T>::getSize() const
{
    return _getSize(root);
}

// Recursively counts the nodes in the left and right subtrees.
template <typename T>
unsigned BinaryTree<T>::_getSize(Node<T>* node) const
{
    if (node == nullptr)
        return 0;

    return 1 + _getSize(node->left) + _getSize(node->right);
}

// Returns the height of the tree
template <typename T>
unsigned BinaryTree<T>::getHeight() const
{
    return _getHeight(root);
}

// Recursive finds the height of the left and right subtrees
template <typename T>
unsigned BinaryTree<T>::_getHeight(Node<T>* node) const
{
    if (node == nullptr)
        return 0;

    unsigned leftHeight = _getHeight(node->left);
    unsigned rightHeight = _getHeight(node->right);
    // adds one for the current node to the greater subtree height
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Public insert function
template <typename T>
void BinaryTree<T>::Insert(const T& x)
{
    _Insert(root, x);
}

// Recursive finds an empty position and inserts a new node
template <typename T>
void BinaryTree<T>::_Insert(Node<T>*& node, const T& x)
{
    if (node == nullptr)
    {
        node = new Node<T>(x);
    }
    else if (x < node->data)
    {
        _Insert(node->left, x);
    }
    else
    {
        _Insert(node->right, x);
    }
}

// Visits the left subtree, current node, and right subtree
template <typename T>
void BinaryTree<T>::Inorder(void (*visit)(const T&))
{
    _Inorder(root, visit);
}

// Recursive inorder traversal
template <typename T>
void BinaryTree<T>::_Inorder(Node<T>* node, void (*visit)(const T&))
{
    if (node != nullptr)
    {
        _Inorder(node->left, visit);
        visit(node->data);
        _Inorder(node->right, visit);
    }
}

#endif // H_BTREE


