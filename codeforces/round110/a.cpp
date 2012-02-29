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

  int n;
  int a[40][40];
  int row[30];
  int col[30];

int main(){
  
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int num;
      cin >> num;
      row[i] += num;
      col[j] += num;
    }
  }

  int win = 0;

   for (int i = 0; i < n; i++) {
     for (int j = 0; j < n; j++) {
       if(col[j] > row[i]){
         win ++;
       }
     }
   }


  cout << win << endl;

  return 0;
}


