// http://uva.onlinejudge.org/external/1/100.html

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

int dp[1000000];


int rec(int x){
  
  if(x >= 1000000) return x % 2? rec(3*x + 1)+1: rec(x/2)+1;

  if(dp[x] == 0){
    dp[x] = x % 2 ? rec(3*x + 1)+1: rec(x/2)+1;
  }
  
  return dp[x];
}

int main(){

  dp[1] = 1;

  int s, e;
  while(cin >> s >> e){

    int max_len = 0;

    for (int i = min(s, e); i <= max(s, e); i++) {
      max_len = max(max_len, rec(i));
    }

    printf("%d %d %d\n", s, e, max_len);
  }

  return 0;
}


