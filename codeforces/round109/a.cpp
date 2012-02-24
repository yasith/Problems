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

  int points[1000];
  for (int i = 0; i < n; i++) {
    cin >> points[i];
  }

  int mn = points[0];
  int mx = points[0];

  int amz = 0;

  for (int i = 0; i < n; i++) {
    if(points[i] > mx){
      amz ++;
      mx = points[i];
    }else if(points[i] < mn){
      amz ++;
      mn = points[i];
    }
  }

  cout << amz << endl;

  return 0;
}


