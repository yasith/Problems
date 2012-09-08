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
#include <climits>

#define p(x) cout << #x << ":" << x << endl;

using namespace std;

int main(){
  
  int n, min_dist = INT_MAX, town = -1;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    
    if(x < min_dist) {
      min_dist = x;
      town = i + 1;
    } else if(x == min_dist) {
      town = -1;
    }
  }

  if(town == -1) {
    cout << "Still Rozdil" << endl;
  } else {
    cout << town << endl;
  }

  return 0;
}


