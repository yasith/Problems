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

struct card{
  int a;
  int b;
} cards[1000];

bool cmp(card a, card b){
  if(a.b == b.b){
    return a.a > b.a;
  }
  return a.b > b.b;
}

int main(){
  
  int n;
  cin >> n;
  
  for (int i = 0; i < n; i++) {
    cin >> cards[i].a >> cards[i].b;
  }

  sort(cards, cards + n, cmp);

  int i = 0;
  int hp = 1;
  int sc = 0;

  while(i < n && hp > 0){
    sc += cards[i].a;
    hp += cards[i].b;
    hp --;
    i ++;
  }

  cout << sc << endl;

  return 0;
}


