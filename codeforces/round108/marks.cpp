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

int highest[100];

int main(){
  
  int n;
  int m;

  cin >> n >> m;
  
  string gb[100];

  for (int i = 0; i < n; i++) {
    cin >> gb[i];
    for (int j = 0; j < m; j++) {
      highest[j] = max(highest[j], gb[i][j] - '0');
    }
  }

  int ss = 0;

  for (int i = 0; i < n; i++) {
    bool found = false;
    for (int j = 0; j < m; j++) {
      if(gb[i][j] - '0' == highest[j]){
        found = true;
        break;
      }
    }
    
    if(found){
      ss ++; 
    }
  }
  
  cout << ss << endl;

  return 0;
}


