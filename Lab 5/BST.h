#ifndef BST_h
#define BST_h

#include <iostream>
#include "BSTNode.h"
#include "Queue.h"
template<typename T>
class BST
{
private:
    BSTNode<T>* root;
    int count;
    
    // Description: finds a specific object in the BST
    // Pre: BSTNode<T>* nodePtr - root node
    //      T inputData - object to find
    // Post:
    // Return: pointer to BSTNode if found, nullptr otherwise
    BSTNode<T>* search(BSTNode<T>* nodePtr, T inputData) const;
    
    // Description: finds a specific object in the BST
    // Pre: BSTNode<T>* nodePtr - root node
    //      T inputData - object to find
    // Post:
    // Return: pointer to BSTNode if found, nullptr otherwise
    void insert(BSTNode<T>*& nodePtr, BSTNode<T>*& newNode);
    
    // Description: finds a specific object in the BST
    // Pre: BSTNode<T>* nodePtr - root node
    //      T inputData - object to find
    // Post:
    // Return: pointer to BSTNode if found, nullptr otherwise
    void printInOrder(BSTNode<T>* nodePtr, std::ostream &out) const;
    
    // Description: Prints BST preorder
    // Pre:
    // Post:
    // Return:
    void printPreOrder(BSTNode<T>* nodePtr, std::ostream &out) const;
    
    // Description: Prints BST preorder
    // Pre:
    // Post:
    // Return:
    void printPostOrder(BSTNode<T>* nodePtr, std::ostream &out) const;
  
    // Description: Prints BST preorder
    // Pre:
    // Post:
    // Return:
    void remove(T inData, BSTNode<T>*& nodePtr);
    
public:
    //Ctor
    BST() : root(nullptr),count(0) { }
    
    //Dtor
    ~BST() { clear(root); }
    
    //BST Operations
    // Description: calls helper function
    // Pre:
    // Post:
    // Return:
    BSTNode<T>* search(T inputData) const { return search(root, inputData); }
    void insertNode(T inputData);
    void deleteNode(T inputData);
    
    // Description: calls helper function
    // Pre:
    // Post:
    // Return:
    void printInOrder(std::ostream &out = std::cout) const { printInOrder(root,out); }
    
    // Description: calls helper function
    // Pre:
    // Post:
    // Return:
    void printPreOrder(std::ostream &out = std::cout) const { printPreOrder(root,out); }
    
    // Description: calls helper function
    // Pre:
    // Post:
    // Return:
    void printPostOrder(std::ostream &out = std::cout) const { printPostOrder(root,out); }
    
    // Description: prints BST in order
    // Pre:
    // Post:
    // Return:
    void printBreadthFirst(std::ostream &out = std::cout) const;
    
    
    // Description: shows how many nodes are in the BST
    // Pre:
    // Post:
    // Return: number of nodes
    int getCount() const { return count; }
    
    
    // Description: shows if BST is empty
    // Pre:
    // Post:
    // Return: true if BST is empty
    bool isEmpty() const { return count == 0; }
    
    
    // Description: deletes all BSTNodes
    // Pre:
    // Post: deletes all BSTNodes count set to 0
    // Return:
    void clear(BSTNode<T>* nodePtr);
};
template <typename T>
BSTNode<T>* BST<T>::search(BSTNode<T>* nodePtr, T inputData) const
{
    T data = nodePtr->getData();
    if(data == inputData)
    {
        return nodePtr;
    }
    if(data > inputData)
    {
        return nodePtr->getLeft() != nullptr ? search(nodePtr->getLeft(),inputData):nullptr;
    }
    else
    {
        return nodePtr->getRight() != nullptr ? search(nodePtr->getRight(), inputData):nullptr;
    }
}

template<typename T>
void BST<T>::insert(BSTNode<T>*& nodePtr, BSTNode<T>*& newNode)
{
    //std::cout << "newnode incoming: " << *newNode;
    if (nodePtr == nullptr)
    {
        nodePtr = newNode;
        //std::cout << "insert success: " << *nodePtr;
        //std::cout << "inserted into: " << nodePtr << " left: " << nodePtr->getLeft() << " right: " << nodePtr->getRight() << std::endl;
        
        //std::cout << std::endl;
        
    } // insert node if no node in place
    else if (newNode->getData() < nodePtr->getData())
    {
        //std::cout << "search left" << std::endl;
        //std::cout <<"searching: " << nodePtr << std::endl;
        
        insert(nodePtr->getLeft(), newNode);
    } // search left subtree
    else
    {
        //std::cout << "search right" << std::endl;
        //std::cout <<"sitting in: " << nodePtr << std::endl;

        //std::cout << "going to right: " << nodePtr->getRight() << std::endl;
        insert(nodePtr->getRight(), newNode);
    } // search right subtree
}

template<typename T>
void BST<T>::insertNode(T inputData)
{
    BSTNode<T>* newNode = nullptr;
    
    newNode = new BSTNode<T>(inputData);
    count++;
    //std::cout << "Create new node obj for " << inputData << std::endl;
    insert(root, newNode);
}
template<typename T>
void BST<T>::printInOrder(BSTNode<T>* nodePtr, std::ostream &out) const
{
    if (nodePtr != nullptr)
    {
        printInOrder(nodePtr->getLeft(),out);
        out << nodePtr->getData() << std::endl;
        printInOrder(nodePtr->getRight(),out);
    }
}
template<typename T>
void BST<T>::printPreOrder(BSTNode<T>* nodePtr, std::ostream &out) const
{
    if (nodePtr != nullptr)
    {
        out << nodePtr->getData() << std::endl;
        printPreOrder(nodePtr->getLeft(),out);
        printPreOrder(nodePtr->getRight(),out);
    }
}
template<typename T>
void BST<T>::printPostOrder(BSTNode<T>* nodePtr, std::ostream &out) const
{
    if (nodePtr != nullptr)
    {
        printPostOrder(nodePtr->getLeft(),out);
        printPostOrder(nodePtr->getRight(),out);
        out << nodePtr->getData() << std::endl;
    }
}
template<typename T>
void BST<T>::printBreadthFirst(std::ostream &out) const
{
    Queue<BSTNode<T>*> next;
    BSTNode<T>* curr;
    next.enqueue(root);
    while(!next.isEmpty())
    {
        curr = next.peekFront();
        out<<curr->getData()<<std::endl;
        next.dequeue();
        if(curr->getLeft())
        {
            next.enqueue(curr->getLeft());
        }
        if(curr->getRight())
        {
            next.enqueue(curr->getRight());
        }
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
    //cout<<"Removing "<<nodePtr -> getData()<<" "<<nodePtr -> getLeft()<<" "<<nodePtr->getRight()<<endl;
    BSTNode<T>* prev = nullptr;
    BSTNode<T>* curr = nodePtr;
    while(curr != nullptr)
    {
        //cout<<curr -> getData()<<curr -> getLeft()<<" "<<curr -> getRight()<<" "<<prev<<endl;
        if(inData > curr->getData())
        {
            prev = curr;
            curr = curr->getRight();
        }
        else if(inData < curr->getData())
        {
            prev = curr;
            curr = curr->getLeft();
        }
        else
        {
            if (curr -> getLeft() == nullptr && curr -> getRight() == nullptr)
            {
               if (prev == nullptr)
               {
                   nodePtr = nullptr;
               }
               else if (prev -> getLeft() == curr)
               {
                   prev -> setLeft(nullptr);
               }
               else
               {
                   prev -> setRight(nullptr);
               }
            }
            else if (curr -> getLeft() != nullptr && curr -> getRight() == nullptr)
            {
                if (prev == nullptr)
                {
                     nodePtr = curr->getLeft();
                }
                else if (prev->getLeft() == curr)
                {
                    prev->setLeft(curr->getLeft());
                }
                else
                {
                    prev->setRight(curr->getLeft());
                }
            }
            else if (curr->getLeft() == nullptr && curr->getRight() != nullptr)
            {
               if (prev == nullptr)
               {
                   nodePtr = curr -> getRight();
               }
               else if (prev->getLeft() == curr)
               {
                   prev->setLeft(curr->getRight());
               }
               else
               {
                   prev->setRight(curr->getRight());
               }
            }
            else {
                BSTNode<T>* next = curr->getRight();
                while (next->getLeft() != nullptr)
                {
                    next = next -> getLeft();
                }
                T tempData = next -> getData();
                remove(tempData, nodePtr);
                curr->setData(tempData);
            }
            return;
             // Node found and removed
        }
    }
    return;
}

template<typename T>
void BST<T>::deleteNode(T inputData)
{
    count--;
    remove(inputData, root);
}

#endif /* BST_h */
