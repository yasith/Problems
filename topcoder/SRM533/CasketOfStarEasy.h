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

using namespace std;

#define p(x) cout << #x << ":" << x << endl;

class CasketOfStarEasy {

public: 

  map<vector<int>, int > dp;

  int rec(vector<int> v){
    if(dp.find(v) != dp.end()){
      return dp[v];
    }

    if(v.size() == 2){
      return 0;
    }

    int max_en = 0;

    for(int i = 1; i < v.size() - 1; i++){
      vector<int> v2 = v;
      v2.erase(v2.begin() + i);
      int val = v[i-1] * v[i+1] + rec(v2);

      max_en = max(val, max_en);
    }

    dp[v] = max_en;
    return max_en;
  }

	int maxEnergy(vector<int> weight) {
		return rec(weight);
	}

};
