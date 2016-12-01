//--------------------------------
// Programmer: Dalton Lobosky
// Class: CS 1510
// Section: B
// Homework: 5
// Date: 11/09/2014
// File: robotcalc.cpp
//--------------------------------


#include <cstdlib>
#include <string>
#include <iostream>
#include "linkedliststack.h"

using namespace std;

int main(){
  
  string input; 
  int prod = 1, sum = 0;
  LinkedListStack<int> stack; 
  
  do{
  
    prod = 1;
    sum = 0;
    cin >> input;
    
    if(input == "+"){
      
      int first = stack.top();
     
      stack.pop();
     
      int second = stack.top();
     
      stack.pop();
     
      stack.push(first + second);
    }
    
    else if(input == "-"){
    
      int first = stack.top();

      stack.pop();

      int second = stack.top();

      stack.pop();

      stack.push(second - first);
    }

    else if(input == "*"){

      int first = stack.top();

      stack.pop();

      int second = stack.top();

      stack.pop();

      stack.push(first*second);
    }

    else if(input == "/"){

      int first = stack.top();

      stack.pop();

      int second = stack.top();

      stack.pop();

      stack.push(second / first);
    }

    else if(input == "%"){
     
      int first = stack.top();

      stack.pop();

      int second = stack.top();

      stack.pop();

      stack.push(second%first);
    }

    else if(input == "!"){
      int first = stack.top();

      stack.pop();

      stack.push(-1 * first);
    }

    else if(input == "sum"){
     
        while(!stack.isEmpty()){
        sum+=stack.top();
        stack.pop();
      }

      stack.push(sum);
    }

    else if(input == "prod"){
      
      while(!stack.isEmpty()){
        prod*=stack.top();
        stack.pop();
      }

      stack.push(prod);
    }

    else if(input == "#"){
      
      LinkedListStack<int> temp;

      while(!stack.isEmpty()){
       
        cout << stack.top() << " ";

        temp.push(stack.top());

        stack.pop();
      }

      cout << endl;

      while(!temp.isEmpty()){
        stack.push(temp.top());

        temp.pop();
      }
    }

    else if(input == "$"){
      stack.clear();
    }

    else{
      
      stack.push(atoi(input.c_str()));
    
    }

  }while(input != "@");
  
}
