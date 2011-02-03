#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

string path;
int maxpeas = -1;
int w, h, k;
string map[100];
  
void walk(int peas, string steps, int x, int y){
  if(y == h){
    if(!(peas%(k+1)) && maxpeas < peas){
      maxpeas = peas;
      path = steps;
    }
    return;
  }
  
  if(x == w || x < 0){
    return;
  }
  
  peas += map[y][x] - '0';
  walk(peas, steps+'L', x-1, y+1);
  walk(peas, steps+'R', x+1, y+1);
  
  return;
}

int main (int argc, char const* argv[]){
  
  
  cin >> h >> w >> k;
  
  for(int i = h-1; i >= 0; i--){
    cin >> map[i];
  }
  
//  for(int i = 0; i < h; i++){
//    for(int j = 0; j < w; j++){
//      cout << map[i][j] << " ";
//    }
//    cout << endl;
//  }
  
  for(int i = 0; i < w; i++){
    string step = "";
    step = step + (char)(i+1);
    walk(0, step, i, 0);
  }
  
  cout << maxpeas << endl;
  cout << (int)path[0] << endl;
  path.erase(0,1);
  path.erase(path.size()-1, 1);
  if(maxpeas >= 0){
    cout << path << endl;
  }
  
  return 0;
}
