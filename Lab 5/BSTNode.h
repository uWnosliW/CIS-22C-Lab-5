//
//  BSTNode.h
//  Lab 5
//
//  Created by Wilson Wu on 6/7/20.
//  Copyright © 2020 None. All rights reserved.
//

#ifndef BSTNode_h
#define BSTNode_h
template<typename T>
class BSTNode
{
public:
    BSTNode():left(nullptr),right(nullptr){}
    BSTNode(T data):left(nullptr),right(nullptr)
    {
        this->data = data;
    }
    virtual ~BSTNode();
    T get() const { return data; }
    BSTNode<T>* getLeft() const { return left; }
    BSTNode<T>* getRight() const { return right; }
    void set(const T data) { this -> data = data; }
    void setLeft(const BSTNode<T>* left) { this -> left = left; }
    void setRight(const BSTNode<T>* right) { this -> right = right; }
protected:
private:
    T data;
    BSTNode<T>* left;
    BSTNode<T>* right;
};
template<typename T>
BSTNode<T>::~BSTNode()
{
    delete left;
    delete right;
}
#endif /* BSTNode_h */
