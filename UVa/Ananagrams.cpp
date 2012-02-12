// http://uva.onlinejudge.org/external/1/156.html

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

string gen_key(string s){
  for (int i = 0; i < s.size(); i++) {
    if(s[i] < 'a'){
      s[i] += 'a' - 'A'; 
    }
  }

  char *str = new char [s.size() + 1];
  strcpy(str, s.c_str());

  sort(str, str+s.size());

  string sorted (str);
  return sorted;
}

int main(){
  
  map<string, vector<string> > m;

  string s;
  cin >> s;

  do{
    string key = gen_key(s);

    if(!m.count(key)){
      vector<string> v;
      m[key] = v;
    }
    m[key].push_back(s);

    cin >> s;

  }while(s.compare("#") != 0);

  vector<string> v;
  
  map<string, vector<string> >::iterator it;

  for(it=m.begin(); it != m.end(); it++){
    if((*it).second.size() <= 1){
      v.push_back((*it).second[0]);
    } 
  }

  sort(v.begin(), v.end());

  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << endl;
  }

  return 0;
}


