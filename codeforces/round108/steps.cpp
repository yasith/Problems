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

long long n, m;
int sx, sy;
int k;
int v[10001][2];

long long steps;

int main(){
  
  cin >> n >> m;
  cin >> sx >> sy;

  cin >> k;

  for (int i = 0; i < k; i++) {
    cin >> v[i][0] >> v[i][1];
  }

  steps = 0;

  for (int i = 0; i < k; i++) {

    long long dx = v[i][0] < 0 ? sx-1 : n - sx;
    long long dy = v[i][1] < 0 ? sy-1 : m - sy;

    long long xm = v[i][0] == 0 ? m : dx / abs(v[i][0]);
    long long ym = v[i][1] == 0 ? n : dy / abs(v[i][1]);

    long long moves = min(xm, ym);

    sx += v[i][0] * moves;
    sy += v[i][1] * moves;

    steps += moves;
  }

  cout << steps << endl;

  return 0;
}


