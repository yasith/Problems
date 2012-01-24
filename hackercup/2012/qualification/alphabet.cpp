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

int T;
int charmap[26];

int main(){
  
  cin >> T;
  string temp;
  getline(cin, temp);
  for (int i = 0; i < T; i++) {
    memset(charmap, 0, sizeof(charmap));
    string s;
    getline(cin, s);
    for (int j = 0; j < s.size(); j++) {
      if(s[j] == ' '){
        continue;
      }
      //p(s[j]);
      //p(s[j] - 'A');
      charmap[s[j] - 'A'] += 1;
    }
    
   
    // Remove C from the target
    // and divide the number of Cs by two
    charmap['C' - 'A'] /= 2;
    string target = "HACKERUP";
    int minrep = 1000;

    for (int j = 0; j < target.size(); j++) {
      //cout << charmap[target[j] - 'A'];
      //cout << (int)target[j] - 'A';
      minrep = min(minrep, charmap[target[j] - 'A']);
    }

    cout << "Case #" << i + 1 << ": " << minrep << endl;

  }

  return 0;
}


