//--------------------------------------------------------------
// Programmer: Dalton Lobosky
// Class: CS1510
// Section: B
// Assignment: Homework 8
// Date: 12/13/2014
// File Name: mybstree.h
//--------------------------------------------------------------





template <typename T>
MyBSTree<T>::MyBSTree(Node<T>* root, int size)
{
  m_root = root;
  m_size = size; 
}

template <typename T>
MyBSTree<T>::MyBSTree(MyBSTree<T> &x) 
{
  *this = x; 
} 

template <typename T>
MyBSTree<T>::~MyBSTree() 
{
  clear();
}

template <typename T>
const MyBSTree<T>& MyBSTree<T>::operator=(const MyBSTree<T> &rhs)
{
  if(this != &rhs)
  {
    clear();
   
    Node<T>* p= new Node<T>;

    Node<T>* b = rhs.m_root;

    p = clone(b);
	
    this -> m_size = rhs.m_size;

    this -> m_root = p;
  }	
  return *this;
}

template <typename T>
Node<T>* MyBSTree<T>::clone(Node<T>* n)
{
  if (n == NULL)
  {
    return n;
  }
  else
  {
	  return new Node<T>(n -> m_data, clone(n -> m_right), clone(n -> m_left)); 
  }
}

template <typename T>
int MyBSTree<T>::size() const
{
  return m_size;
}

template <typename T>
bool MyBSTree<T>::isEmpty() const
{
  if(m_size == 0)
  {
    return true;
  }
  else
  {
    return false;  
  }
}

template <typename T>
int MyBSTree<T>::height() const
{
  if(isEmpty() == true)
  {
    return 0;
  }
  
  Node<T>* tmp = m_root;
  
  int max_height;
  
  max_height = recur_height(tmp, 0,0);
  
  return max_height; 
}

template <typename T>
int MyBSTree<T>::recur_height(Node<T>* tmp, int max_height, int height) const
{
  height++;
  if(tmp -> m_left != NULL)
  {
    if(height > max_height)
	{
	  max_height = height;
	}
	
	max_height = recur_height(tmp -> m_left, max_height, height);
  }
  
  if(tmp -> m_right != NULL)
  {
    if(height > max_height)
	{
	  max_height = height;
	}
	
	max_height = recur_height(tmp -> m_right, max_height, height);
  }
  
  if((tmp -> m_left == NULL && tmp -> m_right == NULL))
  {  
    if(height > max_height)
	{
	  max_height = height;
	}
  }
  
  return max_height;  
}

template <typename T>
const T& MyBSTree<T>::findMax() const throw (Oops)
{  
  Node<T> *p = m_root;

  try
  {
    string no = "Tree is Empty!!!!!";   
	  if(p==NULL)
	  {
	    throw(no);
	  }
	  
    while(p->m_right != NULL)
    {
	  p = p->m_right; 
	} 
  }
  
  catch(string bob)
  {
    cout << bob << endl;
  }
  
  return p->m_data;
}

template <typename T>
 const T& MyBSTree<T>::findMin() const throw (Oops)
 {
  Node<T> *p = m_root;
  try
  {
    string no = "Tree is Empty!!!!!";
    if(p == NULL)
	{
	    throw(no);
	}
	
    while(p->m_left != NULL)
	{
      p = p->m_left; 
	} 
  }
  
  catch(string bob)
  {
    cout << bob << endl;
  }
  
  return p->m_data;
}

template <typename T>
int MyBSTree<T>::find(const T& x) const
{
  if(m_root == NULL)
  {
    return -1;
  }
  
  if(m_root -> m_data == x)
  {
    return 1;
  }
  
  if(m_root -> m_data > x)
  {
    return (recur_find(x, m_root -> m_left, 2)) ;
  }
  
  else if(m_root -> m_data < x)
  {
    return (recur_find(x, m_root -> m_right, 2));
  }
  
  else
  {
    cout << "Error in find!!" <<endl; 
  }
  
  return -1;
}  

template <typename T>
int MyBSTree<T>::recur_find(const T& x, Node<T>* n, int count) const
{
  if(n -> m_data == x)
  {
    return count;
  }
      
  else if(x < n -> m_data)
  {
    count ++;
	
    if(!n -> m_left)
	{
      return (count*-1);
	}  
	  
    return (recur_find(x, n -> m_left, count));
  } 
  
  else if(x > n -> m_data)
  {
    count++;
  
    if(!n -> m_right)
	{
      return (count*-1);
    }
	
	return (recur_find(x, n -> m_right, count));
  }
  
  else 
  {
    cout << "Error in find." << endl;
    return -1;
  }
 }

template <typename T>
void MyBSTree<T>::clear() 
{
  if(m_root == NULL)
  {
	  return;
  } 	
	
	else
	{
	  recur_clear(m_root);
	  m_root = NULL;
    }
	
  return;
}

template<typename T>
void MyBSTree<T>::recur_clear(Node<T>* n)
{ 
  if(n == NULL)
  {
    return;
  }
  	
  if(n -> m_left != NULL)
  {
    recur_clear(n -> m_left);
  }
  
  if(n -> m_right != NULL)
  {
    recur_clear(n -> m_right);
  }
  
  delete n;
  return;  
}  

template <typename T>
void MyBSTree<T>::insert(const T &x) 
{
  if(m_root == NULL)
  {
    Node<T>* t = new Node<T>;

	  t -> m_data = x;

	  m_root = t;

	  m_size++;
  }

  Node<T>* tmp = m_root;

  recur_insert(tmp, x);

  return;  
}

template <typename T>
void MyBSTree<T>::recur_insert(Node<T>* n, const T& x)
{
  if(x == (n -> m_data))
  {
     return;
  }
  
  else if(n -> m_left == NULL && n -> m_right == NULL)
  {
    m_size++;

	  Node<T>* t = new Node<T>;

	  t -> m_data = x;

	  if(x < n -> m_data)
	  {
	    n -> m_left = t;
	  }
	  
	  else
	  {
	    n -> m_right = t;  
	  }
	  
	  return;
  }
  
  else if(n -> m_right == NULL && x > n -> m_data)
  {
    m_size++;
  
    Node<T>* t = new Node<T>;
  
    t -> m_data = x;
  
    n -> m_right = t;
  
    return;
  }
  
  else if(n -> m_left == NULL && x < n -> m_data)
  {
    m_size++;
  
    Node<T>* t = new Node<T>;
  
    t -> m_data = x;
  
    n -> m_left = t;
  
    return;
  }
  
  else if(x < n -> m_data)
  {
    recur_insert(n -> m_left, x);
	
	return;
  }
  
  else if(x > n -> m_data)
  {
    recur_insert(n -> m_right,x);
	
	return;
  }  
} 

template <typename T>
void MyBSTree<T>::remove(const T& x) 
{
  recur_remove(x, m_root);

  return;
}

template <typename T>
void MyBSTree<T>::recur_remove(const T& x, Node<T>* &n)
{
  if(n==NULL)
  {
    return;
  }
  
  else if(x < n -> m_data)
  {
    recur_remove(x, n -> m_left);
  }
  
  else if(x > n -> m_data)
  {
    recur_remove(x, n -> m_right);
  }
  
  else
  {
	  if(n -> m_left != NULL && n -> m_right != NULL)
	  {
	    n -> m_data = recur_findMax(*n -> m_left);
	  
	    recur_remove(n -> m_data, n -> m_left);
	  }
	  
	  else
	  {
		  Node<T>* tmp = n;
		  
		  n = tmp -> m_left;
		  
		  if(n==NULL)
		  {
		    n = tmp -> m_right;
		  }
		  
		  delete tmp;
      
	      m_size--;
	  }
	}
		  	      
  return;
}

template <typename T>
T& MyBSTree<T>::recur_findMax(Node<T> &n)
{
	if(n.m_right == NULL)
	{
	   return n.m_data;
	}
	
	else
	{
	  return  recur_findMax(*n.m_right);	
	}
} 

template <typename T>
void MyBSTree<T>::printPreOrder() const
{
  recur_printPreOrder(m_root);

  return;
}

template <typename T>
void MyBSTree<T>::recur_printPreOrder(Node<T>* n) const
{
  cout << n -> m_data <<endl;

  if(n -> m_left != NULL)
  {
    recur_printPreOrder(n -> m_left);
  }
  
  if(n -> m_right != NULL)
  {
    recur_printPreOrder(n -> m_right);
  }
  
  return;
}

template <typename T>
void MyBSTree<T>::printPostOrder() const 
{
  recur_printPostOrder(m_root);

  return;
}

template <typename T>
void MyBSTree<T>::recur_printPostOrder(Node<T>* n) const
{
  if(n -> m_left != NULL)
  {
    recur_printPostOrder(n -> m_left);
  }
  
  if(n -> m_right != NULL)
  {
    recur_printPostOrder(n -> m_right);
  }
  
  cout << n -> m_data << endl; 
 
 return;
}

template <typename T>
void MyBSTree<T>::print() const
{ 
  print2(m_root, 0);

  return;
} 

template <typename T>
void MyBSTree<T>::print2(const Node<T>* n, int pad) const
{
  string s(pad, ' ');

  if (n == NULL)
  {
    cout << endl;
  }
  
  else
  {
    print2(n -> m_right, pad+4);

    cout << s << n -> m_data << endl;

    print2(n -> m_left, pad+4);
  }  
}
