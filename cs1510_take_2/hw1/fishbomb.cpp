//-------------------------------------------
// Programmer: Dalton Lobosky
// Date: 09/09/2014
// Homework: 1
// Class: CS1510
//-------------------------------------------

#include <iostream> 

using namespace std;

int main()
{
  int t, h, w, x_coor = 0, y_coor = 0, fish = 0, stor = 0;
  int ** arr;
  
  cin >> t;
  
  for (int j = 0; j < t; j++)
  {
    cin >> h >> w;;
   
    arr = new int*[w];
  
    for(int i = 0; i < w; i++)
    {
      arr[i] = new int[h];
    }
    
    for (int q = 0; q < h; q++)
    {
      for(int v = 0; v < w; v++)
      {
        cin >> arr[v][q];
      }
    }
    
    x_coor = 0;
    y_coor = 0;
    fish = 0;
        
    for(int p = 0; p < h; p++)
    {
      for(int z = 0; z < w; z++)
      { 
        stor = 0;
          
        for(int m = 0; m < h; m++)
        {
          stor += arr[z][m];
        }
        
        for(int s = 0; s < w; s++)
        {
          stor += arr[s][p];
        }
        
        stor -= arr[z][p];
        
        if(fish <= stor)
        {
          fish = stor;
          x_coor = z;
          y_coor = p;
        }
      }
    }
  
  
  
  
    cout << "#" << j << ": (" << x_coor << ", " << y_coor << ") " << fish << endl; 
  
    for(int d = 0; d < w; d++)
    {
      delete [] arr[d];
    }
  
    delete [] arr;
  
    arr = NULL;
  }
  
  return 0;
}
  

