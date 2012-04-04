#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

#define p(x) cout << #x << ":" << x << endl;

using namespace std;

map<int, int> off;
map<int, int> on;

int n, r;

int gcd(int a, int b){
  if(b == 0){
    return a;
  }
  return gcd(b, a%b);
}

int main(){
  
  cin >> n >> r;

  for(int i = 0; i < n; i++){
    off[i+1] = 0;
  }

  for (int i = 0; i < r; i++) {
    char c;
    int j;
    cin >> c >> j;

    if(c == '+'){
      if(on.find(j) != on.end()){
        cout << "Already on" << endl;
        continue;
      }
      int conflict = -1;
      int other = 0;
      
      map<int, int>::iterator it;
      for(it = on.begin(); it != on.end(); it++){
        other = (*it).first;
        if(gcd(other, j) != 1){
          conflict = other;
          break;
        }
      }
      
      if(conflict != -1){
        cout << "Conflict with " << other << endl;
        continue;
      }

      on[j] = 0;
      off.erase(j);
      cout << "Success" << endl;
    }

    if(c == '-'){
      if(off.find(j) != off.end()){
        cout << "Already off" << endl;
        continue;
      }
      
      on.erase(j);
      off[j] = 0;
      
      cout << "Success" << endl;
    }
  }


  return 0;
}


