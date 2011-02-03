/*
ID: yasith.1
PROG: gift1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

map<string, int> initial;
map<string, int> now;
string names[10];

ifstream fin("gift1.in");
ofstream fout("gift1.out");

int np;

int main (int argc, char const* argv[]){
  
  fin >> np;

  for(int i = 0; i < np; i++){
    string name;
    fin >> name;
    
    names[i] = name;
    
    initial[name] = now[name] = 0;
  }  
  
  for(int i = 0; i < np; i++){
    string name;
    fin >> name;
    
    int init, ng;
    fin >> init >> ng;
    
    if(init == 0) continue;
    
    initial[name] = init;
    now[name] += init%ng;
    
    for(int j = 0; j < ng; j++){
      string rec_name;
      fin >> rec_name;
      now[rec_name] += (int)(init/ng);
    }
  }
  
  for(int i = 0; i < np; i++){
    string name = names[i];
    fout << name << " " << (now[name] - initial[name]) << endl;
  }
  
  return 0;
}
