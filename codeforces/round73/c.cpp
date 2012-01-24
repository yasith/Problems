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
#include <fstream>


#define p(x) 
//cout << #x << ":" << x << endl;

using namespace std;

string itoa(int val) {stringstream ss;ss << val;return ss.str();} 

int GCD(int a, int b) {if(b == 0) return a; return GCD(b, a%b);}

int LCM(int a, int b) {return (a*b)/GCD(a, b);}

int a, b;
map<int, int> dp;

int go(int t){
    if(t == 0){ return go(t+1);}
    p(t);
    if(dp.find(t) != dp.end()){
        return dp.find(t)->second;
    }
    int g;
    int t2 = t;
    while(t2 % a != 0 && t2 % b != 0){
        t2 ++;
    }
    p(t2);
    if(t2 % a == 0 && t2 % b == 0){
        g = a > b ? 0:1;
    }else{
        g = t2%a ? 0:1;
    }
    
    p(g);
    
    dp[t2] = g;
    dp[t] = g;
    
    return g;
}
    
int main(){

    cin >> a >> b;

    int count = LCM(a, b);   
    
    p(count); 
    
    int gfs[2];
    
    for (int i = 0; i < count; i ++){
        int x = go(i);
        p(x);
        gfs[x] ++;
    }
    
    if(gfs[0] == gfs[1]){
        cout << "Equal" << endl;
    }else if(gfs[0] > gfs[1]){
        cout << "Dasha" << endl;
    }else{
        cout << "Masha" << endl;
    }

    return 0;
}
