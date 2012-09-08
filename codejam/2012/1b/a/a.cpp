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

struct score{
  int i;
  int val;
};

bool cmp(score a, score b){
  return a.val > b.val;
}

int main(){
 
  int T;

  cin >> T;

  for (int i = 0; i < T; i++) {
    
    printf("Case #%d:", i+1);

    int n = 0;
    cin >> n;

    int total = 0;

    score vals[200];

    for (int j = 0; j < n; j++) {
      int tmp;
      cin >> tmp;

      vals[j].val = tmp;
      vals[j].i = j;
      total += tmp;
    }

   



    printf("\n");
  }

  return 0;
}


