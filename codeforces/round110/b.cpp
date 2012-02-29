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
int circs[100];
double const PI = 3.14159265;

bool cmp(int a, int b){
  return a > b;
}

int main(){

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> circs[i];
  }

  sort(circs, circs + n, cmp);
 
  /*
  for(int i = 0; i < n; i++){
    cout << circs[i] << " ";
  }*/

  double sz = 0;

  for (int i = 0; i < n; i++) {
    if(i % 2 == 0){
      sz += PI * circs[i] * circs[i];
    } else{
      sz -= PI * circs[i] * circs[i];
    }
  }

  cout << sz << endl;

  return 0;
}


