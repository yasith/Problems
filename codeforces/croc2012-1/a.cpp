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

long long l[2];
long long lx[2]; 

int main(){
 
  long long n;
  cin >> n;

  string m[2];
  cin >> m[0] >> m[1];

  int mc = m[0].size() * m[1].size();

  int x = n % mc;
  int mx = n/mc;

  p(x)

  for (int i = 0; i <= min(n, (long long)mc); i++) {
    char a = m[0][i % m[0].size()];
    char b = m[1][i % m[1].size()];

    if(a !=  b){

      switch(a){

        case 'R':
          if(b == 'P'){
            l[0] ++;
          } else l[1] ++;

          break;

        case 'P':
          if(b == 'S'){
            l[0] ++;
          } else l[1] ++;

          break;

        case 'S':
          if(b == 'R'){
            l[0] ++;
          } else l[1] ++;

          break;
      }
    }

    if(i == x-1){
      p(i)
      p(lx[0])
      p(lx[1])
      lx[0] = l[0];
      lx[1] = l[1];
    }
  }

  cout << (l[0]*mx)+lx[0]<< " " << (l[1]*mx)+lx[1] << endl;

  return 0;
}


