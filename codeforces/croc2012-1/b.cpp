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

string map[1000];
int width, height;

struct column{
  vector<pair<int, int>> cons;
  int dist = 0;
  bool visited = false;
} chamber[1000][1000], start, end;


int main(){

  cin >> height >> width;

  for (int i = 0; i < height; i++) {
    cin >> map[i];
  }

  for(int i = 0; i < width; i++){
    if(map[0][i] == '#'){
      start.cons.push_back(make_pair(0,i));
    }
  }


  return 0;
}


