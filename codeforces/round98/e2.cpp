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

#define p(x) cout << #x << ":" << x << endl;

using namespace std;

string str;
string vowels = "aeiouAEIOU";
int dp[200000];


int get_count(int s, int e){
  if(s == 0){
    return dp[e-1];
  }
  return dp[e-1] - dp[s-1];
}

int main(){
  
  cin >> str;
  
  int count = 0;
  for (int i = 0; i < str.length(); i++) {
    bool v = false;
    for (int j = 0; j < vowels.length(); j++) {
      if(vowels[j] == str[i]){
        v = true;
        break;
      }
    }
    
    if (v) {
      count ++;
    }
    dp[i] = count;
  }

  count = 0;
  int size = 0;
  for (int sz = str.length(); sz > 0; sz--) {
    bool found = false;
    for (int pos = 0; pos < str.length() - sz + 1; pos++) {
      int v = get_count(pos, pos+sz);
      if(3 * v <= 2 * sz){
        found = true;
        size = sz;
        count ++;
      }
    }
    if(found)
      break;
  }
  
  if(size == 0){
    cout << "No solution" << endl;
  }else{
    cout << size << " " << count << endl;
  }
  return 0;


  return 0;
}


