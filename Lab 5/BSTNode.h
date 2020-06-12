#ifndef BSTNode_h
#define BSTNode_h

#include <iostream>

template<typename T>
class BSTNode
{
private:
    T data;
    BSTNode<T>* left;
    BSTNode<T>* right;
public:
    //Ctor
    BSTNode() : left(nullptr), right(nullptr){ }
    BSTNode(T inputData) : data(inputData), left(nullptr), right(nullptr) { }
    
    //Dtor
    ~BSTNode() = default;
    
    //Getters
    // Description: returns data object
    // Pre:
    // Post:
    // Return: data object
    T getData() const { return data; }
    
    // Description: gets left child
    // Pre:
    // Post:
    // Return: pointer to left child
    BSTNode<T>*& getLeft() { return left; }
    
    // Description: gets right child
    // Pre:
    // Post:
    // Return: returns pointer to right child
    BSTNode<T>*& getRight() { return right; }
    
    //Setters
    // Description: sets data
    // Pre: const T inputData - data to set
    // Post: sets data to inputData
    // Return:
    void setData(const T inputData) { data = inputData; }
    
    // Description: sets left pointer
    // Pre: BSTNode<T>* inputNode - pointer to a BSTNode
    // Post: left points to a new BSTNode object
    // Return:
    void setLeft(BSTNode<T>* inputNode) { left = inputNode; }
    
    // Description: sets right pointer
    // Pre: BSTNode<T>* inputNode - pointer to a BSTNode
    // Post: right points to a new BSTNode object
    // Return:
    void setRight(BSTNode<T>* inputNode) { right = inputNode; }
    
    //overload << for testing
    // Description: ostream operator overload
    // Pre:
    // Post: 
    // Return:
    friend std::ostream& operator<< (std::ostream& out, const BSTNode<T>& obj)
    {
        out << "data: " << obj.data << " left: " << obj.left << " right: " << obj.right << std::endl;
        return out;
    }

};

#endif /* BSTNode_h */
