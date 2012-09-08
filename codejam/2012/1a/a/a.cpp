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
  
  int T;
  cin >> T;

  int a, n;
  double arr[100000];

  for (int i = 0; i < T; i++) {
    cin >> a;
    cin >> n;

    cin >> arr[0];
    for (int j = 1; j < a; j++) {
      double t;
      cin >> t;
      arr[j] = arr[j-1] * t;
    }

    double ans = n+2;

    for (int j = a-1; j >= 0; j--) {

      int bs = a-1 - j;
      int na = a-bs;
      double tc = arr[j] * (double)(n-na+1+bs) + (1.0 - arr[j])*(double)(2*n-na+2+bs);

      ans = min(ans, tc);
    }
    
    printf("Case #%d: %6f\n", i+1, ans);

  }

  return 0;
}


