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
  
  int n, k;
  int a[50];

  cin >> n >> k;
  k --;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if(a[i] >= a[k] && a[i] > 0)
      cnt ++;
  }

  cout << cnt << endl;
  
  return 0;
}


