//----------------------------------------------------
// Programmer: Dalton Lobosky
// Class: CS 1510
// Section: B
// Homework: 2
// Date: 09-22-2014
//----------------------------------------------------

#include <iostream> 
#include "intbox.h"
#include <string>

using namespace std;

// Constructor
IntBox::IntBox(int s, int a)
{
  m_boxsize = s;
  m_ints = new int[s];
    
  for(int i = 0; i < s; i++)
  {
    m_ints[i] = a;
  }
    
}
  
// Destructor
IntBox::~IntBox()
{
  delete m_ints;
}
  
// Operator = 
const IntBox& IntBox::operator = (const IntBox& rhs)
{
  
  if (this == &rhs)
  {
    return *this;
  }
  else if(m_ints != NULL)
  {
    delete m_ints;
  }
  
  m_boxsize = rhs.m_boxsize;
  
  m_ints = new int[m_boxsize];
  for(int k = 0; k < m_boxsize; k++)
  {
    m_ints[k] = rhs.m_ints[k];
  }
  
  return *this;
}
  
// Copy Constructor
IntBox::IntBox (const IntBox& rhs)
{
  m_ints = NULL;
  *this = rhs;
}

// Set
void IntBox::set (int i, int x)
{
  m_ints[i] = x;
}

// Friend
ostream& operator<< (ostream& out, const IntBox& box)
{
  out << "[ ";
  for (int i = 0; i < box.m_boxsize; i++)
  {
    out << box.m_ints[i] << ", ";
  }

  out<<"]";

  return out;
}
