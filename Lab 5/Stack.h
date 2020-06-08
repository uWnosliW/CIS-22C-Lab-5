//Wilson Wu and Keith
//Lab 4
//Implement Stacks and Queues as derived classes of Linked List

#ifndef Stack_hpp
#define Stack_hpp

#include <iostream>
#include "LinkedList.h"
#include "LinkNode.h"
using std::cout;
using std::endl;
using std::cerr;

template<typename T>
class Stack : protected SinglyLinkedList<T>
{
public:
    //Ctor
    Stack() : SinglyLinkedList<T>() { }
    
    //Dtor
    virtual ~Stack();
    
    //Generic List type implementation functions
    
    // Description: shows if stack is empty
    // Pre:
    // Post:
    // Return: true if stack is empty
    virtual bool isEmpty() override;
    
    // Description: delete all elements from stack
    // Pre:
    // Post: delete all elements and reset start and end pointers
    // Return:
    virtual void clear() override;
    
    // Description: returns name of data structure
    // Pre:
    // Post:
    // Return: returns "stack"
    virtual string getStructName() override { return "Stack"; }
    
    // Description: pushes element to top of the stack
    // Pre:
    // Post: new node is created and start pointer is changed to point to the new node
    // Return:
    void push(T inputData);
    
    
    // Description: pops top element of the stack
    // Pre:
    // Post: first node is deleted, start pointer is changed to point to the second node
    // Return:
    void pop();
    
    // Description: shows top element of stack
    // Pre:
    // Post:
    // Return: returns top element in stack
    T peek();
};

template<typename T>
bool Stack<T>::isEmpty()
{
    return SinglyLinkedList<T>::isEmpty();
}

template<typename T>
void Stack<T>::clear()
{
    SinglyLinkedList<T>::clear();
}

template<typename T>
void Stack<T>::push(T inputData)
{
    SinglyLinkedList<T>::prependNode(inputData);
}

template<typename T>
void Stack<T>::pop()
{
    SinglyLinkedList<T>::deleteNode(SinglyLinkedList<T>::start  -> data);
}

template<typename T>
T Stack<T>::peek()
{
    return SinglyLinkedList<T>::start->data;
}

template<typename T>
Stack<T>::~Stack()
{
    LinkNode<T>* nodePtr;
    LinkNode<T>* next;
    nodePtr = SinglyLinkedList<T>::start;
    while (nodePtr != nullptr)
    {
        next = nodePtr->next;
        delete nodePtr;
        nodePtr = next;
    }
}


#endif /* Stack_hpp */
