// http://uva.onlinejudge.org/external/115/11559.html

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

int main(){
  
  int n, b, h, w;

  while(cin >> n >> b >> h >> w){
    int min_cost = b + 1;

    for (int i = 0; i < h; i++) {
      int p;
      cin >> p;
      
      for (int j = 0; j < w; j++) {
        int ab; // available beds
        cin >> ab;

        if(ab >= n)
          min_cost = min(min_cost, n * p);
      }
    }

    if(min_cost < b + 1){
      cout << min_cost << endl; 
    }else{
      cout << "stay home" << endl; 
    }
  }

  return 0;
}


