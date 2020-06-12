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
    BSTNode<T>* search(BSTNode<T>* nodePtr, T inputData) const;
    /* This function searches for a specific object in BST
       Pre: BSTNode<T>* nodePtr - root node pointer to start search
            T inputData = data to search for
       Post:
       Return: pointer to found BSTNode, else nullptr
    */
    
    void insert(BSTNode<T>*& nodePtr, BSTNode<T>*& newNode);
    /* This function inserts a specific object in BST
       Pre: BSTNode<T>*& nodePtr - root node to start traversing with
            BSTNode<T>*& newNode - node containing data to be inserted
       Post:
       Return:
    */
    
    void printInOrder(BSTNode<T>* nodePtr, std::ostream& out) const;
    /* This function prints BST in inorder
       Pre: BSTNode<T>* nodePtr - root node to start traversing with
            std::ostream& out = ostream object to send to
       Post:
       Return:
    */
    
    void printPreOrder(BSTNode<T>* nodePtr, std::ostream& out) const;
    /* This function prints BST in preorder
       Pre: BSTNode<T>* nodePtr - root node to start traversing with
            std::ostream& out = ostream object to send to
       Post:
       Return:
    */
    
    void printPostOrder(BSTNode<T>* nodePtr, std::ostream& out) const;
    /* This function prints BST in postorder
       Pre: BSTNode<T>* nodePtr - root node to start traversing with
            std::ostream& out = ostream object to send to
       Post:
       Return:
    */
    
    void remove(T inData, BSTNode<T>*& nodePtr);
    /* This function removes specific node in BST
       Pre: T inData - data to be removed
            BSTNode<T>* nodePtr - root node to start traversing with
       Post:
       Return:
    */
    
public:
    //Ctor
    BST() : root(nullptr), count(0) { }
    
    //Dtor
    ~BST() { clear(root); }
    
    //BST Operations
    BSTNode<T>* search(T inputData) const { return search(root, inputData); }
    /* This function calls private search function
       Pre: T inputData - data to be searcbed
       Post:
       Return: pointer to BSTNode<T>
    */
    
    void insertNode(T inputData);
    /* This function calls private insert function
       Pre: T inputData - data to be inserted
       Post:
       Return:
    */
    
    void deleteNode(T inputData);
    /* This function calls private remove function
       Pre: T inputData - data to be deleted
       Post:
       Return: pointer to BSTNode<T>
    */
    
    void printInOrder(std::ostream& out = std::cout) const { printInOrder(root,out); }
    /* This function calls private printInOrder function
       Pre:
       Post:std::ostream& out - type of ostream obj to send to, defaulted to std::cout
       Return:
    */
    
    void printPreOrder(std::ostream& out = std::cout) const { printPreOrder(root,out); }
    /* This function calls private printPreOrder function
       Pre:
       Post:std::ostream& out - type of ostream obj to send to, defaulted to std::cout
       Return:
    */
    
    void printPostOrder(std::ostream& out = std::cout) const { printPostOrder(root,out); }
    /* This function calls private printPostOrder function
       Pre:
       Post:std::ostream& out - type of ostream obj to send to, defaulted to std::cout
       Return:
    */
    
    void printBreadthFirst(std::ostream& out = std::cout) const;
    /* This function prints BST in breadth first order
       Pre:
       Post:std::ostream& out - type of ostream obj to send to, defaulted to std::cout
       Return:
    */
    
    int getCount() const { return count; }
    /* This function returns class data member count
       Pre:
       Post:
       Return: int = count of nodes in BST
    */
    
    bool isEmpty() const { return count == 0; }
    /* This function returns a bool indicating if BST is empty or not
       Pre:
       Post:
       Return: true if BST is empty, else false
    */
    
    void clear(BSTNode<T>* nodePtr);
    /* This function deletes all nodes in BST
       Pre:
       Post:
       Return:
    */
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
    if (search(nodePtr, inData) == nullptr)
    {
        throw (std::string("Data not found. Unable to delete. "));
        return;
    }
    
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
    count--;
    remove(inputData, root);
}

#endif /* BST_h */
