#include <iostream>
#include <cstring>
#include <algorithm>


using namespace std;

int main (int argc, char const* argv[]){
  
  string a, b;
  int map[300][300];
  int moves;
  
  for(int i = 0; i < 300; i ++){
    for(int j = 0; j < 300; j ++){
      map[i][j] = 200;
    }
  }
  
  cin >> a >> b >> moves;
  
  if(a.size() != b.size()){
    cout << -1 << endl;
    return 0;
  }
  
  for (int i = 0; i < moves; i += 1){
    int s, d, cost;
    char sc, dc;
    cin >> sc >> dc >> cost;
    s = sc - 'a';
    d = dc - 'a';
    map[s][d] = map[d][s] = min(map[s][d], cost);
  }
  
  
  int cost = 0;
  for (int i = 0; i < a.size(); i += 1){
    int s, d;
    s = a[i] - 'a';
    d = b[i] - 'a';
    if(s == d)
      continue;
    if(map[s][d] > 100){
      cost = -1;
      break;
    }
    cost += map[s][d];
  }
  
  cout << cost << endl;
  
  return 0;
}
