// Programmer ID: 12355927
// Class: Comp Sci 153
// Section: A
// Homework: 6
// Date: 11/04/2013
//----------------------------------------------------------------


#include <iostream>
#include <string>
#include <istream>

using namespace std;

class Map
{
 public:
  int start_col;
  int start_row;
  int num_cols;
  int num_rows;

  string *map_data;

  void findStart()
  {
    for(int r = 0; r<num_rows;r++)
    {
      for(int c = 0;c<num_cols;c++)
      {
        if (map_data[r][c] == 'S')
        {
          start_col = c;
          start_row = r;
          break;
        }
      }
    }
  }

  bool escape(const int r, const int c)
  {
    cout << "escape(" << r << ", " << c << ")" << endl;
    //if goal, return true
    if(map_data[r][c] == 'E')
    {
       cout << "EXIT!!!!!!" << endl;
       return true;
    }

    if(map_data[r][c] == '#')
    {
      cout << "Wall!!" << endl;
      return false;
    }

    //North
    if( r-1>=0 && map_data[r-1][c] != '#' )
    {
      cout << "Move North" << endl;
      map_data[r][c] = '.';
      return escape(r-1,c);
    }

    //East
    if( c+1<=num_cols && map_data[r][c+1] != '#' )
    {
      cout << "Move East" << endl;
      map_data[r][c] = '.';
      return escape(r,c+1);
    }

    //South
    if( r+1<=num_rows && map_data[r+1][c] != '#' )
    {
      cout << "Move South" << endl;
      map_data[r][c] = '.';
      return escape(r+1,c);
    }

    //West
    if( c-1>=0 && map_data[r][c-1] != '#' )
    {
      cout << "Move West" << endl;
      map_data[r][c] = '.';
      return escape(r,c-1);
    }
  }
};

int main()
{
  Map map;

  while(1)
  {
    cin >> map.num_cols;
    if( map.num_cols == 0 )
    {
      break;
    }

    cin >> map.num_rows;
    cin.ignore(80,'\n');

    cout << "Number of Columns: " << map.num_cols << endl;
    cout << "Number of Rows: " << map.num_rows << endl;

    map.map_data = new string[ map.num_rows ];

    for( int i=0; i<map.num_rows; i++ )
    {
      getline(cin, map.map_data[i]);
      cout << "map_data[" << i << "] is " << map.map_data[i] <<endl;
    }

    map.findStart();

    cout << "Start Column: " << map.start_col << endl;
    cout << "Start Row: " << map.start_row << endl;

    if(map.escape(map.start_row, map.start_col))
    {
      for(int n=0; n<map.num_rows;n++)
      {
        cout << map.map_data[n] << endl;
      }
    }

    delete [] map.map_data;
  }
}
