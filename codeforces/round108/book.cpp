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

int n, m;
string names[101];

long long answer = 0;
long long mod = 1000000007;

int main(){
 
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> names[i];
  }

  answer = n;

  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      int dif = 0;
      for (int k = 0; k < m-1; k++) {
        if(names[i][k] != names[j][k]){
          dif += 2;
        }
      }

      answer += dif;
      answer %= mod;
    }
  }
  
  cout << answer << endl;

  return 0;
}


