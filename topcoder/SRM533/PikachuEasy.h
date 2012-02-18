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

using namespace std;

#define p(x) cout << #x << ":" << x << endl;

class PikachuEasy {

public: 
	string check(string word) {

	  int i = 0;
	  bool status = true;
	  while(i < word.size()){
	    string s = word.substr(i, 2);
	    if(s.compare("pi") == 0 || s.compare("ka") == 0){
	      i += 2;
	      continue;
	    }

	    s = word.substr(i, 3);
	    if(s.compare("chu") == 0){
	      i += 3;
	      continue;
	    }
	    status = false;
	    break;
	  }

	  if(status){
	    return "YES";
	  }

	  return "NO";
	}

};
