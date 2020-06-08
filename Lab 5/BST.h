#ifndef BST_h
#define BST_h

#include <iostream>
#include "BSTNode.h"

template<typename T>
class BST
{
private:
    BSTNode<T>* root;
    
    void insert(BSTNode<T>*& nodePtr, BSTNode<T>*& newNode);
    void printInOrder(BSTNode<T>* nodePtr);
    void remove(T inData, BSTNode<T>*& nodePtr);
    
public:
    //Ctor
    BST() : root(nullptr) { }
    
    //Dtor
    ~BST() { clear(root); }
    
    //BST Operations
    void insertNode(T inputData);
    void deleteNode(T inputData);
    void printInOrder() { printInOrder(root); }
    void clear(BSTNode<T>* nodePtr);
};

template<typename T>
void BST<T>::insert(BSTNode<T>*& nodePtr, BSTNode<T>*& newNode)
{
    std::cout << "newnode incoming: " << *newNode;
    if (nodePtr == nullptr)
    {
        nodePtr = newNode;
        std::cout << "insert success: " << *nodePtr;
        std::cout << "inserted into: " << nodePtr << " left: " << nodePtr->getLeft() << " right: " << nodePtr->getRight() << std::endl;
        
        std::cout << std::endl;
        
    } // insert node if no node in place
    else if (newNode->getData() < nodePtr->getData())
    {
        std::cout << "search left" << std::endl;
        std::cout <<"searching: " << nodePtr << std::endl;
        
        insert(nodePtr->getLeft(), newNode);
    } // search left subtree
    else
    {
        std::cout << "search right" << std::endl;
        std::cout <<"sitting in: " << nodePtr << std::endl;

        std::cout << "going to right: " << nodePtr->getRight() << std::endl;
        insert(nodePtr->getRight(), newNode);
    } // search right subtree
}

template<typename T>
void BST<T>::insertNode(T inputData)
{
    BSTNode<T>* newNode = nullptr;
    
    newNode = new BSTNode<T>(inputData);
    
    std::cout << "Create new node obj for " << inputData << std::endl;
    insert(root, newNode);
}

template<typename T>
void BST<T>::printInOrder(BSTNode<T>* nodePtr)
{
    if (nodePtr != nullptr)
    {
        printInOrder(nodePtr->getLeft());
        std::cout << nodePtr->getData() << std::endl;
        printInOrder(nodePtr->getRight());
    }
}

template<typename T>
void BST<T>::clear(BSTNode<T>* nodePtr)
{
    if (nodePtr)
    {
        if (nodePtr->getLeft())
            clear(nodePtr->getLeft());
        if (nodePtr->getRight())
            clear(nodePtr->getRight());
        delete nodePtr;
    }
}

template<typename T>
void BST<T>::remove(T inData, BSTNode<T>*& nodePtr)
{
    if (inData < nodePtr->getData())
    {
        remove(inData, nodePtr->getLeft());
    } // search left
    else if (inData > nodePtr->getData())
    {
        remove(inData, nodePtr->getRight());
    } // search right
    else
    {
        BSTNode<T>* temp = nullptr;
        
        if (nodePtr == nullptr)
        {
            std::cerr << "Unable to delete empty node" << std::endl;
        } // if node is empty
        else if (nodePtr->getRight() == nullptr)
        {
            temp = nodePtr;
            nodePtr = nodePtr->getLeft();
            delete temp;
        } // if right child is empty
        else if (nodePtr->getLeft() == nullptr)
        {
            temp = nodePtr;
            nodePtr = nodePtr->getRight();
            delete temp;
        } //if left child is empty
        else
        {
            temp = nodePtr->getRight();
            while (temp->getLeft())
            {
                temp = temp->getLeft();
            }
            // attach left subtree
            temp->setLeft(nodePtr->getLeft());
            temp = nodePtr;
            
            //attach right subtree
            temp->setRight(nodePtr->getRight());
            delete temp;
            
        } // if node has 2 children
            
    } // delete data and re-attach tree
}

template<typename T>
void BST<T>::deleteNode(T inputData)
{
    remove(inputData, root);
}

#endif /* BST_h */
