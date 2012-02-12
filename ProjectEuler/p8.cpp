#include <vector>
#include <list>
#include <map>
#include <set>
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

string itoa(int val) {stringstream ss;ss << val;return ss.str();} 

int main(){

    string s;
    cin >> s;
    
    int product = 1;
    
    for(int i = 0; i < s.size()-5; i++){
        int p = 1;
        for (int j = i; j < i+5; j ++){
            p *= s[j]-'0';
        }
        product = max(product, p);
            
    }
    
    p(product);

    return 0;
}
