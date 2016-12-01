//----------------------------------------------------
// Programmer: Dalton Lobosky
// Class: CS 1510
// Section: B
// Homework: 3
// Date: 10-5-2014
//----------------------------------------------------


#include <iostream>
using namespace std;

//Destructor
template <typename T>
ArrayList<T>:: ~ArrayList()
{
  m_size = 0;
  m_max = 0;
  if(m_data != NULL)
  {
    delete[] m_data;
    m_data = NULL;
  }
}

// Operator=, performs a deep copy of 'rhs' into 'this' ArrayList
template <typename T>
ArrayList<T>& ArrayList<T>:: operator= (const ArrayList<T> & rhs)
{
  if(this != & rhs)
  {
    delete[] m_data;
    m_data = NULL;
    m_size = rhs.m_size;
    m_max = rhs.m_max;

    if(rhs.m_data != NULL)
    {
      m_data = new T[m_max];
      for(int i = 0; i < m_size; i++)
      {
	m_data[i] = rhs.m_data[i];
      }
    }
  }
  return *this;
}

// Copy Constructor
template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& copy)
{
  m_data = NULL;
  *this = copy;
}

// Accessor function for the number of elements in the list
template <typename T>
int ArrayList<T>::size()const
{
  return m_size;
}

// Accessor function for the first element of the list
template <typename T>
const T& ArrayList<T>::first()const
{
  if(m_size <= 0)
  {
    cout<< "Error! The list is empty!" << endl;
    return m_errobj;
  }
  else
  {
    return m_data[0];
  }
}

// Return a read-and-write reference to the element at the specified position
template <typename T>
T& ArrayList<T> ::operator[](int i)
{
  if(i < 0 || i >= m_size)
  {
    cout<< "Error! i is not in range of m_size!" << endl;
    return m_errobj;
  }
  return m_data[i];
}

// Return a read-only reference to the element at the specified position
template <typename T>
const T& ArrayList<T> ::operator[](int i) const
{
  if(i < 0 || i >= m_size)
  {
    cout<< "Error! i is not in range of m_size!" <<endl;
    return m_errobj;
  }
  return m_data[i];
}

// Finds an element in the ArrayList
template <typename T>
int ArrayList<T>::find(const T& x)
{
  int num = -1;
  for(int k = 0; (k < m_size) && (num == -1); k++)
  {
    if(m_data[k] == x)
    {
      num = k;
    }
  }
  return num;
}

// Clears the ArrayList
template <typename T>
void ArrayList<T>::clear()
{
  m_size = 0;
  m_max = 0;

  if(m_data != NULL)
  {
    delete[] m_data;
    m_data = NULL;
  }
}

// Puts the value x at the end of an ArrayList
template <typename T>
void ArrayList<T>::insert_back(const T& x)
{
  m_size++;
	
  if(m_data == NULL)
  {
    m_max = 4;
    m_size = 1;
    m_data = new T[m_max];
    m_data[0] = x;

    return;
  }

  if(m_size >= m_max)
  {
    m_max *= 2;
    T *tmp = new T[m_max];
    for(int k = 0; k < m_size; k++)
    {
      tmp[k] = m_data[k];
    }

    tmp[m_size - 1] = x;

    delete[] m_data;
    m_data = tmp;
		
    tmp = NULL;
  }
  else
  {
    m_data[m_size -1] = x;
  }
  return;
}

// Puts the value x at the position i in the  ArrayList
template <typename T>
void ArrayList<T>::insert(const T& x, int b)
{
  if(b < 0 || b > m_max)
  {
    cout<< "Error! i is not in range!" <<endl;
  }
  else
  {
    m_size++;
	
    if(m_size >= m_max)
    {
      m_max *= 2;
      T *tmp = new T[m_max];
			
      for(int p = 0; p < m_size; p++)
      {
        tmp[p] = m_data[p];
      }

      for(int q = m_size - 1; q > b; q--)
      {
        tmp[q] = tmp[q-1];
      }

      tmp[b] = x;

      delete[] m_data;
      m_data = new T[m_max];
 
      for(int i = 0; i < m_size; i++)
      {
        m_data[i] = tmp[i];
      }

      delete[] tmp;
      tmp = NULL;
    }
    else
    {
      for(int z = m_size - 1; z > b; z--)
      {
        m_data[z] = m_data[z-1];
      }
      m_data[b] = x;
    }
  }
}

// Removes the element at index i in the array
template <typename T>
void ArrayList<T>::remove(int i)
{
  if(m_size < 0 || i >= m_size)
  {
    cout<< "Error! Empty arraylist." <<endl;
  }
  else
  {
    for(int z = i; z < m_size - 1; z++)
    {
       m_data[z] = m_data[z + 1];
    }

    m_size--;
  }

  if(m_size < m_max/4)
  {
    m_max /= 2;
  }
}

// Swaps two elements of the array
template <typename T>
void ArrayList<T>::swap(int i, int k)
{
  if(i < 0 || k < 0 || i >= m_size || k >= m_size || i ==k)
  {
    if(i == k)
    {
      cout<< "Error! i = k." <<endl;
    }
    else
    {
      cout<< "Error! i or k is out of range." <<endl;
    }
  }
  else
  {
    T tmp;

    tmp = m_data[i];
    m_data[i] = m_data[k];
    m_data[k] = tmp;
  }
}

// Appends two lists
template <typename T>
void ArrayList<T>::append(const ArrayList<T>& alist)
{
  if(m_max < m_size + alist.m_size)
  {
    m_max = m_size + alist.m_size;

    T *tmp = new T[m_max];
    for(int k = 0; k < m_size; k++)
    {
      tmp[k] = m_data[k];
    }

    for(int q = 0; q < alist.m_size; q++)
    {
      tmp[m_size] = alist.m_data[q];
			
      m_size++;
    }

    delete[] m_data;
    m_data = new T[m_max];

    for(int p = 0; p < m_size; p++)
    {
      m_data[p] = tmp[p];
    }

    delete[] tmp;
    tmp = NULL;
  }
  else
  {
    for(int h = 0; h < alist.m_size; h++)
    {
      m_data[m_size] = alist.m_data[h];
 		
      m_size++;
    }
  }
}

// Removes duplicates from an Arraylist
template <typename T>
void ArrayList<T>::purge()
{
  for(int s = 0; s < m_size - 1; s++)
  {
    for(int w = s + 1; w <m_size; w++)
    {
      if(m_data[s] == m_data[w])
      {
      	remove(w);
      }
    }
  }
}
