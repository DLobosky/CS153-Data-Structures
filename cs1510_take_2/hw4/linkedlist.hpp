//----------------------------------------------------
// Programmer: Dalton Lobosky
// Class: CS 1510
// Section: B
// Homework: 4
// Date: 10-14-2014
//----------------------------------------------------

#include <string>
#include <iostream>
using namespace std;


// Operator =
template <class T>
const LinkedList<T>& LinkedList<T>::operator= (const LinkedList<T>& rhs)
{
  LinkedList<T> start(rhs);
  this->m_next = start.m_next;
  this->m_data = start.m_data;
  start.m_next = NULL;
  return *this;
}


// Constructor
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs)
{
  if(rhs.m_next == NULL)
  {
    this->m_next = rhs.m_next;
    this->m_data = rhs.m_data;
  }
  else
  {
    LinkedList* temp = new LinkedList((rhs.m_next)->m_data, (rhs.m_next)->m_next);
    LinkedList* new_loc = temp;
    
    while(temp->m_next != NULL)
    {
      temp->m_next = new LinkedList((temp->m_next)->m_data, (temp->m_next)->m_next);
      temp = temp->m_next;
    }
    
    this->m_data = rhs.m_data;
    this->m_next = new_loc;
  }
}


// Size
template <class T>
int LinkedList<T>::size() const
{
  int x = 0;
  LinkedList<T>* next = m_next;
  while(next != NULL)
  {
    x++;
    next = next->m_next;
  }
  return x;
}


// isEmpty
template <class T>
bool LinkedList<T>::isEmpty() const
{
  return m_next == NULL;
}


// getFirstPtr
template <class T>
LinkedList<T>* LinkedList<T>::getFirstPtr()
{
  if(m_next == NULL)
  {
    cout << "PANIC in LINKEDLIST" << endl;
    return NULL;
  }
  return m_next;
}


// getLastPtr
template <class T>
LinkedList<T>* LinkedList<T>::getLastPtr()
{
  if(m_next == NULL)
  {
    cout << "PANIC in LINKEDLIST" << endl;
    return NULL;
  }
  LinkedList<T>* var = this;
  while(var->m_next != NULL)
  {
    var = var->m_next;
  }
  return var;
}


// getAtPtr
template <class T>
LinkedList<T>* LinkedList<T>::getAtPtr(int i)
{
  int n = 0;
  LinkedList<T>* pres = this;
  while(n < i)
  {
    if(pres == NULL)
    {
      cout << "PANIC in LINKEDLIST" << endl;
      return NULL;
    }
    pres = pres->m_next;
    n++;
  }
  return pres;
}


// Clear
template <class T>
void LinkedList<T>::clear()
{
  LinkedList<T>* temp1 = m_next;
  LinkedList<T>* temp2;
  while(temp1 != NULL)
  {
    temp2 = temp1->m_next;
    delete temp1;
    temp1 = temp2;
  }
  m_next = NULL;
}


// Insert Front
template <class T>
void LinkedList<T>::insert_front(const T& x)
{
  LinkedList<T>* temp = new LinkedList;
  temp->m_next = m_next;
  temp->m_data = m_data;
  m_data = x;
  m_next = temp;
}


// Insert
template <class T>
void LinkedList<T>::insert(const T& x, LinkedList<T>* var1)
{
  LinkedList<T>* temp = new LinkedList;
  temp->m_next = var1->m_next;
  temp->m_data = var1->m_data;
  var1->m_data = x;
  var1->m_next = temp;
  temp = NULL;
}


// Remove
template <class T>
void LinkedList<T>::remove(LinkedList<T>* var2)
{
  LinkedList<T>* temp = var2->m_next;
  var2->m_next = temp->m_next;
  var2->m_data = temp->m_data;
  delete temp;
}


// Operator =
template <class T>
bool LinkedList<T>::operator== (const LinkedList<T>& rhs) const
{
  LinkedList* next = this->m_next;
  LinkedList* rhs_next = rhs.m_next;
  
  if(m_data != rhs.m_data || next == NULL || rhs_next == NULL)
    return false;
  
  while(next != NULL && rhs_next != NULL)
  {
    if(next == NULL || rhs_next == NULL || next->m_data != rhs_next->m_data)
    {
      return false;
    }
    next = next->m_next;
    rhs_next = rhs_next->m_next;
  }
  return true;
}


// Find
template <class T>
LinkedList<T>* LinkedList<T>::find(const T& x)
{
  LinkedList<T>* next = this;
  while(next != NULL)
  {
    if(next->m_data == x)
    {
      return next;
    }
    next = next->m_next;
  }
  return NULL;
}


// Reverse
template <class T>
void LinkedList<T>::reverse()
{
  LinkedList<T>* reverse = new LinkedList<T>;
  reverse->m_next=NULL;
  LinkedList<T>* next=this;
  
  while(next->m_next !=NULL)
  {
    reverse = new LinkedList<T>(next->m_data, reverse);
    next=next->m_next;
  }
  
  m_next->clear();
  delete m_next;
  
  m_data=reverse->m_data;
  m_next=reverse->m_next;
  
  delete reverse;
}


// Append
template <class T>
void LinkedList<T>::append(const LinkedList<T>& xlist)
{
  LinkedList<T>* next = this;
  while((next->m_next)->m_next != NULL)
  {
    next = next->m_next;
  }
  LinkedList<T>* newList = new LinkedList(xlist);
  next->m_next = newList;
  newList = NULL;
}
