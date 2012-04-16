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

#define p(x) 
//cout << #x << ":" << x << endl;

using namespace std;

string itoa(int i){ stringstream ss; ss << i; string s; ss >> s; return s;}

bool compare(string s1, string s2){

  if(s1.size() != s2.size()) return false;

  //cout << s1 << " " << s2 << endl;

  for(int i = 0; i < s1.size()*2; i++){
    bool match = true;
    for(int j = 0; j < s2.size(); j++){
      if(s1[(i+j)%s1.size()] != s2[j]){
        p(i+j);
        p(j);
        p(s1[(i+j)%s1.size()]);
        p(s2[j]);
        match = false;
        break;
      }
    }
    if(match){
      return true;
    }
  }

  return false;
}

int solve(int start, int end){
  int ans = 0;

  for (int i = start; i < end+1; i++) {
    for (int j = i+1; j < end+1; j++) {
      string s1 = itoa(i);
      string s2 = itoa(j);
      
      if(compare(s1, s2)) ans ++;
    }
  }

  return ans;
}

int main(){
  
  //cout << compare(itoa(12345), itoa(34512) )<< endl;

  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    int s, e;
    cin >> s >> e;
    printf("Case #%d: %d\n", i+1, solve(s, e));
  }

  return 0;
}

