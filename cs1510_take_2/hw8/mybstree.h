//--------------------------------------------------------------
// Programmer: Dalton Lobosky
// Class: CS1510
// Section: B
// Assignment: Homework 8
// Date: 12/13/2014
// File Name: mybstree.h
//--------------------------------------------------------------





#ifndef MYBSTREE_H
#define MYBSTREE_H
#include <iostream>
#include <string>
#include "abstractbstree.h"
using namespace std;





template <typename T>
struct Node
{
  T m_data;
  
  Node* m_right;

  Node* m_left;
  
  Node(): m_data(), m_right(NULL), m_left(NULL) {}
 
  Node(T x, Node* r, Node* l): m_data(x), m_right(r), m_left(l) {}  
 
};

template <typename T>
class MyBSTree : public AbstractBSTree<T>
{
  private:
    Node<T>* m_root;
    int m_size;
    
  public:
    MyBSTree(): m_root(NULL), m_size(0) {}
    MyBSTree(Node<T>* root, int size);
	
    Node<T>* clone(Node<T>* t);
    int recur_height(Node<T>* tmp, int max_height, int height) const;
    int recur_find(const T& x, Node<T>* n, int count) const;
    void recur_clear(Node<T>* n);
    void recur_insert(Node<T>* n, const T& x);
    void recur_remove(const T& x, Node<T>* &n);
  
    T& recur_findMax(Node<T> &t);
    void recur_printPreOrder(Node<T>* n) const;
    void recur_printPostOrder(Node<T>* n) const;
    void print2(const Node<T>* n, int pad) const;
    
    ~MyBSTree();
    const MyBSTree<T>& operator=(const MyBSTree<T> &rhs);
    MyBSTree(MyBSTree<T>& x);  
 
    virtual int size() const;
    virtual bool isEmpty() const;
    virtual int height() const;
    virtual const T& findMax() const throw (Oops);
    virtual const T& findMin() const throw (Oops);
    virtual int find(const T& x) const;
    virtual void clear();
    virtual void insert(const T& x);
    virtual void remove(const T& x);
    virtual void printPreOrder() const;
    virtual void printPostOrder() const;
    virtual void print() const;
	
};



#include "mybstree.hpp"
#endif
