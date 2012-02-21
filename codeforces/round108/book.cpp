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

long long answer = 1L;
long long mod = 1000000007;

int main(){
 
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> names[i];
  }

  for (int i = 0; i < m; i++) {
    set<char> s;
    for (int j = 0; j < n; j++) {
      s.insert(names[j][i]);
    }
    answer *= s.size();
    answer %= mod;
  }

  cout << answer << endl;

  return 0;
}


