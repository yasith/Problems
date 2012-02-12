// http://uva.onlinejudge.org/external/117/11799.html

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
  
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int min_speed = 0;
    
    int s;

    do{
      cin >> s;
      min_speed = max(s, min_speed);
    }while(cin.get() != '\n');

    printf("Case %d: %d\n", i+1, min_speed);
  }

  return 0;
}


