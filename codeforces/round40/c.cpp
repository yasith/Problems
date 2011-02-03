#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main (int argc, char const* argv[]){
  
  string input, email;
  cin >> input;
  
  char endchar = input[input.size()-1];
  input[input.size()-1] = '*';
  
  email = email + input[0];
  
  bool o = false, t = false;
  bool at = false;
  for(int i = 1; i < input.size()-1; i++){
    char curchar = input[i];
    if(o && !t){
      if(input[i] != 'o'){
        o = false;
        email = email + 'd';
      } else{
        t = true;
        continue;
      }
    }
    
    if(o && t){
      if(input[i] != 't'){
        o = t = false;
        email = email + "do";
      } else{
        o = t = false;
        email = email + '.';
        continue;
      }
    }
    
    if(!o && t){
      if(input[i] != 't'){
        t = false;
        email = email + 'a';
      } else{
        t = false;
        at = true;
        email = email + '@';
        continue;  
      }
    }
    
    if(input[i] == 'd'){
      o = true;
      continue;
    }
    
    if(input[i] == 'a' && !at){
      t = true;
      continue;
    }
    
    email = email + input[i];
  }
  
  email = email+endchar;
  
  cout << email << endl;
  
  return 0;
}
