// http://uva.onlinejudge.org/external/104/10420.html

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

map<string, int> conquests;

bool cmp(pair<string, int> a, pair<string, int> b){
  return a.first < b.first;
}

int main(){
  

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string country;
    cin >> country;
    
    conquests[country] += 1;

    cin.ignore(256, '\n');
  }
  
  vector<pair<string, int> > v(conquests.begin(), conquests.end());

  sort(v.begin(), v.end(), cmp);

  for (int i = 0; i < v.size(); i++) {
    printf("%s %d\n", v[i].first.c_str(), v[i].second);
  }

  return 0;
}


