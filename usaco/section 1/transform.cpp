/*
ID: yasith.1
PROG: transform
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("transform.in");
ofstream fout("transform.out");

struct block{
  char map[11][11];
} input, output;

int N;

bool compare(block a, block b){

  for(int i = 0; i < N; i ++){
    for(int j = 0; j < N; j ++){
      if(a.map[i][j] != b.map[i][j]){
        return false;
      }
    }
  }
  return true;
}

block reflect(block a){
  block b;
  for(int i = 0; i < N; i ++){
    for(int j = 0; j < N; j ++){
      b.map[i][j] = a.map[i][N-1-j];
    }
  }
  return b;
}

block rotate90(block a){
  block b;
  for(int i = 0; i < N; i ++){
    for(int j = 0; j < N; j ++){
      b.map[j][i] = a.map[N-1-i][j];
//      cout << a.map[N-1-i][j] << " ";
    }
  }
//  cout << endl;
  return b;
}

void print(block a){
  for(int i = 0; i < N; i ++){
    for(int j = 0; j < N; j ++){
      cout << a.map[i][j];
    }
    cout << endl;
  }
}

int main(){

  fin >> N;
  for (int i = 0; i < N; i += 1){
    fin >> input.map[i];
  }

//  cout << "Original" << endl;
//  print(input);
//  cout << "90 Degrees" << endl;
//  print(rotate90(input));
//  cout << "Reflection" << endl;
//  print(reflect(input));
//  return 0;

  for (int i = 0; i < N; i += 1){
    fin >> output.map[i];
  }
  
  input = rotate90(input);
  if(compare(output, input)){
    fout << 1 << endl;
    return 0;
  }
  if(compare(output, reflect(input))){
    fout << 5 << endl;
    return 0;
  }

  input = rotate90(input);
  if(compare(output, input)){
    fout << 2 << endl;
    return 0;
  }
  if(compare(output, reflect(input))){
    fout << 5 << endl;
    return 0;
  }

  input = rotate90(input);
  if(compare(output, input)){
    fout << 3 << endl;
    return 0;
  }
  if(compare(output, reflect(input))){
    fout << 5 << endl;
    return 0;
  }
  
  input = rotate90(input);
  if(compare(output, reflect(input))){
    fout << 4 << endl;
    return 0;
  }
  
  if(compare(output, input)){
    fout << 6 << endl;
    return 0;
  }
  
  fout << 7 << endl;  
  return 0;
}
