//--------------------------------
// Programmer: Dalton Lobosky
// Class: CS 1510
// Section: B
// Homework: 5
// Date: 11/09/2014
// File: linkedliststack.h
//--------------------------------

#include <string>
#include <iostream>
#include "abstractstack.h"
#ifndef LINKEDLISTSTACK_H
#define LINKEDLISTSTACK_H


using namespace std;

template <typename T>
class LinkedListStack{
  
  public:
   
    T m_data;

    LinkedListStack<T>* m_next;
    
    LinkedListStack(){
      m_next = NULL;
    }
    
    ~LinkedListStack(){
      clear();
    }
    
    void clear(){
      while(m_next!=NULL){
        pop();
      }
    }
    
    void push(const T& x){
      LinkedListStack<T>* temp = new LinkedListStack<T>;
    
      temp->m_data = m_data;

      temp->m_next = m_next;

      m_data = x;

      m_next = temp;
    }
    
    void pop(){
      if(m_next!=NULL){
        
        m_data = m_next->m_data;

        LinkedListStack<T>* temp = m_next;

        m_next = m_next->m_next;

        temp->m_next = NULL;

        delete temp;
      }
    }
    
    const T& top() const throw(string){
      
      if(m_next != NULL){
        return m_data;
      }

      else{
        throw new string("Error, stack empty!!!");
      }
    }
    
    bool isEmpty(){
      return m_next == NULL;
    }
    
};

#endif
