
#ifndef H_BTREE
#define H_BTREE

#include "node.h"

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

// Constructor
template <typename T>
BinaryTree<T>::BinaryTree()
{
    root = nullptr;
}

// Returns the number of nodes
template <typename T>
unsigned BinaryTree<T>::getSize() const
{
    return _getSize(root);
}

// Recursive size function
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

// Recursive height function
template <typename T>
unsigned BinaryTree<T>::_getHeight(Node<T>* node) const
{
    if (node == nullptr)
        return 0;

    unsigned leftHeight = _getHeight(node->left);
    unsigned rightHeight = _getHeight(node->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Public insert function
template <typename T>
void BinaryTree<T>::Insert(const T& x)
{
    _Insert(root, x);
}

// Recursive insert function
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

// Public inorder traversal
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


