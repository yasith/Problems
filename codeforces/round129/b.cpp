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
  
  int n, total, prev;

  cin >> n;
  cin >> prev;

  for (int i = 0; i < n - 1; i++) {
    int x;
    cin >> x;
    if(prev > x) {
      total += prev - x;
    }
    
    prev = x;
  }

  return 0;
}


