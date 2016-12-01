//--------------------------------------------------------
// Programmer: Dalton Lobosky
// Date: 12-08-2014
// Class: CS1510
// Section: B
// Homework: 7
// File Name: heist.cpp
//--------------------------------------------------------


#include <iostream>

using namespace std;

const char start = 'B';
void print_map(char** arr_map, int width, int height);
bool locate_edge(int x, int y, int width, int height, char** arr_map);
bool confirm_location(int x, int y, int width, int height, char** arr_map);

int main()
{
  int count = 0;
  char** arr_map;
  int width =0, height = 0;
  int startX=0, startY=0;

  cin >> width;
  cin >> height;
  
  cin.ignore();

  while(width !=0 && height != 0){
    arr_map = new char*[width];
    for(int i = 0; i < width; i++){
      arr_map[i] = new char[height];
    }

    for(int y = 0; y < height; y++){
      for(int x = 0; x < width; x++){
        cin.get(arr_map[x][y]);
        if(arr_map[x][y] == start){
          startX = x;
          startY = y;
        }
      }

      cin.get();
    }

    locate_edge(startX, startY, width, height, arr_map);
    
    cout << "arr_map: " << count << endl;
    print_map(arr_map, width, height);
    
    cout << endl;
 
    for(int i = 0; i < width; i++){
      delete []arr_map[i];
    }

    delete []arr_map;


    cin >> width;
    cin >> height;
   
    cin.ignore();
    
    count++;
  }
}

void print_map(char** arr_map, int width, int height){
  
  for(int y = 0; y < height; y++){
  
    for(int x = 0; x < width; x++){
      cout << arr_map[x][y];
    }

    cout << endl;
  }
}

bool locate_edge(int x, int y, int width, int height, char** arr_map){
  
  bool confirm = false;
  
  if(arr_map[x][y]=='E'){
    return true;
  }

  if(arr_map[x][y] != 'B'){
    arr_map[x][y]='.';
  }

  if(confirm_location(x,y-1, width, height, arr_map)){
    confirm = locate_edge(x,y-1,width,height,arr_map);
  }

  if(!confirm && confirm_location(x+1,y, width, height, arr_map)){
    confirm = locate_edge(x+1,y,width,height,arr_map);
  }

  if(!confirm && confirm_location(x,y+1, width, height, arr_map)){
    confirm = locate_edge(x,y+1,width,height,arr_map);
  }

  if(!confirm && confirm_location(x-1,y, width, height, arr_map)){
    confirm = locate_edge(x-1,y,width,height,arr_map);
  }

  if(!confirm){
    arr_map[x][y] = ' ';
  }

  return confirm;
}

bool confirm_location(int x, int y, int width, int height, char** arr_map){
  if(x==0 || x == width-1 || y==0 || y==height-1){
    return false;
  }

  if(arr_map[x][y] == ' ' || arr_map[x][y] == 'E'){
    return true;
  }

return false;

}
