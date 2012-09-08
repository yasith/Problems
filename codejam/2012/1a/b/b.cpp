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


struct game{
  int one, two;
} games[1000];

int ans;
int total;

int played[1000];

void rec(int s, int n){

  if(s == total){
    if(ans == -1){
      ans = n;
    } else if(ans > n){
      ans = n;
    }
    return;
  }

  int chosen = -1;
  int ds = 0;

  p(total/2);
  p(s);

  for(int i = 0; i < total/2; i++){
    if(played[i] == 0 && games[i].two <= s){
      chosen = i;
      ds = 2;
      break;
    }

    if(played[i] == 1 && games[i].two <= s){
      chosen = i;
      ds = 1;
      break;
    }
 
    if(played[i] == 0 && games[i].one <= s){
      if(chosen == -1){
        chosen = i;
        ds = 1;
      }

      if(chosen != -1){
        if(games[chosen].two < games[i].two){
          chosen = i;
          ds = 1;
        }
      }
    }

 }

  if(chosen != -1){
    played[chosen] += ds;
    rec(s+ds, n+1);
  }

  return;
}

int solve(){

  ans = -1;

  int N;
  cin >> N;

  total = N*2;
  memset(played, 0, sizeof(played));

  for (int i = 0; i < N; i++) {
    cin >> games[i].one >> games[i].two;
  }

  rec(0, 0);

  return ans;

}

int main(){
  
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    int status = solve();
    cout << "Case #" << i+1 << ": ";
    if(status == -1){
      cout << "Too Bad" << endl;
    } else{
      cout << status << endl;
    }
  }

  return 0;
}


