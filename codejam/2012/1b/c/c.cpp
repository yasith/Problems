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

bool found;
vector<int> a;
vector<int> b;

map<int, vector<int> > sums;

void printv(vector<int> v){
  for (int i = 0; i < v.size(); i++) {
    printf("%d ", v[i]);
  }
  printf("\n");
}

int sum(vector<int> v){
  int ret = 0;
  for (int i = 0; i < v.size(); i++) {
    ret += v[i];
  }

  return ret;
}

void rec(vector<int> v){

  if(v.size() == 0) return;

  int s = sum(v);
  //printv(v);
  //cout << s << endl;

  if(sums.find(s) != sums.end()){
    vector<int> v2 = sums[s];

    bool same = false;
    if(v.size() == v2.size()){
      same = true;
      for (int i = 0; i < v.size(); i++) {
        if(v[i] != v2[i]){
          same = false;
          break;
        }
      }
    }

    if(! same){
      a = v;
      b = v2;
      found = true;

      //printf("FOUND\n");
      //printv(a);
      //printv(b);
    }
    return;
  }

  sums[s] = v;

  for(int i = 0; i < v.size(); i++){
    vector<int> nv;
    for (int j = 0; j < v.size(); j++) {
      if(j == i) continue;
      nv.push_back(v[j]);
    }

    rec(nv);

    if(found) return;
  }

  return;
}

int main(){
 
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    printf("Case #%d:\n", i+1);

    sums.clear();
    found = false;

    vector<int> v;
    int n;

    cin >> n;
    for (int j = 0; j < n; j++) {
      int tmp;
      cin >> tmp;
      v.push_back(tmp);
    }

    rec(v);

    if(found){
      printv(a);
      printv(b);
    }else{
      printf("Impossible\n");
    }
  }

  return 0;
}


